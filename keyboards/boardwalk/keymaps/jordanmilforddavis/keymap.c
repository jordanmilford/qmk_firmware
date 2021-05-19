/*
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

#define PREV_WORK LCTL(KC_LEFT)
#define NEXT_WORK LCTL(KC_RGHT)
#define PREV_TAB  LCTL(LSFT(KC_TAB))
#define NEXT_TAB  LCTL(KC_TAB)
#define MOD_A     LSFT_T(KC_A)
#define MOD_S     LCTL_T(KC_S)
#define MOD_D     LALT_T(KC_D)
#define MOD_F     LGUI_T(KC_F)
#define MOD_J     RGUI_T(KC_J)
#define MOD_K     RALT_T(KC_K)
#define MOD_L     RCTL_T(KC_L)
#define MOD_SCLN  RSFT_T(KC_SCLN)
#define L1_SP     LT(1, KC_SPC)


// Layer shorthand
enum layer_names {
    _BASE,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_5x14(
        KC_GRV,  KC_1,    KC_2,      KC_3,      KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSLS,
        KC_QUOT, KC_Q,    KC_W,      KC_E,      KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_EQL,
        KC_ESC,  MOD_A,   MOD_S,     MOD_D,     MOD_F,   KC_G,    KC_LCBR, KC_RCBR, KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCLN, KC_MINS,
        _______, KC_Z,    KC_X,      KC_C,      KC_V,    KC_B,    KC_LCBR, KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_LEAD,
        _______, _______, PREV_WORK, NEXT_WORK, L1_SP,   KC_TAB,  KC_LPRN, KC_RPRN, KC_BSPC, KC_ENT,  _______, _______, _______,  _______
    ),

    [_FN] = LAYOUT_ortho_5x14(
        KC_GRV,  KC_F1,   KC_F2  , KC_F3,     KC_F4,     KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, KC_APP , _______,   _______,   _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______,
        _______, _______, _______, PREV_WORK, NEXT_WORK, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, RESET,
        _______, _______, _______, _______,   _______,   KC_LBRC, _______, _______, KC_RBRC, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, _______,
        _______, _______, _______, _______,   _______,   _______, _______, _______, _______, _______, _______, KC_SLCK, KC_PAUS, _______
    )

};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_THREE_KEYS(KC_J, KC_M, KC_D) {
      SEND_STRING("jordanmilforddavis");
    }
  }
}
