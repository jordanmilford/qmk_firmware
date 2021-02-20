#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_AUDIO_MUTE,                                  KC_CAPSLOCK,    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLASH,
    KC_QUOTE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRACKET,                                    KC_RBRACKET,    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,
    KC_ESCAPE,      LSFT_T(KC_A),   LCTL_T(KC_S),   LALT_T(KC_D),   LGUI_T(KC_F),   KC_G,                                                                           KC_H,           LGUI_T(KC_J),   LALT_T(KC_K),   LCTL_T(KC_L),   LSFT_T(KC_SCOLON),KC_MINUS,
    KC_COLN,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LCBR,                                        KC_RCBR,        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT,
    KC_F4,          KC_MAC_COPY,    KC_MAC_PASTE,   LCTL(KC_LEFT),  LCTL(KC_RIGHT),                                                                                                 LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, LT(3, KC_SLASH),
                                                                                                    RGB_SAD,        RGB_SAI,        RGB_MOD,        RGB_SLD,
                                                                                                                    RGB_VAI,        RGB_HUI,
                                                                                    LT(1,KC_SPACE), LT(2,KC_TAB),   RGB_VAD,        RGB_HUD,        KC_BSPACE,      KC_ENTER
  ),
  [1] = LAYOUT_ergodox_pretty(
    RESET,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
    KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT,                                                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, X(IDENTICAL),   X(INTERSECTION),X(UNION),       X(SUBSET),      X(SUPERSET),    KC_TRANSPARENT,                                 KC_TRANSPARENT, S(KC_4),        S(KC_5),        X(TILDE),       X(MACRON),      X(EMPTYSET),    KC_F11,
    KC_TRANSPARENT, X(AND),         X(OR),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
    KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT,                                                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      rgb_matrix_set_color_all(108, 110, 160);
      break;
    case 2:
      rgb_matrix_set_color_all(254, 215, 102);
      break;
    case 3:
      rgb_matrix_set_color_all(255, 20, 80);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
