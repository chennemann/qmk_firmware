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
    [INDEX(CK_CACU)] = KC_C,
    [INDEX(CK_EACU)] = KC_E,
    [INDEX(CK_IACU)] = KC_I,
    [INDEX(CK_LACU)] = KC_L,
    [INDEX(CK_NACU)] = KC_N,
    [INDEX(CK_OACU)] = KC_O,
    [INDEX(CK_RACU)] = KC_R,
    [INDEX(CK_SACU)] = KC_S,
    [INDEX(CK_UACU)] = KC_U,
    [INDEX(CK_YACU)] = KC_Y,
    [INDEX(CK_ZACU)] = KC_Z,

    [INDEX(CK_ABRV)] = KC_A,
    [INDEX(CK_CBRV)] = KC_C,
    [INDEX(CK_EBRV)] = KC_E,
    [INDEX(CK_NBRV)] = KC_N,
    [INDEX(CK_SBRV)] = KC_S,
    [INDEX(CK_ZBRV)] = KC_Z,

    [INDEX(CK_CCED)] = KC_C,
    [INDEX(CK_SCED)] = KC_S,
    [INDEX(CK_TCED)] = KC_T,

    [INDEX(CK_ATIL)] = KC_A,
    [INDEX(CK_NTIL)] = KC_N,
    [INDEX(CK_OTIL)] = KC_O,

    [INDEX(CK_ADEG)] = KC_A,

    [INDEX(CK_ETRM)] = KC_E,
    [INDEX(CK_ITRM)] = KC_I,
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
    del_oneshot_mods(MOD_MASK_SHIFT);
    unregister_mods(MOD_MASK_SHIFT);  
    
    switch (keycode) {
        case CK_CIRC...CK_UCRC:
            tap_code(___CIRC);
            break;
        case CK__GRV...CK_UGRV:
            tap_code16(___GRV);
            break;
        case CK_ACUT...CK_ZACU:
            tap_code(___ACUT);
            break;
        case CK_ABRV...CK_ZBRV:
            tap_code16(___BREV);
            break;
        case CK_CCED...CK_TCED:
            tap_code16(___CEDI);
            break;
        case CK_ATIL...CK_OTIL:
            tap_code16(___TILD);
            break;
        case CK_ADEG:
            tap_code16(___DEGR);
            break;
        case CK_ETRM...CK_ITRM:
            tap_code16(___TREM);
            break;
    }
    
    if(shift_active) {
        set_oneshot_mods(MOD_LSFT);
    }
    tap_code(next_keycode);


    // Restore mods.
    register_mods(mods);            
}

bool handle_deadkey_diacritic(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_CIRC...CK_ITRM:
            handle_deadkey(keycode, record);
            return true;
        default:
            return false;
    }
}