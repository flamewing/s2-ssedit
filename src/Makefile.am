## Process this file with automake to produce Makefile.in

## Created by Anjuta

uidir = $(datadir)/s2ssedit/ui
ui_DATA = s2ssedit.ui \
	phoenix.png

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(S2SSEDIT_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = s2ssedit

s2ssedit_SOURCES = \
	main.cc   \
	sseditor.h   \
	sseditor.cc   \
	sssegmentobjs.h   \
	sssegmentobjs.cc   \
	sslevelobjs.h   \
	sslevelobjs.cc   \
	ssobjfile.h   \
	ssobjfile.cc   

s2ssedit_CXXFLAGS = \
	-I$(srcdir)/lib

s2ssedit_LDFLAGS = \
	$(builddir)/lib/libenigma.la \
	$(builddir)/lib/libkosinski.la \
	$(builddir)/lib/libnemesis.la

s2ssedit_LDADD = $(S2SSEDIT_LIBS)

EXTRA_DIST = $(ui_DATA)

SUBDIRS = \
	lib\
	tools

AM_CXXFLAGS = 

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/s2ssedit