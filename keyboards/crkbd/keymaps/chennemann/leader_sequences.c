#include "leader.h"
#include "keymap.h"
#include "caps_word.h"

void *leader_caps_func(uint16_t keycode) {
    switch (keycode) {
        case KC_W:
            toggle_caps_word_mode(CWMODE_NORMAL);
            return NULL;
        case KC_K:  // K "for" "K"ONSTANT_CASE
            toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
            return NULL;
        case KC_MINS:  // kebab-case
            toggle_caps_word_space_sub(KC_MINS);
            return NULL;
        case KC_U:  // U for underscore ... snake_case
            toggle_caps_word_space_sub(KC_UNDERSCORE);
            return NULL;
        case KC_C:  // C for camelCase
            toggle_caps_word_mode(CWMODE_CAMEL_CASE);
            return NULL;
        case KC_SLASH:  // slash/case (ex. path/to/file)
            toggle_caps_word_space_sub(KC_SLASH);
            return NULL;
    }
    return NULL;
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_W:
            return leader_caps_func;
    }
    return NULL;
}