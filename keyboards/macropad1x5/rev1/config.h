/*
Copyright 2020 Leon Stubbig <leonskeyboards@gmail.com>

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

/* USB Device descriptor parameter */
#define DEVICE_VER      0x0003
#undef PRODUCT
#define PRODUCT         Macropad1x5 (rev1)

/* Keyboard Matrix Assignments */
#define DIODE_DIRECTION COL2ROW
#define MATRIX_COL_PINS { D1, D7, E6, B4, B5 }
#define MATRIX_ROW_PINS { F7 }

// encoder
#define ENCODERS_PAD_A { D0 }
#define ENCODERS_PAD_B { D4 }

// backlight
#define BACKLIGHT_PIN C6

// RGB underglow
#define RGB_DI_PIN F6
#define RGBLED_NUM 6
#define RGBLIGHT_ANIMATIONS

// Vial defines
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 1, 4 }
#undef VIAL_KEYBOARD_UID
#define VIAL_KEYBOARD_UID {0x05, 0xE2, 0xE2, 0xAE, 0xF6, 0xED, 0xBE, 0x65}
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, BL_DEC, BL_INC, LCTL(KC_MINUS), LCTL(KC_PLUS), KC_TRNS, KC_TRNS }
#define VIAL_TAP_DANCE_ENTRIES 4

