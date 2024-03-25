#include "leader.h"
#include "keycode.h"


#ifndef LEADER_ESC_KEY
#define LEADER_ESC_KEY KC_ESC
#endif

static bool leading = false;
static leader_func_t leader_func = NULL;


// The entry point for leader sequenc functions
__attribute__ ((weak))
void *leader_start_func(uint16_t keycode) {
    return NULL;
}

// Check to see if we are leading
bool is_leading(void) {
    return leading;
}
// Start leader sequence
void start_leading(void) {
    leading = true;
    leader_func = leader_start_func;
}
// Stop leader sequence
void stop_leading(void) {
    leading = false;
    leader_func = NULL;
}

// Process keycode for leader sequences
bool process_leader(uint16_t keycode, const keyrecord_t *record) {
    if (leading && record->event.pressed) {
        // Get the base keycode of a mod or layer tap key
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0)
                    return true;
                keycode = keycode & 0xFF;
                break;
            default:
                break;
        }

        // let through anything above that's normal keyboard keycode or a mod
        if (keycode > QK_MODS_MAX || KEYCODE_IS_MOD(keycode)) {
            return true;
        }
        // early exit if the esc key was hit
        if (keycode == LEADER_ESC_KEY) {
            stop_leading();
            return false;
        }

        // update the leader function
        leader_func = leader_func(keycode);
        if (leader_func == NULL) {
            stop_leading();
        }
        return false;
    }
    return true;
}