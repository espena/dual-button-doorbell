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

#ifndef __mqtt_hpp__
#define __mqtt_hpp__

#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "esp_event.h"
#include "mqtt_client.h"

namespace espena::components {

  class mqtt {

      static const char *LOG_TAG;
      static const configSTACK_DEPTH_TYPE MQTT_TASK_STACK_DEPTH = 32768;

      typedef enum {
        notification
      } mqtt_task_message;

      typedef struct mqtt_task_queue_item_struct {
        mqtt_task_message message;
        void *arg;
      } mqtt_task_queue_item;

      typedef struct mqtt_task_params_struct {
        mqtt *instance;
        TaskHandle_t task_handle;
      } mqtt_task_params;

      QueueHandle_t m_message_queue;
      mqtt_task_params m_mqtt_task_params;

    public:

      typedef struct configuration_struct {

      } configuration;

    private:

      configuration m_config;

      void on_message( mqtt_task_message, void * );

      static void event_handler( void *, esp_event_base_t, int32_t, void * );
      static void mqtt_task( void * );

      void on_mqtt_event( esp_mqtt_event_id_t, esp_mqtt_event_handle_t );

    public:

      mqtt( const configuration & );
      ~mqtt();

  }; // class mqtt

}; // namespace espena::components

#endif // __mqtt_hpp__
