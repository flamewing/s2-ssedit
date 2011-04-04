
bin_PROGRAMS = \
	enicmp\
	koscmp \
	nemcmp \
	plane_map \
	mapping_tool

mapping_tool_SOURCES = \
	mapping_tool.cc

mapping_tool_LDFLAGS = \
	$(builddir)/../lib/libmappings.la

mapping_tool_CXXFLAGS = \
	-I$(srcdir)/../lib

plane_map_SOURCES = \
	plane_map.cc

plane_map_LDFLAGS = \
	$(builddir)/../lib/libenigma.la

plane_map_CXXFLAGS = \
	-I$(srcdir)/../lib

nemcmp_SOURCES = \
	nemcmp.cc

nemcmp_LDFLAGS = \
	$(builddir)/../lib/libnemesis.la

nemcmp_CXXFLAGS = \
	-I$(srcdir)/../lib

koscmp_SOURCES = \
	koscmp.cc

koscmp_LDFLAGS = \
	$(builddir)/../lib/libkosinski.la

koscmp_CXXFLAGS = \
	-I$(srcdir)/../lib

enicmp_SOURCES = \
	enicmp.cc

enicmp_LDFLAGS = \
	$(builddir)/../lib/libenigma.la

enicmp_CXXFLAGS = \
	-I$(srcdir)/../lib

AM_CXXFLAGS = 

## File created by the gnome-build tools

