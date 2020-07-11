/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

namespace mrn {

class Application
{
 public:
   Application ();
   virtual ~Application ();

   void run ();
};

} // namespace mrn
