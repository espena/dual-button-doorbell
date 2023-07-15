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
#include "i_file_io.hpp"

namespace espena::components {

  class mqtt {

      static const char *LOG_TAG;
      static const configSTACK_DEPTH_TYPE MQTT_TASK_STACK_DEPTH = 8192;

      typedef enum {
        start_service,
        push_notify
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
      esp_mqtt_client_config_t m_mqtt_cfg;

    public:

      typedef struct configuration_struct {
        std::string server;
        std::string cert_file;
        std::string topic;
      } configuration;

    private:

      const configuration &m_config;
      unsigned char *m_cert;
      size_t m_cert_len;

      i_file_io *m_filesys;

      char m_client_id[ 13 ];
      std::string m_server;
      std::string m_cert_file;
      std::string m_topic;

      esp_mqtt_client_handle_t m_client;

      void on_message( mqtt_task_message, void * );

      static void event_handler( void *, esp_event_base_t, int32_t, void * );
      static void mqtt_task( void * );

      void on_mqtt_event( esp_mqtt_event_id_t, esp_mqtt_event_handle_t );

      void get_client_id(); // Load MAC address into m_client_id
      void get_cert(); // Load TLS CA certificate into m_cert

      void start();
      void push( char *data );

    public:

      mqtt( const configuration & );
      ~mqtt();

      void init( const std::string, const std::string, const std::string );

      void start_async( espena::components::i_file_io * );
      void push_async( char *data );

  }; // class mqtt

}; // namespace espena::components

#endif // __mqtt_hpp__
