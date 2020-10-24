# SPDX-License-Identifier: GPL-2.0-or-later

incdir = include_directories('include/')

src = [ 'src/mrn/application.cpp',
	     'src/mrn/logger.cpp'
      ]

thread_dep = dependency('threads')

glfw_dep = dependency('glfw')

mrnlib = static_library('mrnengine',
	sources : src,
	include_directories : incdir,
	dependencies : thread_dep)
