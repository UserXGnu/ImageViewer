/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * i-viewer-header-bar.c
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

#include "i-viewer-header-bar.h"

struct _IViewerHeaderBarPrivate
{
	GtkWidget *  MSettings;
};




G_DEFINE_TYPE (IViewerHeaderBar, i_viewer_header_bar, GTK_TYPE_HEADER_BAR);

static void
i_viewer_header_bar_init (IViewerHeaderBar *i_viewer_header_bar)
{
	i_viewer_header_bar->priv = G_TYPE_INSTANCE_GET_PRIVATE (i_viewer_header_bar, I_TYPE_VIEWER_HEADER_BAR, IViewerHeaderBarPrivate);

	/* TODO: Add initialization code here */
}

static void
i_viewer_header_bar_finalize (GObject *object)
{
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (i_viewer_header_bar_parent_class)->finalize (object);
}

static void
i_viewer_header_bar_class_init (IViewerHeaderBarClass *klass)
{
	GObjectClass* object_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (IViewerHeaderBarPrivate));

	object_class->finalize = i_viewer_header_bar_finalize;
}


