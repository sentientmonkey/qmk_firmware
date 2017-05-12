/* Copyright 2021 Leon Stubbig <leonskeyboards@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _Media,
    _BL,
    _Extra,
    _Extra2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_Media] = LAYOUT(
        KC_MUTE, KC_1, KC_2, KC_3, KC_4
    ),
    [_BL] = LAYOUT(
        BL_BRTG, _______, _______, _______, BL_TOGG
    ),
    [_Extra] = LAYOUT(
        _______, _______, _______, _______, _______
    ),
    [_Extra2] = LAYOUT(
        _______, _______, _______, _______, _______
    ),
};

// #ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (!clockwise) {
        tap_code(KC_VOLD);
    } else {
        tap_code(KC_VOLU);
    }
    return true;
}
// #endif