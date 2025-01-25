#pragma once

#include "quantum.h"

// Tap Dance States
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_SUSPENDED,
} td_state_t;

typedef struct {
    uint16_t keycode;
    uint16_t dt_keycode;  // Optional double-tap keycode
    bool has_dt_keycode;  // Flag to check if dt_keycode is set
    uint16_t dt_layer;    // Optional double-tap keycode
    bool has_dt_layer;    // Flag to check if dt_keycode is set
} tap_dance_config_t;


typedef struct {
    td_state_t state;
    uint16_t suspend_time;
    bool cw_mode_active;
} td_tap_t;

td_state_t evaluate_tap_dance_state(tap_dance_state_t *state);

bool was_keycode_handled(uint16_t keycode);
void reset_handled_keycode(void);
void post_tap_dance_shift_task(void);

// Shift Tap Dances
void x_shift_on_each_tap(tap_dance_state_t *state, void *user_data);
void x_shift_on_each_release(tap_dance_state_t *state, void *user_data);
void x_shift_on_timeout(tap_dance_state_t *state, void *user_data);
void x_shift_finished(tap_dance_state_t *state, void *user_data);
void x_shift_reset(tap_dance_state_t *state, void *user_data);


// Layer Tap Dances
void x_layer_finished(tap_dance_state_t *state, void *user_data, uint16_t keycode, uint16_t layer, uint16_t dt_layer);
void x_layer_reset(tap_dance_state_t *state, void *user_data, uint16_t layer, uint16_t dt_layer);
