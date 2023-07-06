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

#ifndef __application_h__
#define __application_h__

#include "esp_event.h"
#include "components/settings_file.hpp"
#include "components/led.hpp"
#include "components/relay.hpp"
#include "components/sound.hpp"
#include "components/sdcard.hpp"
#include "components/rtc.hpp"
#include "components/button.hpp"
#include "components/ntp.hpp"
#include "components/wifi.hpp"
#include "components/cron.hpp"

namespace espena {

  class application {

    static const char *LOG_TAG;

    public:

      /**
       * Main configuration
       */
      typedef struct configuration_struct {
        components::led::configuration led_green;
        components::led::configuration led_red;
        components::relay::configuration relay;
        components::sound::configuration sound;
        components::sdcard::configuration sdcard;
        components::rtc::configuration rtc;
        components::ntp::configuration ntp;
        components::button::configuration button_left;
        components::button::configuration button_right;
        components::led::configuration led_button_left;
        components::led::configuration led_button_right;
        components::cron::configuration cron;
      } configuration;

    private:

      /**
       * Reference to application instance, provided for static methods
       */
      static application *m_the_app;

      /**
       * Reference to relevant parts of main config
       */
      const configuration &m_config;

      /**
       * JSON settings read from from file on SD card
       */
      components::settings_file m_settings_file;

      /**
       * WiFi support
       */
      components::wifi m_wifi;

      /**
       * Components
       */

      components::led m_led_green;
      components::led m_led_red;

      components::relay m_relay;

      components::sound m_sound;

      components::sdcard m_sdcard;

      components::rtc m_rtc;

      components::ntp m_ntp;

      components::button m_button_left;
      components::button m_button_right;

      components::led m_led_button_left;
      components::led m_led_button_right;

      components::cron m_cron;

      /**
       * Handle to custom event loop
       */
      esp_event_loop_handle_t m_event_loop_handle;

      void play_sound( const std::string );

      void ding_dong( const int, const int );
      
      void add_event_listeners();

      void load_settings();
      
      void wifi_connect();

      void block_buttons();
      void release_buttons();

    public:

      /**
       * Constructor
       */
      application( const configuration & );

      /**
       * Destructor
       */
      ~application();

      /**
       * Event - static handler for all incoming events
       */
      static void event_handler( void *handler_arg,
                                 esp_event_base_t event_base,
                                 int32_t event_id,
                                 void *event_params );

      void event_handler_sdcard( int32_t, void * );
      void event_handler_sound( int32_t, void * );
      void event_handler_button( int32_t, int );
      void event_handler_wifi( int32_t, void * );
      void event_handler_ntp( int32_t, void * );
      void event_handler_cron( int32_t, const char * );

      /**
      * Application start
      * Called directly from default appMain rotine.
      */
      void run();
    
  }; // class Application
}; // namespace espena

#endif // __application_h__