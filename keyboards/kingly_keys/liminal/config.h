/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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
#define VENDOR_ID       0x1337
#define PRODUCT_ID      0x6017
#define DEVICE_VER      0x0001
#define MANUFACTURER    Kingly-Keys
#define PRODUCT         liminal
#define DESCRIPTION     A 45% keyboard with superb keycap compatibility.

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { C6, B6, B7, C7 }
#define MATRIX_COL_PINS { D6, C4, D3, D2, D1, D0, C2, B0, B1, B2, B3, B4, D5, C5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define PERMISSIVE_HOLD

#define TAPPING_TERM 200

#define TAPPING_TERM_PER_KEY

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D4
#define RGBLED_NUM 1   // Number of LEDs

#define RGBLIGHT_HUE_STEP 6
#define RGBLIGHT_SAT_STEP 4
#define RGBLIGHT_VAL_STEP 4