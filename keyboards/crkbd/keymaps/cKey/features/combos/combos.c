#include "../../keymap_extras/keymap_ckey.h"
#include "combos.h"

/*
 * Combo positions are named by hand, finger, and row so definitions remain
 * independent of the letters assigned by a particular base layer.
 */
#define DEFINE_COMBO(name, result, ...)                              \
    const uint16_t PROGMEM name##_keys[] = {__VA_ARGS__, COMBO_END}; \
    const combo_t          name          = COMBO(name##_keys, result)

// Left hand shortcuts.
DEFINE_COMBO(select_all, CK_C__A, CMB_LL2, CMB_LR2);
DEFINE_COMBO(copy, CK_C__C, CMB_LR2, CMB_LM2);
DEFINE_COMBO(paste, CK_C__V, CMB_LM2, CMB_LI2);
DEFINE_COMBO(cut, CK_C__X, CMB_LL2, CMB_LR2, CMB_LM2, CMB_LI2);
DEFINE_COMBO(qwertz_toggle, TG(_QWERTZ), CMB_LL1, CMB_LR1, CMB_LM1, CMB_LI1);

// Right hand symbols.
DEFINE_COMBO(plus, CK_PLUS, CMB_RM1, CMB_RI1);
DEFINE_COMBO(minus, CK_MINS, CMB_RR1, CMB_RL1);
DEFINE_COMBO(asterisk, CK_ASTR, CMB_RI1, CMB_RR1);
DEFINE_COMBO(slash, CK_SLSH, CMB_RM1, CMB_RL1);
DEFINE_COMBO(dollar, CK__USD, CMB_RI1, CMB_RM1, CMB_RR1);
DEFINE_COMBO(euro, CK__EUR, CMB_RM1, CMB_RR1, CMB_RL1);
DEFINE_COMBO(equals, CK_EQLS, CMB_RM1, CMB_RR1);
DEFINE_COMBO(percent, CK_PERC, CMB_RI1, CMB_RL1);

DEFINE_COMBO(left_parenthesis, CK_LNBR, CMB_RI2, CMB_RM2);
DEFINE_COMBO(right_parenthesis, CK_RNBR, CMB_RR2, CMB_RL2);
DEFINE_COMBO(left_brace, CK_LCBR, CMB_RI2, CMB_RR2);
DEFINE_COMBO(right_brace, CK_RCBR, CMB_RM2, CMB_RL2);
DEFINE_COMBO(left_bracket, CK_LRBR, CMB_RI2, CMB_RM2, CMB_RR2);
DEFINE_COMBO(right_bracket, CK_RRBR, CMB_RM2, CMB_RR2, CMB_RL2);
DEFINE_COMBO(less_than, CK_LABK, CMB_RM2, CMB_RR2);
DEFINE_COMBO(greater_than, CK_RABK, CMB_RI2, CMB_RM2, CMB_RR2, CMB_RL2);

DEFINE_COMBO(ampersand, CK_AMPR, CMB_RI3, CMB_RM3);
DEFINE_COMBO(hash, CK_HASH, CMB_RM3, CMB_RR3);
DEFINE_COMBO(at_sign, CK___AT, CMB_RR3, CMB_RL3);
DEFINE_COMBO(question_mark, CK_QUES, CMB_RI3, CMB_RR3);
DEFINE_COMBO(exclamation_mark, CK_EXLM, CMB_RM3, CMB_RL3);
DEFINE_COMBO(underscore, CK_UNDS, CMB_RI3, CMB_RM3, CMB_RR3);
DEFINE_COMBO(minus_alt, CK_MINS, CMB_RM3, CMB_RR3, CMB_RL3);
DEFINE_COMBO(tilde, CK_TILD, CMB_RI3, CMB_RL3);

DEFINE_COMBO(slash_alt, CK_SLSH, CMB_RI2, CMB_RM1);
DEFINE_COMBO(backslash, CK_BSLS, CMB_RM1, CMB_RR2);
DEFINE_COMBO(pipe, CK_PIPE, CMB_RI2, CMB_RM1, CMB_RR2);
DEFINE_COMBO(acute, CK_ACUT, CMB_RI3, CMB_RM2);
DEFINE_COMBO(grave, CK__GRV, CMB_RM2, CMB_RR3);
DEFINE_COMBO(caret, CK_CIRC, CMB_RI3, CMB_RM2, CMB_RR3);

DEFINE_COMBO(double_quote, CK_DQUO, CMB_RI2, CMB_RL_2);
DEFINE_COMBO(colon, CK_COLN, CMB_RI2, CMB_RL2);
DEFINE_COMBO(semicolon, CK_SCLN, CMB_RI_2, CMB_RL2);
DEFINE_COMBO(delete_key, CK__DEL, CMB_RL1, CMB_RL_1);

combo_t key_combos[CKEY_COMBO_COUNT] = {
    select_all, copy, paste, cut, qwertz_toggle, plus, minus, asterisk, slash, dollar, euro, equals, percent, left_parenthesis, right_parenthesis, left_brace, right_brace, left_bracket, right_bracket, less_than, greater_than, ampersand, hash, at_sign, question_mark, exclamation_mark, underscore, minus_alt, tilde, slash_alt, backslash, pipe, acute, grave, caret, double_quote, colon, semicolon, delete_key,
};

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    return true;
}
