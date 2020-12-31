#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    MT(MOD_LCTL, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_UP, KC_SLSH,
    KC_GRV, MO(_FN), KC_LALT, KC_LGUI, KC_SPC, KC_ENT, MO(_FN), KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [_FN] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};
