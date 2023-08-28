/*
 *  This file is part of the dual-http_server doorbell project.
 *  Copyright (C) 2023  Espen Andersen (espenandersen.no)
 *
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "http_server.hpp"
#include "settings_file.hpp"
#include "http_context_config.hpp"
#include "esp_log.h"
#include <sys/param.h>
#include <esp_http_server.h>

using namespace espena::components;

const char *http_server::LOG_TAG = "http_server";
const esp_event_base_t http_server::event_base = "HTTP_SERVER_EVENT";

::espena::components::http_context_config http_server::m_ctx_config;

http_server::http_server( const configuration &config ) :
  m_config( config ),
  m_settings_file( NULL )
{
  
}

http_server::~http_server() {

}

esp_err_t http_server::config_get_handler( httpd_req_t *req ) {
  http_server *srv = static_cast<http_server *>( req->user_ctx );
  srv->m_ctx_config.set( srv->m_settings_file );
  httpd_resp_send( req, srv->m_ctx_config.response(), HTTPD_RESP_USE_STRLEN );
  return ESP_OK;
}

esp_err_t http_server::config_post_handler( httpd_req_t *req ) {
  http_server *srv = static_cast<http_server *>( req->user_ctx );
  ESP_LOGI( LOG_TAG, "Post request received" );
  int res = ESP_OK;
  const size_t buflen = req->content_len;
  std::string post_data;
  if( buflen > 0 ) {
    if( char *buf = static_cast<char *>( malloc( buflen + 1 ) ) ) {
      memset( buf, 0x00, buflen + 1 );
      while( 1 ) {
        const int ret = httpd_req_recv( req, buf, buflen );
        if( ret <= 0 ) {
          if( ret == HTTPD_SOCK_ERR_TIMEOUT ) {
            continue;
          }
          res = ESP_FAIL;
        }
        else {
          post_data = buf;
        }
        break;
      }
      char *kv = buf;
      char *k = nullptr, *v = nullptr;
      for( int i = 0; i < buflen; i++ ) {
        if( buf[ i ] == '&' || i == buflen ) {
          buf[ i ] = '\0';
          for( int j = 0; kv && j < strnlen( kv, buflen - i ); j++ ) {
            if( kv[ j ] == '=' ) {
              kv[ j ] = '\0';
              k = kv;
              v = kv + j + 1;
              break;
            }
          }
          ESP_LOGI( LOG_TAG, "%s --> %s", k, v );
          kv = buf + i + 1;
        }
      }
      free( buf ); 
   }
  }
  if( res == ESP_OK ) {
    srv->m_ctx_config.set( srv->m_settings_file ); // <- now with updated parameters
    httpd_resp_send( req, srv->m_ctx_config.response(), HTTPD_RESP_USE_STRLEN );
  }
  return res;
}

esp_err_t http_server::test_get_handler( httpd_req_t *req ) {
  http_server *srv = static_cast<http_server *>( req->user_ctx );
  int btn_id = std::string( req->uri ) == "/test/2" ? 2 : 1;
  srv->m_event_dispatcher.dispatch(
    http_server::event_base,
    ON_HTTP_TEST_BUTTON,
    &btn_id,
    sizeof( btn_id )
  );
  httpd_resp_send( req, "OK", HTTPD_RESP_USE_STRLEN );
  return ESP_OK;
}

void http_server::set( settings_file *sf ) {
  m_settings_file = sf;
}

void http_server::init() {
  static httpd_handle_t server = NULL;
  httpd_config_t srvcfg = HTTPD_DEFAULT_CONFIG();
  srvcfg.server_port = m_config.port;
  ESP_LOGI( LOG_TAG, "Starting http server on port %d", srvcfg.server_port );
  if( httpd_start( &server, &srvcfg ) == ESP_OK ) {
    ESP_LOGI( LOG_TAG, "Registering URI handlers" );

    httpd_uri_t cfg;
    cfg.user_ctx = this;

    cfg.uri = "/";
    cfg.method = HTTP_GET;
    cfg.handler = config_get_handler,
    httpd_register_uri_handler( server, &cfg );

    cfg.uri = "/";
    cfg.method = HTTP_POST;
    cfg.handler = config_post_handler,
    httpd_register_uri_handler( server, &cfg );

    cfg.uri = "/test/1";
    cfg.method = HTTP_GET;
    cfg.handler = test_get_handler,
    httpd_register_uri_handler( server, &cfg );

    cfg.uri = "/test/2";
    cfg.method = HTTP_GET;
    cfg.handler = test_get_handler,
    httpd_register_uri_handler( server, &cfg );

  }
}

void http_server::set_event_loop_handle( esp_event_loop_handle_t event_loop_handle ) {
  m_event_dispatcher.set_event_loop_handle( event_loop_handle );
}

void http_server::add_event_listener( event_id event_id,
                                      esp_event_handler_t event_handler )
{
  m_event_dispatcher.add_event_listener( http_server::event_base,
                                         event_id,
                                         event_handler );
}
