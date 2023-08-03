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
#include "esp_log.h"
#include <esp_http_server.h>

using namespace espena::components;

const char *http_server::LOG_TAG = "http_server";

char http_server::CTX_CONFIG[] = "";
const httpd_uri_t http_server::URI_CONFIG = {
  .uri       = "/hello",
  .method    = HTTP_GET,
  .handler   = hello_get_handler,
  .user_ctx  = CTX_CONFIG
};

http_server::http_server( const configuration &config ) :
  m_config( config )
{
  
}

http_server::~http_server() {

}

esp_err_t http_server::hello_get_handler( httpd_req_t *req ) {
  ESP_LOGI( LOG_TAG, "Get handler for config was called!" );
  const char* resp_str = "Dual-button doorbell CONFIGURATION";
  httpd_resp_send( req, resp_str, HTTPD_RESP_USE_STRLEN );
  return ESP_OK;
}

void http_server::init() {
  static httpd_handle_t server = NULL;
  httpd_config_t srvcfg = HTTPD_DEFAULT_CONFIG();
  srvcfg.server_port = m_config.port;
  ESP_LOGI( LOG_TAG, "Starting http server on port %d", srvcfg.server_port );
  if( httpd_start( &server, &srvcfg ) == ESP_OK ) {
    ESP_LOGI( LOG_TAG, "Registering URI handlers" );
    httpd_register_uri_handler( server, &URI_CONFIG );
  }

}