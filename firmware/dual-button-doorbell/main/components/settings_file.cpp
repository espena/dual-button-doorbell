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
#include <string>
#include <vector>
#include <cstdio>
#include "cJSON.h"
#include "esp_log.h"

using namespace espena::components;

const char *settings_file::LOG_TAG = "settings_file";

settings_file::settings_file() :
  m_root( nullptr ),
  m_button_default_clip{ "left.wav", "right.wav" },
  m_button_silent_clip{ "silent.wav", "silent.wav" },
  m_button_silent_enable{ 0, 0 },
  m_button_bell_count{ 1, 1 },
  m_button_bell_delay{ 200, 200 },
  m_wifi_ssid( "guest" ),
  m_wifi_password( "secret" ),
  m_mqtt_enable( 1 ),
  m_logger_max_file_size_mb( 0 )
{

}

settings_file::~settings_file() {
  if( m_root ) {
    cJSON_Delete( m_root );
  }
}

void settings_file::fetch_button_properties( cJSON *button,
                                             std::string &label )
{
  cJSON *button_label = cJSON_GetObjectItem( button, "label" );
  if( button_label ) {
    label = button_label->valuestring;
  }
}

void settings_file::fetch_default_clip( cJSON *button,
                                        std::string &default_clip )
{
  cJSON *def = cJSON_GetObjectItem( button, "default" );
  if( def ) {
    cJSON *clips = cJSON_GetObjectItem( def, "clips" );
    if( clips ) {
      const int clip_count = cJSON_GetArraySize( clips );
      if( clip_count > 0 ) {
        cJSON *clip = cJSON_GetArrayItem( clips, 0 );
        default_clip = clip->valuestring;
      }
    }
  }
}

void settings_file::fetch_silent_clip( cJSON *button,
                                       int &silent_enable,
                                       std::string &silent_clip,
                                       std::string &silent_from,
                                       time_t &silent_duration )
{
  cJSON *silent = cJSON_GetObjectItem( button, "silent" );
  cJSON *enable = cJSON_GetObjectItem( silent, "enable" );
  if( enable ) {
    silent_enable = enable->valueint;
  }
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

void settings_file::fetch_clip_overrides( cJSON *button,
                                          std::vector<clip_override> &clip_overrides )
{
  cJSON *overrides = cJSON_GetObjectItem( button, "override" );
  if( overrides ) {
    const int override_count = cJSON_GetArraySize( overrides );
    for( int i = 0; i < override_count; i++ ) {
      cJSON *ovrd = cJSON_GetArrayItem( overrides, i );
      cJSON *f = nullptr;
      clip_override new_item;
      new_item.name = ( f = cJSON_GetObjectItem( ovrd, "name" ) ) ? f->valuestring : "";
      new_item.enable = ( f = cJSON_GetObjectItem( ovrd, "enable" ) ) ? f->valueint : 0;
      new_item.from = ( f = cJSON_GetObjectItem( ovrd, "from" ) ) ? f->valuestring : "";
      new_item.duration = 0;
      new_item.duration += ( f = cJSON_GetObjectItem( ovrd, "duration_hours" ) ) ? f->valueint * 60 * 60 : 0;
      new_item.duration += ( f = cJSON_GetObjectItem( ovrd, "duration_minutes" ) ) ? f->valueint * 60 : 0;
      new_item.clip = ( f = cJSON_GetObjectItem( ovrd, "clip" ) ) ? f->valuestring : "";
      clip_overrides.push_back( new_item );
    }
  }
}

void settings_file::fetch_bell_settings( cJSON *button,
                                         int &count,
                                         int &delay )
{
  cJSON *def = cJSON_GetObjectItem( button, "default" );
  if( def ) {
    cJSON *bell = cJSON_GetObjectItem( def, "bell" );
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

void settings_file::fetch_ntp_settings( cJSON *datetime,
                                        std::string &server,
                                        std::string &timezone )
{
  cJSON *ntp = cJSON_GetObjectItem( datetime, "ntp" );
  if( ntp ) {
    cJSON *ntp_server = cJSON_GetObjectItem( ntp, "server" );
    server = ntp_server->valuestring;
  }
  cJSON *ntp_timezone = cJSON_GetObjectItem( datetime, "timezone" );
  if( ntp_timezone ) {
    timezone = ntp_timezone->valuestring;
  }
}

void settings_file::fetch_mqtt_settings( cJSON *mqtt,
                                         int &enable,
                                         std::string &server,
                                         std::string &cert_file,
                                         std::string &topic )
{
  cJSON *mqtt_enable = cJSON_GetObjectItem( mqtt, "enable" );
  if( mqtt_enable ) {
    enable = mqtt_enable->valueint;
  }
  cJSON *mqtt_server = cJSON_GetObjectItem( mqtt, "server" );
  if( mqtt_server ) {
    server = mqtt_server->valuestring;
  }
  cJSON *mqtt_cert_file = cJSON_GetObjectItem( mqtt, "cert_file" );
  if( mqtt_cert_file ) {
    cert_file = mqtt_cert_file->valuestring;
  }
  cJSON *mqtt_topic = cJSON_GetObjectItem( mqtt, "topic" );
  if( mqtt_topic ) {
    topic = mqtt_topic->valuestring;
  }
}

void settings_file::fetch_logger_settings( cJSON *logger,
                                         size_t &max_file_size_mb )
{
  cJSON *logger_max_file_size_mb = cJSON_GetObjectItem( logger, "max_file_size_mb" );
  if( logger_max_file_size_mb ) {
    max_file_size_mb = logger_max_file_size_mb->valueint; // Overwrite default from config
  }
}

void settings_file::debug_output() {

  ESP_LOGI( LOG_TAG, "m_button_default_clip[ 0 ]: %s", m_button_default_clip[ 0 ].c_str() );
  ESP_LOGI( LOG_TAG, "m_button_silent_clip[ 0 ]: %s", m_button_silent_clip[ 0 ].c_str() );
  ESP_LOGI( LOG_TAG, "m_button_silent_from[ 0 ]: %s", m_button_silent_from[ 0 ].c_str() );
  ESP_LOGI( LOG_TAG, "m_button_silent_duration[ 0 ]: %lli", m_button_silent_duration[ 0 ] );
  ESP_LOGI( LOG_TAG, "m_button_bell_count[ 0 ]: %d", m_button_bell_count[ 0 ] );
  ESP_LOGI( LOG_TAG, "m_button_bell_delay[ 0 ]: %d", m_button_bell_delay[ 0 ] );

  ESP_LOGI( LOG_TAG, "m_button_default_clip[ 1 ]: %s", m_button_default_clip[ 1 ].c_str() );
  ESP_LOGI( LOG_TAG, "m_button_silent_clip[ 1 ]: %s", m_button_silent_clip[ 1 ].c_str() );
  ESP_LOGI( LOG_TAG, "m_button_silent_from[ 1 ]: %s", m_button_silent_from[ 1 ].c_str() );
  ESP_LOGI( LOG_TAG, "m_button_silent_duration[ 1 ]: %lli", m_button_silent_duration[ 1 ] );
  ESP_LOGI( LOG_TAG, "m_button_bell_count[ 1 ]: %d", m_button_bell_count[ 1 ] );
  ESP_LOGI( LOG_TAG, "m_button_bell_delay[ 1 ]: %d", m_button_bell_delay[ 1 ] );

  for( int i = 0; i < 2; i++ ) {
    std::vector<clip_override>::iterator ovr;
    for( ovr = m_button_overrides[ i ].begin(); ovr != m_button_overrides[ i ].end(); ovr++ ) {
      ESP_LOGI( LOG_TAG, "m_button_overrides[ %d ].name: %s", i, ( *ovr ).name.c_str() );
      ESP_LOGI( LOG_TAG, "m_button_overrides[ %d ].enable: %d", i, ( *ovr ).enable );
      ESP_LOGI( LOG_TAG, "m_button_overrides[ %d ].from: %s", i, ( *ovr ).from.c_str() );
      ESP_LOGI( LOG_TAG, "m_button_overrides[ %d ].duration: %llu", i, ( *ovr ).duration );
      ESP_LOGI( LOG_TAG, "m_button_overrides[ %d ].clip: %s", i, ( *ovr ).clip.c_str() );
    }
  }

  ESP_LOGI( LOG_TAG, "m_wifi_ssid: %s", m_wifi_ssid.c_str() );
  ESP_LOGI( LOG_TAG, "m_wifi_password: %s", m_wifi_password.c_str() );
  ESP_LOGI( LOG_TAG, "m_mqtt_server: %s", m_mqtt_server.c_str() );
  ESP_LOGI( LOG_TAG, "m_mqtt_cert_file: %s", m_mqtt_cert_file.c_str() );
  ESP_LOGI( LOG_TAG, "m_mqtt_topic: %s", m_mqtt_topic.c_str() );

}

void settings_file::update() {
  if( m_root ) {
    if( cJSON *buttons = cJSON_GetObjectItem( m_root, "buttons" ) ) {
      const char *button_list[ ] = { "left", "right" };
      for( int i = 0; i < sizeof( button_list ) / sizeof( char * ); i++ ) {
        if( cJSON *button = cJSON_GetObjectItem( buttons, button_list[ i ] ) ) {
          if( cJSON *label = cJSON_GetObjectItem( button, "label" ) ) {
            cJSON_SetValuestring( label, m_button_label[ i ].c_str() );
          }
          if( cJSON *deflt = cJSON_GetObjectItem( button, "default" ) ) {
            if( cJSON *clips = cJSON_GetObjectItem( deflt, "clips" ) ) {
              cJSON_ReplaceItemInArray(
                clips,
                0,
                cJSON_CreateStringReference( m_button_default_clip[ i ].c_str() )
              );
            }
            if( cJSON *bell = cJSON_GetObjectItem( deflt, "bell" ) ) {
              if( cJSON *count = cJSON_GetObjectItem( bell, "count" ) ) {
                cJSON_SetIntValue( count, m_button_bell_count[ i ] );
              }
              if( cJSON *delay = cJSON_GetObjectItem( bell, "delay" ) ) {
                cJSON_SetIntValue( delay, m_button_bell_delay[ i ] );
              }
            }
          }
          if( cJSON *silent = cJSON_GetObjectItem( button, "silent" ) ) {
            if( cJSON *enable = cJSON_GetObjectItem( silent, "enable" ) ) {
              cJSON_SetIntValue( enable, m_button_silent_enable[ i ] );
            }
            if( cJSON *from = cJSON_GetObjectItem( silent, "from" ) ) {
              cJSON_SetValuestring( from, m_button_silent_from[ i ].c_str() );
            }
            if( cJSON *duration_hours = cJSON_GetObjectItem( silent, "duration_hours" ) ) {
              cJSON_SetIntValue( duration_hours, m_button_silent_duration[ i ] / 3600 );
            }
            if( cJSON *clips = cJSON_GetObjectItem( silent, "clips" ) ) {
              cJSON_ReplaceItemInArray(
                clips,
                0,
                cJSON_CreateStringReference( m_button_silent_clip[ i ].c_str() )
              );
            }
          }
        }
      }

      // TODO: Implement the rest of the JSON config here

    }
  }
}

void settings_file::write( FILE * settings_json ) {
  if( settings_json ) {
    update();
    char *json_str = cJSON_Print( m_root );
    fseek( settings_json, 0, SEEK_SET );
    fputs( json_str, settings_json );
    cJSON_free( json_str );
  }
}

void settings_file::load( FILE * settings_json ) {

  ESP_LOGI( LOG_TAG, "Load settings from file" );
  fseek( settings_json, 0, SEEK_END );
  const size_t filesize = ftell( settings_json );
  fseek( settings_json, 0L, SEEK_SET );
  char *buf = new char[ filesize + 1 ];
  fread( buf, filesize, 1, settings_json );

  m_root = cJSON_Parse( buf );
  cJSON *buttons = cJSON_GetObjectItem( m_root, "buttons" );

  if( buttons ) {

    cJSON *a[ 2 ];
    a[ 0 ] = cJSON_GetObjectItem( buttons, "left" );
    a[ 1 ] = cJSON_GetObjectItem( buttons, "right" );

    for( int i = 0; a[ i ] && i <= sizeof( a ) / sizeof( a[ 0 ] ); i ++ ) {

      fetch_button_properties( a[ i ], m_button_label[ i ] );

      fetch_default_clip( a[ i ],
                          m_button_default_clip[ i ] );

      fetch_silent_clip( a[ i ],
                         m_button_silent_enable[ i ],
                         m_button_silent_clip[ i ],
                         m_button_silent_from[ i ],
                         m_button_silent_duration[ i ] );

      fetch_clip_overrides( a[ i ], m_button_overrides[ i ] );

      fetch_bell_settings( a[ i ],
                           m_button_bell_count[ i ],
                           m_button_bell_delay[ i ] );

    }

  }

  cJSON *wifi = cJSON_GetObjectItem( m_root, "wifi" );
  if( wifi ) {
    fetch_wifi_settings( wifi,
                        m_wifi_ssid,
                        m_wifi_password );
  }

  cJSON *ntp = cJSON_GetObjectItem( m_root, "datetime" );
  if( ntp ) {
    fetch_ntp_settings( ntp,
                        m_ntp_server,
                        m_ntp_timezone );
  }

  cJSON *mqtt = cJSON_GetObjectItem( m_root, "mqtt" );
  if( mqtt ) {
    fetch_mqtt_settings( mqtt,
                         m_mqtt_enable,
                         m_mqtt_server,
                         m_mqtt_cert_file,
                         m_mqtt_topic );
  }

  cJSON *logger = cJSON_GetObjectItem( m_root, "logger" );
  if( logger ) {
    fetch_logger_settings( logger,
                           m_logger_max_file_size_mb );
  }

  delete [ ] buf;

  debug_output();

}
