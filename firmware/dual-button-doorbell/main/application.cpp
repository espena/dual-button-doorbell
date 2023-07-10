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
#include "components/i_file_io.hpp"

#include <string>
#include "esp_log.h"
#include "esp_task_wdt.h"
#include "esp_event.h"

#include "memory.h"
#include "time.h"
#include "esp_netif_sntp.h"

using namespace espena;

const char *application::LOG_TAG = "application";
application * application::m_the_app = NULL;

application::application( const configuration &conf ) :
  m_config( conf ),
  m_led_green( conf.led_green ),
  m_led_red( conf.led_red ),
  m_relay( conf.relay ),
  m_sound( conf.sound ),
  m_sdcard( conf.sdcard ),
  m_rtc( conf.rtc ),
  m_ntp( conf.ntp ),
  m_button_left( conf.button_left ),
  m_button_right( conf.button_right ),
  m_led_button_left( conf.led_button_left ),
  m_led_button_right( conf.led_button_right ),
  m_cron( conf.cron )
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
  m_wifi.set_event_loop_handle( m_event_loop_handle );
  m_ntp.set_event_loop_handle( m_event_loop_handle );
  m_cron.set_event_loop_handle( m_event_loop_handle );
}

application::~application() {
  esp_event_loop_delete( m_event_loop_handle );
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

void application::play_sound( const std::string wav_file ) {
  ESP_LOGI( LOG_TAG, "Playing file %s", wav_file.c_str() );
  FILE *fp = m_sdcard.open_file( wav_file, "rb" );
  m_sound.play_async( fp );
}

void application::stop_sound() {
  m_sound.stop_async();
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
    application::m_the_app->event_handler_sound( event_id, *( reinterpret_cast<FILE **>( event_params ) ) );
  }
  if( source == ( char * ) components::button::event_base ) {
    application::m_the_app->event_handler_button( event_id, *( reinterpret_cast< int * >( event_params ) ) );
  }
  if( source == ( char * ) components::wifi::event_base ) {
    application::m_the_app->event_handler_wifi( event_id, event_params );
  }
  if( source == ( char * ) components::ntp::event_base ) {
    application::m_the_app->event_handler_ntp( event_id, event_params );
  }
  if( source == ( char * ) components::cron::event_base ) {
    application::m_the_app->event_handler_cron( event_id, reinterpret_cast<char *>( event_params ) );
  }
}

void application::event_handler_sdcard( int32_t event_id, void *event_params ) {
  switch( event_id ) {
    case components::sdcard::ON_MOUNT_OK:
      // SD card mounted successfully
      m_led_green.blink( 1000, 1 );
      load_settings();
      m_ntp.initialize( m_settings_file.m_ntp_server,
                        m_settings_file.m_ntp_timezone );
      wifi_connect();
      break;
    case components::sdcard::ON_MOUNT_FAILED:
      // SD card did not mount
      m_led_red.blink( 50 );
      break;
  }
}

void application::event_handler_sound( int32_t event_id, FILE *fp ) {
  switch( event_id ) {
    case components::sound::ON_PLAY_END:
      ESP_LOGI( LOG_TAG, "Playback ended" );
      ESP_LOGI( LOG_TAG, "File descriptor: %lu", ( long unsigned int ) fp );
      m_sdcard.close_file( fp );
      m_led_red.off();
      release_buttons();
      break;
  }
}

void application::event_handler_wifi( int32_t event_id, void *event_params ) {
  switch( event_id ) {
    case components::wifi::ON_WIFI_CONNECTED:
      ESP_LOGI( LOG_TAG, "Wifi connected!" );
      m_ntp.time_update_async();
      break;
  }
}

void application::event_handler_ntp( int32_t event_id, void *event_params ) {
  switch( event_id ) {
    case components::ntp::ON_NTP_TIME_UPDATED:
      ESP_LOGI( LOG_TAG, "NTP updated system time" );
      m_rtc.sync_from_systime(); // Sync RTC with fresh NTP time
      m_rtc.print_time(); // Show off!
      m_cron.start( &m_sdcard ); // Launch time schedule
      break;
  }
}

void application::event_handler_cron( int32_t event_id, const char *wav_file ) {
  switch( event_id ) {
    case components::cron::ON_TIMED_EVENT:
      play_sound( wav_file );
      break;
  }
}

void application::event_handler_button( int32_t event_id, int btn_id ) {
  switch( event_id ) {
    case components::button::ON_BTN_DOWN:
      block_buttons();
      stop_sound(); // Give priority to doorbell buttons
      m_led_red.on();
      time_t silent_time = 0;
      switch( btn_id ) {
        case 1: // left button
          silent_time = m_cron.get_prev( m_settings_file.m_button_left_silent_from.data() );
          if( ( silent_time + m_settings_file.m_button_left_silent_duration ) > time( NULL ) ) {
            ESP_LOGI( LOG_TAG, "Silent mode" );
            play_sound( m_settings_file.m_button_left_silent_clip );
          }
          else {
            ding_dong( m_settings_file.m_button_left_bell_count,
                      m_settings_file.m_button_left_bell_delay );
            play_sound( m_settings_file.m_button_left_default_clip );
          }
          break;
        case 2: // right button
          silent_time = m_cron.get_prev( m_settings_file.m_button_right_silent_from.data() );
          if( ( silent_time + m_settings_file.m_button_right_silent_duration ) > time( NULL ) ) {
            ESP_LOGI( LOG_TAG, "Silent mode" );
            play_sound( m_settings_file.m_button_right_silent_clip );
          }
          else {
            ding_dong( m_settings_file.m_button_right_bell_count,
                      m_settings_file.m_button_right_bell_delay );
            play_sound( m_settings_file.m_button_right_default_clip );
          }
          break;
        default:
          m_led_green.blink( 1000, 1 );
          m_led_red.blink( 1000, 1 );
      }
      break;
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

void application::add_event_listeners() {
  m_sdcard.add_event_listener( components::sdcard::ON_MOUNT_OK, event_handler );
  m_sdcard.add_event_listener( components::sdcard::ON_MOUNT_FAILED, event_handler );
  m_sound.add_event_listener( components::sound::ON_PLAY_START, event_handler );
  m_sound.add_event_listener( components::sound::ON_PLAY_END, event_handler );
  m_button_left.add_event_listener( components::button::ON_BTN_DOWN, event_handler );
  m_button_right.add_event_listener( components::button::ON_BTN_DOWN, event_handler );
  m_wifi.add_event_listener( components::wifi::ON_WIFI_CONNECTED, event_handler );
  m_ntp.add_event_listener( components::ntp::ON_NTP_TIME_UPDATED, event_handler );
  m_cron.add_event_listener( components::cron::ON_TIMED_EVENT, event_handler );
}

void application::run() {
  add_event_listeners();
  m_sdcard.mount();
  time_t t0 = 0;
  while( 1 ) {
    vTaskDelay( 1 );
    const time_t t1 = time( NULL );
    if( t0 == 0 || t1 - t0 > 300 ) {
      // Kick systime back in place every fifth minute
      m_rtc.sync_to_systime();
      t0 = t1;
    }
  }
}
