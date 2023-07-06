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

#include "settings_file.hpp"
#include <cstdio>
#include "cJSON.h"
#include "esp_log.h"

using namespace espena::components;

const char *settings_file::LOG_TAG = "settings_file";

settings_file::settings_file() :
  m_button_left_default_clip( "left.wav" ),
  m_button_right_default_clip( "right.wav" ),
  m_button_left_silent_clip( "silent.wav" ),
  m_button_right_silent_clip( "silent.wav" ),
  m_button_left_bell_count( 1 ),
  m_button_right_bell_count( 1 ),
  m_button_left_bell_delay( 200 ),
  m_button_right_bell_delay( 200 ),
  m_wifi_ssid( "guest" ),
  m_wifi_password( "secret" )
{

}

settings_file::~settings_file() {

}

void settings_file::fetch_default_clip( cJSON *button,
                                        std::string &default_clip )
{
  ESP_LOGI( LOG_TAG, "Seeking buttons->left/right->default" );
  cJSON *def = cJSON_GetObjectItem( button, "default" );
  if( def ) {
    ESP_LOGI( LOG_TAG, "Seeking buttons->left/right->default->clips" );
    cJSON *clips = cJSON_GetObjectItem( def, "clips" );
    if( clips ) {
      ESP_LOGI( LOG_TAG, "Seeking buttons->left/right->default->clips[ 0 ]" );
      const int clip_count = cJSON_GetArraySize( clips );
      if( clip_count > 0 ) {
        cJSON *clip = cJSON_GetArrayItem( clips, 0 );
        default_clip = clip->valuestring;
        ESP_LOGI( LOG_TAG, "buttons->left/right->default->clips[ 0 ] == %s", default_clip.c_str() );
      }
    }
  }
}

void settings_file::fetch_silent_clip( cJSON *button,
                                       std::string &silent_clip,
                                       std::string &silent_from,
                                       time_t &silent_duration )
{
  cJSON *silent = cJSON_GetObjectItem( button, "silent" );
  cJSON *clips = cJSON_GetObjectItem( silent, "clips" );
  if( clips ) {
    const int clip_count = cJSON_GetArraySize( clips );
    if( clip_count > 0 ) {
      cJSON *clip = cJSON_GetArrayItem( clips, 0 );
      silent_clip = clip->valuestring;
    }
  }
  cJSON *from = cJSON_GetObjectItem( silent, "from" );
  if( from ) {
    silent_from = from->valuestring;
  }
  cJSON *duration_hours = cJSON_GetObjectItem( silent, "duration_hours" );
  if( duration_hours ) {
    silent_duration = duration_hours->valueint * 3600;
  }
}

void settings_file::fetch_bell_settings( cJSON *button,
                                         int &count,
                                         int &delay )
{
  cJSON *bell = cJSON_GetObjectItem( button, "bell" );
  if( bell ) {
    cJSON *bell_count = cJSON_GetObjectItem( bell, "count" );
    if( bell_count ) {
      count = bell_count->valueint;
    }
    cJSON *bell_delay = cJSON_GetObjectItem( bell, "delay" );
    if( bell_delay ) {
      delay = bell_delay->valueint;
    }
  }
}

void settings_file::fetch_wifi_settings( cJSON *wifi,
                                         std::string &ssid,
                                         std::string &password )
{
  cJSON *wifi_ssid = cJSON_GetObjectItem( wifi, "ssid" );
  cJSON *wifi_password = cJSON_GetObjectItem( wifi, "password" );
  if( wifi_ssid && wifi_password ) {
    ssid = wifi_ssid->valuestring;
    password = wifi_password->valuestring;
  }
}

void settings_file::fetch_ntp_settings( cJSON *ntp,
                                        std::string &server,
                                        std::string &timezone )
{
  cJSON *ntp_server = cJSON_GetObjectItem( ntp, "server" );
  if( ntp_server ) {
    server = ntp_server->valuestring;
  }
  cJSON *ntp_timezone = cJSON_GetObjectItem( ntp, "timezone" );
  if( ntp_timezone ) {
    timezone = ntp_timezone->valuestring;
  }
}

void settings_file::debug_output() {
  ESP_LOGI( LOG_TAG, "m_button_left_default_clip: %s", m_button_left_default_clip.c_str() );
  ESP_LOGI( LOG_TAG, "m_button_left_silent_clip: %s", m_button_left_silent_clip.c_str() );
  ESP_LOGI( LOG_TAG, "m_button_left_silent_from: %s", m_button_left_silent_from.c_str() );
  ESP_LOGI( LOG_TAG, "m_button_left_silent_duration: %lli", m_button_left_silent_duration );
  ESP_LOGI( LOG_TAG, "m_button_right_default_clip: %s", m_button_right_default_clip.c_str() );
  ESP_LOGI( LOG_TAG, "m_button_right_silent_clip: %s", m_button_right_silent_clip.c_str() );
  ESP_LOGI( LOG_TAG, "m_button_right_silent_from: %s", m_button_right_silent_from.c_str() );
  ESP_LOGI( LOG_TAG, "m_button_right_silent_duration: %lli", m_button_right_silent_duration );
  ESP_LOGI( LOG_TAG, "m_button_left_bell_count: %d", m_button_left_bell_count );
  ESP_LOGI( LOG_TAG, "m_button_right_bell_count: %d", m_button_right_bell_count );
  ESP_LOGI( LOG_TAG, "m_button_left_bell_delay: %d", m_button_left_bell_delay );
  ESP_LOGI( LOG_TAG, "m_button_right_bell_delay: %d", m_button_right_bell_delay );
  ESP_LOGI( LOG_TAG, "m_wifi_ssid: %s", m_wifi_ssid.c_str() );
  ESP_LOGI( LOG_TAG, "m_wifi_password: %s", m_wifi_password.c_str() );
}

void settings_file::load( FILE * settings_json ) {

  ESP_LOGI( LOG_TAG, "Load settings from file" );
  fseek( settings_json, 0, SEEK_END );
  const size_t filesize = ftell( settings_json );
  fseek( settings_json, 0L, SEEK_SET );
  char *buf = new char[ filesize + 1 ];
  fread( buf, filesize, 1, settings_json );

  cJSON *root = cJSON_Parse( buf );
  cJSON *buttons = cJSON_GetObjectItem( root, "buttons" );

  if( buttons ) {

    cJSON *left = cJSON_GetObjectItem( buttons, "left" );
    if( left ) {

      fetch_default_clip( left,
                          m_button_left_default_clip );

      fetch_silent_clip( left,
                         m_button_left_silent_clip,
                         m_button_left_silent_from,
                         m_button_left_silent_duration );

      fetch_bell_settings( left,
                           m_button_left_bell_count,
                           m_button_left_bell_delay );

    }

    cJSON *right = cJSON_GetObjectItem( buttons, "right" );
    if( right ) {

      fetch_default_clip( right,
                          m_button_right_default_clip );

      fetch_silent_clip( right,
                         m_button_right_silent_clip,
                         m_button_right_silent_from,
                         m_button_right_silent_duration );

      fetch_bell_settings( right,
                           m_button_right_bell_count,
                           m_button_right_bell_delay );
    }
  }

  cJSON *wifi = cJSON_GetObjectItem( root, "wifi" );
  if( wifi ) {
    fetch_wifi_settings( wifi,
                        m_wifi_ssid,
                        m_wifi_password );
  }

  cJSON *ntp = cJSON_GetObjectItem( root, "ntp" );
  if( ntp ) {
    fetch_ntp_settings( ntp,
                        m_ntp_server,
                        m_ntp_timezone );
  }

  cJSON_Delete( root );
  delete [ ] buf;

  debug_output();

}
