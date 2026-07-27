#pragma once

#include "quantum.h"
#include "../../keymap_extras/keycodes.h"

#undef HOME_GL
#undef HOME_AL
#undef HOME_SL
#undef HOME_CL
#undef HOME_CR
#undef HOME_SR
#undef HOME_AR
#undef HOME_GR

/*
 * Home-row mod keycodes
 * ---------------------
 * The suffix identifies the modifier and hand:
 *   G = GUI, A = Alt, S = Shift, C = Control
 *   L = left hand, R = right hand
 *
 * To change a hold action, edit the modifier in MT().
 *
 * F13-F20 are unique internal placeholders. They are never sent as the tap
 * action: home_row_mods.c replaces them with the tap key configured for the
 * active layer. Keep each placeholder unique and keep this order synchronized
 * with the home_row_mods table in home_row_mods.c.
 */
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

bool process_home_row_mods(uint16_t keycode, keyrecord_t *record);
