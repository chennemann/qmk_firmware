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

#include <stdint.h>
#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_ckey.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BYOU] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        CK__ESC, CK____B, CK____Y, CK____O, CK____U, CK____Z,                      CK____Q, CK____L, CK____D, CK____W, CK____V, CK_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK__TAB, HOME_GC, HOME_AI, HOME_SE, HOME_CA, CK_COMM,                      CK__DOT, HOME_CH, HOME_ST, HOME_AS, HOME_GN, CK_DQUO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, CK____G, CK____X, CK____J, CK____K, CK_MINS,                      CK_QUES, CK____R, CK____M, CK____F, CK____P, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO__NAV, MO__NUM, TD__SFT,    CK__ENT, CK__SPC, MO__DIA
                                        //`--------------------------'  `--------------------------'

    ),   

    [_NUM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, XXXXXXX, CK__EUR, CK__USD, XXXXXXX, XXXXXXX,                      XXXXXXX, CK____7, CK____8, CK____9, CK_PERC, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, CK_HASH, CK_PLUS, CK_MINS, CK_EQLS, XXXXXXX,                      XXXXXXX, CK____4, CK____5, CK____6, CK____0, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, CK_CIRC, CK_ASTR, CK_SLSH, CK_AMPR, XXXXXXX,                      CK__DOT, CK____1, CK____2, CK____3, CK_COMM, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX, PRESSED,    LT_FN_0, _______, CK____0
                                        //`--------------------------'  `--------------------------'
    ),
    
    [_SYM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, CK__EUR, CK___AT, CK_AMPR, CK_HASH, CK__GRV,                      CK_ACUT, CK_LABK, CK_LRBR, CK_RRBR, CK_RABK, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK__QUO, CK_EXLM, CK_PLUS, CK_MINS, CK_EQLS, CK_COMM,                      CK__DOT, CK_COLN, CK_LNBR, CK_RNBR, CK_QUES, CK_DQUO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK_CIRC, CK_PERC, CK_ASTR, CK_SLSH, CK_BSLS, CK_UNDS,                      CK_PIPE, CK__USD, CK_LCBR, CK_RCBR, CK_TILD, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            CK__SPC, CK__ENT, CK__SPC,    XXXXXXX, PRESSED, XXXXXXX
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
        
    [_COMBO_REF] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        CK____A, CK____B, CK____C, CK____D, CK____E, CK____F,                      CK____G, CK____H, CK____I, CK____J, CK____K, CK____L,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK____M, CK____N, CK____O, CK____P, CK____Q, CK____R,                      CK____S, CK____T, CK____U, CK____V, CK____W, CK____X,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK____Y, CK____Z, CK____0, CK____1, CK____2, CK____3,                      CK____4, CK____5, CK____6, CK____7, CK____8, CK____9,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),
    
    /*
    
    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, CK__QUO, CK_LABK, CK_RABK, CK_AMPR, CK_ACUT,                      CK__GRV, CK__EUR, CK_LRBR, CK_RRBR, CK_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, CK_EXLM, CK_MINS, CK_PLUS, CK_EQLS, CK_HASH,                      CK_TILD, CK_COLN, CK_LNBR, CK_RNBR, CK_QUES, CK__QUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, CK_CIRC, CK_SLSH, CK_ASTR, CK_BSLS, CK_UNDS,                      CK_PIPE, CK__USD, CK_LCBR, CK_RCBR, CK___AT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO__NAV, CK__SPC, MO__NUM,    XXXXXXX, PRESSED, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  
    */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {     
        
    // Tap Dance Shift
    switch (keycode) {   
        case HOME_CA ... HOME_CZ: 
        case HOME_SA ... HOME_SZ: 
        case HOME_AA ... HOME_AZ: 
        case HOME_GA ... HOME_GZ: 
            // This is a hack to prevent the key from being pressed twice
            if (was_mt_handled(keycode)) {                
                if (!record->event.pressed) {
                    reset_mt_handling();
                }
                return false;
            }
            
            printf("mod tap key pressed at %d\n", timer_read());
            if (is_retroactive_shift_enabled()) {
                if(record->event.pressed) {
                    tap_code16(S(QK_MOD_TAP_GET_TAP_KEYCODE(keycode)));
                    consume_retroactive_shift();
                } else {
                    reset_retroactive_shift();
                }
                return false;
            }
            
            if (is_shift_active()) {
                if(record->event.pressed) {
                    tap_code16(S(QK_MOD_TAP_GET_TAP_KEYCODE(keycode)));
                }
                return false;
            }
            
            return true;
            break;
        case CK____A ... CK____Z:
        
            printf("other key pressed at %d\n", timer_read());
            if (is_retroactive_shift_enabled()) {
                if(record->event.pressed) {
                    tap_code16(S(keycode));
                    consume_retroactive_shift();
                } else {
                    reset_retroactive_shift();
                    
                    // This fixes a weird bug where the key would be repeated endlessly
                    unregister_code(keycode);
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
  tap_dance_cleanup_task();
  select_word_task();
}



void space_sym_finished(tap_dance_state_t *state, void *user_data) {
    x_layer_finished(state, user_data, CK__SPC, _SYM, _NUM);
}
void x_sym_reset(tap_dance_state_t *state, void *user_data) {
    x_layer_reset(state, user_data, _SYM, _NUM);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ENTER] = {
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
    [TD_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_sym_finished, x_sym_reset),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
                       'L', 'L', 'L',  'R', 'R', 'R'
    );
 

// combos are named after the following schema:
// 
// prefixed with cmb
// 
// l denotes the left side of the keyboard
// r denotes the right side of the keyboard
// 
// # denotes the extended columns for the little & index fingers
// 
// l := little finger
// r := ring finger
// m := middle finger
// i := index finger
// t := thumb
// 
// 1 | 2 | 3 denote the first, second, and third row of the keyboard
// 
// So a notation like: l2_r1_m2 would be the equivalent of a,w,d on a qwerty keyboard
// 
// This notation allows for efficient combo creation decoupled from the semantics of a given combo
// This in turn allows for easier redefinition of combos


// Left hand combos
const uint16_t PROGMEM cmb_ll1_lr1[] = {CMB_LL1, CMB_LR1, COMBO_END};
const uint16_t PROGMEM cmb_ll2_lr1[] = {CMB_LL2, CMB_LR1, COMBO_END};
const uint16_t PROGMEM cmb_ll2_lr2[] = {CMB_LL2, CMB_LR2, COMBO_END};
const uint16_t PROGMEM cmb_ll3_lr2[] = {CMB_LL3, CMB_LR2, COMBO_END};
const uint16_t PROGMEM cmb_ll3_lr3[] = {CMB_LL3, CMB_LR3, COMBO_END};

const uint16_t PROGMEM cmb_lr1_lm1[] = {CMB_LR1, CMB_LM1, COMBO_END};
const uint16_t PROGMEM cmb_lr1_lm2[] = {CMB_LR1, CMB_LM2, COMBO_END};
const uint16_t PROGMEM cmb_lr2_lm1[] = {CMB_LR2, CMB_LM1, COMBO_END};
const uint16_t PROGMEM cmb_lr2_lm2[] = {CMB_LR2, CMB_LM2, COMBO_END};
const uint16_t PROGMEM cmb_lr2_lm3[] = {CMB_LR2, CMB_LM3, COMBO_END};
const uint16_t PROGMEM cmb_lr3_lm2[] = {CMB_LR3, CMB_LM2, COMBO_END};
const uint16_t PROGMEM cmb_lr3_lm3[] = {CMB_LR3, CMB_LM3, COMBO_END};

const uint16_t PROGMEM cmb_lm1_li1[] = {CMB_LM1, CMB_LI1, COMBO_END};
const uint16_t PROGMEM cmb_lm1_li2[] = {CMB_LM1, CMB_LI2, COMBO_END};
const uint16_t PROGMEM cmb_lm2_li1[] = {CMB_LM2, CMB_LI1, COMBO_END};
const uint16_t PROGMEM cmb_lm2_li2[] = {CMB_LM2, CMB_LI2, COMBO_END};
const uint16_t PROGMEM cmb_lm2_li3[] = {CMB_LM2, CMB_LI3, COMBO_END};
const uint16_t PROGMEM cmb_lm3_li2[] = {CMB_LM3, CMB_LI2, COMBO_END};
const uint16_t PROGMEM cmb_lm3_li3[] = {CMB_LM3, CMB_LI3, COMBO_END};

const uint16_t PROGMEM cmb_li1_lr1[] = {CMB_LI1, CMB_LR1, COMBO_END};
const uint16_t PROGMEM cmb_lm1_ll1[] = {CMB_LM1, CMB_LL1, COMBO_END};
const uint16_t PROGMEM cmb_li2_lr2[] = {CMB_LI2, CMB_LR2, COMBO_END};
const uint16_t PROGMEM cmb_lm2_ll2[] = {CMB_LM2, CMB_LL2, COMBO_END};
const uint16_t PROGMEM cmb_li3_lr3[] = {CMB_LI3, CMB_LR3, COMBO_END};
const uint16_t PROGMEM cmb_lm3_ll3[] = {CMB_LM3, CMB_LL3, COMBO_END};

const uint16_t PROGMEM cmb_ll1_lr1_lm1[] = {CMB_LL1, CMB_LR1, CMB_LM1, COMBO_END};
const uint16_t PROGMEM cmb_lr1_lm1_li1[] = {CMB_LR1, CMB_LM1, CMB_LI1, COMBO_END};
const uint16_t PROGMEM cmb_ll2_lr2_lm2[] = {CMB_LL2, CMB_LR2, CMB_LM2, COMBO_END};
const uint16_t PROGMEM cmb_lr2_lm2_li2[] = {CMB_LR2, CMB_LM2, CMB_LI2, COMBO_END};
const uint16_t PROGMEM cmb_ll3_lr3_lm3[] = {CMB_LL3, CMB_LR3, CMB_LM3, COMBO_END};
const uint16_t PROGMEM cmb_lr3_lm3_li3[] = {CMB_LR3, CMB_LM3, CMB_LI3, COMBO_END};
const uint16_t PROGMEM cmb_lr2_lm1_li2[] = {CMB_LR2, CMB_LM1, CMB_LI2, COMBO_END};
const uint16_t PROGMEM cmb_lr2_lm3_li2[] = {CMB_LR2, CMB_LM3, CMB_LI2, COMBO_END};
const uint16_t PROGMEM cmb_lr3_lm2_li3[] = {CMB_LR3, CMB_LM2, CMB_LI3, COMBO_END};

const uint16_t PROGMEM cmb_ll1_lr1_lm1_li1[] = {CMB_LL1, CMB_LR1, CMB_LM1, CMB_LI1, COMBO_END};
const uint16_t PROGMEM cmb_ll2_lr2_lm2_li2[] = {CMB_LL2, CMB_LR2, CMB_LM2, CMB_LI2, COMBO_END};
const uint16_t PROGMEM cmb_ll3_lr3_lm3_li3[] = {CMB_LL3, CMB_LR3, CMB_LM3, CMB_LI3, COMBO_END};

// Right hand combos
const uint16_t PROGMEM cmb_rr1_rl1[] = {CMB_RR1, CMB_RL1, COMBO_END};
const uint16_t PROGMEM cmb_rr1_rl2[] = {CMB_RR1, CMB_RL2, COMBO_END};
const uint16_t PROGMEM cmb_rr2_rl2[] = {CMB_RR2, CMB_RL2, COMBO_END};
const uint16_t PROGMEM cmb_rr2_rl3[] = {CMB_RR2, CMB_RL3, COMBO_END};
const uint16_t PROGMEM cmb_rr3_rl3[] = {CMB_RR3, CMB_RL3, COMBO_END};

const uint16_t PROGMEM cmb_rm1_rr1[] = {CMB_RM1, CMB_RR1, COMBO_END};
const uint16_t PROGMEM cmb_rm2_rr1[] = {CMB_RM2, CMB_RR1, COMBO_END};
const uint16_t PROGMEM cmb_rm1_rr2[] = {CMB_RM1, CMB_RR2, COMBO_END};
const uint16_t PROGMEM cmb_rm2_rr2[] = {CMB_RM2, CMB_RR2, COMBO_END};
const uint16_t PROGMEM cmb_rm3_rr2[] = {CMB_RM3, CMB_RR2, COMBO_END};
const uint16_t PROGMEM cmb_rm2_rr3[] = {CMB_RM2, CMB_RR3, COMBO_END};
const uint16_t PROGMEM cmb_rm3_rr3[] = {CMB_RM3, CMB_RR3, COMBO_END};

const uint16_t PROGMEM cmb_ri1_rm1[] = {CMB_RI1, CMB_RM1, COMBO_END};
const uint16_t PROGMEM cmb_ri2_rm1[] = {CMB_RI2, CMB_RM1, COMBO_END};
const uint16_t PROGMEM cmb_ri1_rm2[] = {CMB_RI1, CMB_RM2, COMBO_END};
const uint16_t PROGMEM cmb_ri2_rm2[] = {CMB_RI2, CMB_RM2, COMBO_END};
const uint16_t PROGMEM cmb_ri3_rm2[] = {CMB_RI3, CMB_RM2, COMBO_END};
const uint16_t PROGMEM cmb_ri2_rm3[] = {CMB_RI2, CMB_RM3, COMBO_END};
const uint16_t PROGMEM cmb_ri3_rm3[] = {CMB_RI3, CMB_RM3, COMBO_END};

const uint16_t PROGMEM cmb_ri1_rr1[] = {CMB_RI1, CMB_RR1, COMBO_END};
const uint16_t PROGMEM cmb_rm1_rl1[] = {CMB_RM1, CMB_RL1, COMBO_END};
const uint16_t PROGMEM cmb_ri2_rr2[] = {CMB_RI2, CMB_RR2, COMBO_END};
const uint16_t PROGMEM cmb_rm2_rl2[] = {CMB_RM2, CMB_RL2, COMBO_END};
const uint16_t PROGMEM cmb_ri3_rr3[] = {CMB_RI3, CMB_RR3, COMBO_END};
const uint16_t PROGMEM cmb_rm3_rl3[] = {CMB_RM3, CMB_RL3, COMBO_END};

const uint16_t PROGMEM cmb_ri1_rm1_rr1[] = {CMB_RI1, CMB_RM1, CMB_RR1, COMBO_END};
const uint16_t PROGMEM cmb_rm1_rr1_rl1[] = {CMB_RM1, CMB_RR1, CMB_RL1, COMBO_END};
const uint16_t PROGMEM cmb_ri2_rm2_rr2[] = {CMB_RI2, CMB_RM2, CMB_RR2, COMBO_END};
const uint16_t PROGMEM cmb_rm2_rr2_rl2[] = {CMB_RM2, CMB_RR2, CMB_RL2, COMBO_END};
const uint16_t PROGMEM cmb_ri3_rm3_rr3[] = {CMB_RI3, CMB_RM3, CMB_RR3, COMBO_END};
const uint16_t PROGMEM cmb_rm3_rr3_rl3[] = {CMB_RM3, CMB_RR3, CMB_RL3, COMBO_END};
const uint16_t PROGMEM cmb_ri2_rm1_rr2[] = {CMB_RI2, CMB_RM1, CMB_RR2, COMBO_END};
const uint16_t PROGMEM cmb_ri2_rm3_rr2[] = {CMB_RI2, CMB_RM3, CMB_RR2, COMBO_END};
const uint16_t PROGMEM cmb_ri3_rm2_rr3[] = {CMB_RI3, CMB_RM2, CMB_RR3, COMBO_END};

const uint16_t PROGMEM cmb_ri1_rm1_rr1_rl1[] = {CMB_RI1, CMB_RM1, CMB_RR1, CMB_RL1, COMBO_END};
const uint16_t PROGMEM cmb_ri2_rm2_rr2_rl2[] = {CMB_RI2, CMB_RM2, CMB_RR2, CMB_RL2, COMBO_END};
const uint16_t PROGMEM cmb_ri3_rm3_rr3_rl3[] = {CMB_RI3, CMB_RM3, CMB_RR3, CMB_RL3, COMBO_END};

// Special combos
const uint16_t PROGMEM cmb_rm2_rl_2[] = {CMB_RM2, CMB_RL_2, COMBO_END};
const uint16_t PROGMEM cmb_ri2_rl_2[] = {CMB_RI2, CMB_RL_2, COMBO_END};
    

combo_t key_combos[] = {
    
    COMBO(cmb_ri1_rm1, CK_PLUS),                // +
    COMBO(cmb_rr1_rl1, CK_MINS),                // -
    COMBO(cmb_ri1_rr1, CK_ASTR),                // *
    COMBO(cmb_rm1_rl1, CK_SLSH),                // /
    COMBO(cmb_ri1_rm1_rr1, CK__USD),            // $
    COMBO(cmb_rm1_rr1_rl1, CK__EUR),            // €
    COMBO(cmb_rm1_rr1, CK_EQLS),                // =
    COMBO(cmb_ri1_rm1_rr1_rl1, CK_PERC),        // %
    
    COMBO(cmb_ri2_rm2, CK_LNBR),                // (
    COMBO(cmb_rr2_rl2, CK_RNBR),                // )
    COMBO(cmb_ri2_rr2, CK_LCBR),                // {
    COMBO(cmb_rm2_rl2, CK_RCBR),                // }
    COMBO(cmb_ri2_rm2_rr2, CK_LRBR),            // [
    COMBO(cmb_rm2_rr2_rl2, CK_RRBR),            // ]
    COMBO(cmb_rm2_rr2, CK_LABK),                // <
    COMBO(cmb_ri2_rm2_rr2_rl2, CK_RABK),        // >
    
    COMBO(cmb_ri3_rm3, CK_AMPR),                // &
    COMBO(cmb_rm3_rr3, CK_HASH),                // #
    COMBO(cmb_rr3_rl3, CK___AT),                // @
    COMBO(cmb_ri3_rr3, CK_QUES),                // ?
    COMBO(cmb_rm3_rl3, CK_EXLM),                // !
    COMBO(cmb_ri3_rm3_rr3, CK_UNDS),            // _
    COMBO(cmb_rm3_rr3_rl3, CK_MINS),            // -
    COMBO(cmb_ri3_rm3_rr3_rl3, CK_TILD),        // ~
    
    COMBO(cmb_ri2_rm1, CK_SLSH),                // /
    COMBO(cmb_rm1_rr2, CK_BSLS),                // <backslash>
    COMBO(cmb_ri2_rm1_rr2, CK_PIPE),            // |
    COMBO(cmb_ri3_rm2, CK_ACUT),                // ´
    COMBO(cmb_rm2_rr3, CK__GRV),                // `
    COMBO(cmb_ri3_rm2_rr3, CK_CIRC),            // ^
    
    COMBO(cmb_rm2_rl_2, CK__QUO),               // '
    COMBO(cmb_ri2_rl_2, CK_SCLN),               // ;
};


bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    return true;
}

/*
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CM_ALTB:
            if (pressed) {
                register_mods(MOD_LALT);
                tap_code(KC_TAB);
            } else {
                unregister_mods(MOD_LALT);
            }
            break;
    }
}

bool process_combo_key_repress(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
    switch (combo_index) {
        case CM_ALTB:
            switch (keycode) {
                case KC_F:
                    tap_code16(S(KC_TAB));
                    return true;
                case KC_G:
                    tap_code(KC_TAB);
                    return true;
            }
    }
    return false;
}
*/