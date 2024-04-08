/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keymap.h"
#include "leader.h"
#include "sendstring_german.h"
#include "achordion.h"

#ifdef CAPS_WORD_ENABLE
    #include "caps_word.h"
#endif // CAPS_WORD_ENABLE








// Tap Dance States
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

enum {
    ENT_SFT
};


typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t leader_key_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void ent_sft_finished(tap_dance_state_t *state, void *user_data);
void ent_sft_reset(tap_dance_state_t *state, void *user_data);
















bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  
  // Process Leader Sequences before Home-Row-Mods
  if (!process_leader(keycode, record))    { return false; }
  
  // Enable Achordion Home-Row Mods
  //if (!process_achordion(keycode, record)) { return false; }
  
  switch (keycode) {
    case UKC_LEADER:
        if (record->event.pressed) {
            start_leading();
            return false;
        }
    case UKC_NUM_LOCK:
        static uint16_t colon_timer;
        if (record->event.pressed) {
            colon_timer = timer_read();
            layer_on(_NUM);  //turn on NUM layer
        } else {
            layer_off(_NUM);  //turn off NUM layer
            if (timer_elapsed(colon_timer) < TAPPING_TERM) {
                toggle_caps_word_mode(CWMODE_NUM_LOCK);
            }
        }
        return false;
    }

  return true;
}

//void matrix_scan_user(void) {
  // Setup Achordion (Mod-Tap Fix)
//  achordion_task();
//}

// HOME ROW MODS 
#define HOME_F MT_LC(CK_F)
#define HOME_J MT_RC(CK_J)
#define LENT TD(ENT_SFT)
#define RSPC LT(_SYM, KC_SPC)
#define CK_LENT LT(_NAV, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       CK_TAB,    CK_Q,    CK_W,    CK_E,    CK_R,    CK_T,                         CK_Z,    CK_U,    CK_I,    CK_O,   CK_P,  CK_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK_LCTL,    CK_A,    CK_S,    CK_D,  HOME_F,    CK_G,                         CK_H,  HOME_J,    CK_K,    CK_L,  CK_EQL, CK_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK_LALT,    CK_Y,    CK_X,    CK_C,    CK_V,    CK_B,                         CK_N,    CK_M, CK_COMM,  CK_DOT, CK_MINS,  CK_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                MO(_NAV), TD(ENT_SFT), UKC_NUM_LOCK,  MO(_DIA), LT(_SYM, CK_SPC), CK_LALT 
                                      //`--------------------------'  `--------------------------'
  ),


    [_DIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CK_UDIA, XXXXXXX, CK_ODIA, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, CK_ADIA,   CK_SS, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CK_CCED, CK_OCRC, CK_UCRC, CK_UGRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, CK_ACIR, CK_ABRV, CK_ICIR, CK_SCOM, CK_TCOM,                      XXXXXXX, CK_AGRV, CK_EACU, CK_EGRV, CK_ICRC, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, CK_LSFT,  CK_SPC,    _______, CK_SPC, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),


    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX,  CK_EUR,  CK_USD, XXXXXXX,                      XXXXXXX,    CK_7,    CK_8,    CK_9, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, CK_SLSH, CK_ASTR, CK_MINS, CK_PLUS, XXXXXXX,                      XXXXXXX,    CK_4,    CK_5,    CK_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,  CK_DOT, CK_COMM, XXXXXXX, XXXXXXX,                         CK_0,    CK_1,    CK_2,    CK_3, CK_COMM, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC,  KC_ESC,  KC_ESC,       CK_0, _______,   CK_DOT
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, CK_EXLM,   CK_AT, CK_HASH,  KC_DLR, CK_PERC,                      CK_CIRC, CK_AMPR, CK_LRBR, CK_RRBR, CK_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      CK_MINS,  CK_EQL, CK_LNBR, CK_RNBR, CK_BSLS,  CK_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      CK_UNDS, CK_PLUS, CK_LCBR, CK_RCBR, CK_PIPE, CK_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CK_LGUI,   MO(3),  _______,     _______, _______, CK_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, C(CK_Y), XXXXXXX, XXXXXXX,                      XXXXXXX, CK_HOME, KC_PGUP, KC_PGDN,  CK_END, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+ -------+--------+--------+--------+---------|
      _______, C(CK_A), C(CK_S), C(CK_Z), CK_LCTL, XXXXXXX,                      XXXXXXX, CK_LEFT,   CK_UP, CK_DOWN,CK_RIGHT,  CK_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, C(CK_X), C(CK_C), C(CK_V), XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     CK_RSFT, CK_RCTL, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_CAPS_LOCK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    CK_7, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
  /*
,
    [_DIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, CK_ADIA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  */
};

const uint16_t escape_base[] PROGMEM = { HOME_J,  CK_K, COMBO_END};
const uint16_t escape_num[] PROGMEM =  {   CK_4,  CK_5,   COMBO_END};
const uint16_t escape_nav[] PROGMEM =  { CK_LEFT, CK_DOWN,   COMBO_END};

combo_t key_combos[] = {
    COMBO(escape_base, KC_ESC),
    COMBO(escape_num, KC_ESC),
    COMBO(escape_nav, KC_ESC)
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(*key_combos);








td_state_t leader_key_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else {
        return TD_UNKNOWN;
    }
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ent_sft_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = leader_key_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(CK_ENT);
            break;
        case TD_SINGLE_HOLD: 
            register_code(CK_LSFT); 
            break;
        case TD_DOUBLE_TAP:  
            toggle_caps_word_mode(CWMODE_CONSTANT_CASE); 
            break;
        case TD_DOUBLE_HOLD: 
            layer_on(_CAPS_LOCK); 
            break;
        default: 
            break;
    }
}

void ent_sft_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_HOLD:        
            unregister_code(CK_LSFT);   
            break;
        case TD_DOUBLE_HOLD:       
            layer_off(_CAPS_LOCK);     
            break;
        default:                                                
            break;
    }
    xtap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [ENT_SFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_sft_finished, ent_sft_reset)
};




uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(ENT_SFT):
            return 180;
        default:
            return TAPPING_TERM;
    }
}


