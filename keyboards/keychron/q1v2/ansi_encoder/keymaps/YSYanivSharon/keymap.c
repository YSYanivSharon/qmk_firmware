#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

enum custom_keycodes {
    KC_CAPS_BACKLIGHT = SAFE_RANGE,
    KC_CAPS_WORD_BACKLIGHT,
    KC_RESET
};

#define KC_CBL  KC_CAPS_BACKLIGHT
#define KC_CWBL KC_CAPS_WORD_BACKLIGHT
#define KC_RST  KC_RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_82(
        KC_GRV    ,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11    , KC_F12,   KC_CWBL,            KC_MUTE,
        KC_ESC    ,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS   , KC_EQL,   KC_BSPC,            XXXXXXX,
        KC_TAB    ,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC   , KC_RBRC,  KC_BSLS,            XXXXXXX,
        MO(MAC_FN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT   ,           KC_ENT,             XXXXXXX,
        KC_LSFT   ,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH   ,           KC_RSFT,  KC_UP,
        KC_LCTL   ,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(MAC_FN), KC_APP,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_CBL ,                 KC_MPLY,
        _______,  _______,  _______,  _______,  KC_END ,  _______,  KC_HOME,  _______,  _______,  _______,  _______,  _______,    _______,  KC_DEL ,                 KC_RST,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  _______,    _______,  _______,                 KC_RST,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  _______,  _______,              _______,                 KC_RST,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              RCTL(KC_RSFT), _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,       _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_82(
        KC_GRV    ,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11    , KC_F12,   KC_CWBL,            KC_MUTE,
        KC_ESC    ,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS   , KC_EQL,   KC_BSPC,            XXXXXXX,
        KC_TAB    ,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC   , KC_RBRC,  KC_BSLS,            XXXXXXX,
        MO(WIN_FN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT   ,           KC_ENT,             XXXXXXX,
        KC_LSFT   ,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH   ,           KC_RSFT,  KC_UP,
        KC_LCTL   ,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_APP,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_CBL ,                 KC_MPLY,
        _______,  _______,  _______,  _______,  KC_END ,  _______,  KC_HOME,  _______,  _______,  _______,  _______,  _______,    _______,  KC_DEL ,                 KC_RST,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  _______,    _______,  _______,                 KC_RST,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  _______,  _______,              _______,                 KC_RST,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              RCTL(KC_RSFT), _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,       _______,  _______),
};

// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {[MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [MAC_FN] = {ENCODER_CCW_CW(KC_MRWD, KC_MFFD)}, [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [WIN_FN] = {ENCODER_CCW_CW(KC_MRWD, KC_MFFD)}};
#endif

void caps_word_set_user(bool active);
void set_caps_rgb_state(void);

// The count of pressed down reset keys (KC_RESET)
int reset_down_count = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS_BACKLIGHT:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    // If Caps Word is on, turn it off and don't touch Caps Lock
                    caps_word_off();
                } else {
                    // Otherwise, toggle standard Caps Lock
                    tap_code(KC_CAPS);
                }
                // Small delay to let the OS report the LED state back before updating RGB
                wait_ms(10);
                set_caps_rgb_state();
            }
            return false;
        case KC_CAPS_WORD_BACKLIGHT:
            if (record->event.pressed) {
                // Only trigger Caps Word if normal Caps Lock is off
                if (!host_keyboard_led_state().caps_lock) {
                    caps_word_on();
                }
            }
            return false;
        case KC_RESET:
            if (record->event.pressed) {
                reset_down_count++;

                if (reset_down_count >= 3) {
                    reset_keyboard();
                }
            } else {
                reset_down_count = 0;
            }
            return false;
        default:
            // Process all other keycodes normally
            return true;
    }
}

void caps_word_set_user(bool active) {
    set_caps_rgb_state();
}

void set_caps_rgb_state(void) {
    bool is_caps_lock = host_keyboard_led_state().caps_lock;
    bool is_caps_word = is_caps_word_on();

    if (is_caps_lock || is_caps_word) {
        rgb_matrix_enable();
    } else {
        rgb_matrix_disable();
    }
}
