#pragma once

#include QMK_KEYBOARD_H
#include "keymap_german.h"



// clang-format off

//-----------------------------------
//           ALIASES
//-----------------------------------

// Numbers
#define     CK____1        DE_1            // 1
#define     CK____2        DE_2            // 2
#define     CK____3        DE_3            // 3
#define     CK____4        DE_4            // 4
#define     CK____5        DE_5            // 5
#define     CK____6        DE_6            // 6
#define     CK____7        DE_7            // 7
#define     CK____8        DE_8            // 8
#define     CK____9        DE_9            // 9
#define     CK____0        DE_0            // 0

// Letters
#define     CK____A        KC_A            // A
#define     CK____B        KC_B            // B
#define     CK____C        KC_C            // C
#define     CK____D        KC_D            // D
#define     CK____E        KC_E            // E
#define     CK____F        KC_F            // F
#define     CK____G        KC_G            // G
#define     CK____H        KC_H            // H
#define     CK____I        KC_I            // I
#define     CK____J        KC_J            // J
#define     CK____K        KC_K            // K
#define     CK____L        KC_L            // L
#define     CK____M        KC_M            // M
#define     CK____N        KC_N            // N
#define     CK____O        KC_O            // O
#define     CK____P        KC_P            // P
#define     CK____Q        KC_Q            // Q
#define     CK____R        KC_R            // R
#define     CK____S        KC_S            // S
#define     CK____T        KC_T            // T
#define     CK____U        KC_U            // U
#define     CK____V        KC_V            // V
#define     CK____W        KC_W            // W
#define     CK____X        KC_X            // X
#define     CK____Y        KC_Z            // Y
#define     CK____Z        KC_Y            // Z

// Symbols
#define     CK_LNBR     DE_LPRN         // (
#define     CK_RNBR     DE_RPRN         // )
#define     CK_LRBR     DE_LBRC         // [
#define     CK_RRBR     DE_RBRC         // ]
#define     CK_LCBR     DE_LCBR         // {
#define     CK_RCBR     DE_RCBR         // }
#define     CK_LABK     DE_LABK         // <
#define     CK_RABK     DE_RABK         // >
#define     CK_DQUO     DE_DQUO         // "
#define     CK__QUO     DE_QUOT         // '
#define     CK__DOT     DE_DOT          // .
#define     CK_COLN     DE_COLN         // :
#define     CK_COMM     DE_COMM         // ,
#define     CK_SCLN     DE_SCLN         // ;
#define     CK_QUES     DE_QUES         // ?
#define     CK_EXLM     DE_EXLM         // !
#define     CK_PLUS     DE_PLUS         // +
#define     CK_ASTR     DE_ASTR         // *
#define     CK_MINS     DE_MINS         // -
#define     CK_UNDS     DE_UNDS         // _
#define     CK_SLSH     DE_SLSH         // /
#define     CK_BSLS     DE_BSLS         // <backslash>
#define     CK_PIPE     DE_PIPE         // |
#define     CK_EQLS     DE_EQL          // =
#define     CK_PERC     DE_PERC         // % 
#define     CK_AMPR     DE_AMPR         // &
#define     CK_HASH     DE_HASH         // #
#define     CK_AT       DE_AT           // @
#define     CK_TILD     DE_TILD         // ~
#define     CK_DEG      DE_DEG          // °
#define     CK__EUR     DE_EURO         // €
#define     CK__USD     DE_DLR          // $
#define     CK_SECT     DE_SECT         // §

// Controls
#define     CK_ENT      KC_ENT
#define     CK_SPC      KC_SPC
#define     CK_BSPC     KC_BSPC
#define     CK_DEL      KC_DEL
#define     CK_ESC      KC_ESC
#define     CK_TAB      KC_TAB
#define     CK_LCTL     KC_LCTL
#define     CK_LSFT     KC_LSFT
#define     CK_LALT     KC_LALT
#define     CK_LGUI     KC_LGUI
#define     CK_RCTL     KC_RCTL
#define     CK_RSFT     KC_RSFT
#define     CK_RALT     KC_RALT
#define     CK_RGUI     KC_RGUI
#define     CK_LEFT     KC_LEFT
#define     CK_UP       KC_UP
#define     CK_RIGHT    KC_RIGHT
#define     CK_DOWN     KC_DOWN
#define     CK_HOME     KC_HOME
#define     CK_END      KC_END


//-----------------------------------
//           DIACRITICS
//-----------------------------------


#define     ___CIRC     DE_CIRC         // ^ (dead)
#define     ___GRV      DE_GRV          // ` (dead)
#define     ___ACUT     DE_ACUT         // ´ (dead)

// german
#define     CK_ADIA     DE_ADIA      // Ä
#define     CK_ODIA     DE_ODIA      // Ö
#define     CK_UDIA     DE_UDIA      // Ü
#define     CK_SS       DE_SS           // ß

enum deadkey_diacritics {  
 CK_CIRC,           // ^
 CK_GRV,            // `
 CK_ACUT,           // ´

 // romanian
 CK_ACIR,           // Â
 CK_ABRV,           // Ă
 CK_ICIR,           // Î
 CK_SCOM,           // Ș
 CK_TCOM,           // Ț

 //french
 CK_AGRV,           // à
 CK_CCED,           // ç
 CK_EACU,           // é
 CK_EGRV,           // è
 CK_ICRC,           // î
 CK_OCRC,           // ô
 CK_UCRC,           // û
 CK_UGRV,           // ù
};

bool handle_deadkey_diacritic(uint16_t keycode, keyrecord_t *record);