#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
};



#define DUAL_FUNC_0 LT(4, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_DELETE,      
    KC_TAB,         KC_B,           KC_L,           KC_D,           KC_C,           KC_V,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_J,           KC_Y,           KC_O,           KC_U,           KC_COMMA,       KC_BSLS,        
    KC_GRAVE,       MT(MOD_LGUI, KC_N),MT(MOD_LALT, KC_R),MT(MOD_LCTL, KC_T),MT(MOD_LSFT, KC_S),KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_P,           MT(MOD_RSFT, KC_H),MT(MOD_RCTL, KC_A),MT(MOD_RALT, KC_E),MT(MOD_RGUI, KC_I),KC_BSPC,        
    CW_TOGG,        KC_X,           ST_MACRO_0,     KC_M,           KC_W,           KC_Z,                                           KC_K,           KC_F,           KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_SLASH,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(1, KC_SPACE),KC_ENTER,       KC_TRANSPARENT,                 KC_TRANSPARENT, QK_ALT_REPEAT_KEY,         QK_REPEAT_KEY
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_HOME,        KC_UP,          KC_END,         KC_LCBR,        KC_RCBR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MINUS,       KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_PIPE,        MT(MOD_LGUI, KC_LEFT),MT(MOD_LALT, KC_DOWN),MT(MOD_LCTL, KC_RIGHT),DUAL_FUNC_0,    KC_RPRN,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_0,           MT(MOD_RSFT, KC_4),MT(MOD_RCTL, KC_5),MT(MOD_RSFT, KC_6),MT(MOD_RGUI, KC_ENTER),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PGDN,        KC_ESCAPE,      KC_PGDN,        KC_LBRC,        KC_RBRC,                                        KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R',
                 '*', '*', '*', '*', '*', '*'
);


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI, KC_N):
            return TAPPING_TERM + 250;
        case MT(MOD_LALT, KC_R):
            return TAPPING_TERM + 250;
        case MT(MOD_RALT, KC_E):
            return TAPPING_TERM + 50;
        case MT(MOD_RGUI, KC_I):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}


extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {52,229,255}, {52,229,255}, {192,230,255}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {192,230,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {192,230,255}, {52,229,255}, {139,218,205}, {52,229,255}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {52,229,255}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {52,229,255}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {192,230,255}, {0,0,0}, {0,0,0}, {139,218,205}, {139,218,205}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {52,229,255}, {0,0,0}, {0,0,0}, {0,0,0}, {192,230,255}, {192,230,255}, {192,230,255}, {0,0,0}, {0,0,0}, {192,230,255}, {192,230,255}, {192,230,255}, {0,0,0}, {0,0,0}, {192,230,255}, {192,230,255}, {192,230,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {52,229,255}, {0,0,0}, {0,0,0}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {0,0,0}, {52,229,255}, {139,218,205}, {52,229,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Q)SS_DELAY(100)  SS_TAP(X_U));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LPRN);
        } else {
          unregister_code16(KC_LPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
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


// Custom QMK
// use alt repeat to eliminate SFBs
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  switch (keycode) {
    // col 1 (bnx)
    case KC_B: return KC_N;
    case MT(MOD_LGUI, KC_N): return KC_B;
    case KC_X: return KC_B;
    // col 2 (lrq)
    case KC_L: return KC_R;
    case MT(MOD_LALT, KC_R): return KC_L;
    case KC_Q: return KC_U;
    // col 3 (dtm)
    case KC_D: return KC_T;
    case MT(MOD_LCTL, KC_T): return KC_M;
    case KC_M: return KC_T;
    // col 4 (csw)
    case KC_C: return KC_S;
    case MT(MOD_LSFT, KC_S): return KC_C;
    case KC_W: return KC_S;
    // col 5 (vgz)
    case KC_V: return KC_S;
    case KC_G: return KC_S;
    case KC_Z: return KC_S;
    // col 6 (jpk)
    case KC_J: return KC_Y;
    case KC_P: return KC_H;
    case KC_K: return KC_Y;
    // col 7 (yhf)
    case KC_Y: return KC_P;
    case MT(MOD_RSFT, KC_H): return KC_Y;
    case KC_F: return KC_Y;
    // col 8 (oa')
    case KC_O: return KC_A;
    case MT(MOD_RCTL, KC_A): return KC_O;
    // col 9 (ue;)
    case KC_U: return KC_E;
    case MT(MOD_RALT, KC_E): return KC_U;
    // col 10 (,i.)
    // case MT(MOD_RGUI, KC_I): return KC_I;
  }

  return KC_TRNS;
}
