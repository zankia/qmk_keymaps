// Copyright 2026 zankia mail@zankia.fr
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(QK_MOUSE_BUTTON_1, QK_MOUSE_BUTTON_2)
};

const uint16_t PROGMEM combo[] = { QK_MOUSE_BUTTON_1, QK_MOUSE_BUTTON_2, COMBO_END };
combo_t key_combos[] = {
    COMBO(combo, QK_MOUSE_BUTTON_3)
};
