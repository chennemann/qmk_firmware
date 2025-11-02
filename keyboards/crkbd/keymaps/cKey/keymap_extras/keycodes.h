#pragma once

/*
    Define available layer names
*/
enum layers {
  _BYOU = 0,
  _COMBO_REF,
  _SYM,
  _NUM,
  _FN,
  _DIA,
  _NAV,

  _CAPS,
};


/*
    Define custom keycodes
*/
enum {
    CW_CAPS = 201,
    CW_CAML,
    CW_KEBA,
    CW_SNAK,
    CW_SLSH,
    CW_BSLS,

    CK_SELW,
    CK_SELB,
    CK_LSEL,
    CK_BSEL,   
};


/*
    Define custom Tap Dance Keys
*/
enum {
    TD_ENTER = 101,
    TD_SPACE,
    TD_ENTER_SHIFT,
    TD_ENTER_NUM,
    TD_SPACE_SHIFT,
    TD_SPACE_SYM,
};



// Keycode Aliases for easy access
#define TD__SPC TD(TD_SPACE)        // Tap-Dance Space
#define TD__SFT TD(TD_ENTER)        // Tap-Dance Enter

#define TD_SENT TD(TD_ENTER_SHIFT)      // Tap-Dance Shift/Enter
#define TD_NENT TD(TD_ENTER_NUM)        // Tap-Dance Num/Enter
#define TD_SSPC TD(TD_SPACE_SHIFT)      // Tap-Dance Shift/Space
#define TD_SYSP TD(TD_SPACE_SYM)        // Tap-Dance SYM/Space

#define MO__SYM MO(_SYM)
#define MO__DIA MO(_DIA)
#define MO__NAV MO(_NAV)
#define MO__NUM MO(_NUM)
#define MO___FN MO(_FN)
#define NUM_SPC LT(_NUM, CK__SPC)
#define LT_FN_0 LT(_FN, CK____0)

#define PRESSED _______



// Home Row Modifiers
#define HOME_CA MT(MOD_LCTL, CK____A)
#define HOME_SA MT(MOD_LSFT, CK____A)
#define HOME_AA MT(MOD_LALT, CK____A)
#define HOME_GA MT(MOD_LGUI, CK____A)

#define HOME_CB MT(MOD_LCTL, CK____B)
#define HOME_SB MT(MOD_LSFT, CK____B)
#define HOME_AB MT(MOD_LALT, CK____B)
#define HOME_GB MT(MOD_LGUI, CK____B)

#define HOME_CC MT(MOD_LCTL, CK____C)
#define HOME_SC MT(MOD_LSFT, CK____C)
#define HOME_AC MT(MOD_LALT, CK____C)
#define HOME_GC MT(MOD_LGUI, CK____C)

#define HOME_CD MT(MOD_LCTL, CK____D)
#define HOME_SD MT(MOD_LSFT, CK____D)
#define HOME_AD MT(MOD_LALT, CK____D)
#define HOME_GD MT(MOD_LGUI, CK____D)

#define HOME_CE MT(MOD_LCTL, CK____E)
#define HOME_SE MT(MOD_LSFT, CK____E)
#define HOME_AE MT(MOD_LALT, CK____E)
#define HOME_GE MT(MOD_LGUI, CK____E)

#define HOME_CF MT(MOD_LCTL, CK____F)
#define HOME_SF MT(MOD_LSFT, CK____F)
#define HOME_AF MT(MOD_LALT, CK____F)
#define HOME_GF MT(MOD_LGUI, CK____F)

#define HOME_CG MT(MOD_LCTL, CK____G)
#define HOME_SG MT(MOD_LSFT, CK____G)
#define HOME_AG MT(MOD_LALT, CK____G)
#define HOME_GG MT(MOD_LGUI, CK____G)

#define HOME_CH MT(MOD_LCTL, CK____H)
#define HOME_SH MT(MOD_LSFT, CK____H)
#define HOME_AH MT(MOD_LALT, CK____H)
#define HOME_GH MT(MOD_LGUI, CK____H)

#define HOME_CI MT(MOD_LCTL, CK____I)
#define HOME_SI MT(MOD_LSFT, CK____I)
#define HOME_AI MT(MOD_LALT, CK____I)
#define HOME_GI MT(MOD_LGUI, CK____I)

#define HOME_CJ MT(MOD_LCTL, CK____J)
#define HOME_SJ MT(MOD_LSFT, CK____J)
#define HOME_AJ MT(MOD_LALT, CK____J)
#define HOME_GJ MT(MOD_LGUI, CK____J)

#define HOME_CK MT(MOD_LCTL, CK____K)
#define HOME_SK MT(MOD_LSFT, CK____K)
#define HOME_AK MT(MOD_LALT, CK____K)
#define HOME_GK MT(MOD_LGUI, CK____K)

#define HOME_CL MT(MOD_LCTL, CK____L)
#define HOME_SL MT(MOD_LSFT, CK____L)
#define HOME_AL MT(MOD_LALT, CK____L)
#define HOME_GL MT(MOD_LGUI, CK____L)

#define HOME_CM MT(MOD_LCTL, CK____M)
#define HOME_SM MT(MOD_LSFT, CK____M)
#define HOME_AM MT(MOD_LALT, CK____M)
#define HOME_GM MT(MOD_LGUI, CK____M)

#define HOME_CN MT(MOD_LCTL, CK____N)
#define HOME_SN MT(MOD_LSFT, CK____N)
#define HOME_AN MT(MOD_LALT, CK____N)
#define HOME_GN MT(MOD_LGUI, CK____N)

#define HOME_CO MT(MOD_LCTL, CK____O)
#define HOME_SO MT(MOD_LSFT, CK____O)
#define HOME_AO MT(MOD_LALT, CK____O)
#define HOME_GO MT(MOD_LGUI, CK____O)

#define HOME_CP MT(MOD_LCTL, CK____P)
#define HOME_SP MT(MOD_LSFT, CK____P)
#define HOME_AP MT(MOD_LALT, CK____P)
#define HOME_GP MT(MOD_LGUI, CK____P)

#define HOME_CQ MT(MOD_LCTL, CK____Q)
#define HOME_SQ MT(MOD_LSFT, CK____Q)
#define HOME_AQ MT(MOD_LALT, CK____Q)
#define HOME_GQ MT(MOD_LGUI, CK____Q)

#define HOME_CR MT(MOD_LCTL, CK____R)
#define HOME_SR MT(MOD_LSFT, CK____R)
#define HOME_AR MT(MOD_LALT, CK____R)
#define HOME_GR MT(MOD_LGUI, CK____R)

#define HOME_CS MT(MOD_LCTL, CK____S)
#define HOME_SS MT(MOD_LSFT, CK____S)
#define HOME_AS MT(MOD_LALT, CK____S)
#define HOME_GS MT(MOD_LGUI, CK____S)

#define HOME_CT MT(MOD_LCTL, CK____T)
#define HOME_ST MT(MOD_LSFT, CK____T)
#define HOME_AT MT(MOD_LALT, CK____T)
#define HOME_GT MT(MOD_LGUI, CK____T)

#define HOME_CU MT(MOD_LCTL, CK____U)
#define HOME_SU MT(MOD_LSFT, CK____U)
#define HOME_AU MT(MOD_LALT, CK____U)
#define HOME_GU MT(MOD_LGUI, CK____U)

#define HOME_CV MT(MOD_LCTL, CK____V)
#define HOME_SV MT(MOD_LSFT, CK____V)
#define HOME_AV MT(MOD_LALT, CK____V)
#define HOME_GV MT(MOD_LGUI, CK____V)

#define HOME_CW MT(MOD_LCTL, CK____W)
#define HOME_SW MT(MOD_LSFT, CK____W)
#define HOME_AW MT(MOD_LALT, CK____W)
#define HOME_GW MT(MOD_LGUI, CK____W)

#define HOME_CX MT(MOD_LCTL, CK____X)
#define HOME_SX MT(MOD_LSFT, CK____X)
#define HOME_AX MT(MOD_LALT, CK____X)
#define HOME_GX MT(MOD_LGUI, CK____X)

#define HOME_CY MT(MOD_LCTL, CK____Y)
#define HOME_SY MT(MOD_LSFT, CK____Y)
#define HOME_AY MT(MOD_LALT, CK____Y)
#define HOME_GY MT(MOD_LGUI, CK____Y)

#define HOME_CZ MT(MOD_LCTL, CK____Z)
#define HOME_SZ MT(MOD_LSFT, CK____Z)
#define HOME_AZ MT(MOD_LALT, CK____Z)
#define HOME_GZ MT(MOD_LGUI, CK____Z)


// Combo Keys for easy access

#define CMB_LL1 CK____B
#define CMB_LR1 CK____C
#define CMB_LM1 CK____D
#define CMB_LI1 CK____E
#define CMB_LL2 CK____N
#define CMB_LR2 CK____O
#define CMB_LM2 CK____P
#define CMB_LI2 CK____Q
#define CMB_LL3 CK____Z
#define CMB_LR3 CK____0
#define CMB_LM3 CK____1
#define CMB_LI3 CK____2

#define CMB_RL1 CK____K
#define CMB_RR1 CK____J
#define CMB_RM1 CK____I
#define CMB_RI1 CK____H
#define CMB_RL2 CK____W
#define CMB_RR2 CK____V
#define CMB_RM2 CK____U
#define CMB_RI2 CK____T
#define CMB_RL3 CK____8
#define CMB_RR3 CK____7
#define CMB_RM3 CK____6
#define CMB_RI3 CK____5