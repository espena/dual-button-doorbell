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

#ifndef __logger_hpp__
#define __logger_hpp__

#include "i_file_io.hpp"

namespace espena::components {

  class logger {

    static const char *LOG_TAG;

    public:

      typedef struct configuration_struct {
        std::string filename;
        int max_size_mb;
      } configuration;

      logger( const configuration & );
      ~logger();
  
      void start( i_file_io * );

    private:

      const configuration &m_config;
      i_file_io *m_filesys;

  }; // class logger

}; // namespace espena::components

#endif // __logger_hpp__