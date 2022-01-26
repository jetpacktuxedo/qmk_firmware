#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,          KC_Y, KC_U,  KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J,  KC_K,    KC_L,   LT(2, KC_ENT),
    KC_Z, KC_X, KC_C, KC_V, KC_B,          KC_N, KC_M,  KC_COMM, KC_DOT, KC_SLSH,
         KC_LCTL, LT(1, KC_BSPC),          LT(1, KC_SPC),  KC_RALT
  ),

  [1] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT, KC_TRNS,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS,
                      KC_TRNS,      KC_DEL,                   KC_TRNS,     KC_TRNS
  ),

  [2] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_UNDS, KC_PLUS, KC_COLN, KC_DQUO, KC_TRNS,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_QUES,
                      KC_TRNS,     KC_TRNS,                   KC_TAB,       KC_TRNS
  ),

  [3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
    RGB_SAD, RGB_SAI, KC_TRNS, KC_TRNS, RGB_HUD,      RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, RGB_VAD, RGB_VAI, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS,      KC_TRNS,               KC_TRNS,     KC_TRNS
  ),
};

const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM lshift_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM rshift_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM l3_combo[] = {KC_Z, KC_SLSH, COMBO_END};
const uint16_t PROGMEM lsuper_combo[] = {KC_Z, KC_S, COMBO_END};
const uint16_t PROGMEM rsuper_combo[] = {KC_L, KC_SLSH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	COMBO(esc_combo, KC_ESC),
	COMBO(tab_combo, LT(2, KC_TAB)),
	COMBO(lshift_combo, KC_LSFT),
	COMBO(rshift_combo, KC_RSFT),
	COMBO(bspc_combo, KC_BSPC),
	COMBO(l3_combo, MO(3)),
	COMBO(lsuper_combo, KC_LGUI),
	COMBO(rsuper_combo, KC_RGUI),
};
