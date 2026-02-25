#include "tap_dance.h"
#include "../../keymap_extras/keymap_ckey.h"
#include "../caps_word/caps_word.h"

#include "print.h"

// Shared state for layer tap dances.
static tap_dance_runtime_t layer_tap_state = {
    .state          = TD_NONE,
    .suspend_time   = 0,
    .cw_mode_active = false,
    .is_pressed     = false,
    .hold_registered = false,
};

// Tap Dance Mod state
static uint8_t active_hold_mods       = 0;
static uint8_t active_hold_mod_counts[8] = {0};

// Retroactive Mod state
static bool     retroactive_mod_enabled  = false;
static bool     retroactive_mod_consumed = false;
static uint8_t  retroactive_mods         = 0;
static uint16_t retroactive_mod_timer    = 0;
static uint16_t delayed_key              = 0;

void tap_dance_cleanup_task(void) {
    if (retroactive_mod_enabled) {
        if (timer_elapsed(retroactive_mod_timer) > TAPPING_TERM) {
            if (delayed_key && !retroactive_mod_consumed) {
                print("64: RETROACTIVE MOD: Handle Delayed Key\n");
                tap_code16(delayed_key);
                delayed_key = 0;
            }

            printf("65: RETROACTIVE MOD: Reset %d\n", timer_read());
            reset_retroactive_mod();
        }
    }
}

void enable_retroactive_mod(uint8_t mods, uint16_t *keycode) {
    printf("60: RETROACTIVE MOD: ON %d\n", timer_read());
    retroactive_mod_enabled  = true;
    retroactive_mod_consumed = false;
    retroactive_mods         = mods;
    retroactive_mod_timer    = timer_read();
    delayed_key              = 0;

    if (keycode != NULL) {
        print("61: RETROACTIVE MOD: Register Delayed Key\n");
        delayed_key = *keycode;
    }
}

bool is_retroactive_mod_enabled(void) {
    return retroactive_mod_enabled && !retroactive_mod_consumed;
}

void consume_retroactive_mod(void) {
    print("62: RETROACTIVE MOD: CONSUMED\n");
    retroactive_mod_consumed = true;
    if (delayed_key) {
        delayed_key = 0;
    }
    reset_retroactive_mod();
}

void reset_retroactive_mod(void) {
    printf("63: RETROACTIVE MOD: OFF at %d\n", timer_read());
    delayed_key              = 0;
    retroactive_mods         = 0;
    retroactive_mod_consumed = false;
    retroactive_mod_enabled  = false;
}

static void register_hold_mods(uint8_t mods) {
    for (uint8_t i = 0; i < 8; i++) {
        uint8_t mod = 1 << i;
        if (mods & mod) {
            if (active_hold_mod_counts[i] == 0) {
                register_mods(mod);
                active_hold_mods |= mod;
            }
            active_hold_mod_counts[i]++;
        }
    }
}

static void unregister_hold_mods(uint8_t mods) {
    for (uint8_t i = 0; i < 8; i++) {
        uint8_t mod = 1 << i;
        if (!(mods & mod) || active_hold_mod_counts[i] == 0) {
            continue;
        }

        active_hold_mod_counts[i]--;
        if (active_hold_mod_counts[i] == 0) {
            unregister_mods(mod);
            active_hold_mods &= ~mod;
        }
    }
}

void tap_code16_with_mods(uint16_t keycode, uint8_t mods) {
    uint8_t active_mods = get_mods();

    register_mods(mods);
    tap_code16(keycode);
    set_mods(active_mods);
    send_keyboard_report();
}

static bool is_retroactive_target_key(uint16_t keycode) {
    switch (keycode) {
        case HOME_CA ... HOME_CZ:
        case HOME_SA ... HOME_SZ:
        case HOME_AA ... HOME_AZ:
        case HOME_GA ... HOME_GZ:
        case HOME_C1 ... HOME_C0:
        case HOME_S1 ... HOME_S0:
        case HOME_A1 ... HOME_A0:
        case HOME_G1 ... HOME_G0:
        case CK____A ... CK____Z:
            return true;
        default:
            return false;
    }
}

bool process_td_user(uint16_t keycode, keyrecord_t *record) {
    if (is_retroactive_mod_enabled() && record->event.pressed && !is_retroactive_target_key(keycode)) {
        reset_retroactive_mod();
    }

    switch (keycode) {
        case HOME_CA ... HOME_CZ:
        case HOME_SA ... HOME_SZ:
        case HOME_AA ... HOME_AZ:
        case HOME_GA ... HOME_GZ:
        case HOME_C1 ... HOME_C0:
        case HOME_S1 ... HOME_S0:
        case HOME_A1 ... HOME_A0:
        case HOME_G1 ... HOME_G0:
            printf("mod tap key pressed at %d\n", timer_read());
            if (is_retroactive_mod_enabled()) {
                if (record->event.pressed) {
                    tap_code16_with_mods(QK_MOD_TAP_GET_TAP_KEYCODE(keycode), get_active_tap_dance_mods());
                    consume_retroactive_mod();
                } else {
                    reset_retroactive_mod();
                }
                return false;
            }

            if (get_active_tap_dance_mods()) {
                if (record->event.pressed) {
                    tap_code16_with_mods(QK_MOD_TAP_GET_TAP_KEYCODE(keycode), get_active_tap_dance_mods());
                }
                return false;
            }

            return true;
        case CK____A ... CK____Z:
            printf("other key pressed at %d\n", timer_read());
            if (is_retroactive_mod_enabled()) {
                if (record->event.pressed) {
                    tap_code16_with_mods(keycode, get_active_tap_dance_mods());
                    consume_retroactive_mod();
                } else {
                    reset_retroactive_mod();
                    unregister_code(keycode);
                }
                return false;
            }
            break;
    }

    return true;
}

uint8_t get_active_tap_dance_mods(void) {
    uint8_t mods = active_hold_mods;

    if (is_retroactive_mod_enabled()) {
        mods |= retroactive_mods;
    }

    return mods;
}

td_state_t evaluate_tap_dance_state(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed || state->interrupted)
            return TD_SINGLE_HOLD;
        else
            return TD_SINGLE_TAP;
    } else if (state->count == 2) {
        if (state->pressed || state->interrupted)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->pressed || state->interrupted)
            return TD_TRIPLE_HOLD;
        else
            return TD_TRIPLE_TAP;
    } else {
        return TD_UNKNOWN;
    }
}

static td_state_t evaluate_mod_tap_dance_state(tap_dance_state_t *state, tap_dance_runtime_t *runtime) {
    if (state->count == 1) {
        return runtime->is_pressed ? TD_SINGLE_HOLD : TD_SINGLE_TAP;
    }
    if (state->count == 2) {
        return runtime->is_pressed ? TD_DOUBLE_HOLD : TD_DOUBLE_TAP;
    }
    if (state->count == 3) {
        return runtime->is_pressed ? TD_TRIPLE_HOLD : TD_TRIPLE_TAP;
    }
    return TD_UNKNOWN;
}

/*
        MOD TAP DANCES
*/
void x_mod_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_config_t  *config  = (tap_dance_config_t *)user_data;
    tap_dance_runtime_t *runtime = &config->runtime;

    runtime->is_pressed = true;

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

        if (runtime->cw_mode_active || g_caps_word_mode != CWMODE_NORMAL) {
            runtime->state          = TD_NONE;
            runtime->cw_mode_active = false;
            tap_code16(KC_NO);

            print("00: Caps Word Mode: OFF\n");

            reset_tap_dance(state);
            return;
        }

        if (timer_elapsed(runtime->suspend_time) < 500) {
            runtime->state        = TD_SINGLE_TAP;
            runtime->suspend_time = timer_read();

            print("01: Extend Suspension Timer\n");

            reset_tap_dance(state);
            return;
        }

        if (config->hold_mods && !runtime->hold_registered) {
            register_hold_mods(config->hold_mods);
            runtime->hold_registered = true;
        }
    }

    print("02: Default Tap\n");
}

void x_mod_on_each_release(tap_dance_state_t *state, void *user_data) {
    tap_dance_config_t  *config  = (tap_dance_config_t *)user_data;
    tap_dance_runtime_t *runtime = &config->runtime;

    runtime->is_pressed = false;

    if (runtime->hold_registered) {
        unregister_hold_mods(config->hold_mods);
        runtime->hold_registered = false;
    }

    if (state->count > 3) {
        runtime->state        = TD_SINGLE_TAP;
        runtime->suspend_time = timer_read();

        print("10: Suspend Tap Dance\n");
        print("<enter>\n");
        tap_code16(KC_ENT);
        reset_tap_dance(state);
    }

    print("11: Default Release\n");
}

void x_mod_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_config_t  *config  = (tap_dance_config_t *)user_data;
    tap_dance_runtime_t *runtime = &config->runtime;

    runtime->state = evaluate_mod_tap_dance_state(state, runtime);

    switch (runtime->state) {
        case TD_SINGLE_HOLD:
            print("20: Single Hold: ON\n");
            break;
        case TD_DOUBLE_HOLD:
            print("21: Double Hold: ON\n");
            if (config->has_dt_layer) {
                layer_on(config->dt_layer);
            }
            break;
        default:
            print("22: Default Finished\n");
            break;
    }
}

void x_mod_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_config_t  *config  = (tap_dance_config_t *)user_data;
    tap_dance_runtime_t *runtime = &config->runtime;

    switch (runtime->state) {
        case TD_SINGLE_TAP:
            if (runtime->hold_registered) {
                unregister_hold_mods(config->hold_mods);
                runtime->hold_registered = false;
            }

            if (config->retro_enabled && !state->interrupted) {
                enable_retroactive_mod(config->hold_mods, &config->keycode);
            } else if (!state->interrupted) {
                tap_code16(config->keycode);
            }
            break;
        case TD_SINGLE_HOLD:
            print("32: Single Hold: OFF\n");
            break;
        case TD_DOUBLE_TAP:
            if (config->has_dt_keycode) {
                uint16_t keycode = config->dt_keycode;
                switch (keycode) {
                    case CW_CAPS:
                        runtime->cw_mode_active = true;
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

    if (runtime->hold_registered) {
        unregister_hold_mods(config->hold_mods);
        runtime->hold_registered = false;
    }

    runtime->state      = TD_NONE;
    runtime->is_pressed = false;

    printf("30: Tap Dance Reset: %d\n", timer_read());
}

/*
        LAYER TAP DANCES
*/

void x_layer_finished(tap_dance_state_t *state, void *user_data, uint16_t keycode, uint16_t layer, uint16_t dt_layer) {
    layer_tap_state.state = evaluate_tap_dance_state(state);
    switch (layer_tap_state.state) {
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
    switch (layer_tap_state.state) {
        case TD_DOUBLE_HOLD:
            layer_off(dt_layer);
            break;
        default:
            layer_off(layer);
            break;
    }
    layer_tap_state.state = TD_NONE;
}
