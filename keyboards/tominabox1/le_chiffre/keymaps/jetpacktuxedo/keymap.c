#include QMK_KEYBOARD_H

#define KC_NUM_SPC LT(1, KC_SPC)
#define KC_SYM_BSP LT(2, KC_BSPC)
#define KC_LSZ LSFT_T(KC_Z)
#define KC_RSS RSFT_T(KC_SLSH)

#define KC_CA LCTL_T(KC_A)
#define KC_GS LGUI_T(KC_S)
#define KC_AD LALT_T(KC_D)

#define KC_CENT RCTL_T(KC_ENT)
#define KC_GL RGUI_T(KC_L)
#define KC_AK RALT_T(KC_K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q,   KC_W,  KC_E,    KC_R, KC_T, KC_ESC, KC_Y, KC_U,  KC_I,    KC_O,   KC_P,
    KC_CA,  KC_GS, KC_AD,   KC_F, KC_G,          KC_H, KC_J,  KC_AK,   KC_GL,  KC_CENT,
    KC_LSZ, KC_X,  KC_C,    KC_V, KC_B,          KC_N, KC_M,  KC_COMM, KC_DOT, KC_RSS,
                   KC_LCTL, KC_SYM_BSP,          KC_NUM_SPC,  TG(3)
  ),

  [1] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT, KC_TRNS,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS,
                      KC_TRNS,      KC_DEL,                   KC_TRNS,     KC_TRNS
  ),

  [2] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TILD, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_UNDS, KC_PLUS, KC_COLN, KC_DQUO, KC_TRNS,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_QUES,
                      KC_TRNS,     KC_TRNS,                   KC_TAB,       KC_TRNS
  ),

  [3] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,   RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,
    KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS, KC_LALT,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS,      KC_SPC,                  KC_TRNS,     KC_TRNS
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
	if (IS_LAYER_ON(3)) {
            if (clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
	} else {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
	}
    }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  // This screen is 5 characters wide
  oled_write_ln_P(PSTR("Le   "), false);
  oled_write_ln_P(PSTR("Chiff"), false);
  oled_write_ln_P(PSTR("  -re"), false);

  oled_write_ln_P(PSTR("Layer"), false);
  switch (get_highest_layer(layer_state)) {
    case 0:
      oled_write_ln_P(PSTR("Base "), false);
      break;
    case 1:
      oled_write_ln_P(PSTR("Num  "), false);
      break;
    case 2:
      oled_write_ln_P(PSTR("Sym  "), false);
      break;
    case 3:
      oled_write_ln_P(PSTR("GAMIN"), false);
      break;
    default:
      oled_write_ln_P(PSTR("WTF?!"), false);
      break;
  }

  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_ln_P(led_state.num_lock    ? PSTR("NUMLK") : PSTR("     "), false);
  oled_write_ln_P(led_state.caps_lock   ? PSTR("CAPLK") : PSTR("     "), false);
  oled_write_ln_P(led_state.scroll_lock ? PSTR("SCRLK") : PSTR("     "), false);
}
#endif
