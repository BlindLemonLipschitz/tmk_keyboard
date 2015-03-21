#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP(  // layer 1: Base
  TAB, Q, W, E, R, T, Y, U, I, O, P, MINS, 
  LCTL, A, S, D, F, G, H, J, K, L, SCLN, QUOTE, 
  FN28, Z, X, C, V, FN6, FN5, M, COMM, DOT, SLSH, LSFT, 
  ESC, LCTL, LALT, LGUI, FN2, FN4, FN3, RGUI, RALT, FN5, TRNS),

[1] = KEYMAP(  // layer 1: Numbers
  GRV, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, TRNS, 
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, EQL, LBRC, RBRC, BSLS, TRNS, 
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, EQL, LBRC, RBRC, BSLS, 
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MS_BTN1, MS_BTN2, TRNS, TRNS, TRNS),

[2] = KEYMAP(  // layer 2: Shifted Numbers
  FN10, FN11, FN12, FN13, FN14, FN15, FN16, FN17, FN18, FN19, FN20, FN21, 
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, FN22, FN24, FN25, FN26, 
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),

[3] = KEYMAP(  // layer 3: Media + Macros, keys on left side of board
  POWER, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, 
  TRNS, MPRV, MPLY, MNXT, VOLD, VOLU, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
  TRNS, FN5, FN6, FN7, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
  FN9, FN8, FN10, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS), 

[4] = KEYMAP(  // layer 4: Mouse + Arrow, keys on right side of board
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MS_L, MS_D, MS_U, MS_R, TRNS, TRNS, 
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, LEFT, DOWN, UP, RIGHT, TRNS, TRNS, 
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MS_BTN1, MS_BTN2, TRNS, TRNS, TRNS),
};
enum macro_id {
PASSWORD1,
PASSWORD2,
PASSWORD3,
PASSWORD4,
PASSWORD5,
HELP,
};
/*
 * Macro definition
 */
#include "keymap_passwords.h"
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
            case PASSWORD1:     return MACRO_PASSWORD1;
            case PASSWORD2:     return MACRO_PASSWORD2;
            case PASSWORD3:     return MACRO_PASSWORD3;
            case PASSWORD4:     return MACRO_PASSWORD4;
            case PASSWORD5:     return MACRO_PASSWORD5;
            case HELP:          return MACRO_HELP;
	}
    }return MACRO_NONE;
}
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_TAP_KEY(3, KC_N),	       // FN0  - Media Keys
    [1]  = ACTION_LAYER_TAP_KEY(4, KC_B),	       // FN1  - Mouse and Arrows
    [2]  = ACTION_LAYER_TAP_KEY(1, KC_BSPC),	       // FN2  - Numbers
    [3]  = ACTION_LAYER_TAP_KEY(2, KC_ENT),	       // FN3  - Shifted Numbers
    [28] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_CAPS),     // FN28 - Shift, Caps 
    [4]  = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC),      // FN4  - Shift, Space
    [5]  = ACTION_MACRO(PASSWORD1),		       // FN5  - Password 1	
    [6]  = ACTION_MACRO(PASSWORD2),		       // FN6  - Password 2
    [7]  = ACTION_MACRO(PASSWORD3),		       // FN7  - Password 3
    [8]  = ACTION_MACRO(PASSWORD4),		       // FN8  - Password 4
    [9]  = ACTION_MACRO(HELP),			       // FN9  - Help
    [10] = ACTION_MACRO(PASSWORD5),		       // FN10 - Password 5
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_1),	       // FN11 - !	
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_2),	       // FN12 - @
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_3),	       // FN13 - #
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_4),	       // FN14 - $
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_5),	       // FN15 - %
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_6),	       // FN16 - ^
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_7),	       // FN17 - &
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_8),	       // FN18 - *
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_9),	       // FN19 - (
    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_0),	       // FN20 - )
    [21] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),         // FN21 - _
    [22] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),          // FN22 - +
    [23] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),          // FN22 - ~
    [24] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),         // FN22 - {
    [25] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),         // FN22 - }
    [26] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),         // FN22 - |
};
