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
    td_state_t state;
    bool is_pressed;
    bool hold_registered;
    uint16_t suspend_time;
    bool cw_mode_active;
} tap_dance_runtime_t;

typedef struct {
    uint16_t keycode;
    uint8_t hold_mods;
    bool retro_enabled;
    uint16_t dt_keycode;  // Optional double-tap keycode
    bool has_dt_keycode;  // Flag to check if dt_keycode is set
    uint16_t dt_layer;    // Optional double-tap keycode
    bool has_dt_layer;    // Flag to check if dt_keycode is set
    tap_dance_runtime_t runtime;
} tap_dance_config_t;

td_state_t evaluate_tap_dance_state(tap_dance_state_t *state);

uint8_t get_active_tap_dance_mods(void);

// Special Letter Handling to allow for retroactive modding of a key
// This is useful for fast typing
bool is_retroactive_mod_enabled(void);
void enable_retroactive_mod(uint8_t mods, uint16_t *keycode);
void consume_retroactive_mod(void);
void reset_retroactive_mod(void);

void tap_code16_with_mods(uint16_t keycode, uint8_t mods);
bool process_td_user(uint16_t keycode, keyrecord_t *record);

// Matrix Scan Task to allow for post tap dance cleanups
// This is useful for use-cases such as retroactively turning a SINGLE_TAP into a SINGLE_HOLD
void tap_dance_cleanup_task(void);

// Mod Tap Dances
void x_mod_on_each_tap(tap_dance_state_t *state, void *user_data);
void x_mod_on_each_release(tap_dance_state_t *state, void *user_data);
void x_mod_finished(tap_dance_state_t *state, void *user_data);
void x_mod_reset(tap_dance_state_t *state, void *user_data);


// Layer Tap Dances
void x_layer_finished(tap_dance_state_t *state, void *user_data, uint16_t keycode, uint16_t layer, uint16_t dt_layer);
void x_layer_reset(tap_dance_state_t *state, void *user_data, uint16_t layer, uint16_t dt_layer);
