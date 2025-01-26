#include "tap_dance.h"
#include "../../keymap_extras/keymap_ckey.h"
#include "../caps_word/caps_word.h"

#include "print.h"




// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t x_tap_state = {
    .state = TD_NONE,
    .suspend_time = 0,
    .cw_mode_active = false,
};

static bool retroactive_shift_consumed = false;
static uint16_t delayed_key_timer = 0;
static uint16_t delayed_key = 0;

bool retroactive_shift_enabled(void) {
    bool enabled = delayed_key != 0;
    if (enabled) {
        retroactive_shift_consumed = true;
    }
    return enabled;
}

void reset_retroactive_shift(void) {
    print("62: DELAYED Key: OFF\n");
    delayed_key = 0;
    retroactive_shift_consumed = false;
}

/*
static uint16_t post_tap_dance_shift_idle_timer = 0;
*/
static uint16_t handled_mt_keycode = 0;

bool was_mt_handled(uint16_t keycode) {
    return handled_mt_keycode == keycode;
}

void reset_mt_handling(void) {
    handled_mt_keycode = 0;
}

void tap_dance_cleanup_task(void) {    
    if (delayed_key && !retroactive_shift_consumed) {
        if (timer_elapsed(delayed_key_timer) > 100 && delayed_key) {
            print("61: DELAYED Key: OFF\n");
            tap_code16(delayed_key);
            delayed_key = 0;
        }
    }
}



td_state_t evaluate_tap_dance_state(tap_dance_state_t *state) {    
    if (state->count == 1) {
        if (!state->pressed && !state->interrupted) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed && !state->interrupted) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    } else if (state->count == 3) {
        if (!state->pressed && !state->interrupted) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else {
        return TD_UNKNOWN;
    }
}




bool is_any_key_pressed(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        if (matrix_get_row(row) != 0) {
            return true; // At least one key is pressed in the keymap
        }
    }
    return false; // No keys are pressed in the keymap
}


/*
        SHIFT TAP DANCES
*/
void x_shift_on_each_tap(tap_dance_state_t *state, void *user_data) {

    
    if (state->count == 1) {
        
        print("\n\n");
        
        for (uint8_t row = 0; row < 3; row++) {
            if (matrix_get_row(row)) {
                print("03: Cancel Key Repeat\n");
                tap_code16(KC_ESC);
                reset_tap_dance(state);
                return;
            }
        }
    }
    
    if (x_tap_state.cw_mode_active || g_caps_word_mode != CWMODE_NORMAL) {
        x_tap_state.state = TD_NONE;
        tap_code16(KC_NO);
        x_tap_state.cw_mode_active = false;
   
        print("00: Caps Word Mode: OFF\n");
        
        reset_tap_dance(state);
        return;
    }
    
    if (timer_elapsed(x_tap_state.suspend_time) < 500) {
        x_tap_state.state = TD_SINGLE_TAP;
        // Reset timer
        x_tap_state.suspend_time = timer_read();
        
        print("01: Extend Suspension Timer\n");

        reset_tap_dance(state);
        return;
    }
    
    print("02: Default Tap\n");
}

void x_shift_on_each_release(tap_dance_state_t *state, void *user_data) {  
    
    if (state->count > 3) {
        x_tap_state.state = TD_SINGLE_TAP;
        // Reset timer
        x_tap_state.suspend_time = timer_read();
        
        print("10: Suspend Tap Dance\n");
        print("<enter>\n");
        tap_code16(KC_ENT);
        reset_tap_dance(state);
    }
    
    print("11: Default Release\n");
}

void x_shift_on_timeout(tap_dance_state_t *state, void *user_data) {
    print("40: Default Timeout\n");
}

void x_shift_finished(tap_dance_state_t *state, void *user_data) {

    x_tap_state.state = evaluate_tap_dance_state(state);

    switch (x_tap_state.state) {
        case TD_SINGLE_HOLD:  
            print("20: Single Hold: ON\n");
            register_code(KC_LSFT);
            
            uint16_t mt_keycode = state->interrupting_keycode;
            switch (mt_keycode) {
                case HOME_CA ... HOME_CZ: 
                case HOME_SA ... HOME_SZ: 
                case HOME_AA ... HOME_AZ: 
                case HOME_GA ... HOME_GZ: 
                    print("23: Special Home Row Mod Handling\n");
                    uint16_t tap_code = QK_MOD_TAP_GET_TAP_KEYCODE(mt_keycode);
                    tap_code16(tap_code);
                    handled_mt_keycode = mt_keycode;
                    break;
            }
            
            break;
        case TD_DOUBLE_HOLD:
            print("21: Double Hold: ON\n");
            tap_dance_config_t *config = (tap_dance_config_t *)user_data;
            if (config->has_dt_layer) {
                layer_on(config->dt_layer);
            }
            break;
        default:
            print("22: Default Finished\n");
            break;
    }
}

void x_shift_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_config_t *config = (tap_dance_config_t *)user_data;

    switch (x_tap_state.state) {
        case TD_SINGLE_TAP:
                print("31: DELAYED Key: ON\n");
                delayed_key = config->keycode;
                delayed_key_timer = timer_read();
                /*
                print("31: Single Tap\n");
                print("<enter>\n");
                tap_code16(config->keycode);
                */
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSFT);
            print("32: Single Hold: OFF\n");
            break;
        case TD_DOUBLE_TAP:
            if (config->has_dt_keycode) {
                uint16_t keycode = config->dt_keycode;
                switch (keycode) {
                    case CW_CAPS:
                        x_tap_state.cw_mode_active = true;
                        toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
                        print("33: Caps Word Mode: ON\n");
                        break;
                    default:
                        print("34: UNKNOWN DT_KEYCODE\n");
                        break;
                }
            } else {
                print("35: Double Tap: IGNORED\n");          
            }
            break;
        case TD_DOUBLE_HOLD:
            if (config->has_dt_layer) {
                layer_off(config->dt_layer);
                print("36: Double Hold: OFF\n");
            } else {
                print("37: Double Hold: IGNORED\n");           
            }
            break;
        case TD_SUSPENDED:
            print("38: Suspend Tap Dance\n"); 
            print("<enter>\n");
            tap_code16(config->keycode);
            break;
        default:
            print("39: Default Reset\n"); 
            break;
    }
    
    // Reset tap dance state
    x_tap_state.state = TD_NONE;
    
    print("30: Tap Dance Reset\n"); 
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
