
lib_LTLIBRARIES = \
	libenigma.la\
	libkosinski.la \
	libnemesis.la

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

