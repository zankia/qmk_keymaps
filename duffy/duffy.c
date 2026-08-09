// Copyright 2026 zankia mail@zankia.fr
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

//Invert scroll direction
report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    mouse_report.v = -mouse_report.v;
    return mouse_report;
}
