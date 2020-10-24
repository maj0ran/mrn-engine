/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <chrono>
#include <iostream>
#include <ratio>
#include <thread>

#include <mrn/color_codes.h>
#include <mrn/logger.h>

namespace mrn {

/*
 * LogEntry Class
 */

Logger::LogEntry::LogEntry (long timestamp, LogLevel level, std::string msg)
{
   this->timestamp = timestamp;
   this->level     = level;
   this->msg       = msg;
}

Logger::LogEntry::~LogEntry () = default;


/*
 * Logger Class
 */
Logger::Logger (LogLevel level)
{
   this->is_init   = true;
   this->log_level = level;
   this->start     = timer::now ();
   logthread       = std::thread (&Logger::print, this);
   log (LogLevel::INFO, "Logger initialized");
}
Logger::~Logger ()
{
   log (LogLevel::INFO, "De-initializing Logger");
   is_init = false;
   logthread.join ();
}


int Logger::print ()
{
   while (is_init || this->logbook.size () != 0) {
      std::this_thread::sleep_for (std::chrono::milliseconds (10));
      if (this->logbook.size () != 0) {
         logbook_lock.lock ();
         LogEntry e = logbook.front ();
         logbook.pop ();
         logbook_lock.unlock ();

         std::cout << e.timestamp;
         switch (e.level) {
            case LogLevel::ERROR:
               std::cout << BOLDRED << " [ERROR] " << RESET;
               break;
            case LogLevel::WARNING:
               std::cout << BOLDYELLOW << " [WARNING] " << RESET;
               break;
            case LogLevel::INFO:
               std::cout << BOLDCYAN << " [INFO] " << RESET;
               break;
            case LogLevel::DEBUG:
               std::cout << BOLDWHITE << " [DEBUG] " << RESET;
               break;
            case LogLevel::OK:
               std::cout << BOLDGREEN << " [OK] " << RESET;
               break;
            default:
               break;
         }
         std::cout << e.msg << std::endl;
      }
   }
   return 0;
}

void Logger::set_log_level (LogLevel level)
{
   this->log_level = level;
}

long Logger::timestamp ()
{
   std::chrono::duration<long, std::micro> duration =
         std::chrono::duration_cast<std::chrono::microseconds> (timer::now () - start);
   return duration.count ();
}


} // namespace mrn
