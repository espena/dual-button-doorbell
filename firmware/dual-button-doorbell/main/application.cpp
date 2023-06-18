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

using namespace espena;

application::application( const configuration &conf ) : 
  m_config( conf ),
  m_led_green( conf.led_green ),
  m_led_red( conf.led_red ),
  m_relay( conf.relay ),
  m_sound( conf.sound ),
  m_sdcard( conf.sdcard ) { }

application::~application() { }

void application::run() {
  m_sdcard.mount();
  m_led_red.on();
  m_sound.play( m_sdcard.open_file( "ousse.wav", "rb" ) );
  m_led_red.off();
}
