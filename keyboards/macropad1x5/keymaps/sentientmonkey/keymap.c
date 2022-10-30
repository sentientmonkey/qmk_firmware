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
    _Zoom,
    _Meet,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_Media] = LAYOUT_FLIPPED_1x4(
        TO(_Zoom), KC_MNXT, KC_MUTE, KC_MPLY
    ),
    [_Zoom] = LAYOUT_FLIPPED_1x4(
        TO(_Meet), LSG(KC_V), LSG(KC_A), LGUI(KC_Q)
    ),
    [_Meet] = LAYOUT_FLIPPED_1x4(
        TO(_Media), LGUI(KC_E), LGUI(KC_D), LGUI(KC_W)
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _Media:
      backlight_level(3);
      break;
    case _Zoom:
      backlight_level(2);
      break;
    case _Meet:
      backlight_level(1);
      break;
  }
  return state;
}
