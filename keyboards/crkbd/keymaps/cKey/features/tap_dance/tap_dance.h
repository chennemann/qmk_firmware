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
    TD_TRIPLE_HOLD
} td_state_t;


typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t evaluate_tap_dance_state(tap_dance_state_t *state);



// Shift Tap Dances
void x_shift_finished(tap_dance_state_t *state, void *user_data, uint16_t keycode);
void x_shift_reset(tap_dance_state_t *state, void *user_data);


// Layer Tap Dances
void x_layer_finished(tap_dance_state_t *state, void *user_data, uint16_t keycode, uint16_t layer);
void x_layer_reset(tap_dance_state_t *state, void *user_data, uint16_t layer);