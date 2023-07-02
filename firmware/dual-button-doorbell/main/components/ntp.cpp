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

#include "ntp.hpp"
#include "esp_netif_sntp.h"
#include "esp_event.h"
#include "esp_log.h"

using namespace espena::components;

const char *ntp::LOG_TAG = "ntp";
const esp_event_base_t ntp::event_base = "NTP_EVENT";

ntp::ntp( const ntp::configuration &config ) :
  m_config( config ),
  m_time_updated( false )
{
  ESP_LOGI( LOG_TAG, "Server is %s", m_config.server.c_str() );
  ESP_LOGI( LOG_TAG, "Timezone is %s", m_config.timezone.c_str() );
  m_message_queue = xQueueCreate( 10, sizeof( ntp_task_queue_item ) );
  m_ntp_task_params.instance = this;
  m_ntp_task_params.task_handle = NULL;
  xTaskCreate( &ntp::ntp_task,
               "ntp_task",
               NTP_TASK_STACK_DEPTH,
               &m_ntp_task_params,
               2,
               &m_ntp_task_params.task_handle );
}

ntp::~ntp() {

}

void ntp::ntp_task( void *arg ) {
  ntp_task_params *params = reinterpret_cast<ntp_task_params *>( arg );
  ntp *inst = params->instance;
  ntp_task_queue_item item;
  while( 1 ) {
    if( xQueueReceive( inst->m_message_queue, &item, portMAX_DELAY ) ) {
      inst->on_message( item.message, item.arg );
    }
  }
}

void ntp::on_message( ntp_task_message msg, void *arg ) {
  switch( msg ) {
    case ntp_update:
      time_update();
      break;
  }
}

void ntp::initialize( const std::string server,
                      const std::string timezone )
{
  m_config.server = server;
  m_config.timezone = timezone;
}

void ntp::time_update_async() {
  ntp_task_queue_item item = {
    .message = ntp_update,
    .arg = this
  };
  xQueueSend( m_message_queue, &item, 1 );
}

void ntp::time_update() {
  esp_sntp_config_t sntp_config = ESP_NETIF_SNTP_DEFAULT_CONFIG( m_config.server.c_str() );
  esp_netif_sntp_init( &sntp_config );
  if( esp_netif_sntp_sync_wait( pdMS_TO_TICKS( 20000 ) ) != ESP_OK ) {
    ESP_LOGW( LOG_TAG, "Failed to update system time within 20s timeout" );
  }
  else {
    m_time_updated = true;
    ESP_LOGI( LOG_TAG, "System time successfully updated!" );
  }

}
