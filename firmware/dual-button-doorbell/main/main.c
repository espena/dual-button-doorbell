#include <stdio.h>
#include "driver/gpio.h"
#include "io.h"
#include "init.h"

void app_main( void ) {
  init();
  gpio_set_level( IO_LED_RED, 1 );
  gpio_set_level( IO_LED_GREEN, 1 );
}