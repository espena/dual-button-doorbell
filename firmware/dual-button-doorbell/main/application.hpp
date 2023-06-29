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

namespace espena {

  class application {

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
        components::button::configuration button_left;
        components::button::configuration button_right;
        components::led::configuration led_button_left;
        components::led::configuration led_button_right;
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
       * Components
       */

      components::led m_led_green;
      components::led m_led_red;

      components::relay m_relay;

      components::sound m_sound;

      components::sdcard m_sdcard;

      components::rtc m_rtc;

      components::button m_button_left;
      components::button m_button_right;

      components::led m_led_button_left;
      components::led m_led_button_right;

      /**
       * Handle to custom event loop
       */
      esp_event_loop_handle_t m_event_loop_handle;

      void ding_dong( const int, const int );
      
      void add_event_listeners();

      void load_settings();

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

      /**
      * Application start
      * Called directly from default appMain rotine.
      */
      void run();
    
  }; // class Application
}; // namespace espena

#endif // __application_h__