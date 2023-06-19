#ifndef __dispatcher_app__
#define __dispatcher_app__

#include "esp_event.h"
#include "i_event_dispatcher.hpp"

namespace espena::components::event {

  class event_dispatcher : public i_event_dispatcher {

    esp_event_loop_handle_t m_event_loop_handle;

    public:

      event_dispatcher();
      ~event_dispatcher();

      void set_event_loop_handle( esp_event_loop_handle_t );
      void add_event_listener( esp_event_base_t, int32_t, esp_event_handler_t, void * );
      void dispatch( esp_event_base_t, int32_t, void * );

  }; // class event_dispatcher

}; // namespace espena::components::event

#endif
