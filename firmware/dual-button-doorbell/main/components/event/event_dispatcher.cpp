#include "event_dispatcher.hpp"
#include "esp_log.h"
#include "esp_event.h"

using namespace espena::components::event;

event_dispatcher::event_dispatcher() :
  m_handle_registered( ESP_ERR_NOT_FINISHED ),
  m_event_loop_handle( NULL )
{

}

event_dispatcher::~event_dispatcher() { }

void event_dispatcher::set_event_loop_handle( esp_event_loop_handle_t event_loop_handle ) {
  m_event_loop_handle = event_loop_handle;
}

void event_dispatcher::add_event_listener( esp_event_base_t event_base,
                                           int32_t event_id,
                                           esp_event_handler_t event_handler )
{
  // Unregister first, in case handler alredy is registered by another class instance.
  // Fails silently if no handler was found.
  esp_event_handler_unregister_with( m_event_loop_handle,
                                     event_base,
                                     event_id,
                                     event_handler );

  esp_event_handler_register_with( m_event_loop_handle,
                                   event_base,
                                   event_id,
                                   event_handler,
                                   NULL );
}

void event_dispatcher::dispatch( esp_event_base_t event_base,
                                 int32_t event_id,
                                 void * event_params,
                                 size_t event_params_size )
{
  if( m_event_loop_handle ) {
    esp_event_post_to( m_event_loop_handle,
                       event_base,
                       event_id,
                       event_params,
                       event_params_size,
                       10 );
  }
}