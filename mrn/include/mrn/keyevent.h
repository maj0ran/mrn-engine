#pragma once

#include "event.h"

namespace mrn {

class KeyEvent : public Event
{
 public:
   int key_code;
 protected:
   KeyEvent () = default;

 private:
};

class KeyEventPressed : public KeyEvent
{
   EVENT_TYPE (KeyPressed)

 public:
   KeyEventPressed (int key_code)
   {
      this->key_code = key_code;
   }

};

class KeyEventReleased : public KeyEvent
{
   EVENT_TYPE (KeyReleased)
 public:
   KeyEventReleased (int key_code)
   {
      this->key_code = key_code;
   }
};

} // namespace mrn
