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

#include "relay.hpp"
#include "driver/gpio.h"

using namespace espena::components;

relay::relay( const relay::configuration &config ) : m_config( config ) {
  gpio_reset_pin( config.gpio_relay );
  gpio_set_direction( config.gpio_relay, GPIO_MODE_OUTPUT );
}

relay::~relay() {

}

void relay::on() {
  gpio_set_level( m_config.gpio_relay, 1 );
}

void relay::off() {
  gpio_set_level( m_config.gpio_relay, 0 );
}