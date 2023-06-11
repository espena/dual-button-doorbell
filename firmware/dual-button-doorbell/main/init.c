#include "driver/gpio.h"
#include "io.h"

void init_i2s( void ) {

}

void init_i2c( void ) {

}

void init_jtag( void ) {

}

void init_uart( void ) {

}

void init_relay( void ) {
  gpio_reset_pin( IO_RELAY );
  gpio_set_direction( IO_RELAY, GPIO_MODE_OUTPUT );
}

void init_sdcard( void ) {

}

void init_panel( void ) {

  const gpio_num_t inputs[] = { IO_PANEL_S1_INPUT, IO_PANEL_S1_INPUT };

  const gpio_num_t outputs[] = { IO_PANEL_S1_RED, IO_PANEL_S1_GREEN,
                                 IO_PANEL_S2_RED, IO_PANEL_S2_GREEN };

  for( int i = 0; i < sizeof( inputs ) / sizeof( inputs[ 0 ] ); i++ ) {
    gpio_reset_pin( inputs[ i ] );
    gpio_set_direction( inputs[ i ], GPIO_MODE_INPUT );
  }

  for( int i = 0; i < sizeof( outputs ) / sizeof( outputs[ 0 ] ); i++ ) {
    gpio_reset_pin( outputs[ i ] );
    gpio_set_direction( outputs[ i ], GPIO_MODE_OUTPUT );
  }

}

void init_led( void ) {

  const gpio_num_t outputs[] = { IO_LED_RED, IO_LED_GREEN };

  for( int i = 0; i < sizeof( outputs ) / sizeof( outputs[ 0 ] ); i++ ) {
    gpio_reset_pin( outputs[ i ] );
    gpio_set_direction( outputs[ i ], GPIO_MODE_OUTPUT );
  }

}

void init( void ) {
  init_i2s();
  init_i2c();
  init_led();
  init_jtag();
  init_uart();
  init_relay();
  init_sdcard();
  init_panel();
}
