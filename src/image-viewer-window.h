/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * image-viewer-window.h
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

#ifndef _IMAGE_VIEWER_WINDOW_H_
#define _IMAGE_VIEWER_WINDOW_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define IMAGE_TYPE_VIEWER_WINDOW             (image_viewer_window_get_type ())
#define IMAGE_VIEWER_WINDOW(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), IMAGE_TYPE_VIEWER_WINDOW, ImageViewerWindow))
#define IMAGE_VIEWER_WINDOW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), IMAGE_TYPE_VIEWER_WINDOW, ImageViewerWindowClass))
#define IMAGE_IS_VIEWER_WINDOW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IMAGE_TYPE_VIEWER_WINDOW))
#define IMAGE_IS_VIEWER_WINDOW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), IMAGE_TYPE_VIEWER_WINDOW))
#define IMAGE_VIEWER_WINDOW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), IMAGE_TYPE_VIEWER_WINDOW, ImageViewerWindowClass))

typedef struct _ImageViewerWindowClass ImageViewerWindowClass;
typedef struct _ImageViewerWindow ImageViewerWindow;
typedef struct _ImageViewerWindowPrivate ImageViewerWindowPrivate;


struct _ImageViewerWindowClass
{
	GtkWindowClass parent_class;
};

struct _ImageViewerWindow
{
	GtkWindow parent_instance;

	ImageViewerWindowPrivate *priv;
};

GType image_viewer_window_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* _IMAGE_VIEWER_WINDOW_H_ */

