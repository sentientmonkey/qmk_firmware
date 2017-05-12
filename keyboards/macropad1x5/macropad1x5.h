/* Copyright 2020 Leon Stubbig <leonskeyboards@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

// Select revision
#if defined(KEYBOARD_macropad1x5_rev01)
    #include "rev01.h"
#elif defined(KEYBOARD_macropad1x5_rev03)
    #include "rev03.h"
#endif

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    K1, K2, K3, K4, K5 \
) { \
    { K1, K2, K3, K4, K5 } \
}

// Layout for encoders without button
#define LAYOUT_1x4( \
    K2, K3, K4, K5 \
) { \
    { KC_NO, K2, K3, K4, K5 } \
}

#define LAYOUT_FLIPPED_1x4( \
    K2, K3, K4, K5 \
) { \
    { KC_NO, K5, K4, K3, K2 } \
}

