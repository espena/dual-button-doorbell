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

#ifndef __settings_file_hpp__
#define __settings_file_hpp__

#include <string>
#include <cstdio>
#include "cJSON.h"

namespace espena::components {

  class settings_file {

    static const char *LOG_TAG;

    cJSON *m_root;

    void fetch_button_properties( cJSON *, std::string & );
    void fetch_default_clip( cJSON *, std::string & );
    void fetch_silent_clip( cJSON *, int &, std::string &, std::string &, time_t & );
    void fetch_bell_settings( cJSON *, int &, int & );
    void fetch_wifi_settings( cJSON *, std::string &, std::string & );
    void fetch_ntp_settings( cJSON *, std::string &, std::string & );
    void fetch_mqtt_settings( cJSON *, int &, std::string &, std::string &, std::string & );
    void fetch_logger_settings( cJSON *, size_t & );

    void update();

    void debug_output();
    
    public:

      std::string m_button_label[ 2 ];
      std::string m_button_default_clip[ 2 ];
      std::string m_button_silent_clip[ 2 ];
      std::string m_button_silent_from[ 2 ];
      int m_button_silent_enable[ 2 ];
      time_t m_button_silent_duration[ 2 ];
      int m_button_bell_count[ 2 ];
      int m_button_bell_delay[ 2 ];

      std::string m_wifi_ssid;
      std::string m_wifi_password;

      std::string m_ntp_server;
      std::string m_ntp_timezone;

      int m_mqtt_enable;
      std::string m_mqtt_server;
      std::string m_mqtt_cert_file;
      std::string m_mqtt_topic;

      size_t m_logger_max_file_size_mb;

      settings_file();
      ~settings_file();
  
      void load( FILE * settings_json );
      void write( FILE * settings_json );

  }; // class settings_file

}; // namespace espena::components

#endif // __settings_file_hpp__