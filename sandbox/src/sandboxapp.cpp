/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "mrn/event.h"
#include <mrn.h>
#include <string>
#include <sstream>
#include <sandboxapp.h>
#include <mrn/keyevent.h>

#include <iostream>
int main ()
{
   Sandbox *sandbox = new Sandbox ();
//   sandbox->run ();
   delete sandbox;

   auto e = mrn::KeyEventPressed(100);

   std::cout << static_cast<int>(e.type ()) << e.name () << std::endl;
   return 0;
}
