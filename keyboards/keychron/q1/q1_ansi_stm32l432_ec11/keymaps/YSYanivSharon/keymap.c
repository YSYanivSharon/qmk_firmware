/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    [MAC_BASE] = LAYOUT_all(
                                                                                                                                                            KC_VOLD, KC_VOLU,
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_all(
                                                                                                                                                            RGB_VAD, RGB_VAI,
        _______,  KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_all(
                                                                                                                                                               KC_VOLD, KC_VOLU,
        KC_GRV    ,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11    , KC_F12,   KC_CWBL,            KC_MUTE,
        KC_ESC    ,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS   , KC_EQL,   KC_BSPC,            KC_PSCR,
        KC_TAB    ,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC   , KC_RBRC,  KC_BSLS,            XXXXXXX,
        MO(WIN_FN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT   ,           KC_ENT,             XXXXXXX,
        KC_LSFT   ,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH   ,           KC_RSFT,  KC_UP,
        KC_LCTL   ,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_APP,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_all(
                                                                                                                                                                 KC_MRWD, KC_MFFD,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_CBL ,                 KC_MPLY,
        _______,  _______,  _______,  _______,  KC_END ,  _______,  KC_HOME,  _______,  _______,  _______,  _______,  _______,    _______,  KC_DEL ,                 KC_RST,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  _______,    _______,  _______,                 KC_RST,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  _______,  _______,              _______,                 KC_RST,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              RCTL(KC_RSFT), _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,       _______,  _______),
};

// clang-format on

#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

#define ENCODERS 1
static uint8_t  encoder_state[ENCODERS] = {0};
static keypos_t encoder_cw[ENCODERS]    = {{ 8, 5 }};
static keypos_t encoder_ccw[ENCODERS]  = {{ 7, 5 }};

void encoder_action_unregister(void) {
    for (int index = 0; index < ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t) {
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
            };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void encoder_action_register(uint8_t index, bool clockwise) {
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

void matrix_scan_user(void) {
    encoder_action_unregister();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif

void caps_word_set_user(bool active);
void set_caps_rgb_state(void);

// The capslock states
enum caps_state {
    inactive = 0,
    active = 1,
    word = 2
};

// The current capslock state
int caps_state = inactive;

// The count of pressed down reset keys (KC_RESET)
int reset_down_count = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS_BACKLIGHT:
            if (record->event.pressed) {
                // Handles capslock according to its current state
                switch (caps_state)
                {
                    case inactive:
                        // If capslock is off, enable it
                        tap_code(KC_CAPS);
                        caps_state = active;
                        break;
                    case active:
                        // If capslock is on, disable it
                        tap_code(KC_CAPS);
                        caps_state = inactive;
                        break;
                    case word:
                        // If caps word is on, disable it
                        caps_word_off();
                        caps_state = inactive;
                        break;
                }

                // Update rgb state to signal if capslock is on
                set_caps_rgb_state();
            }
            return false;
        case KC_CAPS_WORD_BACKLIGHT:
            if (record->event.pressed) {
                // Activates caps word only when capslock is off
                if (caps_state == inactive) {
                    caps_word_on();
                }
            }
            return false;
        case KC_RESET:
            if (record->event.pressed) {
                reset_down_count++;

                if (reset_down_count == 3) {
                    reset_keyboard();
                }
            } else {
                reset_down_count--;
            }
            return false;
        default:
            // Process all other keycodes normally
            return true;
    }
}

void caps_word_set_user(bool active) {
    caps_state = active ? word : inactive;
    set_caps_rgb_state();
}

void set_caps_rgb_state(void) {
    // Toggle RGB only if its current state isn't the desired one
    if (caps_state == inactive) {
        rgb_matrix_disable();
    }
    else {
        rgb_matrix_enable();
    }
}
