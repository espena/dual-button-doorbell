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

#include "cron.hpp"
#include "esp_log.h"
#include "memory.h"
#include "../ccronexpr/ccronexpr.h"

using namespace espena::components;

const char *cron::LOG_TAG = "cron";

cron::cron( const cron::configuration &config ) : m_config( config ) {
  m_message_queue = xQueueCreate( 10, sizeof( cron_task_queue_item ) );
  memset( &m_cron_task_params, 0x00, sizeof m_cron_task_params );
  m_cron_task_params.instance = this;
  m_cron_task_params.task_handle = NULL;
  xTaskCreate( &cron::cron_task,
               "cron_task",
               CRON_TASK_STACK_DEPTH,
               &m_cron_task_params,
               3,
               &m_cron_task_params.task_handle );
}

cron::~cron() {

}

void cron::cron_task( void *arg ) {
  cron_task_params *params = reinterpret_cast<cron_task_params *>( arg );
  cron *inst = params->instance;
  cron_task_queue_item item;
  while( 1 ) {
    if( xQueueReceive( inst->m_message_queue, &item, portMAX_DELAY ) ) {
      inst->on_message( item.message, item.arg );
    }
  }
}

void cron::service_start() {
  ESP_LOGI( LOG_TAG, "Starting cron service" );

  /*
    cron_expr expr;
    const char* err = NULL;
    memset( &expr, 0x00, sizeof( expr ) );
    cron_parse_expr( "0 7 * * * *", &expr, &err );
    time_t cur = time( NULL );
    time_t next_time = cron_next( &expr, cur );
    tm *next = localtime( &next_time );
    char next_time_str[ 100 ];
    memset( &next_time_str, 0x00, sizeof( next_time_str ) );
    strftime( next_time_str, sizeof( next_time_str ) - 1, "%Y-%m-%d %H:%M:%S", next );
    ESP_LOGI( LOG_TAG, "Next cron time: %s", next_time_str );
  */

}

void cron::on_message( cron_task_message msg, void *arg ) {
  cron_task_queue_item *item = reinterpret_cast<cron_task_queue_item *>( arg );
  cron *instance = reinterpret_cast<cron *>( item->arg );
  switch( msg ) {
    case cron_start:
      instance->service_start();
      break;
  }
}

void cron::start() {
  cron_task_queue_item item = {
    .message = cron_start,
    .arg = this
  };
  xQueueSend( m_message_queue, &item, 1 );
}
