/*
 *  This file is part of the dual-http_context_config doorbell project.
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

#include "esp_log.h"
#include "http_context_config.hpp"
#include "../utilities/string_format.hpp"
#include <sstream>
#include <memory.h>

using namespace espena::components;

const char *http_context_config::LOG_TAG = "http_context_config";

http_context_config::http_context_config() : m_settings_file( NULL ) {
  memset( m_buf, 0x00, sizeof( m_buf ) );
}

http_context_config::~http_context_config() {

}

void http_context_config::set( ::espena::components::settings_file *sf ) {
  ESP_LOGI( LOG_TAG, "Settings file registered" );
  m_settings_file = sf;
}

const char * http_context_config::response() {
  
  const char *tpl = R"V0G0N(
    <html>
      <head>
        <style>
          * {
            box-sizing: border-box;
          }
          body {
            font-family: "Arial", "Helvetica", sans-serif;
          }
          h1 {
            margin: 0;
            padding: 0;
          }
          main {
            border: solid 1px #ccc;
            border-radius: 10px;
            min-width: 600px;
            max-width: 768px;
            padding: 20px;
            margin: 30px auto 0 auto;
          }
          fieldset {
            border-radius: 10px;
            margin-bottom: 15px;
          }
          form > div {
            padding: 0 10px;
            text-align: right;
          }
          fieldset > div {
            margin-bottom: 5px;
          }
          fieldset > div > div {
            margin: 2px 0 0 210px;
          }
          fieldset > div a {
            font-size: 0.8em;
          }
          legend {
            font-size: 0.9em;
            font-weight: bold;
          }
          button {
            margin-left: 205px;
          }
          label {
            display: inline-block;
            min-width: 200px;
            text-align: right;
            font-size: 0.8em;
          }
          label::after {
            content: ":";
          }
          input[type='number'] {
            width: 50px;
          }
        </style>
      </head>
      <body>
        <main>
          <h1>Dual-button doorbell</h1>
          <p>
            <form method="POST" action="/">
              <fieldset>
                <legend>Button 1</legend>
                <div>
                  <label for="btn1_label">Label</label>
                  <input type="text" id="btn1_label" name="btn1_label" value="%s" />
                </div>
                <div>
                  <label for="btn1_default_clip">Default clip</label>
                  <input type="text" id="btn1_default_clip" name="btn1_default_clip" value="%s" />
                </div>
                <div>
                  <label for="btn1_ring_count">Ring count</label>
                  <input type="text" id="btn1_ring_count" name="btn1_ring_count" value="%d" />
                </div>
                <div>
                  <label for="btn1_ring_delay">Ring interval (ms)</label>
                  <input type="text" id="btn1_ring_delay" name="btn1_ring_delay" value="%d" />
                </div>
                <div>
                  <label for="btn1_silent_enable">Enable silent mode</label>
                  <input type="checkbox" id="btn1_silent_enable" name="btn1_silent_enable" %s />
                </div>
                <div>
                  <label for="btn1_silent_clip">Silent clip</label>
                  <input type="text" id="btn1_silent_clip" name="btn1_silent_clip" value="%s" />
                </div>
                <div>
                  <label>Silent mode start</label>
                  <input type="text" id="btn1_silent_cron_min" name="btn1_silent_cron_min" value="%s" placeholder="min" size="5" />
                  <input type="text" id="btn1_silent_cron_hour" name="btn1_silent_cron_hour" value="%s" placeholder="hour" size="5" />
                  <input type="text" id="btn1_silent_cron_day" name="btn1_silent_cron_day" value="%s" placeholder="day" size="5" />
                  <input type="text" id="btn1_silent_cron_mon" name="btn1_silent_cron_mon" value="%s" placeholder="mon" size="5" />
                  <input type="text" id="btn1_silent_cron_dow" name="btn1_silent_cron_dow" value="%s" placeholder="dow" size="5" />
                </div>
                <div>
                  <label for="btn1_silent_duration">Silent mode duration (hours)</label>
                  <input type="number" id="btn1_silent_duration" name="btn1_silent_duration" value="%d" maxlength="2" />
                </div>
                <div>
                  <button id="btn1_test" name="btn1_test">Test</button>
                </div>
              </fieldset>
              <fieldset>
                <legend>Button 2</legend>
                <div>
                  <label for="btn2_label">Label</label>
                  <input type="text" id="btn2_label" name="btn2_label" value="%s" />
                </div>
                <div>
                  <label for="btn2_default_clip">Default clip</label>
                  <input type="text" id="btn2_default_clip" name="btn2_default_clip" value="%s" />
                </div>
                <div>
                  <label for="btn2_ring_count">Ring count</label>
                  <input type="text" id="btn2_ring_count" name="btn2_ring_count" value="%d" />
                </div>
                <div>
                  <label for="btn2_ring_delay">Ring interval (ms)</label>
                  <input type="text" id="btn2_ring_delay" name="btn2_ring_delay" value="%d" />
                </div>
                <div>
                  <label for="btn2_silent_enable">Enable silent mode</label>
                  <input type="checkbox" id="btn2_silent_enable" name="btn2_silent_enable" %s />
                </div>
                <div>
                  <label for="btn2_silent_clip">Silent clip</label>
                  <input type="text" id="btn2_silent_clip" name="btn2_silent_clip" value="%s" />
                </div>
                <div>
                  <label>Silent mode start</label>
                  <input type="text" id="btn2_silent_cron_min" name="btn2_silent_cron_min" value="%s" placeholder="min" size="5" />
                  <input type="text" id="btn2_silent_cron_hour" name="btn2_silent_cron_hour" value="%s" placeholder="hour" size="5" />
                  <input type="text" id="btn2_silent_cron_day" name="btn2_silent_cron_day" value="%s" placeholder="day" size="5" />
                  <input type="text" id="btn2_silent_cron_mon" name="btn2_silent_cron_mon" value="%s" placeholder="mon" size="5" />
                  <input type="text" id="btn2_silent_cron_dow" name="btn2_silent_cron_dow" value="%s" placeholder="dow" size="5" />
                </div>
                <div>
                  <label for="btn2_silent_duration">Silent mode duration (hours)</label>
                  <input type="number" id="btn2_silent_duration" name="btn2_silent_duration" value="%d" maxlength="2" />
                </div>
                <div>
                  <button id="btn2_test" name="btn2_test">Test</button>
                </div>
              </fieldset>
              <fieldset>
                <legend>Wifi</legend>
                <div>
                  <label for="wifi_ssid">WiFi network (SSID)</label>
                  <input type="text" id="wifi_ssid" name="wifi_ssid" value="%s" />
                </div>
                <div>
                  <label for="wifi_key">WiFi password</label>
                  <input type="password" id="wifi_key" name="wifi_key" value="%s" />
                </div>
              </fieldset>
              <fieldset>
                <legend>Date and time</legend>
                <div>
                  <label for="ntp_server">NTP server/pool</label>
                  <input type="text" id="ntp_server" name="ntp_server" value="%s" />
                </div>
                <div>
                  <label for="ntp_timezone">Timezone</label>
                  <input type="text" id="ntp_timezone" name="ntp_timezone" value="%s" size="30" />
                  <div>
                    <a href="https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv">Available time zone strings</a>
                  </div>
                </div>
              </fieldset>
              <fieldset>
                <legend>MQTT</legend>
                <div>
                  <label for="mqtt_enable">Enable MQTT</label>
                  <input type="checkbox" id="mqtt_enable" name="mqtt_enable" %s />
                </div>
                <div>
                  <label for="mqtt_server">MQTT server</label>
                  <input type="text" id="mqtt_server" name="mqtt_server" value="%s" size="50" />
                </div>
                <div>
                  <label for="mqtt_cert">CA certificate</label>
                  <input type="text" id="mqtt_cert" name="mqtt_cert" value="%s" />
                </div>
                <div>
                  <label for="mqtt_topic">Topic</label>
                  <input type="text" id="mqtt_topic" name="mqtt_topic" value="%s" />
                </div>
              </fieldset>
              <div>
                <input type="reset" value="Reset" />
                <input type="submit" name="operation" value="Save" />
              </div>
            </form>
          </p>
        </main>
        <script>
          function onTest( e ) {
            switch( e.target.id ) {
              case 'btn1_test':
                fetch( '/test/1' );
                break;
              case 'btn2_test':
                fetch( '/test/2' );
                break;
            }
            e.preventDefault();
          }
          document.getElementById( 'btn1_test' ).addEventListener( 'click', onTest );
          document.getElementById( 'btn2_test' ).addEventListener( 'click', onTest );
        </script>
      </body>
    </html>
  )V0G0N";

  if( m_settings_file ) {

    std::string silent_from[ 2 ][ 7 ];
    std::string cron_token;
    int silent_duration[ 2 ];
    for( int i = 0; i < 2; i++ ) {
      std::stringstream cron_line( m_settings_file->m_button_silent_from[ i ] );
      int j = 0;
      while( i < 7 && std::getline( cron_line, cron_token, ' ' ) ) {
        silent_from[ i ][ j++ ] = cron_token;
      }
      time_t ms = m_settings_file->m_button_silent_duration[ i ];
      silent_duration[ i ] = ms / 3600;
    }

    char *response = 
      ::espena::utilities::string_format(
        tpl,
        m_buf,
        sizeof( m_buf ),
        m_settings_file->m_button_label[ 0 ].c_str(),
        m_settings_file->m_button_default_clip[ 0 ].c_str(),
        m_settings_file->m_button_bell_count[ 0 ],
        m_settings_file->m_button_bell_delay[ 0 ],
        m_settings_file->m_button_silent_enable[ 0 ] == 1 ? "checked" : "",
        m_settings_file->m_button_silent_clip[ 0 ].c_str(),
        silent_from[ 0 ][ 1 ].c_str(),
        silent_from[ 0 ][ 2 ].c_str(),
        silent_from[ 0 ][ 3 ].c_str(),
        silent_from[ 0 ][ 4 ].c_str(),
        silent_from[ 0 ][ 5 ].c_str(),
        silent_duration[ 0 ],
        m_settings_file->m_button_label[ 1 ].c_str(),
        m_settings_file->m_button_default_clip[ 1 ].c_str(),
        m_settings_file->m_button_bell_count[ 1 ],
        m_settings_file->m_button_bell_delay[ 1 ],
        m_settings_file->m_button_silent_enable[ 1 ] == 1 ? "checked" : "",
        m_settings_file->m_button_silent_clip[ 1 ].c_str(),
        silent_from[ 1 ][ 1 ].c_str(),
        silent_from[ 1 ][ 2 ].c_str(),
        silent_from[ 1 ][ 3 ].c_str(),
        silent_from[ 1 ][ 4 ].c_str(),
        silent_from[ 1 ][ 5 ].c_str(),
        silent_duration[ 1 ],
        m_settings_file->m_wifi_ssid.c_str(),
        m_settings_file->m_wifi_password.c_str(),
        m_settings_file->m_ntp_server.c_str(),
        m_settings_file->m_ntp_timezone.c_str(),
        m_settings_file->m_mqtt_enable == 1 ? "checked" : "",
        m_settings_file->m_mqtt_server.c_str(),
        m_settings_file->m_mqtt_cert_file.c_str(),
        m_settings_file->m_mqtt_topic.c_str()
      );
    return response;
  }
  else {
    return "Loading...";
  }
}
