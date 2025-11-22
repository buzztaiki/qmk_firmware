/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _ADJUST,
};

#define KC_L_SPC LT(_LOWER, KC_SPC)  // lower
#define KC_R_ENT LT(_RAISE, KC_ENT)  // raise
#define KC_G_JA LGUI_T(KC_LNG1)     // cmd or win
#define KC_G_EN LGUI_T(KC_LNG2)     // cmd or win
#define KC_C_BS LCTL_T(KC_BSPC)      // ctrl
#define KC_A_DEL ALT_T(KC_DEL)       // alt

#define _KC_HEN KC_INT4
#define _KC_MHEN KC_INT5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+---------+--------+---------+--------+--------.
        KC_BSLS, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                 |--------+---------+--------+---------+--------+--------|
   LT(1,KC_GRV), KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , XXXXXXX, XXXXXXX, KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN, LT(1,KC_QUOT),
    //|--------+--------+--------+--------+--------+--------|                 |--------+---------+--------+---------+--------+--------|
  SFT_T(KC_EQL), KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX, XXXXXXX, KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, LT(2,KC_MINS),
    //`--------+--------+--------+--------+--------+--------/                 \--------+---------+--------+---------+--------+--------'
               KC_LGUI, ALT_T(KC_ESC), CTL_T(KC_TAB), LT(2,KC_TAB),     SFT_T(KC_BSPC), CTL_T(KC_SPC), ALT_T(_KC_HEN), GUI_T(KC_APP)
    //                  `--------+--------+--------+--------'                 `--------+---------+--------+---------'
    ),

    [1] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
        QK_BOOT, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, QK_BOOT,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, KC_F11 , KC_F12 , _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
                    _______, _______, CTL_T(KC_SPC), SFT_T(KC_BSPC),     SFT_T(KC_DEL), _______, ALT_T(_KC_MHEN), _______
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
    ),

    [2] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,   KC_10, _______,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_COLN, KC_DQUO,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        KC_PLUS, _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_LABK, KC_RABK, KC_QUES, KC_UNDS,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
                               _______, _______, _______, S(KC_TAB),     _______, _______, _______, _______
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
    ),

    [3] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+--------+--------+--------+--------+--------.
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                     \--------+--------+--------+--------+--------+--------'
                          _______, _______, _______, _______,                       _______, _______, _______, _______
    //                  `--------+--------+--------+--------'                     `--------+--------+--------+--------'
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO)      },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [3] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  }
};
#endif

static bool strong_hold_keycode(uint16_t keycode) {
    switch (keycode) {
    // L0 thumb cluster
    case ALT_T(KC_ESC):
    case CTL_T(KC_ENT):
    case SFT_T(KC_TAB):  case LT(2,KC_TAB):
    case SFT_T(KC_BSPC): case LT(2,KC_BSPC):
    case CTL_T(KC_SPC):
    case ALT_T(_KC_HEN):
    case GUI_T(KC_APP):

    // L1 thumb cluster
    case SFT_T(KC_DEL):  case LT(2,KC_DEL):
    case ALT_T(_KC_MHEN):

     // pinkey
    case LT(1,KC_BSLS):
    case LT(1,KC_QUOT):
    case SFT_T(KC_EQL):  case LT(2,KC_EQL):
    case SFT_T(KC_MINS): case LT(2,KC_MINS):
        return true;
    default:
        return false;
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
 uint16_t other_keycode, keyrecord_t* other_record) {
    if (strong_hold_keycode(tap_hold_keycode)) {
        return true;
    }

    return get_chordal_hold_default(tap_hold_record, other_record);
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return strong_hold_keycode(keycode);
}
