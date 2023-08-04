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

#include "http_context_config.hpp"

using namespace espena::components;

const char *http_context_config::LOG_TAG = "http_context_config";

http_context_config::http_context_config() {
  
}

http_context_config::~http_context_config() {

}

const char * http_context_config::response() {
  return R"V0G0N(
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
            max-width: 768px;
            padding: 20px;
            margin: 30px auto 0 auto;
          }
          fieldset {
            border-radius: 10px;
            margin-bottom: 15px;
          }
          form > div {
            padding-left: 10px;
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
                  <input type="text" id="btn1_label" name="btn1_label" value="Ungene" />
                </div>
                <div>
                  <label for="btn1_default_clip">Default clip</label>
                  <input type="text" id="btn1_default_clip" name="btn1_default_clip" value="ungene.wav" />
                </div>
                <div>
                  <label for="btn1_ring_count">Ring count</label>
                  <input type="text" id="btn1_ring_count" name="btn1_ring_count" value="3" />
                </div>
                <div>
                  <label for="btn1_ring_delay">Ring interval (ms)</label>
                  <input type="text" id="btn1_ring_delay" name="btn1_ring_delay" value="200" />
                </div>
                <div>
                  <label for="btn1_silent_enable">Enable silent mode</label>
                  <input type="checkbox" id="btn1_silent_enable" name="btn1_silent_enable" checked />
                </div>
                <div>
                  <label for="btn1_silent_clip">Silent clip</label>
                  <input type="text" id="btn1_silent_clip" name="btn1_silent_clip" value="knock.wav" />
                </div>
                <div>
                  <label>Silent mode start</label>
                  <input type="text" id="btn1_silent_cron_min" name="btn1_silent_cron_min" value="0" placeholder="min" size="5" />
                  <input type="text" id="btn1_silent_cron_hour" name="btn1_silent_cron_hour" value="21" placeholder="hour" size="5" />
                  <input type="text" id="btn1_silent_cron_day" name="btn1_silent_cron_day" value="*" placeholder="day" size="5" />
                  <input type="text" id="btn1_silent_cron_mon" name="btn1_silent_cron_mon" value="*" placeholder="mon" size="5" />
                  <input type="text" id="btn1_silent_cron_dow" name="btn1_silent_cron_dow" value="*" placeholder="dow" size="5" />
                  <input type="text" id="btn1_silent_cron_year" name="btn1_silent_cron_year" value="*" placeholder="year" size="5" />
                </div>
                <div>
                  <label for="btn1_silent_duration">Silent mode duration (hours)</label>
                  <input type="number" id="btn1_silent_duration" name="btn1_silent_duration" value="6" maxlength="2" />
                </div>
              </fieldset>
              <fieldset>
                <legend>Button 2</legend>
                <div>
                  <label for="btn2_label">Label</label>
                  <input type="text" id="btn2_label" name="btn2_label" value="Pappa" />
                </div>
                <div>
                  <label for="btn2_default_clip">Default clip</label>
                  <input type="text" id="btn2_default_clip" name="btn2_default_clip" value="pappa.wav" />
                </div>
                <div>
                  <label for="btn2_ring_count">Ring count</label>
                  <input type="text" id="btn2_ring_count" name="btn2_ring_count" value="1" />
                </div>
                <div>
                  <label for="btn2_ring_delay">Ring interval (ms)</label>
                  <input type="text" id="btn2_ring_delay" name="btn2_ring_delay" value="300" />
                </div>
                <div>
                  <label for="btn2_silent_enable">Enable silent mode</label>
                  <input type="checkbox" id="btn2_silent_enable" name="btn2_silent_enable" checked />
                </div>
                <div>
                  <label for="btn2_silent_clip">Silent clip</label>
                  <input type="text" id="btn2_silent_clip" name="btn2_silent_clip" value="knock.wav" />
                </div>
                <div>
                  <label>Silent mode start</label>
                  <input type="text" id="btn2_silent_cron_min" name="btn2_silent_cron_min" value="0" placeholder="min" size="5" />
                  <input type="text" id="btn2_silent_cron_hour" name="btn2_silent_cron_hour" value="21" placeholder="hour" size="5" />
                  <input type="text" id="btn2_silent_cron_day" name="btn2_silent_cron_day" value="*" placeholder="day" size="5" />
                  <input type="text" id="btn2_silent_cron_mon" name="btn2_silent_cron_mon" value="*" placeholder="mon" size="5" />
                  <input type="text" id="btn2_silent_cron_dow" name="btn2_silent_cron_dow" value="*" placeholder="dow" size="5" />
                  <input type="text" id="btn2_silent_cron_year" name="btn2_silent_cron_year" value="*" placeholder="year" size="5" />
                </div>
                <div>
                  <label for="btn2_silent_duration">Silent mode duration (hours)</label>
                  <input type="number" id="btn2_silent_duration" name="btn2_silent_duration" value="6" maxlength="2" />
                </div>
              </fieldset>
              <fieldset>
                <legend>Wifi</legend>
                <div>
                  <label for="wifi_ssid">WiFi network (SSID)</label>
                  <input type="text" id="wifi_ssid" name="wifi_ssid" value="my_iot_network" />
                </div>
                <div>
                  <label for="wifi_key">WiFi password</label>
                  <input type="password" id="wifi_key" name="wifi_key" value="secret" />
                </div>
              </fieldset>
              <fieldset>
                <legend>Date and time</legend>
                <div>
                  <label for="ntp_server">NTP server/pool</label>
                  <input type="text" id="ntp_server" name="ntp_server" value="pool.ntp.org" />
                </div>
                <div>
                  <label for="ntp_timezone">Timezone</label>
                  <input type="text" id="ntp_timezone" name="ntp_timezone" value="CET-1CEST,M3.5.0,M10.5.0/3" size="30" />
                  <div>
                    <a href="https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv">Available time zone strings</a>
                  </div>
                </div>
              </fieldset>
              <div>
                <input type="reset" value="Reset" />
                <input type="submit" name="operation" value="Save" />
              </div>
            </form>
          </p>
        </main>
      </body>
    </html>
  )V0G0N";
}
