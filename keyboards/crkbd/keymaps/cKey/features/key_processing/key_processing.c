#include "../../keymap_extras/keymap_ckey.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_cross_layer_hrm(keycode, record) || !process_td_user(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case CK_LSEL:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LSFT));
                process_record_user(CK_SELW, record);
                unregister_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case CK_BSEL:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LSFT));
                process_record_user(CK_SELB, record);
                unregister_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case CW_CAPS:
            if (!record->event.pressed) {
                toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
            }
            return false;
        case CW_CAML:
            if (!record->event.pressed) {
                toggle_caps_word_mode(CWMODE_CAMEL_CASE);
            }
            return false;
        case CW_KEBA:
            if (!record->event.pressed) {
                toggle_caps_word_space_sub(CK_MINS);
            }
            return false;
        case CW_SNAK:
            if (!record->event.pressed) {
                toggle_caps_word_space_sub(CK_UNDS);
            }
            return false;
        case CW_SLSH:
            if (!record->event.pressed) {
                toggle_caps_word_space_sub(CK_SLSH);
            }
            return false;
        case CW_BSLS:
            if (!record->event.pressed) {
                toggle_caps_word_space_sub(CK_BSLS);
            }
            return false;
    }

    if (!process_select_word(keycode, record, CK_SELW, CK_SELB)) {
        return false;
    }
    if (handle_diacritic_keycode(keycode, record)) {
        return false;
    }
    return true;
}

void matrix_scan_user(void) {
    tap_dance_cleanup_task();
    select_word_task();
}
