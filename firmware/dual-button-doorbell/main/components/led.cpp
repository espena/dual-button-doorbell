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

#include "led.hpp"
#include "memory.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_task_wdt.h"
#include "esp_log.h"

using namespace espena::components;

const char *led::LOG_TAG = "led";

led::led( const led::configuration &config ) :
  m_config( config ),
  m_active( false ),
  m_default_level( 0 )
{
  memset( &m_led_task_params, 0x00, sizeof m_led_task_params );
  gpio_reset_pin( config.gpio_num );
  gpio_set_direction( config.gpio_num, GPIO_MODE_INPUT_OUTPUT );
}

led::~led() {

}

void led::led_task( void *arg ) {
  led_task_params *params = static_cast<led_task_params *>( arg );
  int count = 0;
  led *instance = params->instance;
  while( 1 ) {
    instance->on();
    vTaskDelay( params->delay_ms / portTICK_PERIOD_MS );
    instance->off();
    if( params->count > 0 && ++count >= params->count ) {
      instance->kill_led_task();
      count = 0;
    }
    vTaskDelay( params->delay_ms / portTICK_PERIOD_MS );
  }
}

void led::kill_led_task() {
  if( m_led_task_params.task_handle ) {
    TaskHandle_t h = m_led_task_params.task_handle;
    m_led_task_params.task_handle = NULL;
    vTaskDelete( h );
  }
  gpio_set_level( m_config.gpio_num, m_default_level );
}

void led::on() {
  gpio_set_level( m_config.gpio_num, 1 );
}

void led::off() {
  gpio_set_level( m_config.gpio_num, 0 );
  m_active = false;
}

void led::default_on() {
  if( m_default_level == 0 ) {
    gpio_set_level( m_config.gpio_num, 1 );
  }
  m_default_level = 1;
}

void led::default_off() {
  if( m_default_level == 1 ) {
    gpio_set_level( m_config.gpio_num, 0 );
  }
  m_default_level = 0;
}

void led::toggle() {
  gpio_set_level( m_config.gpio_num, !gpio_get_level( m_config.gpio_num ) );
}

void led::led_op( int ms, int count ) {
  kill_led_task();
  m_led_task_params = {
    .instance = this,
    .task_handle = NULL,
    .delay_ms = ms,
    .count = count
  };
  m_active = true;
  xTaskCreate( &led::led_task, "led_task", 2048, &m_led_task_params, 1, &( m_led_task_params.task_handle ) );
}

void led::stop() {
  off();
  kill_led_task();
  m_active = false;
}
