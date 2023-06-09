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

#ifndef __relay_hpp__
#define __relay_hpp__

#include "driver/gpio.h"

namespace espena::components {

  class relay {

    static const char *LOG_TAG;

    public:

      typedef struct configuration_struct {
        gpio_num_t gpio_relay;
      } configuration;

    private:

      const configuration &m_config;

    public:

      relay( const configuration & );
      ~relay();
  
      void on();
      void off();

  }; // class relay

}; // namespace espena::components

#endif // __relay_hpp__