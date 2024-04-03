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
    case UKC_CAPS_WORD:
        if (record->event.pressed) {
            toggle_caps_word_mode(CWMODE_NORMAL);
            return false;
        }
        break;
    case UKC_NUM_LOCK:
        static uint16_t colon_timer;
        if (record->event.pressed) {
            colon_timer = timer_read();
            layer_on(NUM);  //turn on NUM layer
        } else {
            layer_off(NUM);  //turn off NUM layer
            if (timer_elapsed(colon_timer) < TAPPING_TERM) {
                toggle_caps_word_mode(CWMODE_NUM_LOCK);
            }
        }
        return false;
    }

  return true;
}

void matrix_scan_user(void) {
  // Setup Achordion (Mod-Tap Fix)
  achordion_task();
}

// HOME ROW MODS 
#define HOME_A MT_LG(CK_A)
#define HOME_S MT_LA(CK_S)
#define HOME_D MT_LS(CK_D)
#define HOME_F MT_LC(CK_F)
#define HOME_J MT_RC(CK_J)
#define HOME_K MT_RS(CK_K)
#define HOME_L MT_LA(CK_L)
#define HOME__ MT_RG(CK_EQL)
#define LSPC LT(SYM, KC_SPC)
#define RSPC LT(SYM, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [QWERTZ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       CK_TAB,    CK_Q,    CK_W,    CK_E,    CK_R,    CK_T,                         CK_Z,    CK_U,    CK_I,    CK_O,   CK_P,  CK_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CK_LCTL,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    CK_G,                         CK_H,  HOME_J,  HOME_K,  HOME_L,  HOME__, CK_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       CK_ESC,    CK_Y,    CK_X,    CK_C,    CK_V,    CK_B,                         CK_N,    CK_M, CK_COMM,  CK_DOT, CK_MINS,  CK_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ENT, UKC_NUM_LOCK, LSPC,  RSPC, KC_RALT, UKC_LEADER 
                                      //`--------------------------'  `--------------------------'

  ),


    [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,  CK_USD,  CK_EUR, XXXXXXX, XXXXXXX,                      XXXXXXX,    CK_7,    CK_8,    CK_9, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, CK_SLSH, CK_ASTR, CK_MINS, CK_PLUS, XXXXXXX,                      XXXXXXX,    CK_4,    CK_5,    CK_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,  CK_DOT, CK_COMM, XXXXXXX, XXXXXXX,                      CK_COMM,    CK_1,    CK_2,    CK_3, CK_DOT,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC,  KC_ESC,  KC_SPC,    KC_SPC,    CK_0,    CK_0
                                      //`--------------------------'  `--------------------------'
  ),

    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, CK_EXLM,   CK_AT, CK_HASH,  KC_DLR, CK_PERC,                      CK_CIRC, CK_AMPR, CK_LRBR, CK_RRBR, CK_ASTR, CK_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      CK_MINS,  CK_EQL, CK_LNBR, CK_RNBR, CK_BSLS,  CK_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      CK_UNDS, CK_PLUS, CK_LCBR, CK_RCBR, CK_PIPE, CK_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CK_LGUI,   MO(3),  _______,     _______, _______, CK_RALT
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
                                          CK_LGUI, _______,  CK_SPC,     KC_ENT, _______, CK_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

const uint16_t caps_word1[] PROGMEM = { LSFT_T(CK_D), KC_SPC, COMBO_END};
const uint16_t caps_word2[] PROGMEM = { RSFT_T(CK_K), KC_SPC, COMBO_END};

const uint16_t escape[] PROGMEM = { RCTL_T(CK_J), RSFT_T(CK_K), COMBO_END};

combo_t key_combos[] = {
    COMBO(caps_word1, UKC_CAPS_WORD),
    COMBO(caps_word2, UKC_CAPS_WORD),
    COMBO(escape, KC_ESC)
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(*key_combos);
