#ifndef __i_event_dispatcher_hpp__
#define __i_event_dispatcher_hpp__

#include <string>

namespace espena::components::event {

  class i_event_dispatcher {
    public:
      virtual void set_event_loop_handle( esp_event_loop_handle_t ) = 0;
  };

}; // namespace espena::components::events

#endif