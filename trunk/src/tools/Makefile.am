
bin_PROGRAMS = \
	enicmp\
	koscmp \
	nemcmp \
	plane_map \
	mapping_tool \
	recolor_art \
	smps2asm \
	voice_dumper \
	chunk_census

voice_dumper_SOURCES = \
	fmvoice.cc    \
	fmvoice.h    \
	voice_dumper.cc

voice_dumper_CXXFLAGS = \
	-I$(srcdir)/../lib

chunk_census_SOURCES =  \
	chunk_census.cc

chunk_census_CXXFLAGS = -I$(srcdir)/../lib 

chunk_census_LDFLAGS = $(builddir)/../lib/libkosinski.la 

smps2asm_SOURCES = \
	smps2asm.cc\
	fmvoice.cc\
	fmvoice.h \
	songtrack.cc \
	songtrack.h

smps2asm_CXXFLAGS = \
	-I$(srcdir)/../lib

recolor_art_SOURCES = \
	recolor_art.cc

recolor_art_LDFLAGS = \
	$(builddir)/../lib/libnemesis.la \
	$(builddir)/../lib/libkosinski.la

recolor_art_CXXFLAGS = \
	-I$(srcdir)/../lib

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

