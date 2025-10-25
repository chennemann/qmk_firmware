#include "modifiers.h"
#include QMK_KEYBOARD_H

#include "keymap_ckey.h"

// Index from 0
#define INDEX(keycode) (keycode - CK_CIRC)

const uint8_t DEAD_KEYS[] PROGMEM = {
    [INDEX(CK_CIRC)] = KC_SPC,  // <space>
    [INDEX(CK_GRV)] = KC_SPC,   // <space>
    [INDEX(CK_ACUT)] = KC_SPC,  // <space>
};

bool handle_deadkey(uint16_t keycode, keyrecord_t *record) {
    uint8_t next_keycode = pgm_read_byte(&DEAD_KEYS[INDEX(keycode)]);

    if (!record->event.pressed) {
        unregister_code(next_keycode);
        return false;
    }

    // Prevent mods from being applied to the deadkey
    uint8_t mod_state = get_mods();
    del_mods(MOD_MASK_CSAG);
    switch (keycode) {
        case CK_CIRC:
            SEND_STRING("^");
            break;
        case CK_GRV:
            SEND_STRING("`");
            break;
        case CK_ACUT:
            SEND_STRING("´");
            break;
    }
    set_mods(mod_state);

#ifdef CAPS_WORD_ENABLE
    // Not sure why, but caps word will not catch these keys,
    // so we need to apply it manually
    if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
#endif

    register_code(next_keycode);

    return false;
}

bool handle_modtap(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count == 0) {
        // Do not override hold function
        return true;
    }

    if (!record->event.pressed) {
        unregister_code16(keycode);
        return false;
    }

#ifdef CAPS_WORD_ENABLE
    if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
#endif

    register_code16(keycode);

    return false;
}

bool handle_modtap_deadkey(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count == 0) {
        // Do not override hold function
        return true;
    }
    return handle_deadkey(keycode, record);
}

bool handle_deadkey_diacritic(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_CIRC:
        case CK_GRV:
        case CK_ACUT:
            return handle_deadkey(keycode, record);
        default:
            return true;
    }
}