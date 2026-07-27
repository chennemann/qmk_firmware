#pragma once

#include "../../keymap_extras/keymap_ckey.h"

#undef HOME_GL
#undef HOME_AL
#undef HOME_SL
#undef HOME_CL
#undef HOME_CR
#undef HOME_SR
#undef HOME_AR
#undef HOME_GR

enum {
    HOME_GL = MT(MOD_LGUI, KC_F13),
    HOME_AL = MT(MOD_LALT, KC_F14),
    HOME_SL = MT(MOD_LSFT, KC_F15),
    HOME_CL = MT(MOD_LCTL, KC_F16),
    HOME_CR = MT(MOD_LCTL, KC_F17),
    HOME_SR = MT(MOD_LSFT, KC_F18),
    HOME_AR = MT(MOD_LALT, KC_F19),
    HOME_GR = MT(MOD_LGUI, KC_F20),
};
