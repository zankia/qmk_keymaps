/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 256

#define PERMISSIVE_HOLD

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 600000

#undef RGB_MATRIX_VAL_STEP
#define RGB_MATRIX_VAL_STEP 24

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 4

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 24

#undef HOLD_ON_OTHER_KEY_PRESS
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT

#define RGB_MATRIX_STARTUP_SPD 60
