#include QMK_KEYBOARD_H

//Layers
enum layers {
    _COLEMAKDH = 0,
    _SPECIAL,
    _NAVIGATION,
    _MOUSE,
    _NUMPAD,
    _WASD,
};

enum custom_keycodes {
    LGUI_A = LGUI_T(KC_A),
    LALT_R = LALT_T(KC_R),
    LSFT_S = LSFT_T(KC_S),
    _LCTL_T = LCTL_T(KC_T),
    RCTL_N = RCTL_T(KC_N),
    RSFT_E = RSFT_T(KC_E),
    RALT_I = RALT_T(KC_I),
    RGUI_O = RGUI_T(KC_O),
    MOUSE = TT(_MOUSE),
    NUMPD = TT(_NUMPAD),
    WASD = TG(_WASD),
    NAV = TT(_NAVIGATION),
    SPC = TT(_SPECIAL),
};

enum tap_dance {
    TD_GRAVE = 0,
    TD_MINUS,
    TD_EQUAL,
    TD_CPIUP,
    TD_CPIDN,
};

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (colemakdh)
     * +-----------------------------------------+                              +-----------------------------------------+
     * |  ESC |   q  |   w  |   f  |   p  |   b  |                              |   j  |   l  |   u  |   y  |   ;: |  -_  |
     * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
     * |  TAB |a_GUI |r_ALT |s_SFT |t_CTL |   g  |                              |   m  |n_CTL |e_SFT |i_ALT |o_GUI |  '"  |
     * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
     * | NUMPD|   z  |   x  |   c  |   d  |   v  |                              |   k  |   h  |  ,>  |  .>  |  /?  |  \|  |
     * +------+------+------+------+-------------+                              +-------------+------+------+------+------+
     *               |  {[  |   (  |                                      .----.              |  )   |  ]}  |
     *               +-------------+-------------+                       /      \      +------+-------------+
     *                             |BSPC  | Space|                      |        |     |Enter |
     *                             +------+------+                       \      /      +------+
     *                                    +-------------+                 `----'+------+
     *                                    | MOUSE| DEL  |                       | Home |
     *                                    |------+------|                +------+------|
     *                                    |  NAV | SPC  |                | WASD |  End |
     *                                    +-------------+                +-------------+
     */
    [_COLEMAKDH] = LAYOUT_split_4x6_tb(
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, TD(TD_MINUS),
        KC_TAB,  LGUI_A,  LALT_R,  LSFT_S,  _LCTL_T, KC_G,                KC_M,    RCTL_N,  RSFT_E,  RALT_I,  RGUI_O,  KC_QUOT,
        NUMPD,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                          KC_LBRC, KC_LPRN,                                                 KC_RPRN, KC_RBRC,
                                            KC_BSPC, KC_SPC,                       KC_ENT,
                                            MOUSE,   KC_DEL,                       KC_HOME,
                                            NAV,     SPC,                 WASD,    KC_END
    ),

    [_SPECIAL] = LAYOUT_split_4x6_tb(
   TD(TD_GRAVE), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,             KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, TD(TD_EQUAL),
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                          _______, KC_PSCR,                                                 _______, _______,
                                            _______, _______,                      DT_PRNT,
                                            _______, _______,                      DT_UP,
                                            _______, _______,             _______, DT_DOWN
    ),

    [_NAVIGATION] = LAYOUT_split_4x6_tb(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      _______,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    ),

    [_MOUSE] = LAYOUT_split_4x6_tb(
        _______, _______, _______, _______, _______, _______,             _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, TD(TD_CPIUP),
        _______, _______, _______, _______, _______, _______,             KC_WH_L, KC_BTN1, KC_WH_U, KC_BTN2, KC_WH_R, _______,
        _______, _______, _______, _______, _______, _______,             _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, TD(TD_CPIDN),
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      _______,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    ),

    [_NUMPAD] = LAYOUT_split_4x6_tb(
        _______, _______, _______, _______, _______, _______,             _______, KC_7,    KC_8,    KC_9,    KC_PLUS, TD(TD_MINUS),
        _______, _______, _______, _______, _______, _______,             _______, KC_4,    KC_5,    KC_6,    _______, KC_ASTR,
        _______, _______, _______, _______, _______, _______,             _______, KC_1,    KC_2,    KC_3,    KC_ENT,  KC_SLSH,
                          _______, _______,                                                 _______, KC_DOT,
                                            _______, _______,                      KC_0,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    ),

    [_WASD] = LAYOUT_split_4x6_tb(
        _______, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                _______, _______, _______, _______, _______, _______,
        _______, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                _______, _______, _______, _______, _______, _______,
        _______, KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      _______,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    )

    /*[_TEMPLATE] = LAYOUT_split_4x6_tb(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      _______,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    )*/
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOUSE:
            return 100;
        case NAV:
            return 100;
        case SPC:
            return 100;
        case NUMPD:
            return 100;
        default:
            return TAPPING_TERM;
    }
}

// Tap Dance Functions
void dance_grave_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        register_code (KC_RSFT);
    }
    register_code (KC_GRAVE);
}

void dance_cpiup_finished(qk_tap_dance_state_t *state, void *user_data) {
    pointing_device_set_cpi(pointing_device_get_cpi() + 100);
}

void dance_cpidn_finished(qk_tap_dance_state_t *state, void *user_data) {
    pointing_device_set_cpi(pointing_device_get_cpi() - 100);
}

void dance_minus_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        register_code (KC_RSFT);
    }
    register_code (KC_MINUS);
}

void dance_equal_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        register_code (KC_RSFT);
    }
    register_code (KC_EQL);
}

void dance_grave_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        unregister_code (KC_RSFT);
    }
    unregister_code (KC_GRAVE);
}

void dance_minus_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        unregister_code (KC_RSFT);
    }
    unregister_code (KC_MINUS);
}

void dance_equal_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        unregister_code (KC_RSFT);
    }
    unregister_code (KC_EQL);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GRAVE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_grave_finished, dance_grave_reset)
   ,[TD_MINUS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_minus_finished, dance_minus_reset)
   ,[TD_EQUAL] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_equal_finished, dance_equal_reset)
   ,[TD_CPIUP] = ACTION_TAP_DANCE_FN (dance_cpiup_finished)
   ,[TD_CPIDN] = ACTION_TAP_DANCE_FN (dance_cpidn_finished)
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_left()) {
        return OLED_ROTATION_180;
    }

    return rotation;
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _COLEMAKDH:
            oled_write_P(PSTR("Default\n"), false);
            break;

        case _SPECIAL:
            oled_write_P(PSTR("Special\n"), false);
            break;

        case _NAVIGATION:
            oled_write_P(PSTR("Navigation\n"), false);
            break;

        case _MOUSE:
            if (!is_keyboard_left()) {
                oled_write_P(PSTR("Mouse"), false);
            }

            oled_write_P(PSTR("\n"), false);
            break;

        case _NUMPAD:
            if (!is_keyboard_left()) {
                oled_write_P(PSTR("Numpad"), false);
            }

            oled_write_P(PSTR("\n"), false);
            break;

        case _WASD:
            if (is_keyboard_left()) {
                oled_write_P(PSTR("WASD"), false);
            }

            oled_write_P(PSTR("\n"), false);
            break;

        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif

void pointing_device_init_user(void) {
    pointing_device_set_cpi(1600);
}

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

