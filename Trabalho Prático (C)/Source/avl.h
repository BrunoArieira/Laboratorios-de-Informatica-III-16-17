/* Produced by texiweb from libavl.w. */

/* libavl - library for manipulation of binary trees.
   Copyright (C) 1998-2002, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.

   The author may be contacted at <blp@gnu.org> on the Internet, or
   write to Ben Pfaff, Stanford University, Computer Science Dept., 353
   Serra Mall, Stanford CA 94305, USA.
*/

#ifndef AVL_H 
#define AVL_H 1
#endif
typedef struct avl_table * AVL;
typedef struct avl_traverser * TVS;

#include <stddef.h>

/* Function types. */
typedef int avl_comparison_func (const void *, const void *,
                                 void *);
typedef void avl_item_func (void *, void *);
typedef void *avl_copy_func (void *, void *);

#ifndef LIBAVL_ALLOCATOR
#define LIBAVL_ALLOCATOR


/* Default memory allocator. */
extern struct libavl_allocator avl_allocator_default;
void *avl_malloc (struct libavl_allocator *, size_t);
void avl_free (struct libavl_allocator *, void *);

/* Maximum AVL height. */
#ifndef AVL_MAX_HEIGHT
#define AVL_MAX_HEIGHT 32
#endif


/* Table functions. */
AVL avl_create (avl_comparison_func *, void *,
                              struct libavl_allocator *);
AVL avl_copy (const struct avl_table *, avl_copy_func *,
                            avl_item_func *, struct libavl_allocator *);
void avl_destroy (struct avl_table *, avl_item_func *);
void **avl_probe (struct avl_table *, void *);
void *avl_insert (struct avl_table *, void *);
void *avl_replace (struct avl_table *, void *);
void *avl_delete (struct avl_table *, const void *);
void *avl_find (const struct avl_table *, const void *);
void avl_assert_insert (struct avl_table *, void *);
void *avl_assert_delete (struct avl_table *, void *);
int avl_contador(struct avl_table *);

#define avl_count(table) ((size_t) (table)->avl_count)

/* Table traverser functions. */
TVS avl_t_alloc(struct avl_table*);
void avl_t_init (struct avl_traverser *, struct avl_table *);
void *avl_t_first (struct avl_traverser *, struct avl_table *);
void *avl_t_last (struct avl_traverser *, struct avl_table *);
void *avl_t_find (struct avl_traverser *, struct avl_table *, void *);
void *avl_t_insert (struct avl_traverser *, struct avl_table *, void *);
void *avl_t_copy (struct avl_traverser *, const struct avl_traverser *);
void *avl_t_next (struct avl_traverser *);
void *avl_t_prev (struct avl_traverser *);
void *avl_t_cur (struct avl_traverser *);
void *avl_t_replace (struct avl_traverser *, void *);

#endif /* avl.h */
