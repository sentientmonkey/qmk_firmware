/*
Copyright 2021 Leon Stubbig <leonskeyboards@gmail.com>

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
#define VENDOR_ID       0x0801
#define PRODUCT_ID      0x1133
#define MANUFACTURER    LS Keyboards
#define PRODUCT         Macropad1x5
#define DESCRIPTION     1x5 Macropad with Rotary Encoder

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 5

// layer toggle TT()
#define TAPPING_TOGGLE 3

// encoder
#define ENCODER_RESOLUTION 4

// backlight
#define BACKLIGHT_LEVELS 10
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 6

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Vial defines*/
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 1, 4 }
#define VIAL_KEYBOARD_UID {0xEE, 0x91, 0x12, 0x24, 0x66, 0xD4, 0x4F, 0x2B}  // redefined for each revision
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, BL_DEC, BL_INC, LCTL(KC_MINUS), LCTL(KC_PLUS), KC_TRNS, KC_TRNS }
