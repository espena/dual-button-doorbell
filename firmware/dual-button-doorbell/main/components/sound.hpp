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

#ifndef __sound_hpp__
#define __sound_hpp__

#include <string>
#include "driver/gpio.h"
#include "driver/i2s_std.h"
#include "esp_event.h"
#include "event/event_dispatcher.hpp"

namespace espena::components {

  class sound : public event::i_event_dispatcher {

    typedef struct waw_hdr_prologue_st {
      char tag[ 4 ];
      union {
        char b[ 4 ];
        int16_t i;
      } len;
    } waw_hdr_prologue;

    public:

      static const esp_event_base_t event_base;

      typedef enum {
        ON_PLAY_START,
        ON_PLAY_END
      } event_id;

      typedef struct configuration_struct {
        gpio_num_t gpio_i2s_sd_mode;
        gpio_num_t gpio_i2s_bclk;
        gpio_num_t gpio_i2s_lrclk;
        gpio_num_t gpio_i2s_dout;
      } configuration;

    private:

      const configuration &m_config;
      i2s_chan_handle_t m_i2s_tx_handle;
      i2s_std_config_t m_i2s_std_cfg;
      ::espena::components::event::event_dispatcher m_event_dispatcher;

    public:

      sound( const configuration & );
      ~sound();

      void play( FILE * );

      void set_event_loop_handle( esp_event_loop_handle_t );
      void add_event_listener( event_id,
                               esp_event_handler_t,
                               void * );

  }; // class sound

}; // namespace espena::components

#endif // __sound_hpp__