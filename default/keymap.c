#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"

#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
};

enum tap_dance_codes {
  DANCE_0,
};

const uint16_t PROGMEM combo0[] = { KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo4[] = { MT(MOD_LCTL, KC_COMMA), MT(MOD_LALT, KC_DOT), COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_H, MT(MOD_LCTL, KC_COMMA), COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo10[] = { MT(MOD_LCTL, KC_X), KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo11[] = { MT(MOD_LCTL, KC_X), KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_LPRN),
    COMBO(combo1, KC_LBRC),
    COMBO(combo2, KC_UNDS),
    COMBO(combo3, KC_MINUS),
    COMBO(combo4, KC_GT),
    COMBO(combo5, KC_LCBR),
    COMBO(combo6, LM(1, MOD_LGUI)),
    COMBO(combo7, LM(1, MOD_LCTL | MOD_LGUI)),
    COMBO(combo8, LCTL(KC_SPACE)),
    COMBO(combo9, LM(1, MOD_LSFT)),
    COMBO(combo10, LM(2, MOD_LALT)),
    COMBO(combo11, LM(2, MOD_LCTL)),
};

const key_override_t paren_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t bracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
const key_override_t brace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, MT(MOD_LALT, KC_DOT), KC_COLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, MT(MOD_LCTL, KC_COMM), KC_SCLN);
const key_override_t angle_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GT, KC_LT);
const key_override_t under_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_PLUS);
const key_override_t mins_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_EQL);
const key_override_t dot_key_override2 = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COMMA);
const key_override_t home_key_override = ko_make_basic(MOD_MASK_ALT, KC_BSPC, KC_HOME);
const key_override_t end_key_override = ko_make_basic(MOD_MASK_ALT, KC_SPC, KC_END);
const key_override_t quit_app = ko_make_basic(MOD_MASK_GUI, KC_Q, LALT(KC_F4));
const key_override_t **key_overrides = (const key_override_t *[]){
    &paren_key_override,
    &bracket_key_override,
    &brace_key_override,
    &dot_key_override,
    &comma_key_override,
    &angle_key_override,
    &under_key_override,
    &mins_key_override,
    &dot_key_override2,
    &home_key_override,
    &end_key_override,
    &quit_app,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_LGUI, KC_MPRV,  KC_MEDIA_PLAY_PAUSE,KC_MNXT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,             LALT(KC_TAB),LALT(KC_INSERT), LSFT(KC_F6),    SGUI(KC_S),         KC_F12, KC_LCTL,
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                        KC_J,           KC_L,       KC_U,           KC_Y,           KC_P,           KC_BSLS,
    KC_ESC,         KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                        KC_M,           KC_N,       KC_E,           KC_I,           KC_O,           KC_QUOTE,
    KC_LSFT,       MT(MOD_LALT, KC_Z),MT(MOD_LCTL, KC_X),KC_C,           KC_D,           KC_V,                  KC_K,           KC_H,       MT(MOD_LCTL, KC_COMMA),MT(MOD_LALT, KC_DOT),MT(MOD_LGUI, KC_SLASH),KC_RSFT,
                                                    KC_BSPC,        LT(1,KC_DELETE),                                LT(2,KC_ENTER), KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                  KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_CAPS,
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_PIPE,        KC_TILD,        KC_GRAVE,                               KC_GRAVE,       KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                KC_PIPE,        KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_PC_CUT,      LCTL(KC_C),     KC_TRANSPARENT, LCTL(LSFT(KC_V)),                            KC_TILD,        KC_1,           KC_2,           KC_3,           KC_SLASH,       TG(3),
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DOT, KC_0
  ),
  [2] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                LGUI(LSFT(KC_LEFT)), ST_MACRO_2,ST_MACRO_3,LGUI(LSFT(KC_RIGHT)), KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_UP),    LGUI(KC_DOWN),  KC_TRANSPARENT,             LGUI(LALT(KC_LEFT)), LGUI(LCTL(KC_LEFT)),LGUI(LCTL(KC_RIGHT)),LGUI(LALT(KC_RIGHT)),KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_LEFT),  LGUI(KC_RIGHT), KC_TRANSPARENT,               KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_RIGHT,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_PC_CUT,      LCTL(KC_C),     KC_TRANSPARENT, LCTL(LSFT(KC_V)),                            LCTL(KC_LEFT),  LALT(KC_DOWN),  LALT(KC_UP),    LCTL(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                   KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                   KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_TRANSPARENT,
    KC_LEFT_CTRL,    KC_A,           KC_S,           KC_D,           KC_F,           KC_X,                                  KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRANSPARENT,
    KC_LEFT_SHIFT,   KC_Z,           KC_V,           KC_C,           KC_G,           KC_B,                                  KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       TG(3),
                                                    KC_SPACE,       KC_LEFT_ALT,                                  KC_ENTER,       KC_BSPC
  ),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_ENTER)) SS_DELAY(100) SS_LSFT(SS_TAP(X_RIGHT)) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_ENTER)) SS_DELAY(100) SS_LSFT(SS_TAP(X_LEFT)) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_ENTER)) SS_DELAY(100) SS_TAP(X_LEFT) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_ENTER)) SS_DELAY(100) SS_TAP(X_RIGHT) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};
