/* Copyright (C) 2020 Marian Cichy <M.Cichy@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#pragma once

#include <string>
#include <GLFW/glfw3.h>
namespace mrn {

	class Window {
		public:
		Window(const std::string &&title, uint32_t width, uint32_t height);
		~Window();

		GLFWwindow *wnd;
		const std::string title;

		uint32_t width;
		uint32_t height;

		struct WinData {

		};

		struct WinData data;

		private:
		bool glfw_is_init = false;
	};

}
