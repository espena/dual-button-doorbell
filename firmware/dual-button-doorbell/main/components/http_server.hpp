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

#ifndef __http_server_hpp__
#define __http_server_hpp__

#include "http_context_config.hpp"
#include "settings_file.hpp"
#include "driver/gpio.h"
#include "event/event_dispatcher.hpp"
#include <esp_http_server.h>

namespace espena::components {

  class http_server : public event::i_event_dispatcher {

    static const char *LOG_TAG;

    static ::espena::components::http_context_config m_ctx_config;

    public:

      static const esp_event_base_t event_base;

      typedef enum {
        ON_HTTP_TEST_BUTTON
      } event_id;

      typedef struct configuration_struct {
        uint16_t port;
      } configuration;

      static esp_err_t config_get_handler( httpd_req_t * );
      static esp_err_t config_post_handler( httpd_req_t * );
      static esp_err_t test_get_handler( httpd_req_t * );

    private:

      const configuration &m_config;
      ::espena::components::settings_file *m_settings_file;
      ::espena::components::event::event_dispatcher m_event_dispatcher;

    public:

      http_server( const configuration & );
      ~http_server();

      void set_event_loop_handle( esp_event_loop_handle_t );
      void add_event_listener( event_id,
                               esp_event_handler_t );
      void init();
      void set( ::espena::components::settings_file * );

  }; // class http_server

}; // namespace espena

#endif // __http_server_hpp__
