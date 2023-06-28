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

#ifndef __led_hpp__
#define __led_hpp__

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task.h"

namespace espena::components {

  class led {

    static const int LED_DEFAULT_BLINK_MS = 300;
    
    typedef struct led_task_params_struct {
      led *instance;
      TaskHandle_t task_handle;
      int delay_ms;
      int count;
    } led_task_params;

    led_task_params m_led_task_params;

    public:

      typedef struct configuration_struct {
        gpio_num_t gpio_num;
      } configuration;

    private:

      const configuration &m_config;

      void kill_led_task();
      void led_op( int ms, int count );

    public:

      led( const configuration & );
      ~led();
  
      static void led_task( void * );

      void on();
      void off();
      void toggle();
      void stop();
      
      // inline impl.
      void blink() { blink( LED_DEFAULT_BLINK_MS ); }
      void blink( int ms ) { led_op( ms, 0 ); }
      void blink( int ms, int count ) { led_op( ms, count ); }

  }; // class led

}; // namespace espena::components

#endif // __led_hpp__