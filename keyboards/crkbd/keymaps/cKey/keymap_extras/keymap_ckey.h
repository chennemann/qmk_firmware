#pragma once

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "features.h"

// Define the key overrides array
extern const key_override_t *key_overrides[4];

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

// Function Keys
#define     CK___F1         KC_F1           // F1
#define     CK___F2         KC_F2           // F2
#define     CK___F3         KC_F3           // F3
#define     CK___F4         KC_F4           // F4
#define     CK___F5         KC_F5           // F5
#define     CK___F6         KC_F6           // F6
#define     CK___F7         KC_F7           // F7
#define     CK___F8         KC_F8           // F8
#define     CK___F9         KC_F9           // F9
#define     CK__F10         KC_F10          // F10
#define     CK__F11         KC_F11          // F11
#define     CK__F12         KC_F12          // F12

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

#define     CK_C__A         C(CK____A)          // <ctrl-a>
#define     CK_CS_A         C(S(CK____A))       // <ctrl-shift-a>
#define     CK_CSAA         C(S(A(CK____A)))    // <ctrl-shift-alt-a>
#define     CK_C__B         C(CK____B)          // <ctrl-b>
#define     CK_CS_B         C(S(CK____B))       // <ctrl-shift-b>
#define     CK_CSAB         C(S(A(CK____B)))    // <ctrl-shift-alt-b>
#define     CK_C__C         C(CK____C)          // <ctrl-c>
#define     CK_CS_C         C(S(CK____C))       // <ctrl-shift-c>
#define     CK_CSAC         C(S(A(CK____C)))    // <ctrl-shift-alt-c>
#define     CK_C__D         C(CK____D)          // <ctrl-d>
#define     CK_CS_D         C(S(CK____D))       // <ctrl-shift-d>
#define     CK_CSAD         C(S(A(CK____D)))    // <ctrl-shift-alt-d>
#define     CK_C__E         C(CK____E)          // <ctrl-e>
#define     CK_CS_E         C(S(CK____E))       // <ctrl-shift-e>
#define     CK_CSAE         C(S(A(CK____E)))    // <ctrl-shift-alt-e>
#define     CK_C__F         C(CK____F)          // <ctrl-f>
#define     CK_CS_F         C(S(CK____F))       // <ctrl-shift-f>
#define     CK_CSAF         C(S(A(CK____F)))    // <ctrl-shift-alt-f>
#define     CK_C__G         C(CK____G)          // <ctrl-g>
#define     CK_CS_G         C(S(CK____G))       // <ctrl-shift-g>
#define     CK_CSAG         C(S(A(CK____G)))    // <ctrl-shift-alt-g>
#define     CK_C__H         C(CK____H)          // <ctrl-h>
#define     CK_CS_H         C(S(CK____H))       // <ctrl-shift-h>
#define     CK_CSAH         C(S(A(CK____H)))    // <ctrl-shift-alt-h>
#define     CK_C__I         C(CK____I)          // <ctrl-i>
#define     CK_CS_I         C(S(CK____I))       // <ctrl-shift-i>
#define     CK_CSAI         C(S(A(CK____I)))    // <ctrl-shift-alt-i>
#define     CK_C__J         C(CK____J)          // <ctrl-j>
#define     CK_CS_J         C(S(CK____J))       // <ctrl-shift-j>
#define     CK_CSAJ         C(S(A(CK____J)))    // <ctrl-shift-alt-j>
#define     CK_C__K         C(CK____K)          // <ctrl-k>
#define     CK_CS_K         C(S(CK____K))       // <ctrl-shift-k>
#define     CK_CSAK         C(S(A(CK____K)))    // <ctrl-shift-alt-k>
#define     CK_C__L         C(CK____L)          // <ctrl-l>
#define     CK_CS_L         C(S(CK____L))       // <ctrl-shift-l>
#define     CK_CSAL         C(S(A(CK____L)))    // <ctrl-shift-alt-l>
#define     CK_C__M         C(CK____M)          // <ctrl-m>
#define     CK_CS_M         C(S(CK____M))       // <ctrl-shift-m>
#define     CK_CSAM         C(S(A(CK____M)))    // <ctrl-shift-alt-m>
#define     CK_C__N         C(CK____N)          // <ctrl-n>
#define     CK_CS_N         C(S(CK____N))       // <ctrl-shift-n>
#define     CK_CSAN         C(S(A(CK____N)))    // <ctrl-shift-alt-n>
#define     CK_C__O         C(CK____O)          // <ctrl-o>
#define     CK_CS_O         C(S(CK____O))       // <ctrl-shift-o>
#define     CK_CSAO         C(S(A(CK____O)))    // <ctrl-shift-alt-o>
#define     CK_C__P         C(CK____P)          // <ctrl-p>
#define     CK_CS_P         C(S(CK____P))       // <ctrl-shift-p>
#define     CK_CSAP         C(S(A(CK____P)))    // <ctrl-shift-alt-p>
#define     CK_C__Q         C(CK____Q)          // <ctrl-q>
#define     CK_CS_Q         C(S(CK____Q))       // <ctrl-shift-q>
#define     CK_CSAQ         C(S(A(CK____Q)))    // <ctrl-shift-alt-q>
#define     CK_C__R         C(CK____R)          // <ctrl-r>
#define     CK_CS_R         C(S(CK____R))       // <ctrl-shift-r>
#define     CK_CSAR         C(S(A(CK____R)))    // <ctrl-shift-alt-r>
#define     CK_C__S         C(CK____S)          // <ctrl-s>
#define     CK_CS_S         C(S(CK____S))       // <ctrl-shift-s>
#define     CK_CSAS         C(S(A(CK____S)))    // <ctrl-shift-alt-s>
#define     CK_C__T         C(CK____T)          // <ctrl-t>
#define     CK_CS_T         C(S(CK____T))       // <ctrl-shift-t>
#define     CK_CSAT         C(S(A(CK____T)))    // <ctrl-shift-alt-t>
#define     CK_C__U         C(CK____U)          // <ctrl-u>
#define     CK_CS_U         C(S(CK____U))       // <ctrl-shift-u>
#define     CK_CSAU         C(S(A(CK____U)))    // <ctrl-shift-alt-u>
#define     CK_C__V         C(CK____V)          // <ctrl-v>
#define     CK_CS_V         C(S(CK____V))       // <ctrl-shift-v>
#define     CK_CSAV         C(S(A(CK____V)))    // <ctrl-shift-alt-v>
#define     CK_C__W         C(CK____W)          // <ctrl-w>
#define     CK_CS_W         C(S(CK____W))       // <ctrl-shift-w>
#define     CK_CSAW         C(S(A(CK____W)))    // <ctrl-shift-alt-w>
#define     CK_C__X         C(CK____X)          // <ctrl-x>
#define     CK_CS_X         C(S(CK____X))       // <ctrl-shift-x>
#define     CK_CSAX         C(S(A(CK____X)))    // <ctrl-shift-alt-x>
#define     CK_C__Y         C(CK____Y)          // <ctrl-y>
#define     CK_CS_Y         C(S(CK____Y))       // <ctrl-shift-y>
#define     CK_CSAY         C(S(A(CK____Y)))    // <ctrl-shift-alt-y>
#define     CK_C__Z         C(CK____Z)          // <ctrl-z>
#define     CK_CS_Z         C(S(CK____Z))       // <ctrl-shift-z>
#define     CK_CSAZ         C(S(A(CK____Z)))    // <ctrl-shift-alt-z>

#define     CK_UNDO         CK_C__Z      // undo
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

