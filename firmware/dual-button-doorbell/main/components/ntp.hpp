/*
 *  This file is part of the dual-button doorbell project.
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

#ifndef __ntp_hpp__
#define __ntp_hpp__

#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "esp_event.h"
#include "event/i_event_dispatcher.hpp"
#include "event/event_dispatcher.hpp"

namespace espena::components {

  class ntp : public event::i_event_dispatcher {

    static const char *LOG_TAG;
    static const configSTACK_DEPTH_TYPE NTP_TASK_STACK_DEPTH = 2048;

    public:

      static const esp_event_base_t event_base;

      typedef enum {
        ON_NTP_TIME_UPDATED
      } event_id;

      typedef struct configuration_struct {
        std::string server;
        std::string timezone;
      } configuration;

    private:

      configuration m_config;
      bool m_time_updated;

      typedef struct ntp_task_params_struct {
        ntp *instance;
        TaskHandle_t task_handle;
      } ntp_task_params;

      typedef enum {
        ntp_update
      } ntp_task_message;

      typedef struct ntp_task_queue_item_struct {
        ntp_task_message message;
        void *arg;
      } ntp_task_queue_item;

      QueueHandle_t m_message_queue;

      void on_message( ntp_task_message, void * );

      ntp_task_params m_ntp_task_params;

      ::espena::components::event::event_dispatcher m_event_dispatcher;

      static void ntp_task( void * );

    public:

      ntp( const configuration & );
      ~ntp();
  
      void initialize( const std::string, const std::string );

      void time_update();
      void time_update_async();

      bool is_time_updated() { return m_time_updated; }

      void set_event_loop_handle( esp_event_loop_handle_t );
      void add_event_listener( event_id,
                               esp_event_handler_t );

  }; // class ntp

}; // namespace espena::components

#endif // __ntp_hpp__