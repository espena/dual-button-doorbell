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

#include "application.hpp"
#include "string.h"
#include "esp_log.h"
#include "esp_task_wdt.h"
#include "esp_event.h"

using namespace espena;

application * application::m_the_app = NULL;

application::application( const configuration &conf ) : 
  m_config( conf ),
  m_led_green( conf.led_green ),
  m_led_red( conf.led_red ),
  m_relay( conf.relay ),
  m_sound( conf.sound ),
  m_sdcard( conf.sdcard ),
  m_button_left( conf.button_left ),
  m_button_right( conf.button_right )
{
  application::m_the_app = this;
  esp_event_loop_args_t loop_args = {
    .queue_size = 5,
    .task_name = "loop_task",
    .task_priority = uxTaskPriorityGet( NULL ),
    .task_stack_size = 3072,
    .task_core_id = tskNO_AFFINITY
  };
  esp_event_loop_create( &loop_args, &m_event_loop_handle );
  m_sound.set_event_loop_handle( m_event_loop_handle );
  m_sdcard.set_event_loop_handle( m_event_loop_handle );
}

application::~application() {
  esp_event_loop_delete( m_event_loop_handle );
}

void application::event_handler( void *handler_arg,
                                 esp_event_base_t event_base,
                                 int32_t event_id,
                                 void *event_params )
{
  const std::string source = ( char * ) event_base;
  if( source == ( char * ) components::sdcard::event_base ) {
    application::m_the_app->event_handler_sdcard( event_id, event_params );
  }
  if( source == ( char * ) components::sound::event_base ) {
    application::m_the_app->event_handler_sound( event_id, event_params );
  }
}

void application::event_handler_sdcard( int32_t event_id, void *event_params ) {
  switch( event_id ) {
    case components::sdcard::ON_MOUNT_OK:
      // SD card mounted successfully
      m_led_green.blink();
      break;
    case components::sdcard::ON_MOUNT_FAILED:
      // SD card did not mount
      m_led_red.blink( 50 );
      break;
    default:
      ;
  }
}

void application::event_handler_sound( int32_t event_id, void *event_params ) {
  switch( event_id ) {
    case components::sound::ON_PLAY_START:
      m_led_red.blink( 100 );
      break;
    case components::sound::ON_PLAY_END:
      m_led_red.stop();
      break;
    default:
      ;
  }
}

void application::add_event_listeners() {
  m_sdcard.add_event_listener( components::sdcard::ON_MOUNT_OK, event_handler, NULL );
  m_sdcard.add_event_listener( components::sdcard::ON_MOUNT_FAILED, event_handler, NULL );
  m_sound.add_event_listener( components::sound::ON_PLAY_START, event_handler, NULL );
  m_sound.add_event_listener( components::sound::ON_PLAY_END, event_handler, NULL );
}

void application::run() {
  add_event_listeners();
  m_sdcard.mount();
  m_sound.play( m_sdcard.open_file( "ousse.wav", "rb" ) );  
  while( 1 ) {
    ;    
  }
}
