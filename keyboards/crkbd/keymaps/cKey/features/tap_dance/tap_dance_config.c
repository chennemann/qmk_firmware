#include "../../keymap_extras/keymap_ckey.h"

static void space_sym_finished(tap_dance_state_t *state, void *user_data) {
    x_layer_finished(state, user_data, CK__SPC, _DIA, _NUM);
}

static void space_sym_reset(tap_dance_state_t *state, void *user_data) {
    x_layer_reset(state, user_data, _DIA, _NUM);
}

tap_dance_action_t tap_dance_actions[TD_NAV_HOME_GUI + 1] =
    {
        [TD_ENTER] =
            {
                .fn        = {x_mod_on_each_tap, x_mod_finished, x_mod_reset, x_mod_on_each_release},
                .user_data = &(tap_dance_config_t){.keycode = CK__ENT, .hold_mods = MOD_BIT(KC_LSFT), .retro_enabled = true, .dt_keycode = CW_CAPS, .has_dt_keycode = true, .dt_layer = _CAPS, .has_dt_layer = true},
            },
        [TD_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_sym_finished, space_sym_reset),
        [TD_NAV_HOME_SFT] =
            {
                .fn        = {x_mod_on_each_tap, x_mod_finished, x_mod_reset, x_mod_on_each_release},
                .user_data = &(tap_dance_config_t){.keycode = CK_C__E, .hold_mods = MOD_BIT(KC_LSFT), .retro_enabled = false},
            },
        [TD_NAV_HOME_CTL] =
            {
                .fn        = {x_mod_on_each_tap, x_mod_finished, x_mod_reset, x_mod_on_each_release},
                .user_data = &(tap_dance_config_t){.keycode = CK_C__F, .hold_mods = MOD_BIT(KC_LCTL), .retro_enabled = false},
            },
        [TD_NAV_HOME_ALT] =
            {
                .fn        = {x_mod_on_each_tap, x_mod_finished, x_mod_reset, x_mod_on_each_release},
                .user_data = &(tap_dance_config_t){.keycode = CK____Q, .hold_mods = MOD_BIT(KC_LALT), .retro_enabled = false},
            },
        [TD_NAV_HOME_GUI] =
            {
                .fn        = {x_mod_on_each_tap, x_mod_finished, x_mod_reset, x_mod_on_each_release},
                .user_data = &(tap_dance_config_t){.keycode = KC_NO, .hold_mods = MOD_BIT(KC_LGUI), .retro_enabled = false},
            },
};
