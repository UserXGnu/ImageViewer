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
#include "i-viewer-header-bar.h"

struct _IViewerWIndowPrivate {
	GtkWidget * HeaderBar;
};




G_DEFINE_TYPE (IViewerWIndow, i_viewer_window, GTK_TYPE_WINDOW);

static void
i_viewer_window_init (IViewerWIndow * self) {
	IViewerWIndowPrivate * priv = G_TYPE_INSTANCE_GET_PRIVATE (self, I_TYPE_VIEWER_WINDOW, IViewerWIndowPrivate);
	
	gtk_window_set_title (GTK_WINDOW (self), "ImageViewer");
	gtk_window_set_default_size (GTK_WINDOW (self), 640, 480);

	priv->HeaderBar = i_viewer_header_bar_new ();

	gtk_window_set_titlebar (GTK_WINDOW (self), priv->HeaderBar);


	gtk_header_bar_set_show_close_button (GTK_HEADER_BAR (priv->HeaderBar), TRUE);
	gtk_header_bar_set_title (GTK_HEADER_BAR (priv->HeaderBar), "ImageViewer");
	gtk_header_bar_set_subtitle (GTK_HEADER_BAR (priv->HeaderBar), "First Project - (0.1)");
	gtk_header_bar_set_has_subtitle (GTK_HEADER_BAR (priv->HeaderBar), TRUE);
	

	g_signal_connect (self, "destroy", G_CALLBACK (gtk_main_quit), NULL);	
}

static void
i_viewer_window_finalize (GObject * object) {
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (i_viewer_window_parent_class)->finalize (object);
}

static void
i_viewer_window_class_init (IViewerWIndowClass *klass) {
	GObjectClass * object_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (IViewerWIndowPrivate));

	object_class->finalize = i_viewer_window_finalize;
}

GtkWidget *
i_viewer_window_new (void) {
	return GTK_WIDGET (g_object_new (I_TYPE_VIEWER_WINDOW, NULL)); 
}


