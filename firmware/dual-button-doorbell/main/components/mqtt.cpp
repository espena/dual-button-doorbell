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

#include "mqtt.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_event.h"
#include "mqtt_client.h"

using namespace espena::components;

const char *mqtt::LOG_TAG = "mqtt";

mqtt::mqtt( const configuration &config ) : m_config( config ) {

  ESP_LOGI( LOG_TAG, "Initializing" );
  m_message_queue = xQueueCreate( 10, sizeof( mqtt_task_queue_item ) );
  m_mqtt_task_params.instance = this;
  m_mqtt_task_params.task_handle = NULL;
  xTaskCreate( &mqtt::mqtt_task,
              "mqtt_task",
              MQTT_TASK_STACK_DEPTH,
              &m_mqtt_task_params,
              2,
              &m_mqtt_task_params.task_handle );
}

mqtt::~mqtt() {

}

void mqtt::mqtt_task( void *arg ) {
  mqtt_task_params *params = static_cast<mqtt_task_params *>( arg );
  mqtt *inst = params->instance;
  mqtt_task_queue_item item;
  ESP_LOGI( LOG_TAG, "Entering task loop" );
  while( 1 ) {
    if( xQueueReceive( inst->m_message_queue, &item, portMAX_DELAY ) ) {
      inst->on_message( item.message, item.arg );
    }
  }
}

void mqtt::event_handler( void *arg,
                          esp_event_base_t event_base,
                          int32_t event_id,
                          void *event_data )
{
  mqtt *instance = static_cast<mqtt *>( arg );
  instance->on_mqtt_event( static_cast<esp_mqtt_event_id_t>( event_id ),
                           static_cast<esp_mqtt_event_handle_t>( event_data ) );
}

void mqtt::on_mqtt_event( esp_mqtt_event_id_t event_id,
                          esp_mqtt_event_handle_t event )
{
  
}

void mqtt::on_message( mqtt_task_message msg, void *arg ) {
  switch( msg ) {
    case notification:
      // Todo: Write handler
      break;
  }
}
