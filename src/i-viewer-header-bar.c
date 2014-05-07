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

struct _IViewerHeaderBarPrivate {
     GtkWidget * MSettings;

     GtkWidget * OpenItem;
     GtkWidget * ExitItem;
	 
};


#define I_VIEWER_HEADER_BAR_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), I_TYPE_VIEWER_HEADER_BAR, IViewerHeaderBarPrivate))


G_DEFINE_TYPE (IViewerHeaderBar, i_viewer_header_bar, GTK_TYPE_HEADER_BAR);


static void
i_viewer_header_bar_init (IViewerHeaderBar * self) {
	GtkWidget * Menu;
	
	IViewerHeaderBarPrivate * priv = I_VIEWER_HEADER_BAR_GET_PRIVATE (self);

	Menu = gtk_menu_new ();
	
	priv->OpenItem = gtk_menu_item_new_with_mnemonic ("_Open");
	priv->ExitItem = gtk_menu_item_new_with_mnemonic ("_Exit");
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), priv->OpenItem);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), priv->ExitItem);
	

	priv->MSettings = gtk_menu_button_new ();
	gtk_menu_button_set_popup (GTK_MENU_BUTTON (priv->MSettings), Menu);
	gtk_button_set_image (GTK_BUTTON (priv->MSettings),
	                           gtk_image_new_from_icon_name ("emblem-system-symbolic",
	                                                         GTK_ICON_SIZE_MENU));

	gtk_header_bar_set_show_close_button (GTK_HEADER_BAR (self), TRUE);
	gtk_header_bar_set_title (GTK_HEADER_BAR (self), "ImageViewer");
	gtk_header_bar_set_subtitle (GTK_HEADER_BAR (self), "First Project - (0.1)");
	gtk_header_bar_set_has_subtitle (GTK_HEADER_BAR (self), TRUE);

	gtk_header_bar_pack_end ( GTK_HEADER_BAR (self), priv->MSettings);

	gtk_widget_show_all (Menu);
	
}

static void
i_viewer_header_bar_finalize (GObject * object) {
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (i_viewer_header_bar_parent_class)->finalize (object);
}

static void
i_viewer_header_bar_class_init (IViewerHeaderBarClass * klass) {
	GObjectClass* object_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (IViewerHeaderBarPrivate));

	object_class->finalize = i_viewer_header_bar_finalize;
}

GtkWidget *
i_viewer_header_bar_new (void) {
	return GTK_WIDGET (g_object_new (I_TYPE_VIEWER_HEADER_BAR, NULL));
}


// Methods :: Getters and setters ::
GtkWidget * 
i_viewer_header_bar_get_openitem (IViewerHeaderBar * self) {
	IViewerHeaderBarPrivate * priv = I_VIEWER_HEADER_BAR_GET_PRIVATE (self);

	return priv->OpenItem;
}

GtkWidget *
i_viewer_header_bar_get_exititem (IViewerHeaderBar * self){
	IViewerHeaderBarPrivate * priv = I_VIEWER_HEADER_BAR_GET_PRIVATE (self);

	return priv->ExitItem;
}

