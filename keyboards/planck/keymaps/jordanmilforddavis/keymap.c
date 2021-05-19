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

enum planck_layers {
  _BASE,
  _NUM,
  _FUNC,
  _SET,
  _MOUSE,
  _TABS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_QUOT    , KC_Q       , KC_W      , KC_E      , KC_R  , KC_T   , KC_Y    , KC_U   , KC_I    , KC_O    , KC_P     , KC_EQL  ,
    KC_ESC     , MOD_A      , MOD_S     , MOD_D     , MOD_F , KC_G   , KC_H    , MOD_J  , MOD_K   , MOD_L   , MOD_SCLN , KC_MINS ,
    _______    , KC_Z       , KC_X      , KC_C      , KC_V  , KC_B   , KC_N    , KC_M   , KC_COMM , KC_DOT  , KC_SLSH  , KC_LEAD ,
    LGUI(KC_C) , LGUI(KC_V) , _______   , KC_ESC    , L1_SP , L2_TAB , KC_BSPC , KC_ENT , _______ , _______ , _______  , _______
  ),

  // Number layer
  [_NUM] = LAYOUT_planck_grid(
    KC_GRV  , KC_1    , KC_2    , KC_3      , KC_4      , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS ,
    _______ , _______ , _______ , PREV_WORK , NEXT_WORK , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ ,
    _______ , _______ , _______ , _______   , _______   , KC_LBRC , KC_RBRC , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______   , _______   , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),

  // Function key layers
  [_FUNC] = LAYOUT_planck_grid(
    RESET   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5         , KC_F6         , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    _______ , _______ , _______ , _______ , _______ , KC_LBRC       , KC_RBRC       , _______ , _______ , _______ , _______ , KC_F12  ,
    _______ , _______ , _______ , _______ , _______ , LSFT(KC_LBRC) , LSFT(KC_RBRC) , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______       , _______       , _______ , _______ , _______ , _______ , _______
  ),

  // Keyboard settings layer
  [_SET] = LAYOUT_planck_grid(
    RESET   , _______ , RGB_TOG  , RGB_M_R , RGB_M_X , _______ , _______ , _______ , _______ , _______ , _______ , RGB_VAI ,
    _______ , _______ , RGB_M_SW , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , RGB_VAD ,
    MU_TOG  , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    MU_MOD  , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),

  // Mouse layer
  [_MOUSE] = LAYOUT_planck_grid(
    _______ , KC_MS_BTN1 , KC_MS_UP , KC_MS_BTN2 , _______ , _______ , _______ , _______ , KC_MS_WH_UP , KC_MS_WH_DOWN , _______ , _______ ,
    _______ , KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT  , _______ , _______ , _______ , KC_MS_ACCEL0 , KC_MS_ACCEL1 , KC_MS_ACCEL2, _______ , _______ ,
    _______  , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______  , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),

  // Mouse layer
  [_TABS] = LAYOUT_planck_grid(
    _______  , LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), _______ ,
    _______  , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______  , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______  , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
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
