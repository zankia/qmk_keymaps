#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
};


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    LT(_RAISE, KC_Q),KC_W,           KC_E,           KC_R,           KC_T,           KC_CAPS,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,
    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_ESCAPE,      KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
    MT(MOD_LSFT, KC_Z),KC_X,           KC_C,           KC_V,           MT(MOD_LALT, KC_B),KC_TAB,         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       MT(MOD_RCTL, KC_RBRC),
    KC_LEFT_CTRL,   LOWER,          KC_LEFT_GUI,    KC_SPACE,       KC_BSPC,        MT(MOD_RSFT, KC_ENTER),KC_NO,          MT(MOD_RALT, KC_APPLICATION),KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
  ),

  [_LOWER] = LAYOUT_planck_grid(
    LT(_RAISE, KC_GRAVE),KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_DELETE,
    KC_PSCR,        KC_TRANSPARENT, KC_HOME,        KC_LPRN,        KC_RPRN,        KC_PAGE_UP,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLS,
    LALT(LCTL(KC_DELETE)),KC_TRANSPARENT, KC_END,         LSFT(KC_MINUS), LSFT(KC_EQUAL), KC_PGDN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_STOP,  KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,       KC_EQUAL,       KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_F15,         KC_F7,          KC_F8,          KC_F9,          TO(4),          KC_NUM,         KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_SLASH,    KC_SYSTEM_POWER,
    KC_TRANSPARENT, KC_F14,         KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_ASTERISK, KC_SYSTEM_SLEEP,
    KC_TRANSPARENT, KC_F13,         KC_F1,          KC_F2,          KC_F3,          LCTL(KC_I),     LCTL(KC_DOT),   KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_MINUS,    KC_SYSTEM_WAKE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_NO,          KC_KP_0,        KC_TRANSPARENT, KC_KP_DOT,      KC_KP_PLUS,     KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, AU_TOGG,        MU_TOGG,        MU_NEXT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, LED_LEVEL,      RGB_MODE_FORWARD,RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER4] = LAYOUT_planck_grid(
    KC_4,           KC_M,           LSFT(KC_COMMA), KC_P,           KC_Y,           TO(0),          KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           LSFT(KC_DOT),
    KC_Q,           KC_O,           KC_E,           KC_U,           KC_I,           KC_TRANSPARENT, KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_6,
    KC_COMMA,       KC_A,           KC_J,           KC_K,           KC_X,           KC_TRANSPARENT, KC_B,           KC_SCLN,        KC_Z,           KC_V,           KC_W,           KC_EQUAL,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          MO(5),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER5] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_0,           ST_MACRO_0,     KC_2,           ST_MACRO_1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_QUOTE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {129,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {178,255,255} },

    [1] = { {0,255,255}, {178,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {178,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {178,255,255}, {0,0,0}, {178,255,255}, {86,255,255}, {0,0,0}, {129,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {178,255,255}, {86,255,255}, {0,0,0}, {129,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {178,255,255}, {0,0,0}, {129,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {178,255,255}, {178,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {178,255,255}, {178,255,255}, {129,255,255} },

    [2] = { {0,255,255}, {129,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {0,255,255}, {86,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {22,255,255}, {0,0,0}, {129,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {0,0,0}, {0,0,0}, {178,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {22,255,255}, {0,0,0}, {129,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {86,255,255}, {86,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {129,255,255}, {86,255,255}, {0,0,0}, {0,255,255}, {178,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {178,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {0,0,0} },

    [3] = { {0,255,255}, {0,0,0}, {86,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {178,255,255}, {178,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {178,255,255}, {129,255,255}, {0,0,0}, {129,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {178,255,255}, {178,255,255}, {0,0,0}, {129,255,255}, {178,255,255}, {178,255,255}, {178,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(100) SS_TAP(X_O));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(100) SS_TAP(X_U));
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

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



