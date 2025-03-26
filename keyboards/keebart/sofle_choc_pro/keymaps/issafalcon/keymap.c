// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,  // default layer
    MDIA,  // media keys
};

#define _HOME_A LGUI_T(KC_A)
#define _HOME_S LALT_T(KC_S)
#define _HOME_D LSFT_T(KC_D)
#define _HOME_F LCTL_T(KC_F)

#define _HOME_H RCTL_T(KC_H)
#define _HOME_J RSFT_T(KC_J)
#define _HOME_K LALT_T(KC_K)
#define _HOME_L RGUI_T(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬────────┬────────┬────────┬────────┬──────┐                                                 ┌────────┬────────┬────────┬────────┬───┬──────┐
//    │ esc  │   1    │   2    │   3    │   4    │  5   │                                                 │   6    │   7    │   8    │   9    │ 0 │  `   │
//    ├──────┼────────┼────────┼────────┼────────┼──────┤                                                 ├────────┼────────┼────────┼────────┼───┼──────┤
//    │ tab  │   q    │   w    │   e    │   r    │  t   │                                                 │   y    │   u    │   i    │   o    │ p │ bspc │
//    ├──────┼────────┼────────┼────────┼────────┼──────┤                                                 ├────────┼────────┼────────┼────────┼───┼──────┤
//    │ caps │ HOME_A │ HOME_S │ HOME_D │ HOME_F │  g   │                                                 │ HOME_H │ HOME_J │ HOME_K │ HOME_L │ ; │  '   │
//    ├──────┼────────┼────────┼────────┼────────┼──────┼────────────────┐               ┌────────────────┼────────┼────────┼────────┼────────┼───┼──────┤
//    │ lsft │   z    │   x    │   c    │   v    │  b   │      mute      │               │      mply      │   n    │   m    │   ,    │   .    │ / │ rsft │
//    └──────┴────────┴────────┼────────┼────────┼──────┼────────────────┼─────┐   ┌─────┼────────────────┼────────┼────────┼────────┼────────┴───┴──────┘
//                             │  lctl  │  lalt  │ lgui │ LT(MDIA, lgui) │ ent │   │ spc │ LT(MDIA, rgui) │  del   │  ralt  │  rctl  │
//                             └────────┴────────┴──────┴────────────────┴─────┘   └─────┴────────────────┴────────┴────────┴────────┘
[BASE] = LAYOUT_sofle_rgb_issafalcon(
  KC_ESC  , KC_1   , KC_2   , KC_3    , KC_4    , KC_5    ,                                                               KC_6   , KC_7    , KC_8    , KC_9   , KC_0    , KC_GRV ,
  KC_TAB  , KC_Q   , KC_W   , KC_E    , KC_R    , KC_T    ,                                                               KC_Y   , KC_U    , KC_I    , KC_O   , KC_P    , KC_BSPC,
  KC_CAPS , HOME_A , HOME_S , HOME_D  , HOME_F  , KC_G    ,                                                               HOME_H , HOME_J  , HOME_K  , HOME_L , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z   , KC_X   , KC_C    , KC_V    , KC_B    , KC_MUTE           ,                       KC_MPLY           , KC_N   , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
                              KC_LCTL , KC_LALT , KC_LCMD , LT(MDIA, KC_LGUI) , KC_ENT ,     KC_SPC , LT(MDIA, KC_RGUI) , KC_DEL , KC_RALT , KC_RCTL
),

//    ┌─────────┬─────┬─────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │  mute   │     │     │     │     │     │                           │     │     │     │     │     │     │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │ RM_TOGG │     │     │     │     │     │                           │     │     │     │     │     │     │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │ RM_NEXT │     │     │     │     │     │                           │     │     │     │     │     │     │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┐               ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │ RM_HUEU │     │     │     │     │     │     │               │     │     │     │     │     │     │     │
//    └─────────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
//                          │     │     │     │     │     │   │     │     │     │     │     │
//                          └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
[MDIA] = LAYOUT_sofle_rgb_issafalcon(
  KC_MUTE , _______ , _______ , _______ , _______ , _______ ,                                             _______ , _______ , _______ , _______ , _______ , _______,
  RM_TOGG , _______ , _______ , _______ , _______ , _______ ,                                             _______ , _______ , _______ , _______ , _______ , _______,
  RM_NEXT , _______ , _______ , _______ , _______ , _______ ,                                             _______ , _______ , _______ , _______ , _______ , _______,
  RM_HUEU , _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______ , _______ , _______ , _______,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [MDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif

bool alt_tab_active = false;
bool sft_grv_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each
  // key pressed
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: "
          "%u, count: %u\n",
          keycode, record->event.key.col, record->event.key.row,
          record->event.pressed, record->event.time, record->tap.interrupted,
          record->tap.count);
#endif
  switch (keycode) {
  case KC_QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_CLM);
    }
    return false;
  case KC_RSTHD:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_RSTHD);
    }
    return false;

  case KC_NAV:
    if (record->event.pressed) {
      layer_on(_NAV);
    } else {
      layer_off(_NAV);
    }
    return false;
  case KC_SYM:
    if (record->event.pressed) {
      layer_on(_SYM);
    } else {
      layer_off(_SYM);
    }
    return false;
  case KC_NMBR:
    if (record->event.pressed) {
      layer_on(_NUM);
    } else {
      layer_off(_NUM);
    }
    return false;
  case KC_FUN:
    if (record->event.pressed) {
      layer_on(_FUN);
    } else {
      layer_off(_FUN);
    }
    return false;
  case KC_COPY:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_C);
    } else {
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_C);
    }
    return false;
  case KC_PASTE:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_V);
    } else {
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_V);
    }
    return false;
  case KC_CUT:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_X);
    } else {
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_X);
    }
    return false;
    break;
  case KC_UNDO:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_Z);
    } else {
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_Z);
    }
    return false;
  case KC_TMUX:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_B);
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_B);
    }
    return false;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _NAV, _SYM, _ADJ);
#ifdef CONSOLE_ENABLE
  uprintf("%d layer\n", state);
#endif
  return state;
}

void matrix_scan_user(void) { achordion_task(); }

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                     uint16_t other_keycode, keyrecord_t *other_record) {
  // Exceptionally consider the following chords as holds, even though they are
  // on the same hand
  switch (tap_hold_keycode) {
  case HOME_T: // T + A.
    if (other_keycode == HOME_A) {
      return true;
    }
    break;
  }

  // Also allow same-hand holds when the tap_hold_key belongs to thumb cluster
  if (tap_hold_record->event.key.row == 7 ||
      tap_hold_record->event.key.row == 3) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        default:
            return false;  // Deactivate Caps Word.
    }
}
