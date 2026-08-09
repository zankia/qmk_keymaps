// Copyright 2026 zankia mail@zankia.fr
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

void pointing_device_init_kb(void) {
    pointing_device_set_cpi(1000);
}
