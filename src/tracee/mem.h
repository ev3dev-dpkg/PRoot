/* -*- c-set-style: "K&R"; c-basic-offset: 8 -*-
 *
 * This file is part of PRoot.
 *
 * Copyright (C) 2010, 2011, 2012 STMicroelectronics
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA.
 */

#ifndef TRACEE_MEM_H
#define TRACEE_MEM_H

#include <limits.h>    /* PATH_MAX, */
#include <sys/types.h> /* pid_t, size_t, */

#include "arch.h" /* word_t, */
#include "tracee/info.h"

extern int write_data(const struct tracee_info *tracee, word_t dest_tracee, const void *src_tracer, word_t size);
extern int read_data(const struct tracee_info *tracee, void *dest_tracer, word_t src_tracee, word_t size);
extern int read_string(const struct tracee_info *tracee, char *dest_tracer, word_t src_tracee, word_t max_size);
extern word_t peek_mem(const struct tracee_info *tracee, word_t address);
extern void poke_mem(const struct tracee_info *tracee, word_t address, word_t value);

#endif /* TRACEE_MEM_H */
