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

#ifdef OLED_ENABLE

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // QMK Logo and version information
    // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    // clang-format on

    oled_write_P(qmk_logo, false);
    oled_write_P(PSTR("Kyria "), false);
    oled_write_P(PSTR("rev3\n\n"), false);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
    case 0:
      oled_write_P(PSTR("Colemak-DH\n"), false);
      break;
    case 1:
      oled_write_P(PSTR("RSTHD\n"), false);
      break;
    case 2:
      oled_write_P(PSTR("Nav\n"), false);
      break;
    case 3:
      oled_write_P(PSTR("Sym\n"), false);
      break;
    case 4:
      oled_write_P(PSTR("Fun\n"), false);
      break;
    case 5:
      oled_write_P(PSTR("Adj\n"), false);
      break;
    case 6:
      oled_write_P(PSTR("Num\n"), false);
      break;
    default:
      oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "),
                 false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "),
                 false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "),
                 false);
  } else {
    // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
    // clang-format on
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
  }
  return false;
}
#endif
/* #if defined(ENCODER_MAP_ENABLE) */
/* const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = { */
/*     [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }, */
/*     [MDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) } */
/* }; */
/* #endif */
