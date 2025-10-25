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

#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_ckey.h"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BYOU] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        CK__TAB, CK____B, CK____Y, CK____O, CK____U, CK____Z,                      CK____Q, CK____L, CK____D, CK____W, CK____V, CK_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK_LSFT, CK____C, CK____I, CK____E, HOME_CA, CK_COMM,                      CK__DOT, HOME_CH, CK____T, CK____S, CK____N, CK__QUO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK_LCTL, CK____G, CK____X, CK____J, CK____K, CK_MINS,                      CK_QUES, CK____R, CK____M, CK____F, CK____P, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO__NAV, TD_SENT, MO__NUM,    MO__DIA, TD_SYSP, XXXXXXX
                                        //`--------------------------'  `--------------------------'

    ),
    
      [_NAV] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CK_C__Z,                      XXXXXXX, CK_PGUP, CK___UP, CK_PGDN, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+ -------+--------+--------+--------+---------|
        _______, CK_C__A, CK_C__X, CK_C__C, CK_C__V, CK_C__F,                      CK_HOME, CK_LEFT, CK_DOWN, CK_RGHT, CK__END, XXXXXXX,
  
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, CK_REDO, CK__CUT, CK_COPY, CK_PAST, CK_UNDO,                      XXXXXXX, CK_BSEL, CK_SELB, CK_SELW, CK_LSEL, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            PRESSED, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),
    
    [_NUM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CK____7, CK____8, CK____9, CK_PERC, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, CK_MINS, CK_PLUS, CK_EQLS, CK_HASH,                      XXXXXXX, CK____4, CK____5, CK____6, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, CK_SLSH, CK_ASTR, XXXXXXX, XXXXXXX,                      XXXXXXX, CK____1, CK____2, CK____3, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX, PRESSED,    LT_FN_0, CK__DOT, CK_COMM
                                        //`--------------------------'  `--------------------------'
    ),
    
      [_DIA] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, CK_ACUT, CK__GRV, CK_ODIA, CK_UDIA, CK_CIRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, CK_CCED, CK_ICRC, CK_EACU, CK_ADIA, CK_ACRC,                      XXXXXXX, XXXXXXX, CK_TCED, CK___SS, CK_NTIL, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, CK_ITRM, CK_EGRV, CK_ABRV, CK_ADEG,                      XXXXXXX, XXXXXXX, XXXXXXX, CK_SCED, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, CK__SPC, MO___FN,    PRESSED, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, CK__QUO, CK_LABK, CK_RABK, CK_AMPR, CK_ACUT,                      CK__GRV, CK__EUR, CK_LRBR, CK_RRBR, CK_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, CK_EXLM, CK_MINS, CK_PLUS, CK_EQLS, CK_HASH,                      CK_TILD, CK_COLN, CK_LNBR, CK_RNBR, CK_QUES, CK_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, CK_CIRC, CK_SLSH, CK_ASTR, CK_BSLS, CK_UNDS,                      CK_PIPE, CK__USD, CK_LCBR, CK_RCBR, CK___AT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO__NAV, CK__SPC, MO__NUM,    XXXXXXX, PRESSED, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  
  [_FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CK___F7, CK___F8, CK___F9, CK__F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CK___F4, CK___F5, CK___F6, CK__F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CK___F1, CK___F2, CK___F3, CK__F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, PRESSED,    PRESSED, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),





  
    [_CAPS] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CW_SLSH, CW_KEBA, CW_BSLS, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CW_CAPS, CW_SNAK, CW_CAML, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, PRESSED, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) { 
        
    // Tap Dance Shift
    switch (keycode) {   
        case HOME_CA: 
        case HOME_CH:
            if (was_keycode_handled(keycode)) {
                
                if (!record->event.pressed) {
                    reset_handled_keycode();
                }
                
                return false;
            }
            break;
    }   
    
    

    switch (keycode) {        
        case CK_LSEL:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LSFT));
                process_record_user(CK_SELW, record);
                unregister_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case CK_BSEL:
            if (record->event.pressed) {
                    register_mods(MOD_BIT(KC_LSFT));
                    process_record_user(CK_SELB, record);
                    unregister_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case CW_CAPS:
            if (!record->event.pressed) {
                toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
            }
            return false;
        case CW_CAML:
            if (!record->event.pressed) {
                toggle_caps_word_mode(CWMODE_CAMEL_CASE);
            }
            return false;
        case CW_KEBA:
            if (!record->event.pressed) {
                toggle_caps_word_space_sub(CK_MINS);
            }
            return false;
        case CW_SNAK:
            if (!record->event.pressed) {
                toggle_caps_word_space_sub(CK_UNDS);
            }
            return false;
        case CW_SLSH:
            if (!record->event.pressed) {
                toggle_caps_word_space_sub(CK_SLSH);
            }
            return false;
        case CW_BSLS:
            if (!record->event.pressed) {
                toggle_caps_word_space_sub(CK_BSLS);
            }
            return false;
    }

    // Select Word based on https://getreuer.info/posts/keyboards/select-word/index.html
    if (!process_select_word(keycode, record, CK_SELW, CK_SELB)) {
        return false;
    }


    // Based on https://jurf.github.io/2024/01/22/bilingual-qmk-layout-for-programming/
    if (handle_diacritic_keycode(keycode, record)) {
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
  // post_tap_dance_shift_task();
  select_word_task();
}



void space_sym_finished(tap_dance_state_t *state, void *user_data) {
    x_layer_finished(state, user_data, CK__SPC, _SYM, _NUM);
}
void x_sym_reset(tap_dance_state_t *state, void *user_data) {
    x_layer_reset(state, user_data, _SYM, _NUM);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ENTER_SHIFT] = {
        // fn { on_each, finished, reset, release }
        .fn = { x_shift_on_each_tap, x_shift_finished, x_shift_reset, x_shift_on_each_release },
        .user_data = &(tap_dance_config_t){
            .keycode = CK__ENT,
            .dt_keycode = CW_CAPS,
            .has_dt_keycode = true,
            .dt_layer = _CAPS,
            .has_dt_layer = true
        }
    },
    [TD_SPACE_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_sym_finished, x_sym_reset),
};

