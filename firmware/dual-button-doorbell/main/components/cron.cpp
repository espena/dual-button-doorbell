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
#include <string>
#include "esp_log.h"
#include "memory.h"
#include "../ccronexpr/ccronexpr.h"
#include "sdcard.hpp"
#include "i_file_io.hpp"

using namespace espena::components;

const char *cron::LOG_TAG = "cron";
const esp_event_base_t cron::event_base = "CRON_EVENT";

cron::cron( const cron::configuration &config ) :
  m_config( config ),
  m_filesys( NULL )
{
  m_message_queue = xQueueCreate( 10, sizeof( cron_task_queue_item ) );
  memset( &m_cron_task_params, 0x00, sizeof( m_cron_task_params ) );
  init_cron_entries();
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

void cron::init_cron_entries() {
  memset( &m_cron_entries, 0x00, sizeof( m_cron_entries ) );
  m_cron_entries_count = 0;
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

void cron::on_message( cron_task_message msg, void *arg ) {
  switch( msg ) {
    case cron_start:
      service_start();
      break;
  }
}

void cron::parse_cron_line( char *ln ) {
  if( m_cron_entries_count == MAX_CRON_ENTRIES ) {
    ESP_LOGW( LOG_TAG, "Crontab file exceeds maximum of %d valid lines", MAX_CRON_ENTRIES );
    return;
  }
  // trim
  if( char *cr = strrchr( ln, '\r' ) ) *cr = '\0';
  if( char *lf = strrchr( ln, '\n' ) ) *lf = '\0';
  // split token from file name
  char *token_end = strrchr( ln, ' ' );
  char *wav_file = NULL;
  if( token_end ) {
    *token_end = '\0';
    wav_file = token_end + 1;
    while( token_end > ln && *( token_end - 1 ) == ' ' ) {
      *( token_end-- ) = '\0';
    }
  }
  // parse cron token
  cron_entry &entry = m_cron_entries[ m_cron_entries_count ];
  cron_expr &expr = entry.expression;
  const char* err = NULL;
  cron_parse_expr( ln, &expr, &err );
  if( !err ) {
    ESP_LOGI( LOG_TAG, "Input: %s -> %s", ln, wav_file );
    strncpy( entry.wav_file, wav_file, sizeof( entry.wav_file ) );
    entry.next_run = cron_next( &expr, time( NULL ) );
    m_cron_entries_count++;
  }
  else {
    if( ln[ 0 ] != '#' ) {
      ESP_LOGW( LOG_TAG, "Invalid cron token: %s (%s)", ln, err );
    }
  }
}

void cron::print_time( time_t time ) {
  tm *time_tm = localtime( &time );
  char time_str[ 100 ];
  memset( &time_str, 0x00, sizeof( time_str ) );
  strftime( time_str, sizeof( time_str ) - 1, "%Y-%m-%d %H:%M:%S", time_tm );
  ESP_LOGI( LOG_TAG, "Time: %s", time_str );
}

void cron::loop() {
  ESP_LOGI( LOG_TAG, "Entering loop" );
  while( 1 ) {
    time_t now = time( NULL );
    for( int i = 0; i < m_cron_entries_count; i++ ) {
      cron_entry &e = m_cron_entries[ i ];
      if( now >= e.next_run ) {
        time_t next = cron_next( &e.expression, now );
        ESP_LOGI( LOG_TAG, "Scheduled playback of %s", e.wav_file );
        e.next_run = next;
        m_event_dispatcher.dispatch(
          cron::event_base,
          ON_TIMED_EVENT,
          ( void * ) &e.wav_file,
          sizeof( e.wav_file ) );
      }
    }
    vTaskDelay( 250 / portTICK_PERIOD_MS );
  }
}

void cron::service_start() {

  ESP_LOGI( LOG_TAG, "Starting cron service..." );
  init_cron_entries();
  if( m_filesys ) {
    FILE *fp = m_filesys->open_file( m_config.crontab_file, "r" );
    if( fp ) {
      char ln[ 2048 ];
      while( fgets( ln, sizeof( ln ), fp ) ) {
        parse_cron_line( ln );
      }
      m_filesys->close_file( fp );
      if( m_cron_entries_count > 0 ) {
        loop();
      }
    }
    else {
      ESP_LOGW( LOG_TAG, "Crontab file %s not found", m_config.crontab_file.c_str() );
    }
  }
  else {
    ESP_LOGW( LOG_TAG, "No file system" );
  }
}

void cron::set_event_loop_handle( esp_event_loop_handle_t event_loop_handle ) {
  m_event_dispatcher.set_event_loop_handle( event_loop_handle );
}

void cron::add_event_listener( cron::event_id event_id,
                               esp_event_handler_t event_handler )
{
  m_event_dispatcher.add_event_listener( cron::event_base,
                                         event_id,
                                         event_handler );
}

void cron::start( i_file_io *filesys ) {
  m_filesys = filesys;
  cron_task_queue_item item = {
    .message = cron_start,
    .arg = this
  };
  xQueueSend( m_message_queue, &item, 1 );
}
