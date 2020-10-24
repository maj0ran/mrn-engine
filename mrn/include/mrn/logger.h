/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#pragma once

#include <string>
#include <queue>
#include <chrono>
#include <mutex>
#include <thread>
#include <sstream>

namespace mrn {
using std::chrono::steady_clock;
typedef std::chrono::steady_clock timer;
typedef timer::time_point time_point;

enum class LogLevel
{
   ERROR   = 1,
   WARNING = 2,
   INFO    = 3,
   DEBUG   = 4,
   OK      = 5
};

class Logger
{
   class LogEntry
   {
    public:
      LogEntry (long timestamp, LogLevel level, std::string msg);
      ~LogEntry ();

      long timestamp;
      LogLevel level;
      std::string msg;
   };

 public:
   Logger (LogLevel level);
   ~Logger ();
   void set_log_level (LogLevel level);

   template <typename... T>
   int log (LogLevel level, std::string msg, T... args)
   {
      if (level <= this->log_level) {
         compose_msg (msg, args...);
         const std::lock_guard<std::mutex> lock (this->logbook_lock);
         LogEntry e (timestamp (), level, logmsg.str());
         logbook.push (e);
         logmsg.str(std::string());
      }
      return 0;
   }
   void compose_msg (std::string msg)
   {
      logmsg << msg;
      return;
   }

   template <typename T, typename... Args>
   void compose_msg (std::string msg, T arg, Args... args)
   {
      for (std::size_t i = 0; i < msg.length (); i++) {
         if (msg[i] == '%' && (i != msg.length () - 1 && msg[i + 1] == '%')) { // replace %% with %
            msg.erase (msg.begin () + i);
         } else if (msg[i] == '%') { // replace % with args
            logmsg << msg.substr (0, i);
            logmsg << arg;
            msg.erase (msg.begin (), msg.begin () + i + 1);
            compose_msg (msg, args...);
            return;
         }
      }
      return;
   }

   int print ();

   steady_clock::time_point start;
   std::queue<LogEntry> logbook;
   int addEntry (LogLevel level, std::string msg);
   std::mutex logbook_lock;

 private:
   long timestamp ();

   std::ostringstream logmsg;
   LogLevel log_level;
   std::thread logthread;
   bool is_init = false;
};

} // namespace mrn
