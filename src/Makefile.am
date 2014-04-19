## Process this file with automake to produce Makefile.in

## Created by Anjuta



AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(IMAGEVIEWER_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = imageviewer

imageviewer_SOURCES = \
	main.c \
	i-viewer-window.c \
	i-viewer-window.h \
	i-viewer-header-bar.c \
	i-viewer-header-bar.h \
	definitions.h


imageviewer_LDFLAGS = \
	-Wl,--export-dynamic

imageviewer_LDADD = $(IMAGEVIEWER_LIBS)




