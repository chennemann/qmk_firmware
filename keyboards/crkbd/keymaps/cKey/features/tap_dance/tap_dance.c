#include "tap_dance.h"

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
    .is_press_action = true,
    .state = TD_NONE
};



/*
        SHIFT TAP DANCES
*/

void x_shift_finished(tap_dance_state_t *state, void *user_data, uint16_t keycode) {
    x_tap_state.state = evaluate_tap_dance_state(state);
    switch (x_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(keycode);
            break;
        case TD_SINGLE_HOLD: 
            register_code(KC_LSFT); 
            break;
        case TD_DOUBLE_TAP:  
            //toggle_caps_word_mode(CWMODE_CONSTANT_CASE); 
            break;
        case TD_DOUBLE_HOLD: 
            //layer_on(_CAPS_LOCK); 
            break;
        default: 
            break;
    }
}

void x_shift_reset(tap_dance_state_t *state, void *user_data) {
    switch (x_tap_state.state) {
        case TD_SINGLE_HOLD:        
            unregister_code(KC_LSFT);   
            break;
        case TD_DOUBLE_HOLD:       
            //layer_off(_CAPS_LOCK);     
            break;
        default:                                                
            break;
    }
    x_tap_state.state = TD_NONE;
}








/*
        LAYER TAP DANCES
*/

void x_layer_finished(tap_dance_state_t *state, void *user_data, uint16_t keycode, uint16_t layer) {
    x_tap_state.state = evaluate_tap_dance_state(state);
    switch (x_tap_state.state) {
        case TD_SINGLE_HOLD: 
            layer_on(layer); 
            break;
        default: 
            tap_code16(keycode);
            break;
    }
}

void x_layer_reset(tap_dance_state_t *state, void *user_data, uint16_t layer) {
    switch (x_tap_state.state) {
        default:          
            layer_off(layer);                                            
            break;
    }
    x_tap_state.state = TD_NONE;
}
