#pragma once

#include "quantum.h"

#ifndef CROSS_LAYER_HRM_MAX_LAYERS
#    define CROSS_LAYER_HRM_MAX_LAYERS 32
#endif

#ifndef CROSS_LAYER_HRM_SLOT_COUNT
#    define CROSS_LAYER_HRM_SLOT_COUNT 12
#endif

typedef struct {
    uint16_t placeholder;
    const uint16_t *layer_keycodes;
} cross_layer_hrm_config_t;

bool is_cross_layer_hrm_key(uint16_t keycode);
bool process_cross_layer_hrm(uint16_t keycode, keyrecord_t *record);

#define CROSS_LAYER_HRM_PLACEHOLDER_0 KC_F13
#define CROSS_LAYER_HRM_PLACEHOLDER_1 KC_F14
#define CROSS_LAYER_HRM_PLACEHOLDER_2 KC_F15
#define CROSS_LAYER_HRM_PLACEHOLDER_3 KC_F16
#define CROSS_LAYER_HRM_PLACEHOLDER_4 KC_F17
#define CROSS_LAYER_HRM_PLACEHOLDER_5 KC_F18
#define CROSS_LAYER_HRM_PLACEHOLDER_6 KC_F19
#define CROSS_LAYER_HRM_PLACEHOLDER_7 KC_F20
#define CROSS_LAYER_HRM_PLACEHOLDER_8 KC_F21
#define CROSS_LAYER_HRM_PLACEHOLDER_9 KC_F22
#define CROSS_LAYER_HRM_PLACEHOLDER_10 KC_F23
#define CROSS_LAYER_HRM_PLACEHOLDER_11 KC_F24

#define CROSS_LAYER_HRM_PLACEHOLDER_HELPER(slot) CROSS_LAYER_HRM_PLACEHOLDER_##slot
#define CROSS_LAYER_HRM_PLACEHOLDER(slot) CROSS_LAYER_HRM_PLACEHOLDER_HELPER(slot)

/*
Usage:

CROSS_LAYER_HRM_FACTORY(0, HOME_GC_XL, MOD_LGUI,
    [_BYOU] = CK____C,
    [_NUM]  = CK____I,
    [_NAV]  = KC_NO
);

Then place HOME_GC_XL in the keymap and call process_cross_layer_hrm()
from process_record_user().
*/
#define CROSS_LAYER_HRM_FACTORY(slot, name, mod, ...)                                                            \
    static const uint16_t PROGMEM name##_layer_keycodes[CROSS_LAYER_HRM_MAX_LAYERS] = {__VA_ARGS__};           \
    const cross_layer_hrm_config_t cross_layer_hrm_slot_##slot = {                                              \
        .placeholder  = CROSS_LAYER_HRM_PLACEHOLDER(slot),                                                       \
        .layer_keycodes = name##_layer_keycodes,                                                                 \
    };                                                                                                           \
    enum { name = MT(mod, CROSS_LAYER_HRM_PLACEHOLDER(slot)) }
