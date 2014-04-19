/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * i-viewer-header-bar.h
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

#ifndef _I_VIEWER_HEADER_BAR_H_
#define _I_VIEWER_HEADER_BAR_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define I_TYPE_VIEWER_HEADER_BAR             (i_viewer_header_bar_get_type ())
#define I_VIEWER_HEADER_BAR(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), I_TYPE_VIEWER_HEADER_BAR, IViewerHeaderBar))
#define I_VIEWER_HEADER_BAR_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), I_TYPE_VIEWER_HEADER_BAR, IViewerHeaderBarClass))
#define I_IS_VIEWER_HEADER_BAR(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), I_TYPE_VIEWER_HEADER_BAR))
#define I_IS_VIEWER_HEADER_BAR_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), I_TYPE_VIEWER_HEADER_BAR))
#define I_VIEWER_HEADER_BAR_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), I_TYPE_VIEWER_HEADER_BAR, IViewerHeaderBarClass))

typedef struct _IViewerHeaderBarClass IViewerHeaderBarClass;
typedef struct _IViewerHeaderBar IViewerHeaderBar;
typedef struct _IViewerHeaderBarPrivate IViewerHeaderBarPrivate;


struct _IViewerHeaderBarClass
{
	GtkHeaderBarClass parent_class;
};

struct _IViewerHeaderBar
{
	GtkHeaderBar parent_instance;

	IViewerHeaderBarPrivate *priv;
};

GType i_viewer_header_bar_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* _I_VIEWER_HEADER_BAR_H_ */

