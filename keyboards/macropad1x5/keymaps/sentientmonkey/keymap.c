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

const rgblight_segment_t PROGMEM media_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 4, HSV_GREEN}
);

const rgblight_segment_t PROGMEM zoom_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 4, HSV_CYAN}
);

const rgblight_segment_t PROGMEM meet_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 4, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    media_layer,
    zoom_layer,
    meet_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _Media));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _Zoom));
    rgblight_set_layer_state(3, layer_state_cmp(state, _Meet));
    return state;
}
