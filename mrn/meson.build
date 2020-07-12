# SPDX-License-Identifier: GPL-2.0-or-later

incdir = include_directories('include/')

add_global_arguments('-Werror', '-Wall', '-Wno-error=unused-function', language : 'cpp')

src = [ 'src/mrn/application.cpp',
	     'src/mrn/logger.cpp'
      ]

thread_dep = dependency('threads')

mrnlib = static_library('mrnengine',
	sources : src,
	include_directories : incdir,
	dependencies : thread_dep)
