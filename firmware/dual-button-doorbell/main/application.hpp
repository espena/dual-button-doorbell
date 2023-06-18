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

#include "components/led.hpp"
#include "components/relay.hpp"
#include "components/sound.hpp"
#include "components/sdcard.hpp"

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
      } configuration;

    private:

      /**
        * Reference to relevant part of main config
        */
      const configuration &m_config;

      components::led m_led_green;
      components::led m_led_red;
      components::relay m_relay;
      components::sound m_sound;
      components::sdcard m_sdcard;

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
      * Application start
      * Called directly from default appMain rotine.
      */
      void run();
    
  }; // class Application
}; // namespace espena

#endif // __application_h__