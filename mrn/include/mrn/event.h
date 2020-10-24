/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#pragma once

#include <queue>
#include <string>

#include "common.h"

namespace mrn {

enum class EventType
{
   None = 0,
   /* Key-Events */
   KeyPressed,
   KeyReleased,
   /* Mouse-Events */
   MouseButtonPressed,
   MouseButtonReleased,
   MouseMoved,
   MouseScrolled,
};

enum class EventCategory
{
   KeyEvent   = BIT (1),
   MouseEvent = BIT (2),
};

#define EVENT_TYPE(TYPE)               \
 private:                              \
   static EventType getStaticType ()   \
   {                                   \
      return EventType::TYPE;          \
   }                                   \
   static const char *getStaticName () \
   {                                   \
      return #TYPE;                    \
   }                                   \
                                       \
 public:                               \
   EventType type () const             \
   {                                   \
      return getStaticType ();         \
   }                                   \
   const char *name () const           \
   {                                   \
      return getStaticName ();         \
   }                                   \
                                       \
 private:


class Event
{
 public:
   virtual ~Event () = default;

   virtual const char *name () const = 0;
   virtual EventType type () const   = 0;
   bool is_in_category (EventCategory)
   {
      return false;
   }

 private:
 protected:
   //  static EventType type;
};

class EventBus
{
   public:
      EventBus () = default;
      ~EventBus () = default;
   private:

      std::queue<Event> events;
};

} // namespace mrn
