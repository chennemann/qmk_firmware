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
#include "features/tap_dance/tap_dance.h"

/*
    Define available layer names
*/
enum layers {
  _BASE = 0,
  _SYM,
  _NUM,
  _DIA,
  _NAV,
};

/*
    Define custom Tap Dance Keys
*/
enum {
    TD_ENTER_SHIFT = 101,
    TD_ENTER_NUM,
    TD_SPACE_SHIFT,
    TD_SPACE_SYM,
};


/*
    Define generic Home Row Mod Keys to enable easy adjustments
*/
#define BASE__C MT(MOD_LGUI, CK____C)
#define BASE__I MT(MOD_LALT, CK____I)
#define BASE__E MT(MOD_LSFT, CK____E)
#define BASE__A MT(MOD_LCTL, CK____A)
#define BASE__H MT(MOD_LCTL, CK____H)
#define BASE__T MT(MOD_LSFT, CK____T)
#define BASE__S MT(MOD_LALT, CK____S)
#define BASE__N MT(MOD_LGUI, CK____N)

#define TD_SENT TD(TD_ENTER_SHIFT) // Tap-Dance Shift/Enter
#define TD_NENT TD(TD_ENTER_NUM) // Tap-Dance Num/Enter
#define TD_SSPC TD(TD_SPACE_SHIFT) // Tap-Dance Shift/Space
#define TD_SYSP TD(TD_SPACE_SYM) // Tap-Dance SYM/Space

#define MO__SYM MO(_SYM)
#define MO__DIA MO(_DIA)
#define MO__NAV MO(_NAV)
#define NUM_SPC LT(_NUM, CK__SPC)

#define PRESSED _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      CK__ESC, CK____B, CK____Y, CK____O, CK____U, CK____Z,                      CK____Q, CK____L, CK____D, CK____W, CK____V, CK_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK__TAB, BASE__C, BASE__I, BASE__E, BASE__A, CK_COMM,                      CK__DOT, BASE__H, BASE__T, BASE__S, BASE__N, CK__QUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK_LSFT, CK____G, CK____X, CK____J, CK____K, CK_MINS,                      CK_QUES, CK____R, CK____M, CK____F, CK____P, CK_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, TD_NENT, MO__NAV,    MO__DIA, TD_SYSP, XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, CK____7, CK____8, CK____9, CK_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, CK_MINS, CK_PLUS, CK_EQLS, CK_HASH,                      _______, CK____4, CK____5, CK____6, CK_COMM, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, CK_SLSH, CK_ASTR, XXXXXXX, XXXXXXX,                      XXXXXXX, CK____1, CK____2, CK____3, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, PRESSED, XXXXXXX,    CK____0, CK__SPC, CK____0
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, CK_REDO, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+ -------+--------+--------+--------+---------|
      _______, CK_LGUI, CK_LALT, CK_LSFT, CK_LCTL, CK_UNDO,                      XXXXXXX, CK_HOME, CK___UP, CK__END, CK_PGUP, CK_UNDO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, CK_REDO, CK__CUT, CK_COPY, CK_PAST, XXXXXXX,                      XXXXXXX, CK_LEFT, CK_DOWN, CK_RGHT, CK_PGDN, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, PRESSED,    XXXXXXX, CK__SPC, XXXXXXX
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
                                          XXXXXXX, CK__SPC, _______,    PRESSED, XXXXXXX, XXXXXXX
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
                                          XXXXXXX, CK__SPC, _______,    XXXXXXX, PRESSED, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Based on https://jurf.github.io/2024/01/22/bilingual-qmk-layout-for-programming/
    if (handle_diacritic_keycode(keycode, record)) {
        return false;
    }

    return true;
}






void enter_shift_finished(tap_dance_state_t *state, void *user_data) {
    x_shift_finished(state, user_data, KC_ENT);
}
void space_shift_finished(tap_dance_state_t *state, void *user_data) {
    x_shift_finished(state, user_data, KC_SPC);
}

void enter_num_finished(tap_dance_state_t *state, void *user_data) {
    x_layer_finished(state, user_data, KC_ENT, _NUM);
}
void x_num_reset(tap_dance_state_t *state, void *user_data) {
    x_layer_reset(state, user_data, _NUM);
}

void space_sym_finished(tap_dance_state_t *state, void *user_data) {
    x_layer_finished(state, user_data, CK__SPC, _SYM);
}
void x_sym_reset(tap_dance_state_t *state, void *user_data) {
    x_layer_reset(state, user_data, _SYM);
}


tap_dance_action_t tap_dance_actions[] = {
    [TD_ENTER_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter_shift_finished, x_shift_reset),
    [TD_SPACE_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_shift_finished, x_shift_reset),
    [TD_ENTER_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter_num_finished, x_num_reset),
    [TD_SPACE_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_sym_finished, x_sym_reset),
};
