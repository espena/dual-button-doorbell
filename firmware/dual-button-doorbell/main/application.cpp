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
#include <string>
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
  m_rtc( conf.rtc ),
  m_button_left( conf.button_left ),
  m_button_right( conf.button_right ),
  m_led_button_left( conf.led_button_left ),
  m_led_button_right( conf.led_button_right )
{
  application::m_the_app = this;
  esp_event_loop_args_t loop_args = {
    .queue_size = 1000,
    .task_name = "loop_task",
    .task_priority = uxTaskPriorityGet( NULL ),
    .task_stack_size = 8192,
    .task_core_id = tskNO_AFFINITY
  };
  esp_event_loop_create( &loop_args, &m_event_loop_handle );
  m_sound.set_event_loop_handle( m_event_loop_handle );
  m_sdcard.set_event_loop_handle( m_event_loop_handle );
  m_button_left.set_event_loop_handle( m_event_loop_handle );
  m_button_right.set_event_loop_handle( m_event_loop_handle );
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
  if( source == ( char * ) components::button::event_base ) {
    application::m_the_app->event_handler_button( event_id, *( reinterpret_cast< int * >( event_params ) ) );
  }
}

void application::load_settings() {
  FILE *settings_file = m_sdcard.open_file( "setting.jsn", "rb" );
  if( settings_file ) {
    m_settings_file.load( settings_file );
    m_sdcard.close_file( settings_file );
  }
}

void application::wifi_connect() {
  m_wifi.connect( m_settings_file.m_wifi_ssid,
                  m_settings_file.m_wifi_password );
}

void application::event_handler_sdcard( int32_t event_id, void *event_params ) {
  switch( event_id ) {
    case components::sdcard::ON_MOUNT_OK:
      // SD card mounted successfully
      m_led_green.blink( 1000, 1 );
      load_settings();
      wifi_connect();
      break;
    case components::sdcard::ON_MOUNT_FAILED:
      // SD card did not mount
      m_led_red.blink( 50 );
      break;
    default:
      ;
  }
}

void application::block_buttons() {
  m_button_left.is_pressed() ? m_led_button_left.blink() : m_led_button_left.on();
  m_button_right.is_pressed() ? m_led_button_right.blink() : m_led_button_right.on();
  m_button_left.intr_disable();
  m_button_right.intr_disable();
}

void application::release_buttons() {
  m_led_button_left.stop();
  m_led_button_right.stop();
  m_button_left.intr_enable();
  m_button_right.intr_enable();
}

void application::event_handler_sound( int32_t event_id, void *event_params ) {
  switch( event_id ) {
    case components::sound::ON_PLAY_END:
      ESP_LOGI( "APPLICATION", "Lydavspilling avsluttet" );
      m_led_red.off();
      release_buttons();
      break;
    default:
      ;
  }
}

void application::ding_dong( const int count, const int speed_ms ) {
  for( int i = 0; i < count; i++ ) {
    m_relay.on();
    vTaskDelay( speed_ms / portTICK_PERIOD_MS );
    m_relay.off();
    if( i < count - 1 ) {
      vTaskDelay( speed_ms / portTICK_PERIOD_MS );
    }
  }
}

void application::event_handler_button( int32_t event_id, int btn_id ) {
  switch( event_id ) {
    case components::button::ON_BTN_DOWN:
      block_buttons();
      m_led_red.on();
      switch( btn_id ) {
        case 1: // left button
          ding_dong( m_settings_file.m_button_left_bell_count,
                     m_settings_file.m_button_left_bell_delay );
          m_sound.play( m_sdcard.open_file( m_settings_file.m_button_left_default_clip, "rb" ) );
          break;
        case 2: // right button
          ding_dong( m_settings_file.m_button_right_bell_count,
                     m_settings_file.m_button_right_bell_delay );
          m_sound.play( m_sdcard.open_file( m_settings_file.m_button_right_default_clip, "rb" ) );
          break;
        default:
          m_led_green.blink( 1000, 1 );
          m_led_red.blink( 1000, 1 );
      }
      break;
    default:
      ;
  }
}

void application::add_event_listeners() {
  m_sdcard.add_event_listener( components::sdcard::ON_MOUNT_OK, event_handler );
  m_sdcard.add_event_listener( components::sdcard::ON_MOUNT_FAILED, event_handler );
  m_sound.add_event_listener( components::sound::ON_PLAY_START, event_handler );
  m_sound.add_event_listener( components::sound::ON_PLAY_END, event_handler );
  m_button_left.add_event_listener( components::button::ON_BTN_DOWN, event_handler );
  m_button_right.add_event_listener( components::button::ON_BTN_DOWN, event_handler );
}

void application::run() {
  add_event_listeners();
  m_sdcard.mount();
  while( 1 ) {
    vTaskDelay( 1 );
  }
}
