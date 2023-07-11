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

#include "button.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "esp_event.h"
#include "esp_task_wdt.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "../io.h"

using namespace espena::components;

const char *button::LOG_TAG = "button";
const esp_event_base_t button::event_base = "BUTTON_EVENT";

button::button( const configuration &config ) :
  m_config( config ),
  m_pressed( 0 )
{
  m_message_queue = xQueueCreate( 10, sizeof( button * ) );
  gpio_reset_pin( config.gpio_button );
  gpio_set_direction( config.gpio_button, GPIO_MODE_INPUT );
  gpio_set_intr_type( config.gpio_button, GPIO_INTR_ANYEDGE );
  gpio_reset_pin( config.gpio_led );
  gpio_set_direction( config.gpio_led, GPIO_MODE_INPUT_OUTPUT );
  gpio_isr_handler_add( config.gpio_button, btn_isr_handler, this );
  xTaskCreate( button_event_task, "Button event task", 2048, this, 1, NULL );
}

button::~button() {

}

int button::is_pressed() {
  return gpio_get_level( m_config.gpio_button );
}

void button::intr_disable() {
  gpio_intr_disable( m_config.gpio_button );
}

void button::intr_enable() {
  gpio_intr_enable( m_config.gpio_button );
}

void button::btn_isr_handler( void *args ) {
  button *btn = static_cast<button *>( args );
  xQueueSendFromISR( btn->m_message_queue, btn, NULL );
}

void button::button_event_task( void *arg ) {
  button *btn = static_cast<button *>( arg );
  button *btn2 = NULL;
  while( 1 ) {
    if( xQueueReceive( btn->m_message_queue, &btn2, portMAX_DELAY ) ) {
      btn->on_btn_event();
    }
  }
}

void button::on_btn_event() {
  m_event_dispatcher.dispatch(
    button::event_base,
    is_pressed() ? ON_BTN_DOWN : ON_BTN_UP,
    ( void * ) &( m_config.btn_id ),
    sizeof( m_config.btn_id ) );
}

void button::set_event_loop_handle( esp_event_loop_handle_t event_loop_handle ) {
  m_event_dispatcher.set_event_loop_handle( event_loop_handle );
}

void button::add_event_listener( event_id event_id,
                                 esp_event_handler_t event_handler )
{
  m_event_dispatcher.add_event_listener( button::event_base,
                                         event_id,
                                         event_handler );
}
