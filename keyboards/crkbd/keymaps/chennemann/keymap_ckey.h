
#pragma once
#include "keycodes.h"
// clang-format off

//-----------------------------------
//           ALIASES
//-----------------------------------

// Number Row
#define ___CIRC KC_GRV  // ^
#define CK_1    KC_1    // 1
#define CK_2    KC_2    // 2
#define CK_3    KC_3    // 3
#define CK_4    KC_4    // 4
#define CK_5    KC_5    // 5
#define CK_6    KC_6    // 6
#define CK_7    KC_7    // 7
#define CK_8    KC_8    // 8
#define CK_9    KC_9    // 9
#define CK_0    KC_0    // 0
#define ___QUES KC_MINS // ?
#define ___EXLM KC_EQL  // !

// 1st letter row
#define CK_Q    KC_Q    // Q
#define CK_W    KC_W    // W
#define CK_E    KC_E    // E
#define CK_R    KC_R    // R
#define CK_T    KC_T    // T
#define CK_Z    KC_Y    // Z
#define CK_U    KC_U    // U
#define CK_I    KC_I    // I
#define CK_O    KC_O    // O
#define CK_P    KC_P    // P
#define ___LCBR KC_LBRC // {
#define ___RCBR KC_RBRC // }

// 2nd letter row
#define CK_A    KC_A    // A
#define CK_S    KC_S    // S
#define CK_D    KC_D    // D
#define CK_F    KC_F    // F
#define CK_G    KC_G    // G
#define CK_H    KC_H    // H
#define CK_J    KC_J    // J
#define CK_K    KC_K    // K
#define CK_L    KC_L    // L
#define ___EQL  KC_SCLN // =
#define ___LNBR KC_QUOT // (
#define ___RNBR KC_NUHS // )

// 3rd letter row
#define ___LABK KC_NUBS // <
#define CK_Y    KC_Z    // Y
#define CK_X    KC_X    // X
#define CK_C    KC_C    // C
#define CK_V    KC_V    // V
#define CK_B    KC_B    // B
#define CK_N    KC_N    // N
#define CK_M    KC_M    // M
#define ___COMM KC_COMM // ,
#define ___DOT  KC_DOT  // .
#define ___MINS KC_SLSH // -


//-----------------------------------
//           DIACRITICS
//-----------------------------------

// german
#define CK_ADIA ALGR(CK_A)    // Ä
#define CK_ODIA ALGR(CK_O)    // Ö
#define CK_UDIA ALGR(CK_U)    // Ü
#define CK_SS   ALGR(CK_S)    // ß
// romanian
#define CK_ACIR ALGR(___LABK) // Â
#define CK_ABRV ALGR(CK_Y)    // Ă
#define CK_ICIR ALGR(CK_X)    // Î
#define CK_SCOM ALGR(CK_C)    // Ș
#define CK_TCOM ALGR(CK_V)    // Ț
// french
#define CK_AGRV ALGR(CK_B)    // à
#define CK_CCED ALGR(CK_F)    // ç
#define CK_EACU ALGR(CK_N)    // é
#define CK_EGRV ALGR(CK_M)    // è
#define CK_ICRC ALGR(___COMM) // î
#define CK_OCRC ALGR(CK_G)    // ô
#define CK_UCRC ALGR(CK_H)    // û
#define CK_UGRV ALGR(CK_J)    // ù



//-----------------------------------
//           SYMBOLS
//-----------------------------------

#define CK_DOT  ___DOT           // .
#define CK_COLN S(___DOT)        // :
#define CK_COMM ___COMM          // ,
#define CK_SCLN S(___COMM)       // ;
#define CK_QUES ___QUES          // ?
#define CK_EXLM ___EXLM          // !
#define CK_LNBR ___LNBR          // (
#define CK_RNBR ___RNBR          // )
#define CK_LCBR ___LCBR          // {
#define CK_RCBR ___RCBR          // }
#define CK_LRBR S(___LCBR)       // [
#define CK_RRBR S(___RCBR)       // ]
#define CK_LABK ___LABK          // <
#define CK_LABK S(___LABK)       // >
#define CK_EQL  ___EQL           // =
#define CK_PLUS S(___EQL)        // +
#define CK_PLUS ALGR(___EQL)     // *
#define CK_MINS ___MINS          // -
#define CK_UNDS S(___MINS)       // _
#define CK_SLSH S(___RNBR)       // /
#define CK_BSLS ALGR(___RNBR)    // (backslash)
#define CK_PIPE S(ALGR(CK_LABK)) // |
#define CK_CIRC ___CIRC          // ^
#define CK_PERC S(CK_5)          // %
#define CK_DQUO S(CK_LNBR)       // "
#define CK_QUOT ALGR(CK_LNBR)    // '
#define CK_GRV  S(CK_0)          // `
#define CK_ACUT S(CK_9)          // ´

#define CK_EUR  S(CK_3)          // €
#define CK_USD  S(CK_4)          // $
#define CK_PND  ALGR(CK_5)       // £
#define CK_CNT  ALGR(CK_2)       // ¢
     
#define CK_DEG  S(CK_CIRC)       // °
#define CK_HASH S(CK_1)          // #
#define CK_AT   S(CK_2)          // @
#define CK_AMPR S(CK_6)          // &
#define CK_TILD ALGR(___LCBR)    // ~
#define CK_SECT S(ALGR(CK_3))    // §
#define CK_SUP1 S(ALGR(CK_7))    // ¹
#define CK_SUP2 S(ALGR(CK_8))    // ²
#define CK_SUP3 S(ALGR(CK_9))    // ³
#define CK_HALF S(ALGR(CK_0))    // ½
#define CK_THFO S(ALGR(___QUES)) // ¾
#define CK_DIVI S(ALGR(___EXLM)) // ÷


