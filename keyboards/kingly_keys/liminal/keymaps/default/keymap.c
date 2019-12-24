#include QMK_KEYBOARD_H
#include "quantum.h"

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _OTHER
};

//Tap Dance Declarations
enum {
  TD_RST = 0,
  TD_DBQT = 1
};

void dance_rst_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    reset_keyboard();
    reset_tap_dance(state);
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_RST] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, NULL, dance_rst_reset),
 [TD_DBQT] = ACTION_TAP_DANCE_DOUBLE (KC_QUOTE, KC_DQT)
};

enum custom_keycodes {
  M_PAR = SAFE_RANGE,
  M_BKT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_PAR:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("()" SS_TAP(X_LEFT));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case M_BKT:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("[]" SS_TAP(X_LEFT));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
return true;

};

#define XXXXX KC_TRNS
#define OTHER MO(_OTHER)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default layer
     * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ BsPc │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │  Enter  │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───────┤
     * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RShift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬──────┘
     * │LCtl│LGui│LAlt│         Space          │RAlt│ Fn │ 
     * └────┴────┴────┴────────────────────────┴────┴────┘ 
     */
    [_QWERTY] = LAYOUT_base_kit(  
        KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_MINUS,  KC_BSPC, 
        KC_PGUP, KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,     KC_ENT,  
        KC_PGDN,  KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,  OTHER,   
        KC_DEL,  KC_DEL, KC_LGUI, KC_LALT,                            LT(_LOWER, KC_SPACE),                    RAISE, KC_MENU, LOWER
    ),

    /* LOWER layer
     * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ BsPc │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │  Enter  │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───────┤
     * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RShift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬──────┘
     * │LCtl│LGui│LAlt│         Space          │RAlt│ Fn │ 
     * └────┴────┴────┴────────────────────────┴────┴────┘ 
     */
    [_LOWER] = LAYOUT_base_kit(  
        KC_GRAVE,  XXXXX, KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_UNDS,  XXXXX, 
        KC_TILD, XXXXX,  KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,  KC_ASTR,  M_PAR,  M_BKT, TD(TD_DBQT),  
        KC_TILD,  XXXXX,     XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,   XXXXX,    XXXXX,  XXXXX,   
        XXXXX,  XXXXX, XXXXX, XXXXX,                            XXXXX,                    XXXXX, XXXXX, XXXXX
    ),

        /* RAISE layer
     * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ BsPc │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │  Enter  │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───────┤
     * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RShift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬──────┘
     * │LCtl│LGui│LAlt│         Space          │RAlt│ Fn │ 
     * └────┴────┴────┴────────────────────────┴────┴────┘ 
     */
    [_RAISE] = LAYOUT_base_kit(  
        XXXXX,  XXXXX,  XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,  KC_EQUAL,  XXXXX, 
        KC_PGUP, KC_CAPS,  XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,     XXXXX,  
        KC_PGDN,  XXXXX,     XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,   KC_LBRC,    KC_RBRC,  XXXXX,   
        KC_PSCR,  XXXXX, XXXXX, XXXXX,                            XXXXX,                    XXXXX, XXXXX, XXXXX
    ),

        /* OTHER layer
     * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ BsPc │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │  Enter  │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───────┤
     * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RShift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬──────┘
     * │LCtl│LGui│LAlt│         Space          │RAlt│ Fn │ 
     * └────┴────┴────┴────────────────────────┴────┴────┘ 
     */
    [_OTHER] = LAYOUT_base_kit(  
        RGB_MOD,  XXXXX,  RGB_VAI,    RGB_HUI,    RGB_SAI,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    KC_UP,  KC_BSLS,  XXXXX, 
        XXXXX,  XXXXX,  RGB_VAD,    RGB_HUD,    RGB_SAD,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    KC_LEFT,    KC_RIGHT,     KC_PIPE,  
        XXXXX,  XXXXX,     XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,   KC_DOWN,    XXXXX,  XXXXX,   
        TD(TD_RST),  XXXXX,      XXXXX,      XXXXX,                            XXXXX,                    XXXXX,       XXXXX,       XXXXX
    )

};

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LT(_LOWER, KC_SPACE):
      return 160;
    case TD(TD_DBQT):
      return 230;
    default:
      return TAPPING_TERM;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_setrgb (RGB_PURPLE);
        break;
    case _RAISE:
        rgblight_setrgb (RGB_CYAN);
        break;
    case _OTHER:
        rgblight_setrgb (RGB_ORANGE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (RGB_CORAL);
        break;
    }
  return state;
}

