# SPDX-License-Identifier: GPL-2.0-or-later

incdir_engine = include_directories('../mrn/include')
incdir_app = include_directories('include')

executable('mrn-sandbox-app',
	   'src/sandboxapp.cpp',
	   include_directories : [incdir_engine, incdir_app],
	   link_with : mrnlib)
