#include QMK_KEYBOARD_H

#define XXX KC_NO

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
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          /***/          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , XXXXXXX, /***/ XXXXXXX, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , CK_CLEAR_ALL,
   LT(1,KC_GRV), KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , XXXXXXX, /***/ XXXXXXX, KC_H   , KC_J   , KC_K   , KC_L   , LT(3,KC_SCLN), LT(1,KC_QUOT),
        TG(1)  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX, /***/ XXXXXXX, KC_N   , KC_M   , KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  XXX, XXX, XXX, KC_LGUI, ALT_T(KC_ESC), CTL_T(KC_ENT), SFT_T(KC_TAB), /***/ SFT_T(KC_BSPC), LT(2,KC_SPC), TD(TD_ALT_HEN), GUI_T(KC_APP), XXX, XXX, XXX
    ),
    [1] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______,          /***/          _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, KC_F11 , KC_F12 , _______, /***/ _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, /***/ _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, /***/ _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, _______, _______,
XXX,XXX,XXX,  _______, ALT_T(KC_SPC), CTL_T(KC_BSPC), TD(TD_SFT_STAB), /***/ _______, _______, ALT_T(KC_MHEN), _______, XXX, XXX, XXX

    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,          /***/          _______, _______, _______, _______, _______, _______,
        XXXXXXX, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, _______, /***/ _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
        KC_TILD, _______, KC_LBRC, KC_RBRC, KC_MINS,  KC_EQL, _______, /***/ _______, KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO,
        _______, _______, _______, _______, KC_BSLS, _______, _______, /***/ _______, _______, KC_PIPE, KC_LABK, KC_RABK, KC_QUES, _______,
    XXX, XXX, XXX, _______, _______, TD(TD_CTL_CENT), TD(TD_CTL_CTAB), /***/ _______, _______, _______, _______, XXX, XXX, XXX

    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______,          /***/          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, /***/ _______, _______, _______, _______, _______, _______, _______,
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______, /***/ _______, KC_6   , KC_7   , KC_8   , KC_9   , _______, _______,
        _______, _______, _______, _______, KC_0   , _______, _______, /***/ _______, _______, KC_0   , _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_0   , _______, /***/ _______, KC_0   , _______, _______, _______, _______, _______
    )
};

void keyboard_post_init_user(void) {
    // turn off default backlight
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, r, g, b)
    // g_led_config.matrix_co[row][col]

    // indicator for split keyboard connection status
    RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[1][6], 64, 32, 0);
    RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[6][6], 64, 32, 0);

    // lock state
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 128);
    }
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 128);
    }
    if (host_keyboard_led_state().scroll_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 128);
    }

    // layer state
    switch (get_highest_layer(layer_state)) {
        case 1:
            RGB_MATRIX_INDICATOR_SET_COLOR(37, 0, 0, 128);

            RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[0][0], 0, 0, 128);
            RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[1][0], 0, 0, 128);
            RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[2][0], 0, 0, 128);

            break;
        case 2:
            RGB_MATRIX_INDICATOR_SET_COLOR(38, 0, 0, 128);

            RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[0][1], 0, 128, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[1][1], 0, 128, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[2][1], 0, 128, 0);

            break;
        case 3:
            RGB_MATRIX_INDICATOR_SET_COLOR(39, 0, 0, 128);

            RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[0][2], 128, 128, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[1][2], 128, 128, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[2][2], 128, 128, 0);

            break;
    }
    return false;
}

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

// TAP_DANCE_ALT_HENKAN
// tap twice or more to send henkan, otherwise to send alt

static void tap_dance_alt_henkan_on_each_tap(tap_dance_state_t *state, void *user_data) {
    if (state->count > 1) {
        register_code16(KC_HEN);
    }
}

static void tap_dance_alt_henkan_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1
        && (state->pressed || state->interrupted))
    {
        register_code16(KC_LALT);
    }
}

static void tap_dance_alt_henkan_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LALT);
    } else if (state->count > 1) {
        unregister_code16(KC_HEN);
    }
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
    // do nothing
}

static void tap_dance_mod_tap_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_mod_tap_t *mod_tap = (tap_dance_mod_tap_t *)user_data;

    if (state->pressed || state->interrupted) {
        register_code16(mod_tap->mod_kc);
    }
    else {
        tap_code16(mod_tap->tap_kc);
    }
}

static void tap_dance_mod_tap_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_mod_tap_t *mod_tap = (tap_dance_mod_tap_t *)user_data;
    unregister_code16(mod_tap->mod_kc);
}


tap_dance_action_t tap_dance_actions[] = {
    [TD_ALT_HEN] = ACTION_TAP_DANCE_FN_ADVANCED(tap_dance_alt_henkan_on_each_tap, tap_dance_alt_henkan_finished, tap_dance_alt_henkan_reset),
    [TD_CTL_CENT] = ACTION_TAP_DANCE_MOD_TAP(KC_LCTL, LCTL(KC_ENT)),
    [TD_SFT_STAB] = ACTION_TAP_DANCE_MOD_TAP(KC_LSFT, LSFT(KC_TAB)),
    [TD_CTL_CTAB] = ACTION_TAP_DANCE_MOD_TAP(KC_LCTL, LCTL(KC_TAB)),
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
