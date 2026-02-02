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
    TD_CTL_CENT,
    TD_SFT_STAB,
    TD_CTL_CTAB,
};

enum custom_keycodes {
    CK_CLEAR_ALL = SAFE_RANGE,

    // home row mods left
    CK_TILD,
    // home row mods right
    CK_LCBR, CK_RCBR, CK_COLN, CK_DQUO,
};

#define CASE_CK_TAP(from, to) \
    case from: return custom_key_tap(to, record);

#define CASE_CUSTOM_KEY_TAPS                    \
    /* home row mods left */                    \
    CASE_CK_TAP(LT(1,CK_TILD), KC_TILD);        \
    /* home row mods right */                   \
    CASE_CK_TAP(RSFT_T(CK_LCBR), KC_LCBR);      \
    CASE_CK_TAP(RGUI_T(CK_RCBR), KC_RCBR);      \
    CASE_CK_TAP(LT(3,CK_COLN), KC_COLN);        \
    CASE_CK_TAP(LT(1,CK_DQUO), KC_DQUO);


#define HRM(l1,l2,l3,l4,l5,l6,c1,c2,r1,r2,r3,r4,r5,r6)  \
    LT(1,l1), LT(3,l2), LGUI_T(l3),                     \
        LSFT_T(l4), l5, l6,                             \
        c1, c2,                                         \
        r1, r2, RSFT_T(r3),                             \
        RGUI_T(r4), LT(3,r5), LT(1,r6)

#define HRM_LAYOUT(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = HRM_LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
   CK_CLEAR_ALL, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
   HRM( KC_GRV , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , XXXXXXX, XXXXXXX, KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT),
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX, XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, QK_CAPS_WORD_TOGGLE,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
               KC_LGUI, ALT_T(KC_ESC), CTL_T(KC_ENT), SFT_T(KC_TAB),     SFT_T(KC_BSPC), LT(2,KC_SPC), ALT_T(KC_MHEN), GUI_T(KC_APP)
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
    ),

    [1] = HRM_LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
        QK_BOOT, _______, _______, _______, KC_F11 , KC_F12 ,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, QK_BOOT,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
   HRM( _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______),
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
            _______, ALT_T(KC_SPC), CTL_T(KC_BSPC), TD(TD_SFT_STAB),     _______, _______, _______, _______
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
    ),

    [2] = HRM_LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
        XXXXXXX, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
   HRM( CK_TILD, _______, KC_LBRC, KC_RBRC, KC_MINS,  KC_EQL, _______, _______, KC_PLUS, KC_UNDS, CK_LCBR, CK_RCBR, CK_COLN, CK_DQUO),
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, KC_BSLS, _______, _______, _______, _______, KC_PIPE, KC_LABK, KC_RABK, KC_QUES, _______,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
                 _______, _______, TD(TD_CTL_CENT), TD(TD_CTL_CTAB),     _______, _______, _______, _______
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
    ),

    [3] = HRM_LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
   HRM( _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , _______, _______),
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

static bool home_row_mod_tap(uint16_t keycode) {
    switch (keycode) {
    case LT(3, KC_A):
    case LGUI_T(KC_S):
    case LSFT_T(KC_D):
    case RSFT_T(KC_K):
    case RGUI_T(KC_L):
        return true;
    default:
        return false;
    }
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
    // C-k と C-a は溜めがちなので長めにする
    if (get_mods() == MOD_BIT(KC_LCTL)) {
        switch (keycode) {
        case LT(3,KC_A):
        case RSFT_T(KC_K):
            return 500;
        }
    }

    switch (keycode) {
    case CTL_T(KC_ENT):
    case LT(2,KC_SPC):
        return 115;
    }

    if (thumb_mod_tap(keycode)) {
        return 130;
    }
    if (home_row_mod_tap(keycode)) {
        return 130;
    }

    return TAPPING_TERM;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CTL_T(KC_ENT):
    case LT(2,KC_SPC):
        return 115;
    }
    return QUICK_TAP_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    if (strong_hold_keycode(keycode)) {
        return true;
    }
    return false;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    if (home_row_mod_tap(keycode)) {
        return true;
    }
    return false;
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

#define ACTION_TAP_DANCE_MOD_TAP(mod_kc, tap_kc) \
    { .fn = {tap_dance_mod_tap_on_each_tap, tap_dance_mod_tap_finished, tap_dance_mod_tap_reset, NULL}, .user_data = (void *)&((tap_dance_mod_tap_t){mod_kc, tap_kc}), }

typedef struct {
    uint16_t mod_kc;
    uint16_t tap_kc;
} tap_dance_mod_tap_t;

static void tap_dance_mod_tap_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_mod_tap_t *mod_tap = (tap_dance_mod_tap_t *)user_data;

    if (state->count == 1) {
        return;
    }

    if (state->count == 2) {
        // send first tap delayed
        tap_code16(mod_tap->tap_kc);
    }
    // repeat tap
    tap_code16(mod_tap->tap_kc);
}

static void tap_dance_mod_tap_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_mod_tap_t *mod_tap = (tap_dance_mod_tap_t *)user_data;

    if (state->count > 1) {
        return;
    }

    if (state->pressed || state->interrupted) {
        register_code16(mod_tap->mod_kc);
    } else {
        tap_code16(mod_tap->tap_kc);
    }
}

static void tap_dance_mod_tap_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_mod_tap_t *mod_tap = (tap_dance_mod_tap_t *)user_data;
    unregister_code16(mod_tap->mod_kc);
}


tap_dance_action_t tap_dance_actions[] = {
    [TD_CTL_CENT] = ACTION_TAP_DANCE_MOD_TAP(KC_LCTL, LCTL(KC_ENT)),
    [TD_SFT_STAB] = ACTION_TAP_DANCE_MOD_TAP(KC_LSFT, LSFT(KC_TAB)),
    [TD_CTL_CTAB] = ACTION_TAP_DANCE_MOD_TAP(KC_LCTL, LCTL(KC_TAB)),
};

static bool custom_key_tap(uint16_t real_keycode, keyrecord_t *record) {
    if (record->tap.count > 0) {
        if (record->event.pressed) {
            register_code16(real_keycode);
        } else {
            unregister_code16(real_keycode);
        }
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CK_CLEAR_ALL:
        if (record->event.pressed) {
            clear_mods();
            layer_clear();
        }
        return false;
    CASE_CUSTOM_KEY_TAPS;
    }
    return true;
}
