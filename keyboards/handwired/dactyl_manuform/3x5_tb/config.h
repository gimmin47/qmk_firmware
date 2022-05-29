/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define PRODUCT_ID 0x3436
#define DEVICE_VER 0x0001
#ifdef MANUFACTURER
 #undef MANUFACTURER
#endif
#define MANUFACTURER    Gimmin
#define PRODUCT         Charydbis Nano TrackBall (3x5+TB)

// Communication
#define USE_SERIAL

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

// row-driven
#define MATRIX_ROW_PINS { F0, B6, F6, F5 }
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5, B7, D5, C7, F1 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#undef LOCKING_RESYNC_ENABLE

#define PERMISSIVE_HOLD
