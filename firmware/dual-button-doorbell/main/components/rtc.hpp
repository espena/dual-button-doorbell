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

#ifndef __rtc_hpp__
#define __rtc_hpp__

#include "driver/gpio.h"
#include "driver/i2c.h"

namespace espena::components {

  class rtc {

    static const char *LOG_TAG;

    char m_tz[ 50 ];

    public:

      typedef struct configuration_struct {
        gpio_num_t gpio_sda;
        gpio_num_t gpio_scl;
      } configuration;

    private:

      const configuration &m_config;
      i2c_config_t m_i2c_config;

      void save_current_timezone();
      void utc_push();
      void utc_pop();

      static uint8_t dec2bcd( uint8_t );
      static uint8_t bcd2dec( uint8_t );

      void get_time_string( char *, size_t, tm * );

    public:

      rtc( const configuration & );
      ~rtc();

      void get_time( tm &rtc_tm );
      void print_time();
      void sync_to_systime();
      void sync_from_systime();

  }; // class rtc

}; // namespace espena::components

#endif // __rtc_hpp__