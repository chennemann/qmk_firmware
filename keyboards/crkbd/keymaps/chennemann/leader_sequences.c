#include "leader.h"
#include "keymap.h"
#include "caps_word.h"

void *leader_caps_func(uint16_t keycode) {
    switch (keycode) {
        case DE_Q:
            toggle_caps_word_mode(CWMODE_NORMAL);
            return NULL;
        case DE_W:  // KONSTANT_CASE
            toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
            return NULL;
        case DE_E:  // camelCase
            toggle_caps_word_mode(CWMODE_CAMEL_CASE);
            return NULL;
        case DE_S:  // slash/case (ex. path/to/file)
            toggle_caps_word_space_sub(DE_SLSH);
            return NULL;
        case DE_R:  // snake_case
            toggle_caps_word_space_sub(DE_UNDS);
            return NULL;
        case DE_T:  // kebab-case
            toggle_caps_word_space_sub(DE_MINS);
            return NULL;
    }
    return NULL;
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case DE_W:
            return leader_caps_func;
    }
    return NULL;
}