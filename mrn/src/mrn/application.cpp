/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <mrn/application.h>

namespace mrn {

Application::Application ()
{
	window = new Window("Game", 800, 600);
}
Application::~Application ()
{
}

void Application::run ()
{
   while (true) {
	   glClearColor(1, 0, 1, 1);
	   glClear(GL_COLOR_BUFFER_BIT);
   }
}

} // namespace mrn
