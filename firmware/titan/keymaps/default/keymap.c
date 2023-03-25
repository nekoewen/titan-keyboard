#include "titan.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		         KC_UP,                            KC_H, KC_B,           KC_MUTE, 
		KC_LEFT, KC_DOWN, KC_RGHT, KC_ESC, KC_ENT, KC_A, KC_S, KC_D, KC_F, 
		KC_UP,                                     KC_Z, KC_X, KC_C, KC_V),

	LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, 
		KC_TRNS, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD),

};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return true;
}

void matrix_init_user(void) {
}
