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
  _SYM
};


/*
    Define generic Home Row Mod Keys to enable easy adjustments
*/
#define HOME_1 LGUI_T(DE_C)
#define HOME_2 LALT_T(DE_I)
#define HOME_3 LSFT_T(DE_E)
#define HOME_4 LCTL_T(DE_A)
#define HOME_5 LCTL_T(DE_H)
#define HOME_6 LSFT_T(DE_T)
#define HOME_7 LALT_T(DE_S)
#define HOME_8 LGUI_T(DE_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    DE_B,    DE_Y,    DE_O,    DE_U, DE_PLUS,                       DE_EQL,    DE_L,    DE_D,    DE_W,    DE_V, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,  HOME_1,  HOME_2,  HOME_3,  HOME_4, DE_COMM,                       DE_DOT,  HOME_5,  HOME_6,  HOME_7,  HOME_8, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         DE_Q,    DE_G,    DE_X,    DE_J,    DE_K, DE_MINS,                      DE_QUES,    DE_R,    DE_M,    DE_F,    DE_P,    DE_Z,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,LSFT_T(KC_ENT),MO(_NUM),     XXXXXXX,LT(_SYM, KC_SPC), XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, DE_EURO,  DE_DLR, XXXXXXX, XXXXXXX,                      _______, CK____7, CK____8, CK____9, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DE_PLUS, DE_MINS, DE_ASTR, DE_SLSH, DE_PERC,                      _______, CK____4, CK____5, CK____6, DE_COMM, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, CK_CIRC, CK_GRV, CK_ACUT,                      XXXXXXX,  CK____1, CK____2, CK____3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    _______, _______, CK____0
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DE_PLUS, DE_MINS, DE_ASTR, DE_SLSH, DE_PERC,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS,                      KC_EXLM, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Based on https://jurf.github.io/2024/01/22/bilingual-qmk-layout-for-programming/
    if (!handle_deadkey_diacritic(keycode, record)) {
        return false;
    }

    return true;
}
