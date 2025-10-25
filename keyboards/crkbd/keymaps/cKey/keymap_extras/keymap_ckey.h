#pragma once

#include QMK_KEYBOARD_H
#include "keymap_german.h"



// clang-format off

//-----------------------------------
//           ALIASES
//-----------------------------------

// Numbers
#define     CK____1         DE_1            // 1
#define     CK____2         DE_2            // 2
#define     CK____3         DE_3            // 3
#define     CK____4         DE_4            // 4
#define     CK____5         DE_5            // 5
#define     CK____6         DE_6            // 6
#define     CK____7         DE_7            // 7
#define     CK____8         DE_8            // 8
#define     CK____9         DE_9            // 9
#define     CK____0         DE_0            // 0

// Letters
#define     CK____A         KC_A            // A
#define     CK____B         KC_B            // B
#define     CK____C         KC_C            // C
#define     CK____D         KC_D            // D
#define     CK____E         KC_E            // E
#define     CK____F         KC_F            // F
#define     CK____G         KC_G            // G
#define     CK____H         KC_H            // H
#define     CK____I         KC_I            // I
#define     CK____J         KC_J            // J
#define     CK____K         KC_K            // K
#define     CK____L         KC_L            // L
#define     CK____M         KC_M            // M
#define     CK____N         KC_N            // N
#define     CK____O         KC_O            // O
#define     CK____P         KC_P            // P
#define     CK____Q         KC_Q            // Q
#define     CK____R         KC_R            // R
#define     CK____S         KC_S            // S
#define     CK____T         KC_T            // T
#define     CK____U         KC_U            // U
#define     CK____V         KC_V            // V
#define     CK____W         KC_W            // W
#define     CK____X         KC_X            // X
#define     CK____Y         KC_Z            // Y
#define     CK____Z         KC_Y            // Z

// Symbols
#define     CK_LNBR         DE_LPRN         // (
#define     CK_RNBR         DE_RPRN         // )
#define     CK_LRBR         DE_LBRC         // [
#define     CK_RRBR         DE_RBRC         // ]
#define     CK_LCBR         DE_LCBR         // {
#define     CK_RCBR         DE_RCBR         // }
#define     CK_LABK         DE_LABK         // <
#define     CK_RABK         DE_RABK         // >
#define     CK_DQUO         DE_DQUO         // "
#define     CK__QUO         DE_QUOT         // '
#define     CK__DOT         DE_DOT          // .
#define     CK_COLN         DE_COLN         // :
#define     CK_COMM         DE_COMM         // ,
#define     CK_SCLN         DE_SCLN         // ;
#define     CK_QUES         DE_QUES         // ?
#define     CK_EXLM         DE_EXLM         // !
#define     CK_PLUS         DE_PLUS         // +
#define     CK_ASTR         DE_ASTR         // *
#define     CK_MINS         DE_MINS         // -
#define     CK_UNDS         DE_UNDS         // _
#define     CK_SLSH         DE_SLSH         // /
#define     CK_BSLS         DE_BSLS         // <backslash>
#define     CK_PIPE         DE_PIPE         // |
#define     CK_EQLS         DE_EQL          // =
#define     CK_PERC         DE_PERC         // % 
#define     CK_AMPR         DE_AMPR         // &
#define     CK_HASH         DE_HASH         // #
#define     CK___AT         DE_AT           // @
#define     CK_TILD         DE_TILD         // ~
#define     CK__DEG         DE_DEG          // °
#define     CK__EUR         DE_EURO         // €
#define     CK__USD         DE_DLR          // $
#define     CK_SECT         DE_SECT         // §

// Controls
#define     CK__ENT         KC_ENT          // <enter>
#define     CK__INS         KC_INS          // <insert>
#define     CK__SPC         KC_SPC          // <space>
#define     CK_BSPC         KC_BSPC         // <backspace>
#define     CK__DEL         KC_DEL          // <delete>
#define     CK__ESC         KC_ESC          // <escape>
#define     CK__TAB         KC_TAB          // <tab>
#define     CK_LCTL         KC_LCTL         // <left control>
#define     CK_LSFT         KC_LSFT         // <left shift>
#define     CK_LALT         KC_LALT         // <left alt>
#define     CK_LGUI         KC_LGUI         // <left gui>
#define     CK_RCTL         KC_RCTL         // <right control>
#define     CK_RSFT         KC_RSFT         // <right shift>
#define     CK_RALT         KC_RALT         // <right alt>
#define     CK_RGUI         KC_RGUI         // <right gui>
#define     CK_LEFT         KC_LEFT         // <left>
#define     CK___UP         KC_UP           // <up>
#define     CK_RGHT         KC_RIGHT        // <right>
#define     CK_DOWN         KC_DOWN         // <down>
#define     CK_HOME         KC_HOME         // <home>
#define     CK__END         KC_END          // <end>
#define     CK_PGUP         KC_PGUP         // <page up>
#define     CK_PGDN         KC_PGDN         // <page down>

#define     CK_UNDO         C(CK____Z)      // undo
#define     CK_REDO         C(CK____Y)      // redo
#define     CK_COPY         C(CK____C)      // copy
#define     CK__CUT         C(CK____X)      // cut
#define     CK_PAST         C(CK____V)      // paste



//-----------------------------------
//           DIACRITICS
//-----------------------------------


#define     ___CIRC     DE_CIRC         // ^ (dead)
#define     ___GRV      DE_GRV          // ` (dead)
#define     ___ACUT     DE_ACUT         // ´ (dead)
#define     ___BREV     ALGR(DE_F)      // ˘ (dead)
#define     ___CEDI     ALGR(DE_G)      // ¸ (dead)
#define     ___TILD     ALGR(DE_H)      // ~ (dead)
#define     ___DEGR     ALGR(DE_V)      // ° (dead)
#define     ___TREM     ALGR(DE_B)      // ¨ (dead)

// german
#define     CK_ADIA     DE_ADIA         // ä
#define     CK_ODIA     DE_ODIA         // ö
#define     CK_UDIA     DE_UDIA         // ü
#define     CK___SS     DE_SS           // ß

enum deadkey_diacritics {  
    CK_CIRC = SAFE_RANGE+1000,          // ^
    CK_ACRC,                            // â
    CK_ECRC,                            // ê
    CK_ICRC,                            // î
    CK_OCRC,                            // ô
    CK_UCRC,                            // û

    CK__GRV,                            // `
    CK_AGRV,                            // à
    CK_EGRV,                            // è
    CK_IGRV,                            // ì
    CK_OGRV,                            // ò
    CK_UGRV,                            // ù

    CK_ACUT,                            // ´
    CK_AACU,                            // á
    CK_CACU,                            // ć
    CK_EACU,                            // é
    CK_IACU,                            // í
    CK_LACU,                            // ĺ
    CK_NACU,                            // ń
    CK_OACU,                            // ó
    CK_RACU,                            // ŕ
    CK_SACU,                            // ś
    CK_UACU,                            // ú
    CK_YACU,                            // ý
    CK_ZACU,                            // ź

    CK_ABRV,                            // ă
    CK_CBRV,                            // č
    CK_EBRV,                            // ě
    CK_NBRV,                            // ň
    CK_SBRV,                            // š
    CK_ZBRV,                            // ž

    CK_CCED,                            // ç
    CK_SCED,                            // ş
    CK_TCED,                            // ţ

    CK_ATIL,                            // ã
    CK_NTIL,                            // ñ
    CK_OTIL,                            // õ

    CK_ADEG,                            // å

    CK_ETRM,                            // ë
    CK_ITRM,                            // ï
};

bool handle_diacritic_keycode(uint16_t keycode, keyrecord_t *record);