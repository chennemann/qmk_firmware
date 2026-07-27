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

/*
 * When an interrupt resolves a home-row mod as a hold, give the host a short
 * modifier-only lead-in before QMK reports the interrupting key. This mirrors
 * a conventional physical modifier chord instead of introducing both keys in
 * one HID report. Key and modifier releases then use QMK's normal behavior.
 *
 * A home-row mod resolved by the tapping-term timeout is unaffected.
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BYOU] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        CK__ESC, CK____B, CK____Y, CK____O, CK____U, CK____Z,                      CK____Q, CK____L, CK____D, CK____W, CK____V, CK_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK__TAB, HOME_GL, HOME_AL, HOME_SL, HOME_CL, XXXXXXX,                      CK__DOT, HOME_CR, HOME_SR, HOME_AR, HOME_GR, CK__QUO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, CK____G, CK____X, CK____J, CK____K, XXXXXXX,                      CK_COMM, CK____R, CK____M, CK____F, CK____P, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO__NAV, MO__NUM, CK_LSFT,    CK__ENT, CK__SPC, MO__DIA
                                        //`--------------------------'  `--------------------------'
    ),

    [_QWERTZ] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        CK__ESC, CK____Q, CK____W, CK____E, CK____R, CK____T,                      CK____Z, CK____U, CK____I, CK____O, CK____P, CK_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK__TAB, CK____A, CK____S, CK____D, CK____F, CK____G,                      CK____H, CK____J, CK____K, CK____L, CK__DOT, CK__QUO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CK_LSFT, CK____Y, CK____X, CK____C, CK____V, CK____B,                      CK____N, CK____M, CK_COMM, CK__DOT, CK_SLSH, CK__ENT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO__NAV, MO__NUM, CK_LSFT,    CK__ENT, CK__SPC, MO__DIA
                                        //`--------------------------'  `--------------------------'
    ),

    [_NUM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, CK____A, CK____B, CK____K, CK____W, CK____E,                      XXXXXXX, CK____7, CK____8, CK____9, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, CK____O,                      _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, CK____Y, CK____D, CK____C, CK____F, CK____T,                      _______, CK____1, CK____2, CK____3, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, PRESSED, _______,    _______, CK__SPC, LT_FN_0
                                        //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, XXXXXXX, XXXXXXX, XXXXXXX, CK_C__H, CK_CS_H,                      XXXXXXX, CK_PGUP, CK___UP, CK_PGDN, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+ -------+--------+--------+--------+---------|
        _______, _______, _______, _______, _______, CK_CS_F,                      CK_HOME, CK_LEFT, CK_DOWN, CK_RGHT, CK__END, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, CK_C__D, CK_UNDO, CK_REDO,                      CK_BSEL, CK_SELB, CK_CSAN, CK_SELW, CK_LSEL, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------j+--------+--------|10
                                            PRESSED, XXXXXXX, XXXXXXX,    _______, _______, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),

    [_DIA] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, CK_ACUT, CK__GRV, CK_ODIA, CK_UDIA, CK_CIRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, CK_CCED, CK_ICRC, CK_EACU, CK_ADIA, CK_ACRC,                      XXXXXXX, XXXXXXX, CK_TCED, CK___SS, CK_NTIL, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, CK_ITRM, CK_EGRV, CK_ABRV, CK_ADEG,                      XXXXXXX, XXXXXXX, XXXXXXX, CK_SCED, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, CK__SPC, _______,    PRESSED, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),

    [_FN] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CK___F7, CK___F8, CK___F9, CK__F10, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CK___F4, CK___F5, CK___F6, CK__F11, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CK___F1, CK___F2, CK___F3, CK__F12, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX, PRESSED,    PRESSED, XXXXXXX, XXXXXXX
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
};

// combos are named after the following schema:
//
// prefixed with cmb
//
// l denotes the left side of the keyboard
// r denotes the right side of the keyboard
//
// _ denotes the extended columns for the little & index fingers
//
// l := little finger
// r := ring finger
// m := middle finger
// i := index finger
// t := thumb
//
// 1 | 2 | 3 denote the first, second, and third row of the keyboard
//
// So a notation like: ll2_lr1_lm2_li_2 would be the equivalent of a,w,d,g on a qwerty keyboard
//
// This notation allows for efficient combo creation decoupled from the semantics of a given combo
// This in turn allows for easier redefinition of combos

#define DEFINE_COMBO(name, result, ...)                              \
    const uint16_t PROGMEM name##_keys[] = {__VA_ARGS__, COMBO_END}; \
    const combo_t          name          = COMBO(name##_keys, result)

// Left hand combos

DEFINE_COMBO(select_all, CK_C__A, CMB_LL2, CMB_LR2);                        // ctrl + a
DEFINE_COMBO(copy, CK_C__C, CMB_LR2, CMB_LM2);                              // ctrl + c
DEFINE_COMBO(paste, CK_C__V, CMB_LM2, CMB_LI2);                             // ctrl + v
DEFINE_COMBO(cut, CK_C__X, CMB_LL2, CMB_LR2, CMB_LM2, CMB_LI2);             // ctrl + x
DEFINE_COMBO(qwertz_toggle, TG(_QWERTZ), CMB_LL1, CMB_LR1, CMB_LM1, CMB_LI1); // toggle QWERTZ gaming layer

// Right hand combos

DEFINE_COMBO(plus, CK_PLUS, CMB_RM1, CMB_RI1);                              // +
DEFINE_COMBO(minus, CK_MINS, CMB_RR1, CMB_RL1);                             // -
DEFINE_COMBO(asterisk, CK_ASTR, CMB_RI1, CMB_RR1);                          // *
DEFINE_COMBO(slash, CK_SLSH, CMB_RM1, CMB_RL1);                             // /
DEFINE_COMBO(dollar, CK__USD, CMB_RI1, CMB_RM1, CMB_RR1);                   // $
DEFINE_COMBO(euro, CK__EUR, CMB_RM1, CMB_RR1, CMB_RL1);                     // €
DEFINE_COMBO(equals, CK_EQLS, CMB_RM1, CMB_RR1);                            // =
DEFINE_COMBO(percent, CK_PERC, CMB_RI1, CMB_RL1);                           // %

DEFINE_COMBO(left_parenthesis, CK_LNBR, CMB_RI2, CMB_RM2);                  // (
DEFINE_COMBO(right_parenthesis, CK_RNBR, CMB_RR2, CMB_RL2);                 // )
DEFINE_COMBO(left_brace, CK_LCBR, CMB_RI2, CMB_RR2);                        // {
DEFINE_COMBO(right_brace, CK_RCBR, CMB_RM2, CMB_RL2);                       // }
DEFINE_COMBO(left_bracket, CK_LRBR, CMB_RI2, CMB_RM2, CMB_RR2);             // [
DEFINE_COMBO(right_bracket, CK_RRBR, CMB_RM2, CMB_RR2, CMB_RL2);            // ]
DEFINE_COMBO(less_than, CK_LABK, CMB_RM2, CMB_RR2);                         // <
DEFINE_COMBO(greater_than, CK_RABK, CMB_RI2, CMB_RM2, CMB_RR2, CMB_RL2);    // >

DEFINE_COMBO(ampersand, CK_AMPR, CMB_RI3, CMB_RM3);                         // &
DEFINE_COMBO(hash, CK_HASH, CMB_RM3, CMB_RR3);                              // #
DEFINE_COMBO(at_sign, CK___AT, CMB_RR3, CMB_RL3);                           // @
DEFINE_COMBO(question_mark, CK_QUES, CMB_RI3, CMB_RR3);                     // ?
DEFINE_COMBO(exclamation_mark, CK_EXLM, CMB_RM3, CMB_RL3);                  // !
DEFINE_COMBO(underscore, CK_UNDS, CMB_RI3, CMB_RM3, CMB_RR3);               // _
DEFINE_COMBO(minus_alt, CK_MINS, CMB_RM3, CMB_RR3, CMB_RL3);                // -
DEFINE_COMBO(tilde, CK_TILD, CMB_RI3, CMB_RL3);                             // ~

DEFINE_COMBO(slash_alt, CK_SLSH, CMB_RI2, CMB_RM1);                         // /
DEFINE_COMBO(backslash, CK_BSLS, CMB_RM1, CMB_RR2);                         // <backslash>
DEFINE_COMBO(pipe, CK_PIPE, CMB_RI2, CMB_RM1, CMB_RR2);                     // |
DEFINE_COMBO(acute, CK_ACUT, CMB_RI3, CMB_RM2);                             // ´
DEFINE_COMBO(grave, CK__GRV, CMB_RM2, CMB_RR3);                             // `
DEFINE_COMBO(caret, CK_CIRC, CMB_RI3, CMB_RM2, CMB_RR3);                    // ^

DEFINE_COMBO(double_quote, CK_DQUO, CMB_RI2, CMB_RL_2);                     // "
DEFINE_COMBO(colon, CK_COLN, CMB_RI2, CMB_RL2);                             // :
DEFINE_COMBO(semicolon, CK_SCLN, CMB_RI_2, CMB_RL2);                        // ;

// Special combos
DEFINE_COMBO(delete_key, CK__DEL, CMB_RL1, CMB_RL_1); // DEL

combo_t key_combos[] = {

    select_all,
    copy,
    paste,
    cut,
    qwertz_toggle,

    plus,
    minus,
    asterisk,
    slash,
    dollar,
    euro,
    equals,
    percent,

    left_parenthesis,
    right_parenthesis,
    left_brace,
    right_brace,
    left_bracket,
    right_bracket,
    less_than,
    greater_than,

    ampersand,
    hash,
    at_sign,
    question_mark,
    exclamation_mark,
    underscore,
    minus_alt,
    tilde,

    slash_alt,
    backslash,
    pipe,
    acute,
    grave,
    caret,

    double_quote,
    colon,
    semicolon,

    delete_key,

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
