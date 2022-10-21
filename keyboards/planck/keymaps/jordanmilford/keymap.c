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

enum planck_layers {
  _BASE,
  _NUM,
  _FUNC,
  _PINKY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_Q       , KC_W      , KC_E      , KC_R  , KC_T   , _______, _______,  KC_Y    , KC_U   , KC_I    , KC_O    , KC_P     ,
    MOD_A      , MOD_S     , MOD_D     , MOD_F , KC_G   , _______, _______,  KC_H    , MOD_J  , MOD_K   , MOD_L   , MOD_SCLN ,
    KC_Z       , KC_X      , KC_C      , KC_V  , KC_B   , _______, _______,  KC_N    , KC_M   , KC_COMM , KC_DOT  , KC_SLSH  ,
    LGUI(KC_V) , _______   , KC_ESC    , L1_SP , L2_TAB , _______, _______,  KC_ENTER, LT_BSPC, _______ , _______ , _______
  ),

  // Number layer
  [_NUM] = LAYOUT_planck_grid(
    KC_1    , KC_2    , KC_3      , KC_4      , KC_5    , _______, _______, KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS ,
    _______ , _______ , PREV_WORK , NEXT_WORK , _______ , _______, _______, KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ ,
    _______ , _______ , _______ , _______   , _______   , _______, _______, KC_LBRC , KC_RBRC , _______ , _______ , _______ , _______,
    _______ , _______ , _______ , _______   , _______   , _______, _______, _______ , _______ , _______ , _______ , _______ , _______
  ),

  // Function key layers
  [_FUNC] = LAYOUT_planck_grid(
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5         , KC_F6  , KC_F7   , KC_F8         , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
    _______ , _______ , _______ , _______ , KC_LBRC       , _______, _______ , KC_RBRC       , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , LSFT(KC_LBRC) , _______, _______ , LSFT(KC_RBRC) , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______       , _______, _______ , _______       , _______ , _______ , _______ , _______ ,
  ),

  // Pinky layer
  [_PINKY] = LAYOUT_planck_grid(
    KC_GRAVE , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_EQL
    KC_ESCAPE, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS
    KC_QUOTE , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_BSLS
    _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
};
