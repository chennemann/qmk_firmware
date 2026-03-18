#pragma once

#include "quantum.h"

#ifndef CROSS_LAYER_HRM_MAX_LAYERS
#    define CROSS_LAYER_HRM_MAX_LAYERS 32
#endif

#ifndef CROSS_LAYER_HRM_MAX_CONFIGS
#    define CROSS_LAYER_HRM_MAX_CONFIGS 16
#endif

#ifndef CROSS_LAYER_HRM_PLACEHOLDER_BASE
#    define CROSS_LAYER_HRM_PLACEHOLDER_BASE KC_F13
#endif

#ifndef CROSS_LAYER_HRM_PLACEHOLDER_COUNT
#    define CROSS_LAYER_HRM_PLACEHOLDER_COUNT 12
#endif

typedef struct {
    uint16_t mt_keycode;
    const uint16_t *layer_keycodes;
} cross_layer_hrm_config_t;

extern const cross_layer_hrm_config_t *const cross_layer_hrm_registry[];

bool process_cross_layer_hrm(uint16_t keycode, keyrecord_t *record);

/*
Usage:

enum { CROSS_LAYER_HRM_COUNTER_BASE = __COUNTER__ };

DECLARE_CROSS_LAYER_HRM(HOME_CL, MOD_LCTL,
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
#define DECLARE_CROSS_LAYER_HRM(name, mod, ...) \
    DECLARE_CROSS_LAYER_HRM_I((__COUNTER__ - CROSS_LAYER_HRM_COUNTER_BASE - 1), name, mod, __VA_ARGS__)

#define DECLARE_CROSS_LAYER_HRM_I(index, name, mod, ...)                                                      \
    _Static_assert((index) < CROSS_LAYER_HRM_PLACEHOLDER_COUNT, "Too many cross-layer HRM declarations"); \
    static const uint16_t PROGMEM name##_layer_keycodes[CROSS_LAYER_HRM_MAX_LAYERS] = {__VA_ARGS__};        \
    static const cross_layer_hrm_config_t name##_cross_layer_hrm = {                                         \
        .mt_keycode    = MT(mod, (CROSS_LAYER_HRM_PLACEHOLDER_BASE + (index))),                              \
        .layer_keycodes = name##_layer_keycodes,                                                              \
    };                                                                                                        \
    enum { name = MT(mod, (CROSS_LAYER_HRM_PLACEHOLDER_BASE + (index))) }
