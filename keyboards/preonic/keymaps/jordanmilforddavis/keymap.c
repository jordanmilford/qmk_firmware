#include QMK_KEYBOARD_H

#define PREV_WORK LCTL(KC_LEFT)
#define NEXT_WORK LCTL(KC_RGHT)
#define PREV_TAB  LCTL(LSFT(KC_TAB))
#define NEXT_TAB  LCTL(KC_TAB)

enum unicode_names {
  IDENTICAL,
  INTERSECTION,
  UNION,
  SUBSET,
  SUPERSET,
  TILDE,
  MACRON,
  EMPTYSET,
  AND,
  OR,
  THEREFORE,
  NABLA,
  INTEGRAL,
  SUM,
  ALPHA,
  BETA,
  ELEMENTOF,
  LAMDA,
  PI,
  FORALL,
  EXISTS,
};

const uint32_t PROGMEM unicode_map[] = {
    [IDENTICAL]     = 0x2261,  // ≡
    [INTERSECTION]  = 0x2229,  // ∩
    [UNION]         = 0x222a,  // ∪
    [SUBSET]        = 0x2282,  // ⊂
    [SUPERSET]      = 0x2283,  // ⊃
    [TILDE]         = 0x223C,  // ∼
    [MACRON]        = 0xAF  ,  // ¯
    [EMPTYSET]      = 0x2205,  // ∅
    [AND]           = 0x2227,  // ∧
    [OR]            = 0x2228,  // ∨
    [THEREFORE]     = 0x2234,  // ∴
    [NABLA]         = 0x2207,  // ∇
    [INTEGRAL]      = 0x222B,  // ∫
    [ALPHA]         = 0x03B1,  // α
    [BETA]          = 0x03B2,  // β
    [ELEMENTOF]     = 0x2208,  // ∈
    [LAMDA]         = 0x03BB,  // λ
    [PI]            = 0x03C0,  // π
    [FORALL]        = 0x2200,  // ∀
    [EXISTS]        = 0x2203,  // ∃
};

enum preonic_layers {
  _BASE,
  _FUNC,
  _MOUSE,
  _MATH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_preonic_grid(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS ,
    KC_QUOT    , KC_Q         , KC_W         , KC_E         , KC_R         , KC_T    , KC_Y , KC_U         , KC_I         , KC_O         , KC_P            , KC_EQL   ,
    KC_ESC     , LSFT_T(KC_A) , LCTL_T(KC_S) , LALT_T(KC_D) , LGUI_T(KC_F) , KC_G    , KC_H , RGUI_T(KC_J) , RALT_T(KC_K) , RCTL_T(KC_L) , RSFT_T(KC_SCLN) , KC_MINS  ,
    TG(2)    , KC_Z         , KC_X         , KC_C         , KC_V         , KC_B    , KC_N , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH         , KC_LEAD  ,
    LGUI(KC_C) , LGUI(KC_V)   , PREV_WORK    , NEXT_WORK    , LT(1         , KC_SPC) , LT(2 , KC_TAB)      , KC_BSPC, KC_ENT       , PREV_TAB        , NEXT_TAB , KC_LBRC , LT(3 , KC_RBRC)
  )            ,

  // Function layer
  [_FUNC] = LAYOUT_preonic_grid(
    _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5         , KC_F6         , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , KC_LBRC , KC_RBRC , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),

  // Keyboard settings layer
  [_MOUSE] = LAYOUT_preonic_grid(
    RESET   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , KC_MS_BTN1 , KC_MS_UP , KC_MS_BTN2 , _______ , _______ , _______ , _______ , KC_MS_WH_UP , KC_MS_WH_DOWN , _______ , _______ ,
    _______ , KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT  , _______ , _______ , _______ , KC_MS_ACCEL0 , KC_MS_ACCEL1 , KC_MS_ACCEL2, _______ , _______ ,
    _______  , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______  , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),

  // Math layer
  [_MATH] = LAYOUT_preonic_grid(
    _______ , X(IDENTICAL),   X(INTERSECTION), X(UNION), X(SUBSET), X(SUPERSET), _______, _______, X(TILDE), X(MACRON), X(EMPTYSET), _______,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , KC_LBRC , KC_RBRC , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
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
