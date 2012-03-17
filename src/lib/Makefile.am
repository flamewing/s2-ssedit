
lib_LTLIBRARIES = \
	libenigma.la\
	libkosinski.la \
	libnemesis.la \
	libmappings.la 

libmappings_la_SOURCES = \
	singledplc.h    \
	singledplc.cc    \
	framedplc.h    \
	framedplc.cc    \
	dplcfile.h    \
	dplcfile.cc    \
	singlemapping.h    \
	singlemapping.cc    \
	framemapping.h    \
	framemapping.cc    \
	mappingfile.h    \
	mappingfile.cc

libmappings_la_LIBADD = \
	$(S2SSEDIT_LIBS)

libnemesis_la_SOURCES = \
	bigendian_io.h \
	bitstream.h \
	nemesis.cc \
	nemesis.h

libnemesis_la_LIBADD = \
	$(S2SSEDIT_LIBS)

libkosinski_la_SOURCES = \
	bigendian_io.h  \
	bitstream.h  \
	kosinski.cc  \
	kosinski.h

libkosinski_la_LIBADD = \
	$(S2SSEDIT_LIBS)

libenigma_la_SOURCES = \
	bigendian_io.h\
	bitstream.h \
	enigma.cc \
	enigma.h

libenigma_la_LIBADD = \
	$(S2SSEDIT_LIBS)

AM_CPPFLAGS = \
	$(S2SSEDIT_CFLAGS)

## File created by the gnome-build tools

