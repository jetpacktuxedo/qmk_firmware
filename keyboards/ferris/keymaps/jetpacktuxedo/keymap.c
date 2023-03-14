#include QMK_KEYBOARD_H

enum custom_keycodes {
    GIGACRINGE = SAFE_RANGE,
    HUSTLECHEER,
    PUNCHERS,
    MALFOCRINGE,
    HUSTRICK,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case GIGACRINGE:
        if (record->event.pressed) {
            SEND_STRING("thehus1A thehus1B \nthehus1C thehus1D \n");
        } else {
        }
        break;

    case HUSTLECHEER:
        if (record->event.pressed) {
            SEND_STRING("thehus1HUScheer thehus1TLEcheer thehus1CATcheer ");
        } else {
        }
        break;

    case PUNCHERS:
        if (record->event.pressed) {
           SEND_STRING("thehus1PunchersFORREAL "); 
        }
        break;
    case MALFOCRINGE:
        if (record->event.pressed) {
           SEND_STRING("malfO1 malfO2 thehus1A thehus1B \nmalfO3 malfKiss  thehus1C thehus1D \n"); 
        }
        break;
    case HUSTRICK:
        if (record->event.pressed) {
           SEND_STRING("thehus1Taps thehus1HUScheer thehus1TLEcheer thehus1CATcheer thehus1Taps thehus1HUScheer thehus1TLEcheer thehus1CATcheer thehus1Taps \n");
        }
        break;
    }
    return true;
};

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
  [4] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      HUSTRICK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      GIGACRINGE, HUSTLECHEER, PUNCHERS, MALFOCRINGE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS,      KC_TRNS,               KC_TRNS,     KC_TRNS
  ),
};

const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM tild_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_EXLM, KC_AT, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM lshift_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM rshift_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM l3_combo[] = {KC_Z, KC_SLSH, COMBO_END};
const uint16_t PROGMEM l4_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM lsuper_combo[] = {KC_Z, KC_S, COMBO_END};
const uint16_t PROGMEM rsuper_combo[] = {KC_L, KC_SLSH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	COMBO(esc_combo, KC_ESC),
	COMBO(tild_combo, KC_TILD),
	COMBO(grv_combo, KC_GRV),
	COMBO(tab_combo, LT(2, KC_TAB)),
	COMBO(lshift_combo, KC_LSFT),
	COMBO(rshift_combo, KC_RSFT),
	COMBO(bspc_combo, KC_BSPC),
	COMBO(l3_combo, MO(3)),
	COMBO(l4_combo, MO(4)),
	COMBO(lsuper_combo, KC_LGUI),
	COMBO(rsuper_combo, KC_RGUI),
};
