#include "extended_keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = {  // layer 1: Base
{KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS},
{KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOTE},
{FUNC(11), KC_Z, KC_X, KC_C, KC_V, FUNC(6), FUNC(5), KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT},
{KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, FUNC(2), FUNC(4), FUNC(3), KC_RGUI, KC_RALT, FUNC(5), KC_TRNS}},

[1] = {  // layer 1: Numbers
{KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS}},

[2] = {  // layer 2: Shifted Numbers
{S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINS)},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_EQL), S(KC_LBRC), S(KC_RBRC), S(KC_BSLS)}, 
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}},

[3] = {  // layer 3: Media + Macros, keys on left side of board
{KC_POWER, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11},
{KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
{KC_TRNS, FUNC(5), FUNC(6), FUNC(7), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
{FUNC(9), FUNC(8), FUNC(10), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}},

[4] = {  // layer 4: Mouse + Arrow, keys on right side of board
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS}},
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
    [4]  = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC),      // FN4  - Shift, Space
    [5]  = ACTION_MACRO(PASSWORD1),		       // FN5  - Password 1	
    [6]  = ACTION_MACRO(PASSWORD2),		       // FN6  - Password 2
    [7]  = ACTION_MACRO(PASSWORD3),		       // FN7  - Password 3
    [8]  = ACTION_MACRO(PASSWORD4),		       // FN8  - Password 4
    [9]  = ACTION_MACRO(HELP),			       // FN9  - Help
    [10] = ACTION_MACRO(PASSWORD5),		       // FN10 - Password 5
    [11] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_CAPS),     // FN11 - Shift, Caps 
};
