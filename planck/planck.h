#pragma once

#include "quantum.h"

void planck_ez_right_led_on(void);
void planck_ez_right_led_off(void);
void planck_ez_right_led_level(uint8_t level);
void planck_ez_left_led_on(void);
void planck_ez_left_led_off(void);
void planck_ez_left_led_level(uint8_t level);

enum planck_ez_keycodes {
    LED_LEVEL = QK_KB_0,
    TOGGLE_LAYER_COLOR,
};

#define RGB_LTOG TOGGLE_LAYER_COLOR

#ifndef WEBUSB_ENABLE
#    define WEBUSB_PAIR KC_NO
#endif

typedef union {
  uint32_t raw;
  struct {
    uint8_t      led_level :3;
    bool         disable_layer_led   :1;
    bool         rgb_matrix_enable   :1;
  };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;

#undef  HSV_PURPLE
#define HSV_PURPLE 180, 255, 255
