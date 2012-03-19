/*
 * Copyright (C) 2010-2012 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Written By: Gal Hammer <ghammer@redhat.com>
 * Base on code written by: Ray Strode <rstrode@redhat.com>
 *
 */

#include "gdm-ovirtcred-extension.h"

#include <gio/gio.h>
#include <gtk/gtk.h>

GdmGreeterExtension *
gdm_greeter_plugin_get_extension (void)
{
        static GObject *extension;

        if (extension != NULL) {
                g_object_ref (extension);
        } else {
                extension = g_object_new (GDM_TYPE_OVIRTCRED_EXTENSION, NULL);
                g_object_add_weak_pointer (extension, (gpointer *) &extension);
        }

        return GDM_GREETER_EXTENSION (extension);
}
