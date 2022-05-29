#include QMK_KEYBOARD_H
#include<stdio.h>

// sudo ./util/docker_build.sh handwired/dactyl_manuform/4x6_tb:gimmin:dfu-split-left
// sudo ./util/docker_build.sh handwired/dactyl_manuform/4x6_tb:gimmin:dfu-split-right

uint16_t my_cpi = USER_CPI;
char my_cpi_str[5];

//Layers
enum layers {
    _COLEMAKDH = 0,
    _SPECIAL,
    _FUNCTION,
    _NAVIGATION,
    _NUMPAD,
    _MOUSE,
    _WASD,
};

enum custom_keycodes {
    SNIPE = SAFE_RANGE,
    RESET_CPI,
    CPI_UP,
    CPI_DOWN,
    //LGUI_A = LGUI_T(KC_A),
    LALT_R = LALT_T(KC_R),
    LSFT_S = LSFT_T(KC_S),
    _LCTL_T = LCTL_T(KC_T),
    RCTL_N = RCTL_T(KC_N),
    RSFT_E = RSFT_T(KC_E),
    RALT_I = RALT_T(KC_I),
    //RGUI_O = RGUI_T(KC_O),
    WASD = TG(_WASD),
    NAV = _NAVIGATION,
    SPC = _SPECIAL,
    FNC = _FUNCTION,
    //FNC_ENT = LT(FNC, KC_ENT),
    //MSE_SPC = LT(_MOUSE, KC_SPC),
    //NUM_BK = LT(_NUMPAD, KC_BSPC),
    //NAV_TAB = LT(NAV, KC_TAB),
    //SPC_DEL = LT(_SPECIAL, KC_DEL),

    NUM_A = LT(_NUMPAD, KC_A),
    //LGUI_Z = LGUI_T(KC_Z),
    RGUI_SLSH = RGUI_T(KC_SLSH),
    NAV_SPC = LT(NAV, KC_SPC),
    MSE_TAB = LT(_MOUSE, KC_TAB),
    FNC_DEL = LT(FNC, KC_DEL),
    SPC_ENT = LT(_SPECIAL, KC_ENT),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (colemakdh)
     * +-----------------------------------------+                              +-----------------------------------------+
     * |      |   q  |   w  |   f  |   p  |   b  |                              |   j  |   l  |   u  |   y  |   '" |      |
     * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
     * |      |a_NUM |r_ALT |s_SFT |t_CTL |   g  |                              |   m  |n_CTL |e_SFT |i_ALT |   o  |      |
     * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
     * |      |   z  |   x  |   c  |   d  |   v  |                              |   k  |   h  |  ,<  |  .>  |/?GUI |      |
     * +------+------+------+------+-------------+                              +-------------+------+------+------+------+
     *               |      |      |                                      .----.              |      |      |
     *               +-------------+-------------+                       /      \      +------+-------------+
     *                             | BSPC | Space|                      |        |     | ENT  |
     *                             +------+------+                       \      /      +------+
     *                                    +-------------+                 `----'+------+
     *                                    |      | TAB  |                       |  DEL |
     *                                    |------+------|                +------+------|
     *                                    |      |      |                |      |      |
     *                                    +-------------+                +-------------+
     */
    [_COLEMAKDH] = LAYOUT_split_4x6_tb(
        _______, KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,   _______,
        _______, NUM_A,  LALT_R,  LSFT_S,  _LCTL_T, KC_G,               KC_M,    RCTL_N,  RSFT_E,  RALT_I,  KC_O,      _______,
        _______, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,               KC_K,    KC_H,    KC_COMM, KC_DOT,  RGUI_SLSH, _______,
                         _______, _______,                                                         _______, _______,
                                  KC_BSPC, NAV_SPC,                              SPC_ENT,
                                  _______, MSE_TAB,                              FNC_DEL,
                                  _______, _______,                     _______, _______
    ),

    [_SPECIAL] = LAYOUT_split_4x6_tb(

        _______, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,  KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, KC_LALT, KC_LSFT,  KC_LCTL, _______,             KC_EQL,  KC_MINS, KC_LBRC, KC_RBRC, KC_SCLN, _______,
        _______, _______, KC_TILD, KC_GRAVE, KC_PIPE, _______,             KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, KC_BSLS, _______,
                          _______, _______,                                                 _______, _______,
                                             _______, _______,                      _______,
                                             _______, _______,                      _______,
                                             _______, _______,             _______, _______
    ),

    [_FUNCTION] = LAYOUT_split_4x6_tb(

        _______, KC_F1, KC_F2,   KC_F3,   KC_F4,  KC_PSCR,                  _______, WASD,      TG(_MOUSE), _______, _______, _______,
        _______, KC_F5, KC_F6,   KC_F7,   KC_F8,  _______,                  _______, KC_RCTL,   KC_RSFT,    KC_RALT, _______, _______,
        _______, KC_F9, KC_F10,  KC_F11,  KC_F12, KC_PAUS,                  _______, _______,   _______,    _______, KC_RGUI, _______,
                        _______, _______,                                                       _______,    _______,
                                          _______, _______,                          _______,
                                          _______, _______,                          _______,
                                          _______, _______,                 _______, _______
    ),

    [_NAVIGATION] = LAYOUT_split_4x6_tb(
        _______, KC_ESC,  _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LALT, KC_LSFT, KC_LCTL, _______,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,             KC_INS,  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      _______,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    ),

    [_NUMPAD] = LAYOUT_split_4x6_tb(
        _______, _______, _______, _______, _______, _______,             _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, _______, _______, _______, _______,             KC_DOT,  KC_4,    KC_5,    KC_6,    KC_DOT,  _______,
        _______, _______, _______, _______, _______, _______,             _______, KC_1,    KC_2,    KC_3,    _______, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      KC_0,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    ),

    [_MOUSE] = LAYOUT_split_4x6_tb(
        _______, KC_ESC,  _______, _______, _______, _______,             CPI_UP,    KC_HOME, KC_BTN3, KC_END,  KC_BTN4, _______,
        _______, _______, KC_LALT, KC_LSFT, KC_LCTL, _______,             RESET_CPI, KC_BTN1, KC_WH_U, KC_BTN2, SNIPE,   _______,
        _______, _______, _______, _______, _______, _______,             CPI_DOWN,  KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN5, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      TG(_MOUSE),
                                            _______, _______,                      WASD,
                                            _______, _______,             _______, _______
    ),

    [_WASD] = LAYOUT_split_4x6_tb(
        _______, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                _______, _______, _______, _______, _______, _______,
        _______, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                _______, _______, _______, _______, _______, _______,
        _______, KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, KC_SPC,                       TG(_MOUSE),
                                            _______, _______,                      WASD,
                                            _______, _______,             _______, _______
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MSE_TAB :
            return FAST_TAPPING_TERM;
        case NAV:
            return FAST_TAPPING_TERM;
        case SPC:
            return FAST_TAPPING_TERM;
        case NUM_A:
            return TAPPING_TERM;
        case FNC_DEL:
            return FAST_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SNIPE:
        if(record->event.pressed) {
            pointing_device_set_cpi(SNIPE_CPI);
            sprintf(my_cpi_str, "%d", SNIPE_CPI);
        } else {
            pointing_device_set_cpi(my_cpi);
            sprintf(my_cpi_str, "%d", my_cpi);
        }
        break;
    case RESET_CPI:
        if(record->event.pressed) {
            pointing_device_set_cpi(USER_CPI);
            sprintf(my_cpi_str, "%d", USER_CPI);
            my_cpi = USER_CPI;
        } else {
            // when RESET_CPI is released
        }
        break;
    case CPI_UP:
        if(record->event.pressed) {
            if(my_cpi + CPI_DELTA >= MAX_CPI) {
                pointing_device_set_cpi(MAX_CPI);
            } else {
                pointing_device_set_cpi(pointing_device_get_shared_cpi() + CPI_DELTA);
                my_cpi = pointing_device_get_shared_cpi();
            }
            sprintf(my_cpi_str, "%d", my_cpi);
        } else {
            // when CPI_UP is released
        }
        break;
    case CPI_DOWN:
        if(record->event.pressed) {
            if(my_cpi - CPI_DELTA <= MIN_CPI) {
                pointing_device_set_cpi(MIN_CPI);
            } else {
                pointing_device_set_cpi(pointing_device_get_shared_cpi() - CPI_DELTA);
                my_cpi = pointing_device_get_shared_cpi();
            }
            sprintf(my_cpi_str, "%d", my_cpi);
        } else {
            // when CPI_DOWN is released
        }
        break;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_clear();
    oled_write_P(PSTR("Layer\nBase"), false);

    if(IS_LAYER_ON(_SPECIAL)) {
        oled_write_P(PSTR("\nSpcl"), false);
    } else {
        oled_write_P(PSTR("\n"), false);
    }
    if(IS_LAYER_ON(_NAVIGATION)) {
        oled_write_P(PSTR("\nNav"), false);
    } else {
        oled_write_P(PSTR("\n"), false);
    }

    if(!is_keyboard_left()) {
        if(IS_LAYER_ON(_NUMPAD)) {
            oled_write_P(PSTR("\nNump"), false);
        } else {
            oled_write_P(PSTR("\n"), false);
        }
        if(IS_LAYER_ON(_MOUSE)) {
            oled_write_P(PSTR("\nMous"), false);
        } else {
            oled_write_P(PSTR("\n"), false);
        }
    }

    if(is_keyboard_left()) {
        if(IS_LAYER_ON(_WASD)) {
            oled_write_P(PSTR("\nWASD"), false);
        } else {
            oled_write_P(PSTR("\n"), false);
        }
        oled_write_P(PSTR("\n\n\n\nCRI:\n"), false);

        // Print CPI
        oled_write(my_cpi_str, false);
    }

    // Host Keyboard LED Status
    if(is_keyboard_master()) {
        led_t led_state = host_keyboard_led_state();
        oled_write_P(!led_state.num_lock ? PSTR("\n!NUM ") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("\nCAP ") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("\nSCR ") : PSTR("    "), false);
    }

    return false;
}
#endif

void keyboard_post_init_user(void) {
    pointing_device_set_cpi(my_cpi);
    sprintf(my_cpi_str, "%d", my_cpi);
}

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

