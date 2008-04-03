/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2008 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
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
 */

#ifndef __PK_NOTIFY_H
#define __PK_NOTIFY_H

#include <glib-object.h>
#include "pk-enum.h"
#include "pk-enum-list.h"
#include "pk-package-list.h"

G_BEGIN_DECLS

#define PK_TYPE_NOTIFY		(pk_notify_get_type ())
#define PK_NOTIFY(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), PK_TYPE_NOTIFY, PkNotify))
#define PK_NOTIFY_CLASS(k)	(G_TYPE_CHECK_CLASS_CAST((k), PK_TYPE_NOTIFY, PkNotifyClass))
#define PK_IS_NOTIFY(o)	 	(G_TYPE_CHECK_INSTANCE_TYPE ((o), PK_TYPE_NOTIFY))
#define PK_IS_NOTIFY_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), PK_TYPE_NOTIFY))
#define PK_NOTIFY_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), PK_TYPE_NOTIFY, PkNotifyClass))
#define PK_NOTIFY_ERROR	 	(pk_notify_error_quark ())

typedef struct _PkNotifyPrivate		PkNotifyPrivate;
typedef struct _PkNotify		PkNotify;
typedef struct _PkNotifyClass		PkNotifyClass;

struct _PkNotify
{
	GObject		 parent;
	PkNotifyPrivate	*priv;
};

struct _PkNotifyClass
{
	GObjectClass	parent_class;
	/* signals */
	void		(* updates_changed)		(PkNotify	*notify);
	void		(* repo_list_changed)		(PkNotify	*notify);
	void		(* restart_schedule)		(PkNotify	*notify);
	/* padding for future expansion */
	void (*_pk_reserved1) (void);
	void (*_pk_reserved2) (void);
	void (*_pk_reserved3) (void);
	void (*_pk_reserved4) (void);
	void (*_pk_reserved5) (void);
};

GType		 pk_notify_get_type			(void) G_GNUC_CONST;
PkNotify	*pk_notify_new				(void);

G_END_DECLS

#endif /* __PK_NOTIFY_H */

