// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTZ_MAC,
    _QWERTZ_LIN,
    _LOWER_LIN,
    _LOWER_MAC,
    _RAISE_MAC,
    _RAISE_LIN,
    _ADJUST
};
enum custom_keycodes {
  QWERTZ_MAC = SAFE_RANGE,
  QWERTZ_LIN,
  LOWER_LIN,
  LOWER_MAC,
  RAISE_MAC,
  RAISE_LIN,
  ADJUST,
};

// ( 
#define M_ONB LSFT(KC_8) 

// )
#define M_CNB LSFT(KC_9)

// {
#define M_OCB LALT(KC_8) 
// }
#define M_CCB LALT(KC_9) 

//
#define M_OSB LALT(KC_5)
#define M_CSB LALT(KC_6)

// <
#define M_OTB KC_GRAVE
// >
#define M_CTB LSFT(KC_GRAVE)

// |
#define M_PIPE LALT(KC_7)
// ~
#define M_TILDE LALT(KC_N)
// Backslash
#define M_BSLS LALT(LSFT(7)) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTZ_MAC] = LAYOUT_ortho_5x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_AUDIO_MUTE,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENTER,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
  KC_LCTL, KC_RALT, KC_LGUI, KC_LALT, LOWER_MAC,   KC_SPC,  KC_SPC,  RAISE_MAC,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER_MAC] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_EQL , KC_DEL,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE_MAC] = LAYOUT_ortho_5x12(
  _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  KC_CIRC ,  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_0),    KC_MINS,   KC_BSLS ,     KC_DEL,
  M_PIPE       ,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,    _______,
  M_TILDE,      M_BSLS ,    M_OTB  ,    M_OSB  ,    M_OCB  ,    M_ONB  ,    M_CNB  ,    M_CCB  ,    M_CSB  ,    M_CTB  ,    _______,    _______,
  _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MPLY
),

  
[_QWERTZ_LIN] = LAYOUT_ortho_5x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_AUDIO_MUTE,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_A,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENTER,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
  KC_LCTL, KC_RALT, KC_LGUI, KC_LALT, LOWER_LIN,   KC_SPC,  KC_SPC,  RAISE_LIN,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
 
[_LOWER_LIN] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_EQL , KC_DEL,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),
[_RAISE_LIN] = LAYOUT_ortho_5x12(
  _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  KC_CIRC ,  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_0),    KC_MINS,   KC_BSLS ,     KC_DEL,
  M_PIPE       ,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,    _______,
  M_TILDE,      M_BSLS ,    M_OTB  ,    M_OSB  ,    M_OCB  ,    M_ONB  ,    M_CNB  ,    M_CCB  ,    M_CSB  ,    M_CTB  ,    _______,    _______,
  _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MPLY
),
[_ADJUST] =  LAYOUT_ortho_5x12(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, QK_BOOT, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  QWERTZ_MAC, _______,  _______, _______,
  _______, _______, _______, _______, QWERTZ_LIN, _______, _______, QWERTZ_MAC, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTZ_LIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTZ_LIN);
      }
      return false;
      break;
    case QWERTZ_MAC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTZ_MAC);
      }
      return false;
      break;
    case LOWER_MAC:
      if (record->event.pressed) {
        layer_on(_LOWER_MAC);
        update_tri_layer(_LOWER_MAC, _RAISE_MAC, _ADJUST);
      } else {
        layer_off(_LOWER_MAC);
        update_tri_layer(_LOWER_MAC, _RAISE_MAC, _ADJUST);
      }
      return false;
      break;
    case LOWER_LIN:
      if (record->event.pressed) {
        layer_on(_LOWER_LIN);
        update_tri_layer(_LOWER_LIN, _RAISE_LIN, _ADJUST);
      } else {
        layer_off(_LOWER_LIN);
        update_tri_layer(_LOWER_LIN, _RAISE_LIN, _ADJUST);
      }
      return false;
      break;
    case RAISE_MAC:
      if (record->event.pressed) {
        layer_on(_RAISE_MAC);
        update_tri_layer(_LOWER_MAC, _RAISE_MAC, _ADJUST);
      } else {
        layer_off(_RAISE_MAC);
        update_tri_layer(_LOWER_MAC, _RAISE_MAC, _ADJUST);
      }
      return false;
      break;
    case RAISE_LIN:
      if (record->event.pressed) {
        layer_on(_RAISE_LIN);
        update_tri_layer(_LOWER_LIN, _RAISE_LIN, _ADJUST);
      } else {
        layer_off(_RAISE_LIN);
        update_tri_layer(_LOWER_LIN, _RAISE_LIN, _ADJUST);
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

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTZ_MAC] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_RAISE_MAC] = { ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    [_LOWER_MAC] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_QWERTZ_LIN] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_RAISE_LIN] = { ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    [_LOWER_LIN] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_SPI, RGB_SPD), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) }
};
#endif
