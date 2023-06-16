#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "io.h"
#include "init.h"

void app_main( void ) {
  init();
  while( gpio_get_level( IO_PANEL_S2_INPUT ) == 0 ) {
    ;
  }
  gpio_set_level( IO_RELAY, 1 );
  vTaskDelay( 1000 / portTICK_PERIOD_MS );
  gpio_set_level( IO_RELAY, 0 );
}