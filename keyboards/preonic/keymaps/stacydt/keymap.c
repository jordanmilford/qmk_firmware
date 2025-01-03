/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H

#define EMOJI LCTL(LGUI(KC_SPC))

enum unicode_names {
  INTERROBANG,
  EMDASH
};

const uint32_t PROGMEM unicode_map[] = {
  [INTERROBANG] = 0x203D,  // ‽
  [EMDASH]      = 0x2014,  // —
};

enum preonic_layers {
  _QWERTY,
  _FUNC,
  _SPECIAL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
  KC_LGUI, KC_LCTL, KC_LALT, MO(1),   KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  EMOJI,   KC_LEFT, KC_DOWN, KC_RGHT
),

[_FUNC] = LAYOUT_preonic_grid(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11,
  _______ , _______ , _______ , _______ , RESET   , _______ , _______ , _______ , _______ , _______ , _______ , KC_F12,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS , KC_EQUAL,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
),

[_SPECIAL] = LAYOUT_preonic_grid(
  RESET   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , X(INTERROBANG),
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , X(EMDASH), _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______
),

};
