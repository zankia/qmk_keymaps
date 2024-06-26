#include QMK_KEYBOARD_H

enum planck_layers {
  _BASE,
  _MOUSE,
  _NAVIGO,
  _RSYMB,
  _LSYMB,
  _FUNC,
  _NUM,
  _ACCESS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
     MT(KC_NO,KC_Q), MT(KC_NO,KC_W), MT(KC_NO,KC_E),   MT(KC_NO,KC_R),  MT(KC_NO,KC_T), KC_NO, KC_NO, MT(KC_NO,KC_Y), MT(KC_NO,KC_U),  MT(KC_NO,KC_I),  MT(KC_NO,KC_O), MT(KC_NO,KC_P),
     LSFT_T(KC_A),   LT(_NUM,KC_S),  LT(_NAVIGO,KC_D), LT(_LSYMB,KC_F), MT(KC_NO,KC_G), KC_NO, KC_NO, MT(KC_NO,KC_H), LT(_RSYMB,KC_J), LT(_MOUSE,KC_K), LT(_FUNC,KC_L), LSFT_T(KC_SCLN),
     MT(KC_NO,KC_Z), LCTL_T(KC_X),   LALT_T(KC_C),     MT(KC_NO,KC_V),  MT(KC_NO,KC_B), KC_NO, KC_NO, MT(KC_NO,KC_N), MT(KC_NO,KC_M),  LALT_T(KC_COMM), LCTL_T(KC_DOT), MT(KC_NO,KC_SLSH),
     KC_NO,          KC_NO,          KC_NO,            LGUI_T(KC_SPC),  KC_BSPC,  MO(_ACCESS), KC_NO, SC_SENT,        RALT_T(KC_TAB),  KC_NO,           KC_NO,          KC_NO
  ),
  [_MOUSE] = LAYOUT_planck_grid(
    KC_TRNS, KC_BTN2,       KC_MS_U,  KC_BTN1,  KC_BTN3,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_MS_L,       KC_MS_D,  KC_MS_R,  KC_WH_U,     KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1,  KC_NO,        KC_BTN2, KC_TRNS,
    KC_TRNS, KC_WH_L,       KC_TRNS,  KC_WH_R,  KC_WH_D,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS
  ),
  [_NAVIGO] = LAYOUT_planck_grid(
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,  KC_UP,        KC_END,  KC_TRNS,
    KC_TRNS, LSFT(KC_LGUI), KC_NO,    KC_LGUI,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_PGUP, KC_LEFT,  KC_DOWN,      KC_RIGHT,KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS
  ),
  [_RSYMB] = LAYOUT_planck_grid(
    KC_GRV,  KC_BSLS,       KC_LPRN,  KC_RPRN,  KC_PSLS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_CIRC, KC_DLR,        KC_UNDS,  KC_PLUS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_MINUS, KC_EQUAL, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS
  ),
  [_LSYMB] = LAYOUT_planck_grid(
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_NO,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS
  ),
  [_FUNC] = LAYOUT_planck_grid(
    KC_TRNS, KC_F7,         KC_F8,    KC_F9,    KC_F10,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F4,         KC_F5,    KC_F6,    KC_F11,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LALT), KC_NO,   KC_TRNS,
    KC_TRNS, KC_F1,         KC_F2,    KC_F3,    KC_F12,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS

  ),
  [_NUM] = LAYOUT_planck_grid(
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_QUOT, KC_7,     KC_8,         KC_9,    KC_LBRC,
    KC_TRNS, KC_NO,         KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_PPLS, KC_4,     KC_5,         KC_6,    KC_PAST,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_0,    KC_1,     KC_2,         KC_3,    KC_PEQL,
    KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS
  ),
  [_ACCESS] = LAYOUT_planck_grid(
    KC_ESC,  LSFT(KC_Z),    KC_COMM,  KC_X,     KC_PSCR,     KC_TRNS, KC_TRNS, KC_BRIU, KC_TRNS,  KC_MSTP,      KC_TRNS, RGB_VAI,
    KC_TRNS, KC_PAST,       KC_LBRC,  KC_ENT,   LCTL(KC_I),  KC_TRNS, KC_TRNS, KC_BRID, KC_MPRV,  KC_MPLY,      KC_MNXT, RGB_VAD,
    KC_CAPS, KC_TRNS,       KC_APP,   KC_EXLM, LCTL(KC_DOT), KC_TRNS, KC_TRNS, RGB_HUI, RGB_RMOD, RGB_LTOG,     RGB_MOD, QK_BOOT,
    KC_MUTE, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_DEL,      KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS
  )
};

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
  [_BASE] = {
    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_OFF}, {HSV_OFF}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE},
    {HSV_CYAN},   {HSV_RED},    {HSV_RED},    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_OFF}, {HSV_OFF}, {HSV_PURPLE}, {HSV_RED},    {HSV_RED},    {HSV_RED},    {HSV_CYAN},
    {HSV_PURPLE}, {HSV_CYAN},   {HSV_CYAN},   {HSV_PURPLE}, {HSV_PURPLE}, {HSV_OFF}, {HSV_OFF}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_CYAN},   {HSV_CYAN},   {HSV_PURPLE},
    {HSV_WHITE},  {HSV_OFF},    {HSV_OFF},    {HSV_CYAN},   {HSV_CYAN},   {HSV_RED},            {HSV_CYAN},   {HSV_CYAN},   {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
  },
  [_MOUSE] = {
    {HSV_OFF},    {HSV_CYAN},   {HSV_PURPLE}, {HSV_CYAN},   {HSV_CYAN},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},   {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_CYAN},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},   {HSV_CYAN},   {HSV_RED},    {HSV_CYAN},   {HSV_OFF},
    {HSV_OFF},    {HSV_CYAN},   {HSV_OFF},    {HSV_CYAN},   {HSV_CYAN},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},   {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},     {HSV_OFF},            {HSV_OFF},   {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
  },
  [_NAVIGO] = {
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_CYAN},   {HSV_PURPLE}, {HSV_CYAN},   {HSV_OFF},
    {HSV_OFF},    {HSV_GREEN},  {HSV_RED},    {HSV_CYAN},   {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_CYAN},   {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_CYAN},   {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},            {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
  },
  [_RSYMB] = {
    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_CYAN},   {HSV_CYAN},   {HSV_PURPLE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_CYAN},   {HSV_CYAN},   {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_RED},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_CYAN},   {HSV_CYAN},   {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},            {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
  },
  [_LSYMB] = {
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_RED},    {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},            {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
  },
  [_FUNC] = {
    {HSV_OFF},    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF},    {HSV_CYAN},   {HSV_RED},    {HSV_OFF},
    {HSV_OFF},    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},            {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
  },
  [_NUM] = {
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_CYAN},   {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_CYAN},
    {HSV_OFF},    {HSV_RED},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_CYAN},   {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_CYAN},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_CYAN},
    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},            {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
  },
  [_ACCESS] = {
    {HSV_CYAN},   {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_GREEN},  {HSV_OFF}, {HSV_OFF}, {HSV_GREEN},  {HSV_OFF},    {HSV_PURPLE}, {HSV_OFF},    {HSV_ORANGE},
    {HSV_OFF},    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_CYAN},   {HSV_GREEN},  {HSV_OFF}, {HSV_OFF}, {HSV_GREEN},  {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_ORANGE},
    {HSV_CYAN},    {HSV_OFF},    {HSV_CYAN},   {HSV_PURPLE}, {HSV_GREEN},  {HSV_OFF}, {HSV_OFF}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_WHITE},
    {HSV_WHITE},  {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_CYAN},   {HSV_RED},            {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
  },
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color(i, 0, 0, 0);
    } else {
        float f = (float) rgb_matrix_get_val() / UINT8_MAX;
        if (i == 36) {
            f = 1;
        } else if (i == 41) {
            f /= 4;
        }
        RGB rgb = hsv_to_rgb( hsv );
        rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  uint8_t current_layer = get_highest_layer(layer_state);
  if (current_layer >= sizeof(ledmap)) {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  } else {
      set_layer_color(current_layer);
  }
  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        switch (get_highest_layer(layer_state)) {
            case _MOUSE:
                register_code(KC_LGUI);
                tap_code(KC_RIGHT);
                unregister_code(KC_LGUI);
                break;
            case _ACCESS:
                tap_code(KC_VOLU);
                break;
            default:
                tap_code(KC_MS_WH_RIGHT);
        }
    } else { // anti clockwise
        switch (get_highest_layer(layer_state)) {
            case _MOUSE:
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LGUI);
                break;
            case _ACCESS:
                tap_code(KC_VOLD);
                break;
            default:
                tap_code(KC_MS_WH_LEFT);
        }
    }
    return false;
}
#endif
