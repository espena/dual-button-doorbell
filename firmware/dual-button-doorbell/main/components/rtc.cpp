#include "rtc.hpp"
#include "driver/i2c.h"
#include "esp_log.h"
#include "../io.h"

using namespace espena::components;

const char *rtc::LOG_TAG = "rtc";

rtc::rtc( const rtc::configuration &config ) : m_config( config ) {
  i2c_config_t i2c_config = {
    .mode = I2C_MODE_MASTER,
    .sda_io_num = config.gpio_sda,
    .scl_io_num = config.gpio_scl,
    .sda_pullup_en = GPIO_PULLUP_ENABLE,
    .scl_pullup_en = GPIO_PULLUP_ENABLE,
    .master = {
      .clk_speed = 400000
    },
    .clk_flags = 0
  };
  i2c_param_config( I2C_NUM_0, &i2c_config );
  esp_err_t ret = i2c_driver_install( I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0 );
  if( ret == ESP_OK ) {
    ESP_LOGI( LOG_TAG, "Initialization OK!" );
  }
  else {
    ESP_LOGE( LOG_TAG, "Initialization failed." );
  }
}

rtc::~rtc() {
  
}
