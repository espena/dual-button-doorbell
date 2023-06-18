#ifndef __SDCARD_HPP__
#define __SDCARD_HPP__

#include <string>
#include "driver/gpio.h"
#include "driver/spi_common.h"

namespace espena::components {

  class sdcard {

    public:

      typedef struct configuration_struct {
        gpio_num_t gpio_sdspi_mosi;
        gpio_num_t gpio_sdspi_miso;
        gpio_num_t gpio_sdspi_cs;
        gpio_num_t gpio_sdspi_clk;
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

    public:

      sdcard( const configuration & );
      ~sdcard();

      void mount();
  
  }; // class sdcard

}; // namespace espena

#endif // __SDCARD_HPP__
