// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

#define PRV_WRK LCTL(KC_LEFT)
#define NXT_WRK LCTL(KC_RGHT)
#define MOD_A     LSFT_T(KC_A)
#define MOD_S     LCTL_T(KC_S)
#define MOD_D     LALT_T(KC_D)
#define MOD_F     LGUI_T(KC_F)
#define MOD_J     RGUI_T(KC_J)
#define MOD_K     RALT_T(KC_K)
#define MOD_L     RCTL_T(KC_L)
#define MOD_SCLN  RSFT_T(KC_SCLN)
#define L1_SP     LT(1, KC_SPC)
#define L2_TAB    LT(2 , KC_TAB)
#define L3_BSPC   LT(3 , KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */
    [0] = LAYOUT_split_3x6_3(
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     _______,
        _______, MOD_A,   MOD_S,   MOD_D,   MOD_F,   KC_G,                               KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCLN, _______ ,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  _______,
                                            L2_TAB,  L1_SP, L2_TAB,              KC_ENT, L3_BSPC, KC_ENT
    ),
    [1] = LAYOUT_split_3x6_3(
	_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, PRV_WRK, NXT_WRK, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, KC_LBRC,                            KC_RBRC, _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),
    [2] = LAYOUT_split_3x6_3(
        _______, KC_F1,   KC_F2  , KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
        _______, _______, _______, _______, KC_BTN1, KC_BTN2,                            _______, _______, _______, _______, KC_F12, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, KC_F12, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),
    [3] = LAYOUT_split_3x6_3(
        _______, KC_GRV,  _______, _______, _______, _______,                            _______, _______, _______, _______, KC_EQL, _______,
        _______, KC_ESC,  _______, _______, _______, _______,                            _______, _______, _______, _______, KC_MINS, _______,
        _______, KC_QUOT, _______, _______, _______, _______,                            _______, _______, _______, _______, KC_SLSH, _______,
                                            _______, _______, _______,          _______, _______, _______
    )
};

