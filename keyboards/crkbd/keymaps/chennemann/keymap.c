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


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  
  // Process Leader Sequences before Home-Row-Mods
  if (!process_leader(keycode, record))    { return false; }
  
  // Enable Achordion Home-Row Mods
  if (!process_achordion(keycode, record)) { return false; }
  
  switch (keycode) {
    case UKC_LEADER:
        if (record->event.pressed) {
            start_leading();
            return false;
        }
    case UKC_NUM_LOCK:
        if (record->event.pressed) {
            toggle_caps_word_mode(CWMODE_NUM_LOCK);
            return false;
        }
        break;
    case UKC_CAPS_WORD:
        if (record->event.pressed) {
            toggle_caps_word_mode(CWMODE_NORMAL);
            return false;
        }
        break;
    }

  return true;
}


void matrix_scan_user(void) {
  // Setup Achordion (Mod-Tap Fix)
  achordion_task();
}

// HOME ROW MODS 
#define HOME_C MT_LG(DE_C)
#define HOME_I MT_L(DE_I)
#define HOME_E MT_L(DE_E)
#define HOME_A MT_L(DE_A)
#define HOME_H MT(RCTL, DE_H)
#define HOME_T MT(RSFT, DE_T)
#define HOME_S MT(LALT, DE_S)
#define HOME_N MT(RGUI, DE_N)

#define QHOME_A MT_LG(DE_A)
#define QHOME_S MT_LA(DE_S)
#define QHOME_D MT_LS(DE_D)
#define QHOME_F MT_LC(DE_F)
#define QHOME_J MT_RC(DE_J)
#define QHOME_K MT_RS(DE_K)
#define QHOME_L MT_LA(DE_L)
#define QHOME__ MT_RG(DE_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [QWERTZ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                         DE_Z,    DE_U,    DE_I,    DE_O,   DE_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, QHOME_A, QHOME_S, QHOME_D, QHOME_F,    DE_G,                         DE_H, QHOME_J, QHOME_K, QHOME_L, QHOME__, DE_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                         DE_N,    DE_M, DE_COMM,  DE_DOT, DE_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ENT, UKC_NUM_LOCK, KC_SPC,  KC_SPC, KC_RALT, UKC_LEADER 
                                      //`--------------------------'  `--------------------------'

  ),


    [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,                      XXXXXXX,    DE_7,    DE_8,    DE_9, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,                      XXXXXXX,    DE_4,    DE_5,    DE_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,  KC_ESC,                      DE_COMM,    DE_1,    DE_2,    DE_3, DE_DOT,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC,  KC_ESC,   KC_ESC,    KC_SPC,    DE_0,    DE_0
                                      //`--------------------------'  `--------------------------'
  )


/*
    [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    DE_B,    DE_Y,    DE_O,    DE_U, DE_QUOT,                      DE_DQUO,    DE_L,    DE_D,    DE_W,   DE_V,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  HOME_C,  HOME_I,  HOME_E,  HOME_A, DE_COMM,                       DE_DOT,  HOME_H,  HOME_T,  HOME_S, HOME_N,     DE_Z,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    DE_G,    DE_X,    DE_J,    DE_K, DE_MINS,                      DE_QUES,    DE_R,    DE_M,    DE_F,   DE_P,     DE_Q,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ENT,  QK_CAPS_WORD_TOGGLE,  KC_SPC,     KC_SPC, XXXXXXX, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, DE_EXLM,   DE_AT, DE_HASH,  DE_DLR, DE_PERC,                      DE_CIRC, DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, DE_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      DE_MINS,  DE_EQL, DE_LBRC, DE_RBRC, DE_BSLS,  DE_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      DE_UNDS, DE_PLUS, DE_LCBR, DE_RCBR, DE_PIPE, DE_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          DE_LGUI,   MO(3),  _______,     _______, _______, DE_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          DE_LGUI, _______,  DE_SPC,     DE_ENT, _______, DE_RALT
                                      //`--------------------------'  `--------------------------'
  )*/
};

const uint16_t caps_word1[] PROGMEM = { LSFT_T(DE_D), KC_SPC, COMBO_END};
const uint16_t caps_word2[] PROGMEM = { RSFT_T(DE_K), KC_SPC, COMBO_END};

const uint16_t escape[] PROGMEM = { RCTL_T(DE_J), RSFT_T(DE_K), COMBO_END};

combo_t key_combos[] = {
    COMBO(caps_word1, UKC_CAPS_WORD),
    COMBO(caps_word2, UKC_CAPS_WORD),
    COMBO(escape, KC_ESC)
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(*key_combos);
