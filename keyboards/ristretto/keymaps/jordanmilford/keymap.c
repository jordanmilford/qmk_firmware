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
#define L2_TAB    LT(2 , KC_TAB)
#define L3_BSPC   LT(3 , KC_BSPC)

enum layer_names {
  _BASE,
  _NUM,
  _FUNC,
  _PINK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    _______ , KC_Q    , KC_W      , KC_E      , KC_R  , KC_T,               KC_Y    , KC_U   , KC_I    , KC_O    , KC_P     , _______ ,
    _______ , MOD_A   , MOD_S     , MOD_D     , MOD_F , KC_G              , KC_H    , MOD_J  , MOD_K   , MOD_L   , MOD_SCLN , _______ ,
    _______ , KC_Z    , KC_X      , KC_C      , KC_V  , KC_B              , KC_N    , KC_M   , KC_COMM , KC_DOT  , KC_SLSH  , _______ ,
    _______ , _______ , _______   , L2_TAB    , L1_SP , _______ ,  _______, _______ , L3_BSPC, KC_ENT  , _______ , _______  , _______
  ),
  // Number layer
  [_NUM] = LAYOUT(
    KC_GRV  , KC_1    , KC_2    , KC_3      , KC_4      , KC_5             , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS ,
    _______ , _______ , _______ , PREV_WORK , NEXT_WORK , _______          , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ ,
    _______ , _______ , _______ , _______   , _______   , KC_LBRC          , KC_RBRC , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______   , _______   , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______
  ),
  // Function key layer
  [_FUNC] = LAYOUT(
    RESET   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5                  , KC_F6         , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    _______ , _______ , _______ , _______ , _______ , KC_LBRC                , KC_RBRC       , _______ , _______ , _______ , _______ , KC_F12  ,
    _______ , _______ , _______ , _______ , _______ , LSFT(KC_LBRC)          , LSFT(KC_RBRC) , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______      , _______ , _______       , _______ , _______ , _______ , _______ , _______
  ),
  // Pinky key layer
  [_PINK] = LAYOUT(
    _______ , KC_GRAVE, _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , KC_EQL  , _______ ,
    _______ , KC_ESC  , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , KC_MINS , _______ ,
    _______ , KC_QUOT , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , KC_SLSH , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
}

__attribute__((weak)) void oled_task_user(void) {
	oled_write_P(PSTR("\n\n"), false);
	oled_write_ln_P(PSTR("JMD"), false);
	oled_write_ln_P(PSTR(""), false);
	switch (get_highest_layer(layer_state)) {
		case _BASE:
			oled_write_P(PSTR("BASE\n"), false);
			break;
		case _NUM:
			oled_write_P(PSTR("NUM\n"), false);
			break;
		case _FUNC:
			oled_write_P(PSTR("FUNC\n"), false);
			break;
	}
}

#endif
