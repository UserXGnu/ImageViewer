/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * imageviewer.c
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
#include "imageviewer.h"

#include <glib/gi18n.h>




G_DEFINE_TYPE (Imageviewer, imageviewer, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro IMAGEVIEWER_APPLICATION gets Imageviewer - DO NOT REMOVE */

/* Create a new window loading a file */
static void
imageviewer_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "ImageViewer");
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	if (file != NULL)
	{
		/* TODO: Add code here to open the file in the new window */
	}

	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
imageviewer_activate (GApplication *application)
{
	imageviewer_new_window (application, NULL);
}

static void
imageviewer_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		imageviewer_new_window (application, files[i]);
}

static void
imageviewer_init (Imageviewer *object)
{
}

static void
imageviewer_finalize (GObject *object)
{
	G_OBJECT_CLASS (imageviewer_parent_class)->finalize (object);
}

static void
imageviewer_class_init (ImageviewerClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = imageviewer_activate;
	G_APPLICATION_CLASS (klass)->open = imageviewer_open;

	G_OBJECT_CLASS (klass)->finalize = imageviewer_finalize;
}

Imageviewer *
imageviewer_new (void)
{
	return g_object_new (imageviewer_get_type (),
	                     "application-id", "org.gnome.imageviewer",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

