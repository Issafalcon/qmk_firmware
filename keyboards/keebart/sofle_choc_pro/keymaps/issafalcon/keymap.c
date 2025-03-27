// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0, // default layer
    _NAV,        // navigation layer
    _SYM,        // symbols layer
    _NUM,        // numbers layer
    _NVIM,       // nvim layer
};

#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

#define HOME_H RCTL_T(KC_H)
#define HOME_J RSFT_T(KC_J)
#define HOME_K LALT_T(KC_K)
#define HOME_L RGUI_T(KC_L)

#define SPACE LT(_SYM, KC_SPC)
#define BSPC LT(_NAV, KC_BSPC)
#define DEL LT(_FUN, KC_DEL)
#define ENTER RSFT_T(KC_ENT)
#define TAB LT(_NUM, KC_TAB)

#define R_BSPC LT(_NUM, KC_BSPC)

#define O_GUI OSM(MOD_LGUI)
#define O_SFT OSM(MOD_LSFT)
#define O_CTL OSM(MOD_LCTL)
#define O_LALT OSM(MOD_LALT)
#define O_RALT OSM(MOD_RALT)

#define CT_TAB LCTL(KC_TAB)
#define CT_SFT_TAB LCTL(LSFT(KC_TAB))

#define SFT_TAB LSFT(KC_TAB)

enum custom_keycodes { KC_QWERTY = QK_USER, KC_NAV, KC_SYM, KC_NMBR, KC_FUN, ALT_TAB, ALT_SFT_TAB, KC_SFT_TAB, KC_QWERTY, KC_TMUX };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬────────┬────────┬─────────┬─────────┬─────┐                                  ┌────────┬────────┬────────┬────────┬───┬─────────┐
//    │ xxxxxxx │   1    │   2    │    3    │    4    │  5  │                                  │   6    │   7    │   8    │   9    │ 0 │    `    │
//    ├─────────┼────────┼────────┼─────────┼─────────┼─────┤                                  ├────────┼────────┼────────┼────────┼───┼─────────┤
//    │   tab   │   q    │   w    │    e    │    r    │  t  │                                  │   y    │   u    │   i    │   o    │ p │  bspc   │
//    ├─────────┼────────┼────────┼─────────┼─────────┼─────┤                                  ├────────┼────────┼────────┼────────┼───┼─────────┤
//    │   esc   │ HOME_A │ HOME_S │ HOME_D  │ HOME_F  │  g  │                                  │ HOME_H │ HOME_J │ HOME_K │ HOME_L │ ; │    '    │
//    ├─────────┼────────┼────────┼─────────┼─────────┼─────┼──────┐                   ┌───────┼────────┼────────┼────────┼────────┼───┼─────────┤
//    │ xxxxxxx │   z    │   x    │    c    │    v    │  b  │ mute │                   │ mply  │   n    │   m    │   ,    │   .    │ / │ xxxxxxx │
//    └─────────┴────────┴────────┼─────────┼─────────┼─────┼──────┼───────┐   ┌───────┼───────┼────────┼────────┼────────┼────────┴───┴─────────┘
//                                │ xxxxxxx │ xxxxxxx │ TAB │ BSPC │ SPACE │   │ ENTER │ SPACE │  tMUX  │ xxxxxx │ xxxxxx │
//                                └─────────┴─────────┴─────┴──────┴───────┘   └───────┴───────┴────────┴────────┴────────┘
[_QWERTY] = LAYOUT_sofle_rgb_issafalcon(
  xxxxxxx , KC_1   , KC_2   , KC_3    , KC_4    , KC_5 ,                                         KC_6    , KC_7   , KC_8    , KC_9   , KC_0    , KC_GRV ,
  KC_TAB  , KC_Q   , KC_W   , KC_E    , KC_R    , KC_T ,                                         KC_Y    , KC_U   , KC_I    , KC_O   , KC_P    , KC_BSPC,
  KC_ESC  , HOME_A , HOME_S , HOME_D  , HOME_F  , KC_G ,                                         HOME_H  , HOME_J , HOME_K  , HOME_L , KC_SCLN , KC_QUOT,
  xxxxxxx , KC_Z   , KC_X   , KC_C    , KC_V    , KC_B , KC_MUTE ,                     KC_MPLY , KC_N    , KC_M   , KC_COMM , KC_DOT , KC_SLSH , xxxxxxx,
                              xxxxxxx , xxxxxxx , TAB  , BSPC    , SPACE ,     ENTER , SPACE   , KC_TMUX , xxxxxx , xxxxxx
),

//    ┌─────────────┬───────┬────────┬───────┬───────┬────────┐                           ┌──────┬──────┬──────┬──────┬─────┬─────┐
//    │             │       │        │       │       │        │                           │      │      │      │      │     │     │
//    ├─────────────┼───────┼────────┼───────┼───────┼────────┤                           ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │             │       │        │       │       │        │                           │      │      │ home │ end  │     │ f12 │
//    ├─────────────┼───────┼────────┼───────┼───────┼────────┤                           ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │   ALT_TAB   │ O_GUI │ O_LALT │ O_SFT │ O_CTL │ O_RALT │                           │ left │ down │  up  │ rght │     │ f11 │
//    ├─────────────┼───────┼────────┼───────┼───────┼────────┼─────┐               ┌─────┼──────┼──────┼──────┼──────┼─────┼─────┤
//    │ ALT_SFT_TAB │ undo  │  cut   │ copy  │ paste │  pscr  │     │               │     │      │ pgdn │ pgup │      │     │ f10 │
//    └─────────────┴───────┴────────┼───────┼───────┼────────┼─────┼─────┐   ┌─────┼─────┼──────┼──────┼──────┼──────┴─────┴─────┘
//                                   │       │       │        │     │     │   │     │     │      │      │      │
//                                   └───────┴───────┴────────┴─────┴─────┘   └─────┴─────┴──────┴──────┴──────┘
[_NAV] = LAYOUT_sofle_rgb_issafalcon(
  _______     , _______ , _______ , _______ , _______  , _______ ,                                             _______ , _______ , _______ , _______  , _______ , _______,
  _______     , _______ , _______ , _______ , _______  , _______ ,                                             _______ , _______ , KC_HOME , KC_END   , _______ , KC_F12 ,
  ALT_TAB     , O_GUI   , O_LALT  , O_SFT   , O_CTL    , O_RALT  ,                                             KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , KC_F11 ,
  ALT_SFT_TAB , KC_UNDO , KC_CUT  , KC_COPY , KC_PASTE , KC_PSCR , _______ ,                         _______ , _______ , KC_PGDN , KC_PGUP , _______  , _______ , KC_F10 ,
                                    _______ , _______  , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌─────────┬─────┬─────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │         │     │     │     │     │     │                           │     │     │     │     │     │     │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │         │  '  │  <  │  >  │  "  │  `  │                           │  &  │  _  │  [  │  ]  │  %  │     │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │   tab   │  !  │  -  │  +  │  =  │  #  │                           │  |  │  :  │  (  │  )  │  ;  │  "  │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┐               ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │ SFT_TAB │  ^  │  /  │  *  │  \  │  @  │     │               │     │  ~  │  $  │  {  │  }  │  ?  │     │
//    └─────────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
//                          │     │     │     │     │     │   │     │     │     │     │     │
//                          └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
[_SYM] = LAYOUT_sofle_rgb_issafalcon(
  _______ , _______ , _______ , _______ , _______ , _______ ,                                             _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_QUOT , KC_LABK , KC_RABK , KC_DQUO , KC_GRV  ,                                             KC_AMPR , KC_UNDS , KC_LBRC , KC_RBRC , KC_PERC , _______,
  KC_TAB  , KC_EXLM , KC_MINS , KC_PLUS , KC_EQL  , KC_HASH ,                                             KC_PIPE , KC_COLN , KC_LPRN , KC_RPRN , KC_SCLN , KC_DQUO,
  SFT_TAB , KC_CIRC , KC_SLSH , KC_ASTR , KC_BSLS , KC_AT   , _______ ,                         _______ , KC_TILD , KC_DLR  , KC_LCBR , KC_RCBR , KC_QUES , _______,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌────────────┬───────┬────────┬───────┬───────┬────────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │            │       │        │       │       │        │                           │     │     │     │     │     │     │
//    ├────────────┼───────┼────────┼───────┼───────┼────────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │            │       │        │       │       │        │                           │     │  7  │  8  │  9  │     │     │
//    ├────────────┼───────┼────────┼───────┼───────┼────────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │   CT_TAB   │ O_GUI │ O_LALT │ O_SFT │ O_CTL │ O_RALT │                           │     │  4  │  5  │  6  │  0  │     │
//    ├────────────┼───────┼────────┼───────┼───────┼────────┼─────┐               ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │ CT_SFT_TAB │       │        │       │       │        │     │               │     │     │  1  │  2  │  3  │     │     │
//    └────────────┴───────┴────────┼───────┼───────┼────────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
//                                  │       │       │        │     │     │   │     │     │     │     │     │
//                                  └───────┴───────┴────────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
[_NUM] = LAYOUT_sofle_rgb_issafalcon(
  _______    , _______ , _______ , _______ , _______ , _______ ,                                             _______ , _______ , _______ , _______ , _______ , _______,
  _______    , _______ , _______ , _______ , _______ , _______ ,                                             _______ , KC_7    , KC_8    , KC_9    , _______ , _______,
  CT_TAB     , O_GUI   , O_LALT  , O_SFT   , O_CTL   , O_RALT  ,                                             _______ , KC_4    , KC_5    , KC_6    , KC_0    , _______,
  CT_SFT_TAB , _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , KC_1    , KC_2    , KC_3    , _______ , _______,
                                   _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌─────────┬────────┬────────┬───────┬───────┬────────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │         │        │        │       │       │        │                           │     │     │     │     │     │     │
//    ├─────────┼────────┼────────┼───────┼───────┼────────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │ QK_BOOT │ qWERTY │ rSTHD  │       │       │        │                           │     │ f7  │ f8  │ f9  │ f12 │ f15 │
//    ├─────────┼────────┼────────┼───────┼───────┼────────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │         │  lgui  │ O_LALT │ O_SFT │ O_CTL │ O_RALT │                           │     │ f4  │ f5  │ f6  │ f11 │ f14 │
//    ├─────────┼────────┼────────┼───────┼───────┼────────┼─────┐               ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │         │        │        │       │       │        │     │               │     │     │ f1  │ f2  │ f3  │ f10 │ f13 │
//    └─────────┴────────┴────────┼───────┼───────┼────────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
//                                │       │       │        │     │     │   │     │     │     │     │     │
//                                └───────┴───────┴────────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
[_FUN] = LAYOUT_sofle_rgb_issafalcon(
  _______ , _______   , _______  , _______ , _______ , _______ ,                                             _______ , _______ , _______ , _______ , _______ , _______,
  QK_BOOT , KC_QWERTY , KC_RSTHD , _______ , _______ , _______ ,                                             _______ , KC_F7   , KC_F8   , KC_F9   , KC_F12  , KC_F15 ,
  _______ , KC_LGUI   , O_LALT   , O_SFT   , O_CTL   , O_RALT  ,                                             _______ , KC_F4   , KC_F5   , KC_F6   , KC_F11  , KC_F14 ,
  _______ , _______   , _______  , _______ , _______ , _______ , _______ ,                         _______ , _______ , KC_F1   , KC_F2   , KC_F3   , KC_F10  , KC_F13 ,
                                   _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌─────┬─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────┐
//    │     │         │         │         │         │         │                           │         │         │         │         │         │     │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │     │ LCTL(1) │ LCTL(2) │ LCTL(3) │ LCTL(4) │ LCTL(5) │                           │ LCTL(6) │ LCTL(7) │ LCTL(8) │ LCTL(9) │ LCTL(0) │     │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │     │ LALT(1) │ LALT(2) │ LALT(3) │ LALT(4) │ LALT(5) │                           │ LALT(6) │ LALT(7) │ LALT(8) │ LALT(9) │ LALT(0) │     │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┐               ┌─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │     │         │         │         │         │         │     │               │     │         │         │         │         │         │     │
//    └─────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────┼─────┐   ┌─────┼─────┼─────────┼─────────┼─────────┼─────────┴─────────┴─────┘
//                              │         │         │         │     │     │   │     │     │         │         │         │
//                              └─────────┴─────────┴─────────┴─────┴─────┘   └─────┴─────┴─────────┴─────────┴─────────┘
[_NVIM] = LAYOUT_sofle_rgb_issafalcon(
  _______ , _______    , _______    , _______    , _______    , _______    ,                                             _______    , _______    , _______    , _______    , _______    , _______,
  _______ , LCTL(KC_1) , LCTL(KC_2) , LCTL(KC_3) , LCTL(KC_4) , LCTL(KC_5) ,                                             LCTL(KC_6) , LCTL(KC_7) , LCTL(KC_8) , LCTL(KC_9) , LCTL(KC_0) , _______,
  _______ , LALT(KC_1) , LALT(KC_2) , LALT(KC_3) , LALT(KC_4) , LALT(KC_5) ,                                             LALT(KC_6) , LALT(KC_7) , LALT(KC_8) , LALT(KC_9) , LALT(KC_0) , _______,
  _______ , _______    , _______    , _______    , _______    , _______    , _______ ,                         _______ , _______    , _______    , _______    , _______    , _______    , _______,
                                      _______    , _______    , _______    , _______ , _______ ,     _______ , _______ , _______    , _______    , _______
)
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [MDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif

// clang-format on
bool alt_tab_active = false;
bool sft_grv_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each
    // key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: "
            "%u, count: %u\n",
            keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
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

void matrix_scan_user(void) {
    achordion_task();
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        default:
            return false; // Deactivate Caps Word.
    }
}
