#include "event_dispatcher.hpp"
#include "esp_event.h"

using namespace espena::components::event;

event_dispatcher::event_dispatcher() { }

event_dispatcher::~event_dispatcher() { }

void event_dispatcher::set_event_loop_handle( esp_event_loop_handle_t event_loop_handle ) {
  m_event_loop_handle = event_loop_handle;
}

void event_dispatcher::add_event_listener( esp_event_base_t event_base,
                                           int32_t event_id,
                                           esp_event_handler_t event_handler,
                                           void * event_params )
{
  esp_event_handler_register_with( m_event_loop_handle,
                                   event_base,
                                   event_id,
                                   event_handler,
                                   event_params );
}

void event_dispatcher::dispatch( esp_event_base_t event_base,
                                 int32_t event_id,
                                 void * event_params )
{
  if( m_event_loop_handle ) {
    esp_event_post_to( m_event_loop_handle,
                       event_base,
                       event_id,
                       event_params,
                       0,
                       10 );
  }
}