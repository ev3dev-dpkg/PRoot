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

#ifndef TRACEE_REG_H
#define TRACEE_REG_H

#include "tracee/info.h"
#include "arch.h"

enum reg {
	SYSARG_NUM = 0,
	SYSARG_1,
	SYSARG_2,
	SYSARG_3,
	SYSARG_4,
	SYSARG_5,
	SYSARG_6,
	SYSARG_RESULT,
	STACK_POINTER,

	/* Helpers. */
	REG_FIRST = SYSARG_NUM,
	REG_LAST  = STACK_POINTER,
};

extern int fetch_regs(struct tracee_info *tracee);
extern int push_regs(struct tracee_info *tracee);
extern word_t peek_reg(const struct tracee_info *tracee, enum reg reg);
extern void poke_reg(struct tracee_info *tracee, enum reg reg, word_t value);
extern word_t resize_stack(struct tracee_info *tracee, ssize_t size);

#endif /* TRACEE_REG_H */
