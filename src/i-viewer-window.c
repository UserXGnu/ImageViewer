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
    GtkWidget * box;
    GtkWidget * image;

};


#define I_VIEWER_WINDOW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), I_TYPE_VIEWER_WINDOW, IViewerWIndowPrivate))

G_DEFINE_TYPE (IViewerWIndow, i_viewer_window, GTK_TYPE_WINDOW);


static void
i_viewer_window_init (IViewerWIndow * self) {
	IViewerWIndowPrivate * priv = G_TYPE_INSTANCE_GET_PRIVATE (self, I_TYPE_VIEWER_WINDOW, IViewerWIndowPrivate);
	
    /*GdkPixbuf * pb;
    GError * error = NULL;*/
	gtk_window_set_title (GTK_WINDOW (self), "ImageViewer");
	gtk_window_set_default_size (GTK_WINDOW (self), 640, 480);

	priv->HeaderBar = i_viewer_header_bar_new ();

	gtk_window_set_titlebar (GTK_WINDOW (self), priv->HeaderBar);

    priv->box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);

    /*priv->image = gtk_image_new ();
    pb = gdk_pixbuf_new_from_file ("bla.jpg", &error);
    pb = gdk_pixbuf_scale_simple (GDK_PIXBUF(pb), 540, 380, GDK_INTERP_BILINEAR);
    gtk_image_set_from_pixbuf (GTK_IMAGE (priv->image), pb);
    
    gtk_box_pack_start (GTK_BOX(priv->box), priv->image, TRUE, TRUE, 5);*/

    gtk_container_add (GTK_CONTAINER (self), priv->box);


	i_viewer_window_connect_all_signals (self);
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


// methods ::
void
i_viewer_window_connect_all_signals (IViewerWIndow * self) {
	IViewerWIndowPrivate * priv =  I_VIEWER_WINDOW_GET_PRIVATE (self);

	g_signal_connect (i_viewer_header_bar_get_exititem (I_VIEWER_HEADER_BAR (priv->HeaderBar)),
                     "activate", G_CALLBACK (i_viewer_exit_callback),
                     self);

	g_signal_connect (i_viewer_header_bar_get_openitem (I_VIEWER_HEADER_BAR (priv->HeaderBar)), 
                      "activate", G_CALLBACK (i_viewer_open_callback),
                      self);

	g_signal_connect (priv->HeaderBar, "move-focus", G_CALLBACK (i_viewer_focus), NULL);
	g_signal_connect (self, "destroy", G_CALLBACK(i_viewer_exit_callback), self);
	
}



// callbacks ::
void
i_viewer_exit_callback (GtkWidget * widget, gpointer user_data) {
	gtk_main_quit ();
}
void
i_viewer_open_callback (GtkWidget * widget, gpointer user_data) {
	GtkWidget * dialog;
    GtkWidget * wrn_dialog;



    GdkPixbuf * pb;
    GError * error;

    const gchar * filename;

  	GtkResponseType asw;

	IViewerWIndowPrivate * priv = I_VIEWER_WINDOW_GET_PRIVATE (I_VIEWER_WINDOW (user_data));
	
	dialog = gtk_file_chooser_dialog_new ("Open File",
										 NULL,
										 GTK_FILE_CHOOSER_ACTION_OPEN,
										 "CANCEL", GTK_RESPONSE_CANCEL,
                                         "OPEN", GTK_RESPONSE_OK,
										 NULL);
										 
	gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER(dialog), "/home/userx");
	
	asw = gtk_dialog_run (GTK_DIALOG (dialog));
	
	if (asw == GTK_RESPONSE_OK) {
		
        filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));

        error = NULL;
		pb = gdk_pixbuf_new_from_file_at_size (filename, 640, 480, &error);
        if (pb == NULL) {
            wrn_dialog = gtk_message_dialog_new (GTK_WINDOW (dialog),
                                                GTK_DIALOG_DESTROY_WITH_PARENT|GTK_DIALOG_USE_HEADER_BAR,
                                                GTK_MESSAGE_WARNING, 
                                                GTK_BUTTONS_OK,
                                                error->message, NULL);
            gtk_dialog_run (GTK_DIALOG (wrn_dialog));

        }
        priv->image = gtk_image_new_from_pixbuf (GDK_PIXBUF (pb));
        gtk_box_pack_start (GTK_BOX (priv->box), priv->image, TRUE, TRUE, 5);
        gtk_widget_show_all (priv->box);

	} 

    gtk_widget_destroy (dialog);
	
}

void
i_viewer_focus (GtkWidget * widget, gpointer user_data) {
	g_print ("Focus\n");
}
