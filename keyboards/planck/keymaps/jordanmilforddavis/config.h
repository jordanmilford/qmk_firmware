#pragma once

// Leader key
#define LEADER_TIMEOUT 450
#define LEADER_PER_KEY_TIMING

// RGB
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

// Tap-hold settings
#define TAPPING_TERM 300
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// audio
#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif
