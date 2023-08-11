#ifndef __string_format_hpp__
#define __string_format_hpp__

#include <memory>
#include <string>
#include "esp_log.h"

namespace espena::utilities {
  template<typename ... Args>
  char * string_format( const std::string& format, char *buf, size_t len, Args ... args )
  {
      std::snprintf( buf, len, format.c_str(), args ... );
      return buf;
  }
}

#endif // __string_format_hpp__