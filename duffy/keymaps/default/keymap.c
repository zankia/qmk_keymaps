// Copyright 2026 zankia mail@zankia.fr
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"
#include "sendstring_dvorak.h"

enum layer_names {
    _DEFAULT,
    _MEDIA,
    _DRAWING,
    _MODELING,
    _GAMING,
    _STREAMING,
    _SELECTOR,
};

enum custom_keycodes {
    UPLOAD = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        MO(_SELECTOR),               KC_MUTE,
        KC_PGUP,       MS_BTN3,      KC_APP,
        KC_PGDN,       KC_HOME,      KC_END
    ),
    [_MEDIA] = LAYOUT(
        KC_TRNS,                     KC_TRNS,
        KC_MSEL,       KC_MSTP,      KC_TRNS,
        KC_MPRV,       KC_MPLY,      KC_MNXT
    ),
    [_DRAWING] = LAYOUT(
        KC_TRNS,                     KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS
    ),
    [_MODELING] = LAYOUT(
        KC_TRNS,                     UPLOAD,
        LCTL(DV_O),    LCTL(DV_Z),   KC_ENTER,
        KC_F5,         KC_F6,        KC_F7
    ),
    [_GAMING] = LAYOUT(
        KC_TRNS,                     KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TAB,
        KC_TRNS,       KC_ENTER,     KC_ALGR
    ),
    [_STREAMING] = LAYOUT(
        KC_TRNS,                     KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS
    ),
    [_SELECTOR] = LAYOUT(
        KC_TRNS,                     QK_BOOT,
        TO(_DEFAULT),  TO(_MEDIA),   TO(_DRAWING),
        TO(_MODELING), TO(_GAMING),  TO(_STREAMING)
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DEFAULT]   = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MEDIA]     = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_DRAWING]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_MODELING]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_GAMING]    = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_STREAMING] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_SELECTOR]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

#ifdef RGB_MATRIX_ENABLE
#undef HSV_WHITE
#define HSV_WHITE   0,  64, 255
#undef HSV_ORANGE
#define HSV_ORANGE 10, 255, 255

const hsv_t led_map[][RGB_MATRIX_LED_COUNT] = {
    [_DEFAULT] = {
        {HSV_CYAN},       {HSV_PURPLE}, {HSV_GREEN},
        {HSV_CYAN},       {HSV_RED},    {HSV_RED}
    },
    [_MEDIA] = {
        {HSV_CYAN},       {HSV_PURPLE}, {HSV_OFF},
        {HSV_CHARTREUSE}, {HSV_PURPLE}, {HSV_CHARTREUSE}
    },
    [_DRAWING] = {
        {HSV_OFF},        {HSV_OFF},    {HSV_RED},
        {HSV_OFF},        {HSV_OFF},    {HSV_OFF}
    },
    [_MODELING] = {
        {HSV_GREEN},      {HSV_RED},    {HSV_CYAN},
        {HSV_ORANGE},     {HSV_ORANGE}, {HSV_ORANGE}
    },
    [_GAMING] = {
        {HSV_GREEN},      {HSV_PURPLE}, {HSV_CYAN},
        {HSV_GREEN},      {HSV_CYAN},   {HSV_CYAN}
    },
    [_STREAMING] = {
        {HSV_OFF},        {HSV_OFF},    {HSV_OFF},
        {HSV_OFF},        {HSV_OFF},    {HSV_PURPLE}
    },
    [_SELECTOR] = {
        {HSV_WHITE},  {HSV_CHARTREUSE}, {HSV_RED},
        {HSV_ORANGE},     {HSV_CYAN},   {HSV_PURPLE}
    },
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t active_layer = get_highest_layer(layer_state);

    //uint8_t pos = 0;
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {
                hsv_t hsv = led_map[active_layer][
                    row * sizeof(g_led_config.matrix_co[row]) / sizeof(g_led_config.matrix_co[row][col]) + col
                ];

                if (hsv.v > rgb_matrix_get_val()) {
                    hsv.v = rgb_matrix_get_val();
                }

                rgb_t color = hsv_to_rgb(hsv);
                rgb_matrix_set_color(index, color.r, color.g, color.b);
            }
        }
    }

    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case UPLOAD:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("\n") SS_DELAY(500) "upload" SS_DELAY(10) SS_LSFT("G") SS_DELAY(10) "code\n");
        }
        break;
    }
    return true;
};
