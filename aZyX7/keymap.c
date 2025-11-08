#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};



#define DUAL_FUNC_0 LT(14, KC_8)
#define DUAL_FUNC_1 LT(3, KC_F15)
#define DUAL_FUNC_2 LT(2, KC_F18)
#define DUAL_FUNC_3 LT(8, KC_1)
#define DUAL_FUNC_4 LT(10, KC_V)
#define DUAL_FUNC_5 LT(4, KC_F24)
#define DUAL_FUNC_6 LT(12, KC_F2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, 
    KC_TAB,         KC_B,           KC_L,           KC_D,           KC_C,           KC_V,           TG(1),                                          TG(2),          KC_J,           KC_Y,           KC_O,           KC_U,           KC_QUES,        KC_DELETE,      
    KC_UNDS,        MT(MOD_LGUI, KC_N),MT(MOD_LALT, KC_R),MT(MOD_LCTL, KC_T),MT(MOD_LSFT, KC_S),KC_G,           TG(3),                                                                          TG(4),          KC_P,           MT(MOD_RSFT, KC_H),MT(MOD_RCTL, KC_A),MT(MOD_RALT, KC_E),MT(MOD_RGUI, KC_I),KC_BSPC,        
    CW_TOGG,        KC_X,           KC_Q,           KC_M,           KC_W,           KC_Z,                                           KC_K,           KC_F,           KC_COMMA,       KC_DOT,         KC_QUOTE,       KC_SLASH,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LM(1,MOD_LSFT),                                                                                                 MO(2),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_ENTER,       KC_LEFT_GUI,                    KC_ESCAPE,      QK_ALT_REPEAT_KEY,         QK_REPEAT_KEY
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_LABK,        KC_RABK,        KC_MINUS,       KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_RPRN,        KC_RCBR,        KC_DLR,         KC_QUES,        KC_TRANSPARENT, 
    KC_TRANSPARENT, DUAL_FUNC_0,    DUAL_FUNC_1,    MT(MOD_LCTL, KC_SLASH),MT(MOD_RSFT, KC_EQUAL),DUAL_FUNC_2,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, DUAL_FUNC_3,    DUAL_FUNC_4,    DUAL_FUNC_5,    MT(MOD_RSFT, KC_SCLN),DUAL_FUNC_6,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TILD,        KC_PLUS,        KC_LBRC,        KC_RBRC,        KC_PERC,                                        KC_AT,          KC_COLN,        KC_COMMA,       KC_DOT,         KC_QUOTE,       KC_BSLS,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        MT(MOD_RSFT, KC_KP_MINUS),KC_TRANSPARENT, 
    KC_TRANSPARENT, MO(3),          KC_LEFT,        KC_KP_DOT,      KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_KP_EQUAL,    MT(MOD_RSFT, KC_KP_4),MT(MOD_RCTL, KC_KP_5),MT(MOD_RALT, KC_KP_6),MT(MOD_RGUI, KC_KP_0),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_PAGE_UP,     KC_DOWN,        KC_PGDN,        KC_TRANSPARENT,                                 KC_KP_ASTERISK, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_MS_BTN1),RSFT(KC_MS_BTN2),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_TRANSPARENT, KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_DOWN,     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_MS_BTN1),LCTL(KC_MS_BTN2),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,       
    KC_GRAVE,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,       
    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       
    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC
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
    [0] = { {0,0,0}, {192,230,255}, {52,229,255}, {192,230,255}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {192,230,255}, {9,225,246}, {9,225,246}, {52,229,255}, {192,230,255}, {192,230,255}, {9,225,246}, {0,0,0}, {192,230,255}, {192,230,255}, {52,229,255}, {0,0,0}, {192,230,255}, {52,229,255}, {139,218,205}, {52,229,255}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {52,229,255}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {52,229,255}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {192,230,255}, {9,225,246}, {9,225,246}, {52,229,255}, {52,229,255}, {192,230,255}, {9,225,246} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {0,0,0}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {9,225,246}, {0,0,0}, {0,0,0}, {0,0,0}, {192,230,255}, {192,230,255}, {192,230,255}, {0,0,0}, {0,0,0}, {192,230,255}, {52,229,255}, {192,230,255}, {0,0,0}, {0,0,0}, {192,230,255}, {192,230,255}, {192,230,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {52,229,255}, {139,218,205}, {52,229,255}, {0,0,0}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {192,230,255}, {0,0,0}, {0,0,0}, {0,0,0}, {192,230,255}, {0,0,0}, {192,230,255}, {0,0,0}, {0,0,0}, {0,0,0}, {192,230,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {192,230,255}, {192,230,255}, {192,230,255}, {0,0,0}, {0,0,0}, {192,230,255}, {192,230,255}, {192,230,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {192,230,255}, {192,230,255}, {52,229,255}, {192,230,255}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {0,0,0}, {0,0,0}, {52,229,255}, {0,0,0}, {0,0,0}, {0,0,0}, {52,229,255}, {52,229,255}, {52,229,255}, {52,229,255}, {192,230,255}, {139,218,205}, {139,218,205}, {52,229,255}, {192,230,255}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {52,229,255}, {192,230,255}, {139,218,205}, {139,218,205}, {139,218,205}, {52,229,255}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,0}, {0,0,0}, {0,0,0}, {192,230,255}, {0,0,0}, {0,0,0}, {0,0,0} },

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
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
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
  case QK_MODS ... QK_MODS_MAX: 
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_EXLM);
        } else {
          unregister_code16(KC_EXLM);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_ASTR);
        } else {
          unregister_code16(KC_ASTR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_AMPR);
        } else {
          unregister_code16(KC_AMPR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_HASH);
        } else {
          unregister_code16(KC_HASH);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
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
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LCBR);
        } else {
          unregister_code16(KC_LCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DQUO);
        } else {
          unregister_code16(KC_DQUO);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
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
