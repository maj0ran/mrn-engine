/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#pragma once

#include "mrn/window.h"

namespace mrn {

class Application
{
 public:
   Application ();
   virtual ~Application ();

   void run ();

 private:

  Window *window;
};

} // namespace mrn
