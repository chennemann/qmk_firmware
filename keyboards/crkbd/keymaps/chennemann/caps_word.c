// Heavily inspired by Ga68 (https://www.reddit.com/r/olkb/comments/y07cb8/new_multimode_use_for_caps_word/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button)
// https://github.com/Ga68/qmk_firmware/blob/my_layout/keyboards/sofle/keymaps/Ga68/caps_word.c

#include "keymap.h"
#include "caps_word.h"

caps_word_mode_t g_caps_word_mode = CAPS_WORD_MODE_DEFAULT;
bool g_caps_word_last_key_was_space = false;
uint16_t g_caps_word_space_substitute = CAPS_WORD_SPACE_SUB_DEFAULT;

bool caps_word_press_user(uint16_t keycode, bool *interrupted) {

    if (keycode == KC_NO) {
        return true;
    }

    if (keycode == KC_ESC) {
        // Prematurely exit the mode while preventing any unwanted keystrokes
        tap_code16(KC_NO);
        return false;
    }

    if (keycode == KC_SPC) {
        if (!g_caps_word_last_key_was_space) {

            switch (g_caps_word_mode) {
                case CWMODE_NUM_LOCK:
                    layer_off(NUM);
                    break;
                case CWMODE_CONSTANT_CASE:
                    tap_code16(CK_UNDS);
                    *interrupted = true;
                    break;
                case CWMODE_CAMEL_CASE:
                    add_oneshot_mods(MOD_LSFT);
                    *interrupted = true;
                    break;
                case CWMODE_SPACE_SUB:
                    tap_code16(g_caps_word_space_substitute);
                    *interrupted = true;
                default:
                    break;
            }

            g_caps_word_last_key_was_space = true;
            return true;
        } else {
            // if this is the second space in a row, delete one and exit Caps Word
            tap_code16(KC_BACKSPACE);
            return false;
        }
    }

    if (g_caps_word_last_key_was_space) {
        if (keycode == KC_BSPC) {
            // if a Backspace is registered after we pressed space
            // we delete the added space and resume the Caps_Word_Mode
            if (g_caps_word_mode == CWMODE_NUM_LOCK) {
                layer_on(NUM);
            }
            g_caps_word_last_key_was_space = false;
            return true;
        }

        switch(g_caps_word_mode) {
            case CWMODE_NORMAL:
            case CWMODE_NUM_LOCK:
                return false;  // Deactivate Caps Word.
            default:
                break;
        }
    }

    switch(g_caps_word_mode) {
        case CWMODE_NORMAL:
            switch (keycode) {
                // Keycodes that continue Caps Word, with shift applied.
                case CK_A ... CK_Z:
                    add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
                    return true;

                // Keycodes that continue Caps Word, without shifting.
                case CK_1 ... CK_0:
                case KC_BSPC:
                case CK_MINS:
                case CK_UNDS:
                    return true;
                default:
                    return false;  // Deactivate Caps Word.
            }
        case CWMODE_NUM_LOCK:
            switch (keycode) {
                // Keycodes that continue Num Lock.
                case CK_1 ... CK_0:
                case CK_DOT:
                case CK_COMM:
                case CK_PLUS:
                case CK_MINS:
                case CK_SLSH:
                case CK_ASTR:
                case KC_BSPC:
                    return true;
                default:
                    return false;  // Deactivate Caps Word.
            }
        case CWMODE_ARROW_SHIFT:
            switch (keycode) {
                // Keycodes that continue Caps Word, without shifting.
                case KC_LEFT:
                case KC_RIGHT:
                case KC_UP:
                case KC_DOWN:
                case A(KC_LEFT):
                case A(KC_RIGHT):
                case A(KC_UP):
                case A(KC_DOWN):
                case G(KC_LEFT):
                case G(KC_RIGHT):
                case G(KC_UP):
                case G(KC_DOWN):
                    add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
                    return true;

                default:
                    return false;  // Deactivate Caps Word.
            }
        case CWMODE_CONSTANT_CASE:
        case CWMODE_CAMEL_CASE:
        case CWMODE_SPACE_SUB:
            switch (keycode) {
                case KC_SPACE:
                // Keys that do NOT break the Caps Word state
                case CK_A ... CK_Z:
                case CK_1 ... CK_0:
                case KC_BACKSPACE:
                    // If we're continuing on after a space, then we need to resume the handling normally
                    if (g_caps_word_last_key_was_space) {
                        g_caps_word_last_key_was_space = false;
                    }
                    // If we're in CONSTANT_CASE, then we need to upper case letters
                    if (
                        g_caps_word_mode == CWMODE_CONSTANT_CASE
                        && (CK_A <= keycode && keycode <= CK_Z)
                    ) {
                        add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
                    }
                    return true;

                default:
                    return false;  // Deactivate Caps Word
            }

        default:
            return false;
    }
}

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        g_caps_word_last_key_was_space = false;
    } else {
        // Do something when Caps Word deactivates.
        // If leaving the num_lock mode, then we need to exit that layer
        if (g_caps_word_mode == CWMODE_NUM_LOCK) {
            layer_off(NUM);  // leave the numbers layer
        }
        // Go back to make sure that when it turns on next without any sepcification (ex. through
        // the CAPS_WORD key), it's in the default caps_word mode
        g_caps_word_mode = CAPS_WORD_MODE_DEFAULT;
        g_caps_word_space_substitute = CAPS_WORD_SPACE_SUB_DEFAULT;
    }
}

// Toggles caps word for the given mode. If that mode is already on, then it's getting turned off.
// If it's a new mode (or caps word isn't on at all), the old one will cycle off, then the new
// one will turn on. Returns true if caps word (in any mode) is on after the call.
bool toggle_caps_word_mode(caps_word_mode_t new_mode) {
    // remember the old settings before we turn it off since that will clear these values
    bool caps_word_was_off = !is_caps_word_on();
    caps_word_mode_t prior_mode = g_caps_word_mode;
    // want to cycle it off, regardless of whether we're going to turn something else on, so that
    // any "wrap up code" (ex. function caps_word_set_user) can execute between the change.
    caps_word_off();
    // if it wasn't on (and thus we're toggling it on) or we're going into a new mode
    if (caps_word_was_off || prior_mode != new_mode) {
        caps_word_on();
        g_caps_word_mode = new_mode;
        // if we're going into num_lock, then switch into the numbers layer
        if (g_caps_word_mode == CWMODE_NUM_LOCK) {
            layer_on(NUM);
        }
    }
    return is_caps_word_on();
}

// Sets up caps word where every space is substituted with the provided key code. This can be used
// for kebab-case (dash/hyphen), snake_case (underscore), or others.
bool toggle_caps_word_space_sub(uint16_t sub_keycode) {
    g_caps_word_space_substitute = sub_keycode;
    return toggle_caps_word_mode(CWMODE_SPACE_SUB);
}