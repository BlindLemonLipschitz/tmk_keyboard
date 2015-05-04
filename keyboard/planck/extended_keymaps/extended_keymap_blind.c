#include "extended_keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = {  // layer 0: Qwerty
{KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS},
{KC_LCTL, KC_A, KC_S, KC_D, FUNC(20), FUNC(16), FUNC(17), FUNC(19), KC_K, KC_L, KC_SCLN, KC_QUOTE},
{FUNC(11), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT},
{KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, FUNC(2), KC_SPC, KC_NO, FUNC(3), KC_RGUI, KC_RALT, FUNC(12), FUNC(15)}},

[1] = {  // layer 1: Workman
{KC_TAB, KC_Q, KC_D, KC_R, KC_W, KC_B, KC_J, KC_F, KC_U, KC_P, KC_SCLN, KC_MINS},
{KC_LCTL, KC_A, KC_S, KC_H, FUNC(22), FUNC(16), FUNC(18), FUNC(21), KC_E, KC_O, KC_I, KC_QUOTE},
{FUNC(11), KC_Z, KC_X, KC_M, KC_C, KC_V, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT},
{KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, FUNC(2), KC_SPC, KC_NO, FUNC(3), KC_RGUI, KC_RALT, FUNC(12), FUNC(15)}},

[2] = {  // layer 2: Numbers and Special Chars
{S(KC_GRV), S(KC_5), S(KC_7), S(KC_SLSH), S(KC_EQL), S(KC_2), S(KC_4), S(KC_MINS), KC_LBRC, KC_RBRC, S(KC_1), S(KC_6)},
{KC_GRV, KC_SLSH, S(KC_9), KC_EQL, KC_0, S(KC_LBRC), S(KC_RBRC), KC_1, S(KC_8), S(KC_0), KC_EQL, S(KC_3)},
{FUNC(11), KC_6, KC_7, KC_8, KC_9, S(KC_BSLS), KC_BSLS, KC_2, KC_3, KC_4, KC_5, KC_RSFT},
{KC_TRNS, KC_TRNS, FUNC(1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(0), KC_TRNS, KC_TRNS}},

[3] = {  // layer 3: Mouse + Arrow, keys on right side of board
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(14), KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_MS_BTN1, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS}},

[4] = {  // layer 4: Media + Macros, keys on left side of board
{KC_POWER, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11},
{KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
{LGUI(S(KC_L)), FUNC(5), FUNC(6), FUNC(7), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
{FUNC(9), FUNC(8), FUNC(10), KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}},
};
enum macro_id {
PASSWORD1,
PASSWORD2,
PASSWORD3,
PASSWORD4,
PASSWORD5,
GOOGLE,
HELP,
ITUNES,
PINBOARD,
READLATER,
};
/*
 * Macro definition
 */
#include "keymap_passwords.h"
#include "keymap_blind_macros.h"
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
            case PASSWORD1:     return MACRO_PASSWORD1;
            case PASSWORD2:     return MACRO_PASSWORD2;
            case PASSWORD3:     return MACRO_PASSWORD3;
            case PASSWORD4:     return MACRO_PASSWORD4;
            case PASSWORD5:     return MACRO_PASSWORD5;
            case GOOGLE:        return MACRO_GOOGLE;
            case HELP:          return MACRO_HELP;
            case ITUNES:        return MACRO_ITUNES;
            case PINBOARD:      return MACRO_PINBOARD;
            case READLATER:     return MACRO_READLATER;
			

	}
    }return MACRO_NONE;
}
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_DEFAULT_LAYER_SET(0)                // FN0  - Qwerty
    [1]  = ACTION_DEFAULT_LAYER_SET(1)                // FN1  - Workman
    [2]  = ACTION_LAYER_TAP_KEY(3, KC_BSPC),	      // FN2  - Delete / Mouse Layer
    [3]  = ACTION_LAYER_TAP_KEY(4, KC_ENT),	      // FN3  - Return / Media Layer
    [4]  = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC),     // FN4  - Shift, Space
    [5]  = ACTION_MACRO(PASSWORD1),		      // FN5  - Password 1	
    [6]  = ACTION_MACRO(PASSWORD2),		      // FN6  - Password 2
    [7]  = ACTION_MACRO(PASSWORD3),		      // FN7  - Password 3
    [8]  = ACTION_MACRO(PASSWORD4),		      // FN8  - Password 4
    [9]  = ACTION_MACRO(HELP),			      // FN9  - Help
    [10] = ACTION_MACRO(PASSWORD5),		      // FN10 - Password 5
    [11] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_CAPS),    // FN11 - Shift, Caps 
    [12] = ACTION_MACRO(GOOGLE),		      // FN12 - Google
    [13] = ACTION_MACRO(PINBOARD),		      // FN13 - Pinboard
    [14] = ACTION_MACRO(ITUNES),		      // FN14 - Itunes
    [15] = ACTION_MACRO(READLATER),                   // FN15 - Read later Pinboard
    [16]  = ACTION_LAYER_TAP_KEY(2, KC_G),	      // FN16  - G / Num Layer
    [17]  = ACTION_LAYER_TAP_KEY(2, KC_H),	      // FN17  - H / Num Layer
    [18]  = ACTION_LAYER_TAP_KEY(2, KC_Y),	      // FN18  - Y / Num Layer
    [19]  = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_J),      // FN19  - J / Shift
    [20]  = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_F),      // FN20  - F / Shift
    [21]  = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_N),      // FN21  - N / Shift
    [22]  = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_T),      // FN22  - T / Shift
};
