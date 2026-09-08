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
     KC_Q,         KC_W,              KC_E,              KC_R,            KC_T,     KC_NO,       KC_NO, KC_Y,    KC_U,            KC_I,            KC_O,           KC_P,
     LSFT_T(KC_A), LT(_NUM,KC_S),     LT(_NAVIGO,KC_D),  LT(_LSYMB,KC_F), KC_G,     MS_WHLU,     KC_NO, KC_H,    LT(_RSYMB,KC_J), LT(_MOUSE,KC_K), LT(_FUNC,KC_L), LSFT_T(KC_SCLN),
     KC_Z,         LCTL_T(KC_X),      LALT_T(KC_C),      KC_V,            KC_B,     MS_WHLD,     KC_NO, KC_N,    KC_M,            LALT_T(KC_COMM), LCTL_T(KC_DOT), KC_SLSH,
     LGUI(KC_U),   QK_MOUSE_BUTTON_2, QK_MOUSE_BUTTON_1, LGUI_T(KC_SPC),  KC_BSPC,  MO(_ACCESS), KC_NO, SC_SENT, RALT_T(KC_TAB),  KC_NO,           KC_NO,          KC_NO
  ),
  [_MOUSE] = LAYOUT_planck_grid(
    KC_TRNS, MS_BTN2,       MS_UP,    MS_BTN1,  MS_BTN3,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, MS_LEFT,       MS_DOWN,  MS_RGHT,  MS_WHLU,     KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1,  KC_NO,        MS_BTN2, KC_TRNS,
    KC_TRNS, MS_WHLL,       KC_TRNS,  MS_WHLR,  MS_WHLD,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS,
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
    KC_ESC,  LSFT(KC_Z),    KC_COMM,  KC_X,     KC_PSCR,     KC_TRNS, KC_TRNS, KC_BRIU, KC_TRNS,  KC_MSTP,      KC_TRNS, UG_VALU,
    KC_TRNS, KC_PAST,       KC_LBRC,  KC_ENT,   LCTL(KC_I),  KC_TRNS, KC_TRNS, KC_BRID, KC_MPRV,  KC_MPLY,      KC_MNXT, UG_VALD,
    KC_CAPS, KC_TRNS,       KC_APP,   KC_EXLM,  LCTL(KC_DOT),KC_TRNS, KC_TRNS, UG_HUEU, UG_PREV,TOGGLE_LAYER_COLOR,UG_NEXT,QK_BOOT,
    KC_MUTE, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_DEL,      KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS
  )
};

#ifdef RGB_MATRIX_ENABLE
const hsv_t led_map[][RGB_MATRIX_LED_COUNT] = {
  [_BASE] = {
    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_OFF}, {HSV_OFF},  {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_PURPLE},
    {HSV_CYAN},   {HSV_RED},    {HSV_RED},    {HSV_PURPLE}, {HSV_PURPLE}, {HSV_GREEN},{HSV_OFF}, {HSV_PURPLE}, {HSV_RED},    {HSV_RED},    {HSV_RED},    {HSV_CYAN},
    {HSV_PURPLE}, {HSV_CYAN},   {HSV_CYAN},   {HSV_PURPLE}, {HSV_PURPLE}, {HSV_GREEN},{HSV_OFF}, {HSV_PURPLE}, {HSV_PURPLE}, {HSV_CYAN},   {HSV_CYAN},   {HSV_PURPLE},
    {HSV_WHITE},  {HSV_GREEN},  {HSV_GREEN},  {HSV_CYAN},   {HSV_CYAN},   {HSV_RED},             {HSV_CYAN},   {HSV_CYAN},   {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
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
    {HSV_CYAN},   {HSV_OFF},    {HSV_CYAN},   {HSV_PURPLE}, {HSV_GREEN},  {HSV_OFF}, {HSV_OFF}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_WHITE},
    {HSV_WHITE},  {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_CYAN},   {HSV_RED},            {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF},    {HSV_OFF}
  },
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }

    uint8_t active_layer = get_highest_layer(layer_state);

    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
        hsv_t hsv = led_map[active_layer][i];

        if (hsv.v > rgb_matrix_get_val()) {
            hsv.v = rgb_matrix_get_val();
        }

        rgb_t color = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, color.r, color.g, color.b);
    }

    return false;
}
#endif

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
                tap_code(QK_MOUSE_WHEEL_RIGHT);
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
                tap_code(QK_MOUSE_WHEEL_LEFT);
        }
    }
    return false;
}
#endif
