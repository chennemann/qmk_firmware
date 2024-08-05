#include "modifiers.h"
#include QMK_KEYBOARD_H

#include "keymap_ckey.h"

// Index from 0
#define INDEX(keycode) (keycode - CK_CIRC)

const uint8_t DEAD_KEYS[] PROGMEM = {
    [INDEX(CK_CIRC)] = KC_SPC,
    [INDEX(CK_ACRC)] = KC_A,
    [INDEX(CK_ECRC)] = KC_E,
    [INDEX(CK_ICRC)] = KC_I,
    [INDEX(CK_OCRC)] = KC_O,
    [INDEX(CK_UCRC)] = KC_U,
    
    [INDEX(CK__GRV)] = KC_SPC, 
    [INDEX(CK_AGRV)] = KC_A, 
    [INDEX(CK_EGRV)] = KC_E, 
    [INDEX(CK_IGRV)] = KC_I, 
    [INDEX(CK_OGRV)] = KC_O, 
    [INDEX(CK_UGRV)] = KC_U, 

    [INDEX(CK_ACUT)] = KC_SPC,
    [INDEX(CK_AACU)] = KC_A, 
    [INDEX(CK_EACU)] = KC_E, 
    [INDEX(CK_IACU)] = KC_I, 
    [INDEX(CK_OACU)] = KC_O, 
    [INDEX(CK_UACU)] = KC_U, 
};

void handle_deadkey(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed) {
        // Return early on Release
        return;
    }

    uint8_t next_keycode = pgm_read_byte(&DEAD_KEYS[INDEX(keycode)]);
    
    // Get current mod and one-shot mod states.
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    const bool shift_active = (mods | oneshot_mods) & MOD_MASK_SHIFT;
    // Temporarily delete shift.
    del_oneshot_mods(MOD_MASK_SHIFT);
    unregister_mods(MOD_MASK_SHIFT);  
    
    switch (keycode) {
        case CK_CIRC...CK_UCRC:
            tap_code(___CIRC);
            break;
        case CK__GRV...CK_UGRV:
            tap_code16(___GRV);
            break;
        case CK_ACUT...CK_UACU:
            tap_code(___ACUT);
            break;
    }
    
    if(shift_active) {
        set_oneshot_mods(MOD_LSFT);
    }
    tap_code(next_keycode);


    // Restore mods.
    register_mods(mods);            
/*

//    if (!record->event.pressed) {
//        unregister_code(next_keycode);
//        return false;
//    }

    // Prevent mods from being applied to the deadkey
    uint8_t mod_state = get_mods();
    del_mods(MOD_MASK_CSAG);
    switch (keycode) {
        case CK_CIRC...CK_UCRC:
            tap_code(next_keycode);
            //tap_code(next_keycode);
            break;
        case CK_GRV:
            //SEND_STRING("`");
            break;
        case CK_ACUT:
            //SEND_STRING("´");
            break;
        default:
            return false;
    }
    set_mods(mod_state);

#ifdef CAPS_WORD_ENABLE
    // Not sure why, but caps word will not catch these keys,
    // so we need to apply it manually
    if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
#endif

if (false) {
    register_code(next_keycode);
}

*/
}

/*
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
*/

bool handle_deadkey_diacritic(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_CIRC...CK_UACU:
            handle_deadkey(keycode, record);
            return true;
        default:
            return false;
    }
}