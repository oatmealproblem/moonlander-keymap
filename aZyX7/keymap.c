#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TAB,         KC_B,           KC_L,           KC_D,           KC_C,           KC_V,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_J,           KC_Y,           KC_O,           KC_U,           KC_COMMA,       KC_DELETE,      
    KC_GRAVE,       KC_N,           KC_R,           KC_T,           KC_S,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_P,           KC_H,           KC_A,           KC_E,           KC_I,           KC_BSPC,        
    KC_LEFT_SHIFT,  KC_X,           KC_Q,           KC_M,           KC_W,           KC_Z,                                           KC_K,           KC_F,           KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_LEFT,        KC_RIGHT,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_UP,          KC_DOWN,        KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_RIGHT_CTRL,  
    KC_SPACE,       KC_ENTER,       KC_TRANSPARENT,                 KC_TRANSPARENT, QK_ALT_REPEAT_KEY,         QK_REPEAT_KEY
  ),
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_N:
            return TAPPING_TERM + 300;
        case KC_R:
            return TAPPING_TERM + 300;
        case KC_E:
            return TAPPING_TERM + 100;
        case KC_I:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {52,229,255}, {52,229,255}, {192,230,255}, {192,230,255}, {149,208,153}, {149,208,153}, {149,208,153}, {149,208,153}, {192,230,255}, {149,208,153}, {149,208,153}, {149,208,153}, {149,208,153}, {192,230,255}, {149,208,153}, {149,208,153}, {149,208,153}, {149,208,153}, {52,229,255}, {149,208,153}, {149,208,153}, {149,208,153}, {149,208,153}, {52,229,255}, {149,208,153}, {149,208,153}, {149,208,153}, {149,208,153}, {0,0,0}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {192,230,255}, {192,230,255}, {149,208,153}, {52,229,255}, {149,208,153}, {52,229,255}, {192,230,255}, {149,208,153}, {149,208,153}, {149,208,153}, {52,229,255}, {192,230,255}, {149,208,153}, {149,208,153}, {149,208,153}, {52,229,255}, {52,229,255}, {149,208,153}, {149,208,153}, {149,208,153}, {149,208,153}, {52,229,255}, {149,208,153}, {149,208,153}, {149,208,153}, {149,208,153}, {0,0,0}, {0,0,0}, {0,0,0}, {149,208,153}, {149,208,153}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}



