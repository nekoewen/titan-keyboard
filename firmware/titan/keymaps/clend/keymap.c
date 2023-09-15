#include "titan.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		         KC_W,                             KC_T, KC_Y,           KC_MUTE, 
		KC_A,    KC_S, KC_D,   KC_ESC, KC_ENT,     KC_F, KC_G, KC_J, KC_K, 
		KC_SPACE,                                  KC_V, KC_B, KC_N, KC_M),
 
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
