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

#ifndef __sdcard_hpp__
#define __sdcard_hpp__

#include <string>
#include "driver/gpio.h"
#include "driver/spi_common.h"
#include "esp_event.h"
#include "event/event_dispatcher.hpp"

namespace espena::components {

  class sdcard : public event::i_event_dispatcher {

    static const char *LOG_TAG;

    public:

      static const esp_event_base_t event_base;

      typedef enum {
        ON_MOUNT_OK,
        ON_MOUNT_FAILED
      } event_id;

      typedef struct configuration_struct {
        gpio_num_t gpio_sdspi_mosi;
        gpio_num_t gpio_sdspi_miso;
        gpio_num_t gpio_sdspi_cs;
        gpio_num_t gpio_sdspi_clk;
        gpio_num_t gpio_sd_det;
        union {
          int slot;
          spi_host_device_t id;
        } sdspi_bus;
        int sdspi_max_transfer_sz;
        spi_dma_chan_t sdspi_dma_channel;
        std::string mount_point;
      } configuration;

    private:

      const configuration &m_config;
      ::espena::components::event::event_dispatcher m_event_dispatcher;

    public:

      sdcard( const configuration & );
      ~sdcard();

      void mount();
      
      FILE *open_file( const std::string, const std::string );
      void close_file( FILE * );

      void set_event_loop_handle( esp_event_loop_handle_t );
      void add_event_listener( event_id,
                               esp_event_handler_t );

  }; // class sdcard

}; // namespace espena

#endif // __sdcard_hpp__
