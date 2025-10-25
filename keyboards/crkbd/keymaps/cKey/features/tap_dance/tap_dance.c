#include "tap_dance.h"
#include "../../keymap_extras/keymap_ckey.h"


td_state_t evaluate_tap_dance_state(tap_dance_state_t *state) {    
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else {
        return TD_UNKNOWN;
    }
}


// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t x_tap_state = {
    .state = TD_NONE,
    .enforce_shift = false,
    .suspend_time = 0,
    .cw_mode_active = false,
};



/*
        SHIFT TAP DANCES
*/
void x_shift_on_each_tap(tap_dance_state_t *state, void *user_data) {
    
    if (x_tap_state.cw_mode_active) {
        x_tap_state.state = TD_SINGLE_TAP;
        state->finished = true;
        reset_tap_dance(state);
    }
    
    if (timer_elapsed(x_tap_state.suspend_time) < 500) {
        x_tap_state.state = TD_SINGLE_TAP;
        // Reset timer
        x_tap_state.suspend_time = timer_read();
        state->finished = true;
        reset_tap_dance(state);
    }
}

void x_shift_on_each_release(tap_dance_state_t *state, void *user_data) {
    if (state->count > 3) {
        x_tap_state.state = TD_SINGLE_TAP;
        // Reset timer
        x_tap_state.suspend_time = timer_read();
        state->finished = true;
        reset_tap_dance(state);
    }
}

void x_shift_finished(tap_dance_state_t *state, void *user_data) {

    if (state->count == 1 && state->interrupted) {
        x_tap_state.state = TD_SINGLE_TAP;
        x_tap_state.enforce_shift = true;
        reset_tap_dance(state);
    }

    x_tap_state.state = evaluate_tap_dance_state(state);
    tap_dance_config_t *config = (tap_dance_config_t *)user_data;

    switch (x_tap_state.state) {
        case TD_SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case TD_DOUBLE_HOLD:
            if (config->has_dt_layer) {
                layer_on(config->dt_layer);
            }
            break;
        default:
            break;
    }
}

void x_shift_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_config_t *config = (tap_dance_config_t *)user_data;

    switch (x_tap_state.state) {
        case TD_SINGLE_TAP:
            if (x_tap_state.cw_mode_active) {
                tap_code16(KC_NO);
                x_tap_state.cw_mode_active = false;
            } else if (x_tap_state.enforce_shift) {
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            } else {
                tap_code16(config->keycode);
            }
            break;
        case TD_DOUBLE_TAP:
            if (config->has_dt_keycode) {
                uint16_t keycode = config->dt_keycode;
                switch (keycode) {
                    case CW_CAPS:
                        x_tap_state.cw_mode_active = true;
                        toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
                        break;
                    default:
                        tap_code16(keycode);
                        break;
                }
            }
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        case TD_DOUBLE_HOLD:
            if (config->has_dt_layer) {
                layer_off(config->dt_layer);
            }
            break;
        case TD_SUSPENDED:
            tap_code16(config->keycode);
            break;
        default:
            break;
    }
    
    // Reset tap dance state
    x_tap_state.state = TD_NONE;
    x_tap_state.enforce_shift = false;
}








/*
        LAYER TAP DANCES
*/

void x_layer_finished(tap_dance_state_t *state, void *user_data, uint16_t keycode, uint16_t layer, uint16_t dt_layer) {
    x_tap_state.state = evaluate_tap_dance_state(state);
    switch (x_tap_state.state) {
        case TD_SINGLE_HOLD:
            layer_on(layer);
            break;
        case TD_DOUBLE_HOLD:
            layer_on(dt_layer);
            break;
        default:
            tap_code16(keycode);
            break;
    }
}

void x_layer_reset(tap_dance_state_t *state, void *user_data, uint16_t layer, uint16_t dt_layer) {
    switch (x_tap_state.state) {
        case TD_DOUBLE_HOLD:
            layer_off(dt_layer);
            break;
        default:
            layer_off(layer);
            break;
    }
    x_tap_state.state = TD_NONE;
}
