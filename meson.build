# SPDX-License-Identifier: GPL-2.0-only

project('mrn-engine', 'cpp',
	version : '0.1.0',
	license: 'GPL-2.0-or-later',
	default_options : ['cpp_std=c++2a',
			   'warning_level=3'
			  ])

compiler = meson.get_compiler('cpp')

add_global_arguments('-Werror',
		     '-Wno-error=unused-function',
		     language : 'cpp')

subdir('mrn')
subdir('sandbox')
# subdir('tests')
