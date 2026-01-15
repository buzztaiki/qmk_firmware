/*
  Copyright 2012 Jun Wako <wakojun@gmail.com>
  Copyright 2015 Jack Humbert
  Copyright 2025 Taiki Sugawara
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

#define KC_HEN KC_INT4
#define KC_MHEN KC_INT5

enum {
    TD_ALT_HEN,
    TD_CTL_CENT,
    TD_SFT_STAB,
    TD_CTL_CTAB,
};

enum custom_keycodes {
    CK_CLEAR_ALL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+---------+--------+---------+--------+--------.
        KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , CK_CLEAR_ALL,
    //|--------+--------+--------+--------+--------+--------|                 |--------+---------+--------+---------+--------+--------|
   LT(1,KC_GRV), KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , XXXXXXX, XXXXXXX, KC_H   , KC_J    , KC_K   , KC_L    , LT(3,KC_SCLN), LT(1,KC_QUOT),
    //|--------+--------+--------+--------+--------+--------|                 |--------+---------+--------+---------+--------+--------|
        TG(1)  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX, XXXXXXX, KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, XXXXXXX,
    //`--------+--------+--------+--------+--------+--------/                 \--------+---------+--------+---------+--------+--------'
               KC_LGUI, ALT_T(KC_ESC), CTL_T(KC_ENT), SFT_T(KC_TAB),     SFT_T(KC_BSPC), LT(2,KC_SPC), TD(TD_ALT_HEN), GUI_T(KC_APP)
    //                  `--------+--------+--------+--------'                 `--------+---------+--------+---------'
    ),

    [1] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
        QK_BOOT, _______, _______, _______, KC_F11 , KC_F12 ,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, QK_BOOT,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
            _______, ALT_T(KC_SPC), CTL_T(KC_BSPC), TD(TD_SFT_STAB),     _______, _______, ALT_T(KC_MHEN), _______
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
    ),

    [2] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
        XXXXXXX, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        KC_TILD, _______, KC_LBRC, KC_RBRC, KC_MINS,  KC_EQL, _______, _______, KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, KC_BSLS, _______, _______, _______, _______, KC_PIPE, KC_LABK, KC_RABK, KC_QUES, _______,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
                 _______, _______, TD(TD_CTL_CENT), TD(TD_CTL_CTAB),     _______, _______, _______, _______
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
    ),

    [3] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , _______, _______,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, KC_0   , _______, _______, _______, _______, KC_0   , _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
                                    _______, _______, KC_0, _______,     _______, KC_0, _______, _______
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
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

static bool thumb_mod_tap(uint16_t keycode) {
    uint16_t thumb_tap_keycodes[] = {
        KC_APP, KC_BSPC, KC_DEL, KC_ENT, KC_ESC, KC_SPC, KC_TAB, KC_HEN, KC_MHEN
    };
    for (int i = 0; i < ARRAY_SIZE(thumb_tap_keycodes); i++) {
        if (keycode == CTL_T(thumb_tap_keycodes[i]) ||
            keycode == ALT_T(thumb_tap_keycodes[i]) ||
            keycode == SFT_T(thumb_tap_keycodes[i]) ||
            keycode == GUI_T(thumb_tap_keycodes[i]) ||
            keycode == LT(2,thumb_tap_keycodes[i])) {
            return true;
        }
    }
    return false;
}


static bool strong_hold_keycode(uint16_t keycode) {
    if (thumb_mod_tap(keycode)) {
        return true;
    }

    switch (keycode) {
    // pinky
    case LT(1,KC_GRV):
    case LT(1,KC_QUOT):
    case LT(3,KC_SCLN):
        return true;
    default:
        return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(2,KC_SPC):
        return 115;
    }

    if (thumb_mod_tap(keycode)) {
        return 130;
    }

    return TAPPING_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return strong_hold_keycode(keycode);
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    if (strong_hold_keycode(tap_hold_keycode)) {
        return true;
    }

    return get_chordal_hold_default(tap_hold_record, other_record);
}

// TAP_DANCE_MOD_TAP
// tap to send tap_kc, held to send mod_kc

#define ACTION_TAP_DANCE_MOD_TAP(mod_kc, tap_kc, tap_count) \
    { .fn = {tap_dance_mod_tap_on_each_tap, tap_dance_mod_tap_finished, tap_dance_mod_tap_reset, NULL}, .user_data = (void *)&((tap_dance_mod_tap_t){mod_kc, tap_kc, tap_count}), }

typedef struct {
    uint16_t mod_kc;
    uint16_t tap_kc;
    uint8_t tap_start;
} tap_dance_mod_tap_t;

static void tap_dance_mod_tap_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_mod_tap_t *mod_tap = (tap_dance_mod_tap_t *)user_data;

    if (state->count == 1) {
        return;
    }

    if (state->count == 2 && mod_tap->tap_start == 1) {
        // send first tap delayed
        tap_code16(mod_tap->tap_kc);
    }
    if (state->count >= mod_tap->tap_start) {
        // repeat tap
        tap_code16(mod_tap->tap_kc);
    }
}

static void tap_dance_mod_tap_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_mod_tap_t *mod_tap = (tap_dance_mod_tap_t *)user_data;

    if (state->count > 1) {
        return;
    }

    if (state->pressed || state->interrupted) {
        register_code16(mod_tap->mod_kc);
    } else if (mod_tap->tap_start == 1) {
        tap_code16(mod_tap->tap_kc);
    }
}

static void tap_dance_mod_tap_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_mod_tap_t *mod_tap = (tap_dance_mod_tap_t *)user_data;
    unregister_code16(mod_tap->mod_kc);
}


tap_dance_action_t tap_dance_actions[] = {
    [TD_ALT_HEN] = ACTION_TAP_DANCE_MOD_TAP(KC_LALT, KC_HEN, 2),
    [TD_CTL_CENT] = ACTION_TAP_DANCE_MOD_TAP(KC_LCTL, LCTL(KC_ENT), 1),
    [TD_SFT_STAB] = ACTION_TAP_DANCE_MOD_TAP(KC_LSFT, LSFT(KC_TAB), 1),
    [TD_CTL_CTAB] = ACTION_TAP_DANCE_MOD_TAP(KC_LCTL, LCTL(KC_TAB), 1),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CK_CLEAR_ALL:
        if (record->event.pressed) {
            clear_mods();
            layer_clear();
        }
        break;
    }
    return true;
}
