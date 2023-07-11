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

    void fetch_default_clip( cJSON *, std::string & );
    void fetch_silent_clip( cJSON *, std::string &, std::string &, time_t & );
    void fetch_bell_settings( cJSON *, int &, int & );
    void fetch_wifi_settings( cJSON *, std::string &, std::string & );
    void fetch_ntp_settings( cJSON *, std::string &, std::string & );
    void fetch_mtqq_settings( cJSON *, std::string &, std::string & );

    void debug_output();
    
    public:

      std::string m_button_left_default_clip;
      std::string m_button_right_default_clip;

      std::string m_button_left_silent_clip;
      std::string m_button_right_silent_clip;

      std::string m_button_left_silent_from;
      std::string m_button_right_silent_from;

      time_t m_button_left_silent_duration;
      time_t m_button_right_silent_duration;

      int m_button_left_bell_count;
      int m_button_right_bell_count;

      int m_button_left_bell_delay;
      int m_button_right_bell_delay;

      std::string m_wifi_ssid;
      std::string m_wifi_password;

      std::string m_ntp_server;
      std::string m_ntp_timezone;

      std::string m_mtqq_server;
      std::string m_mtqq_cert_file;

      settings_file();
      ~settings_file();
  
      void load( FILE * settings_json );

  }; // class settings_file

}; // namespace espena::components

#endif // __settings_file_hpp__