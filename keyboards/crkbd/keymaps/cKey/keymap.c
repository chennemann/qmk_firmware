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

/*
    Define available layer names
*/
enum layers {
  _BASE = 0,
  _NUM,
  _SYM,
  _DIA
};


/*
    Define generic Home Row Mod Keys to enable easy adjustments
*/
#define HOME__1 LGUI_T(CK____C)
#define HOME__2 LALT_T(CK____I)
#define HOME__3 LSFT_T(CK____E)
#define HOME__4 LCTL_T(CK____A)
#define HOME__5 LCTL_T(CK____H)
#define HOME__6 LSFT_T(CK____T)
#define HOME__7 LALT_T(CK____S)
#define HOME__8 LGUI_T(CK____N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      CK__ESC, CK____B, CK____Y, CK____O, CK____U, CK_PLUS,                      CK_EQLS, CK____L, CK____D, CK____W, CK____V, CK_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK__TAB, HOME__1, HOME__2, HOME__3, HOME__4, CK_COMM,                      CK__DOT, HOME__5, HOME__6, HOME__7, HOME__8, CK__QUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK____Q, CK____G, CK____X, CK____J, CK____K, CK_MINS,                      CK_QUES, CK____R, CK____M, CK____F, CK____P, CK____Z,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,LSFT_T(CK__ENT),MO(_NUM),     MO(_DIA),LT(_SYM, CK__SPC), XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, CK__EUR, CK__USD, XXXXXXX, _______,                      _______, CK____7, CK____8, CK____9, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, CK_PLUS, CK_MINS, CK_ASTR, CK_SLSH, _______,                      _______, CK____4, CK____5, CK____6, CK_COMM, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, CK_PERC, _______,                      XXXXXXX, CK____1, CK____2, CK____3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    CK__ENT, _______, CK____0
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______, CK_LRBR, CK_RRBR, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, CK_PLUS, CK_MINS, CK_ASTR, CK_SLSH, _______,                      _______, CK_LNBR, CK_RNBR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, CK_PERC, _______,                      XXXXXXX, CK_LCBR, CK_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CK_LSFT, CK__ENT, CK__SPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_DIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, CK_ACUT, CK__GRV, CK_ODIA, CK_UDIA, CK_CIRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, CK_CCED, CK_ICRC, CK_EACU, CK_ADIA, CK_ACRC,                      XXXXXXX, CK_LSFT, CK_TCED, CK___SS, CK_NTIL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK_LSFT, XXXXXXX, XXXXXXX, CK_EGRV, CK_ABRV, CK_ADEG,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CK_LSFT, CK__ENT, CK__SPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Based on https://jurf.github.io/2024/01/22/bilingual-qmk-layout-for-programming/
    if (handle_diacritic_keycode(keycode, record)) {
        return false;
    }

    return true;
}
