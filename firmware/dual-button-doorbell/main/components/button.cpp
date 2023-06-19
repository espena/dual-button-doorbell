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
#include "esp_event.h"
#include "../io.h"

using namespace espena::components;

const esp_event_base_t button::event_base = "BUTTON_EVENT";

button::button( const configuration &config ) : m_config( config )
{

}

button::~button() {

}

void button::set_event_loop_handle( esp_event_loop_handle_t event_loop_handle ) {
  m_event_dispatcher.set_event_loop_handle( event_loop_handle );
}

void button::add_event_listener( event_id event_id,
                                 esp_event_handler_t event_handler,
                                 void *event_params )
{
  m_event_dispatcher.add_event_listener( button::event_base,
                                         event_id,
                                         event_handler,
                                         event_params );
}
