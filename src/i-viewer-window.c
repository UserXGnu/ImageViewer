/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * i-viewer-window.c
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

#include "i-viewer-window.h"

struct _IViewerWIndowPrivate
{
	GtkWidget *  HeaderBar;
};




G_DEFINE_TYPE (IViewerWIndow, i_viewer_window, GTK_TYPE_WINDOW);

static void
i_viewer_window_init (IViewerWIndow *i_viewer_window)
{
	i_viewer_window->priv = G_TYPE_INSTANCE_GET_PRIVATE (i_viewer_window, I_TYPE_VIEWER_WINDOW, IViewerWIndowPrivate);

	/* TODO: Add initialization code here */
}

static void
i_viewer_window_finalize (GObject *object)
{
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (i_viewer_window_parent_class)->finalize (object);
}

static void
i_viewer_window_class_init (IViewerWIndowClass *klass)
{
	GObjectClass* object_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (IViewerWIndowPrivate));

	object_class->finalize = i_viewer_window_finalize;
}


