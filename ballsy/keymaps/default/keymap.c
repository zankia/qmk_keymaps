// Copyright 2026 zankia mail@zankia.fr
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(QK_MOUSE_BUTTON_1, TD(0))
};

const uint16_t PROGMEM combo[] = { QK_MOUSE_BUTTON_1, TD(0), COMBO_END };
combo_t key_combos[] = {
    COMBO(combo, QK_MOUSE_BUTTON_3)
};

// Heavily copied from ploopyco
bool  is_drag_scroll       = false;
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (is_drag_scroll) {
        scroll_accumulated_h += (float)mouse_report.x / 16;
        scroll_accumulated_v += (float)mouse_report.y / 16;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = -(int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

#ifdef TAP_DANCE_ENABLE
void tap_dance_finished(tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 1:
            register_code(QK_MOUSE_BUTTON_2);
            break;
        case 2:
            is_drag_scroll = true;
            break;
    }
}

void tap_dance_reset(tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 1:
            unregister_code(QK_MOUSE_BUTTON_2);
            break;
        case 2:
            is_drag_scroll = false;
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_finished, tap_dance_reset)
};
#endif

