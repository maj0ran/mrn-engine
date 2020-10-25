/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <GLFW/glfw3.h>
#include <assert.h>

#include "mrn.h"

namespace mrn {

Window::Window(const std::string &&title, uint32_t width, uint32_t height) :
	title(title),
	width(width),
	height(height)
{
	if(!glfw_is_init) {
		if (!glfwInit())
			printf("GLFW not initialized\n");

		glfw_is_init = true;
	}

	wnd = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(wnd);
}

Window::~Window()
{
	glfwDestroyWindow(wnd);
}
}
