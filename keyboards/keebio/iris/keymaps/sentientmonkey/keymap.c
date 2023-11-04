#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LCTL,LT(_RAISE,KC_A), KC_S, KC_D,   KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT, LCAG(KC_NO),RGB_MOD,        RGB_TOG, LCAG(KC_NO), MO(_LOWER), KC_MINS, KC_QUOT, KC_ENT,  KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LSFT, KC_BSPC, KC_LCTL,                   KC_RALT,  KC_SPC, MO(_LOWER)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TAB,  KC_EXLM,  KC_AT,   KC_UP,  KC_LCBR, KC_RCBR,                            KC_PGUP,  KC_7,    KC_8,    KC_9,    KC_ASTR, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                             KC_PGDN,  KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                             KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV, TG(_RAISE), _______, KC_LGUI, KC_LSFT, KC_NO,   KC_NO,            KC_NO,  KC_RCBR, _______,  KC_DOT,  KC_0,    KC_EQL,  KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LSFT, KC_BSPC, KC_LCTL,                  KC_RALT,  KC_SPC, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TAB,  KC_INS,  KC_HOME,   KC_UP,   KC_END, KC_PGUP,                            KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_DEL, KC_LEFT,  KC_DOWN,KC_RGHT, KC_PGDN,                             KC_DOWN,  KC_F4,   KC_F5,   KC_F6,   KC_F11, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_NO,   KC_VOLU, KC_NO,    KC_NO,    QK_BOOT,                           KC_RSFT,  KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_NO, KC_NO,             _______, TO(_QWERTY),TO(_QWERTY),KC_PSCR,KC_SCRL, KC_PAUS, KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_BSPC, KC_LCTL,                   KC_RALT, KC_SPC,  TO(_QWERTY)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable_noeeprom();
  rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
}

// Initialize rgblight
/*
void keyboard_post_init_user(void) {
        rgblight_enable_noeeprom();
        //rgblight_mode_noeeprom(RGBLIGHT_DEFAULT_MODE);
        layer_state_set_user(layer_state);
        uint16_t user_hue = rgblight_get_hue();
        for (uint16_t i = 0; i < 256; ++i) {
                rgblight_sethsv_noeeprom( (i + user_hue) % 256, 255, 255);
                wait_ms(5);
        }
        layer_state_set_user(layer_state);
};

// Turn on RGB underglow according to active layer
uint32_t layer_state_set_user(uint32_t state) {
        switch (biton32(state)) {
                case _QWERTY: rgblight_sethsv_noeeprom(HSV_GREEN); break;
                case _LOWER: rgblight_sethsv_noeeprom(HSV_BLUE); break;
                case _RAISE: rgblight_sethsv_noeeprom(HSV_RED); break;
                default: rgblight_sethsv_noeeprom(HSV_WHITE); break;
        }
        return state;
};
*/
