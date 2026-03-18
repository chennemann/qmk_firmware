#pragma once

#include "quantum.h"

#ifndef CROSS_LAYER_HRM_MAX_LAYERS
#    define CROSS_LAYER_HRM_MAX_LAYERS 32
#endif

#ifndef CROSS_LAYER_HRM_MAX_CONFIGS
#    define CROSS_LAYER_HRM_MAX_CONFIGS 16
#endif

typedef struct {
    uint16_t tap_keycode;
    const uint16_t *layer_keycodes;
} cross_layer_hrm_config_t;

extern const cross_layer_hrm_config_t *const cross_layer_hrm_registry[];

bool process_cross_layer_hrm(uint16_t keycode, keyrecord_t *record);

/*
Usage:

#undef HOME_CL
#define HOME_CL MT(MOD_LCTL, KC_F16)
CROSS_LAYER_HRM_FACTORY(HOME_CL, KC_F16,
    [_BYOU] = CK____A,
    [_NUM]  = CK____L,
    [_NAV]  = CK_C__F
);

Then add &HOME_CL_cross_layer_hrm to cross_layer_hrm_registry[] and call
process_cross_layer_hrm() from process_record_user().

Resolution rules:
- active layers are snapshotted on key press
- highest active layer wins
- KC_NO means "no mapping on this layer", so lower active layers are tried
- if no mapping is found, nothing is sent on tap
*/
#define CROSS_LAYER_HRM_FACTORY(name, tap_keycode_value, ...)                                                  \
    static const uint16_t PROGMEM name##_layer_keycodes[CROSS_LAYER_HRM_MAX_LAYERS] = {__VA_ARGS__};         \
    static const cross_layer_hrm_config_t name##_cross_layer_hrm = {                                          \
        .tap_keycode    = (tap_keycode_value),                                                                 \
        .layer_keycodes = name##_layer_keycodes,                                                               \
    }
