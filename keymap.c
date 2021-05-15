/* Copyright 2021 Robert Hayden
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

// Heavily borrowed from standard keymap.c associated to the BDN9 QMK
// and the following references:
//
// See https://beta.docs.qmk.fm/using-qmk/guides/custom_quantum_functions for functions allowed in keymap.c
// See https://github.com/qmk/qmk_firmware/blob/master/keyboards/keebio/bdn9/keymaps/brandonschlack/keymap.c
// Posts on reddit r/OLKB
//

#include QMK_KEYBOARD_H

// Currently only have two encoders:  top left, top right
enum encoder_names {
  _LEFT,
  _RIGHT,
};

enum my_layers {
  _BASE = 0,   // mainly iTunes
  _LED         // Fun with LEDs
};

// AutoHotKey (AHK) - installed and configured independently
//   F14 - iTunes back (ctl-left arrow)
//   F16 - iTunes pause/play toggle (ctl-space)
//   F17 - iTunes mini player toggle (ctl-shit-M)
//   F19 - iTunes next (ctl-right arrow)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up   |                       | Knob 2: RBG+        |
        | Press: Mute         | F16 (AHK controlled)  | Press: RBG off/on   |
	---------------------------------------------------------------------
        | F14 (AHK controlled)| F17 (AHK controlled)  | F19 (AHK controlled)|
	---------------------------------------------------------------------
        | Toggle(1)           | F18                   | F20                 |
     */
    [_BASE] = LAYOUT(
        KC_MUTE, KC_F16, RGB_TOG,
        KC_F14 , KC_F17, KC_F19,
        TG(1)  , KC_F18, KC_F20
    ),
    /*
        | (Falls to layer 0) | (Falls to layer 0) | (Falls to layer 0) |
	---------------------------------------------------------------
        | RGB Mode Plain     | RGB Mode Breathing | (Falls to layer 0) |
	---------------------------------------------------------------
        | (Falls to layer 0) | RGB Mode Swirl     | RGB Mode Rainbow   |
     */
    [_LED] = LAYOUT(
        KC_TRNS , KC_TRNS, KC_TRNS,
        RGB_M_P , RGB_M_B, KC_TRNS,
        KC_TRNS , RGB_M_SW, RGB_M_R
    ),
};

// Called once at end of initialization.  Good to overwrite default settings
// I cannot seem to get this to work.....
void keyboard_post_init_user(void) {
//	rgblight_enable_noeeprom();  // Enabled RGB, without saving settings
//	rgblight_sethsv_noeeprom(169,255,255);  // Blue
//	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//      rgb_matrix_set_color(10, 255, 0, 0);
//      rgb_matrix_set_color(9, 255, 0, 0);
}

// Custom Indicators (e.g. Caps Lock Indicator)
//   Only include if RGB_MATRIX_ENABLE is true (#ifdef)
#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_user(void) {
	switch(get_highest_layer(layer_state)) {
		case _BASE:
			break;
		case _LED:
		    // Set LEDs 9 and 10 to be "red" to indicate layer 1
			rgb_matrix_set_color(9,255,0,0);
			rgb_matrix_set_color(10,255,0,0);
			break;
	}
}
#endif

// Runs code every time the layers get changed
//layer_state_t layer_state_set_user(layer_state_t state) {
//   switch(get_highest_layer(state)) {
//   case _BASE:
//	   break;
//   case _LED:
//	   break;
//   default:  // for any other layers, or the default layer
//	   break;
//   }
//   return state;
//}

// Called when encoder is twisted.  Flex on layer
void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);
    switch (layer) {
       case _BASE:
          if (index == _LEFT) {
              if (clockwise) {
                  tap_code(KC_VOLU); // volume up
              } else {
                  tap_code(KC_VOLD); // volume down
              }
	  }
          else if (index == _RIGHT) {
              if (clockwise) {
                  rgblight_step(); // change lighting effects
              } else {
                  rgblight_step_reverse();
              }
	  }
          break;
       case _LED:
          if (index == _LEFT) {
              if (clockwise) {
                  rgblight_increase_hue_noeeprom(); // change colors
              } else {
                  rgblight_decrease_hue_noeeprom();
              }
          }
          else if (index == _RIGHT) {
              if (clockwise) {
                  rgblight_increase_speed_noeeprom(); // change effect speeds faster
              } else {
                  rgblight_decrease_speed_noeeprom(); // change effect speeds slower
              }
          }
          break;
    }
}

