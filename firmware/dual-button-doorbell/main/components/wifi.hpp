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

#ifndef __wifi_hpp__
#define __wifi_hpp__

#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_event.h"
#include "event/event_dispatcher.hpp"

namespace espena::components {

  class wifi : public event::i_event_dispatcher {

    public:

      static const esp_event_base_t event_base;

      typedef enum {
        ON_WIFI_CONNECTED
      } event_id;

    private:

      static const configSTACK_DEPTH_TYPE WIFI_TASK_STACK_DEPTH = 32768;
      
      typedef struct wifi_task_params_struct {
        wifi *instance;
        TaskHandle_t task_handle;
      } wifi_task_params;

      typedef enum {
        wifi_connect
      } wifi_task_message;

      typedef struct wifi_task_queue_item_struct {
        wifi_task_message message;
        void *arg;
      } wifi_task_queue_item;

      static EventGroupHandle_t m_wifi_event_group;
      QueueHandle_t m_message_queue;

      void on_message( wifi_task_message, void * );

      wifi_task_params m_wifi_task_params;
      std::string m_ssid;
      std::string m_password;
      ::espena::components::event::event_dispatcher m_event_dispatcher;

      static void event_handler( void *, esp_event_base_t, int32_t, void * );
      static void wifi_task( void * );

      void connect( void );

    public:

      wifi();
      ~wifi();

      void connect( std::string, std::string );
      void set_event_loop_handle( esp_event_loop_handle_t );
      void add_event_listener( event_id,
                               esp_event_handler_t );


  }; // class wifi

}; // namespace espena::components

#endif // __wifi_hpp__