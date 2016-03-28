/*
Copyright 2016 Fred Sundvik <fsundvik@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

#include "print.h"

static GFXINLINE void init_board(GDisplay *g) {
    (void) g;
}

static GFXINLINE void post_init_board(GDisplay *g) {
	(void) g;
}

static GFXINLINE void write_cmd(GDisplay *g, uint8_t cmd) {
	(void) g;
	(void) cmd;
}

static GFXINLINE void write_data(GDisplay *g, uint8_t* data, uint16_t length) {
	(void) g;
	(void) data;
	(void) length;
}

#endif /* _GDISP_LLD_BOARD_H */
