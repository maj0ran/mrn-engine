/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <mrn.h>
#include <string>
#include <sstream>
#include <sandboxapp.h>

int main ()
{
   Sandbox *sandbox = new Sandbox ();
   sandbox->run ();
   delete sandbox;

   return 0;
}
