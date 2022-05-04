#include QMK_KEYBOARD_H
#include<stdio.h>

// sudo ./util/docker_build.sh handwired/dactyl_manuform/4x6_tb:gimmin:dfu-split-left
// sudo ./util/docker_build.sh handwired/dactyl_manuform/4x6_tb:gimmin:dfu-split-right

uint16_t my_cpi = USER_CPI;
char my_cpi_str[5];

//Layers
enum layers {
    _COLEMAKDH = 0,
    _RAISE,
    _LOWER,
    _NUMPAD,
    _MOUSE,
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
    NAV = TT(_LOWER),
    SPC = TT(_RAISE),
    SNIPE = SAFE_RANGE,
    RESET_CPI,
    CPI_UP,
    CPI_DOWN,
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
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINUS,
        KC_TAB,  LGUI_A,  LALT_R,  LSFT_S,  _LCTL_T, KC_G,                KC_M,    RCTL_N,  RSFT_E,  RALT_I,  RGUI_O,  KC_QUOT,
        NUMPD,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                          _______, _______,                                                 _______, _______,
                                            KC_BSPC, LT(NAV, KC_SPC),              LT(NAV, KC_ENT),
                                            MOUSE,   LT(SPC, KC_INS),              KC_DEL,
                                            NAV,     SPC,                 WASD,    _______
    ),

    [_RAISE] = LAYOUT_split_4x6_tb(

        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,               KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRAVE,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,              KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      _______,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    ),

    [_LOWER] = LAYOUT_split_4x6_tb(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,             KC_PGUP, KC_HOME, KC_END,  KC_PGDN, _______, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      _______,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    ),

    [_NUMPAD] = LAYOUT_split_4x6_tb(
        _______, _______, _______, _______, _______, _______,             _______, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_MINUS,
        _______, _______, _______, _______, _______, _______,             _______, KC_4,    KC_5,    KC_6,    _______, KC_ASTR,
        _______, _______, _______, _______, _______, _______,             KC_DOT,  KC_1,    KC_2,    KC_3,    KC_ENT,  KC_SLSH,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      KC_0,
                                            _______, _______,                      _______,
                                            _______, _______,             _______, _______
    ),

    [_MOUSE] = LAYOUT_split_4x6_tb(
        _______, _______, _______, _______, _______, _______,             _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, CPI_UP,
        _______, _______, _______, _______, _______, _______,             _______, KC_BTN1, KC_WH_U, KC_BTN2, SNIPE,   RESET_CPI,
        _______, _______, _______, _______, _______, _______,             _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, CPI_DOWN,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,                      _______,
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
            return FAST_TAPPING_TERM;
        case NAV:
            return FAST_TAPPING_TERM;
        case SPC:
            return FAST_TAPPING_TERM;
        case NUMPD:
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

    if(IS_LAYER_ON(_RAISE)) {
        oled_write_P(PSTR("\nSpcl"), false);
    } else {
        oled_write_P(PSTR("\n"), false);
    }
    if(IS_LAYER_ON(_LOWER)) {
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

