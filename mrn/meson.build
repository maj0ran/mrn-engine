# SPDX-License-Identifier: GPL-2.0-only

incdir = include_directories('include/')

src = [ 'src/mrn/application.cpp',
	     'src/mrn/logger.cpp',
	     'src/mrn/window.cpp',
      ]

thread_dep = dependency('threads')

mrnlib = static_library('mrnengine',
	sources : src,
	include_directories : incdir,
	dependencies : [thread_dep, glfw_dep, gl_dep])
