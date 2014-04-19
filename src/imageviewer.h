/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * imageviewer.h
 * Copyright (C) 2014 UserX <userx@archlinux.info>
 * 
 * ImageViewer is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * ImageViewer is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _IMAGEVIEWER_
#define _IMAGEVIEWER_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define IMAGEVIEWER_TYPE_APPLICATION             (imageviewer_get_type ())
#define IMAGEVIEWER_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), IMAGEVIEWER_TYPE_APPLICATION, Imageviewer))
#define IMAGEVIEWER_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), IMAGEVIEWER_TYPE_APPLICATION, ImageviewerClass))
#define IMAGEVIEWER_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IMAGEVIEWER_TYPE_APPLICATION))
#define IMAGEVIEWER_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), IMAGEVIEWER_TYPE_APPLICATION))
#define IMAGEVIEWER_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), IMAGEVIEWER_TYPE_APPLICATION, ImageviewerClass))

typedef struct _ImageviewerClass ImageviewerClass;
typedef struct _Imageviewer Imageviewer;


struct _ImageviewerClass
{
	GtkApplicationClass parent_class;
};

struct _Imageviewer
{
	GtkApplication parent_instance;

};

GType imageviewer_get_type (void) G_GNUC_CONST;
Imageviewer *imageviewer_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */

