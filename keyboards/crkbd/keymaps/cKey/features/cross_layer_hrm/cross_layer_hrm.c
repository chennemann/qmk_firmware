#include "cross_layer_hrm.h"

static uint8_t cross_layer_hrm_registry_count(void) {
    uint8_t count = 0;

    while (count < CROSS_LAYER_HRM_MAX_CONFIGS && cross_layer_hrm_registry[count] != NULL) {
        count++;
    }

    return count;
}

typedef struct {
    uint16_t      keycode;
    layer_state_t layer_snapshot;
    bool          registered;
} cross_layer_hrm_runtime_t;

static cross_layer_hrm_runtime_t cross_layer_hrm_runtime[CROSS_LAYER_HRM_MAX_CONFIGS] = {0};

static int8_t cross_layer_hrm_find_index(uint16_t keycode) {
    if (!IS_QK_MOD_TAP(keycode)) {
        return -1;
    }

    uint8_t count = cross_layer_hrm_registry_count();

    for (uint8_t i = 0; i < count; i++) {
        if (cross_layer_hrm_registry[i]->mt_keycode == keycode) {
            return i;
        }
    }

    return -1;
}

static uint16_t cross_layer_hrm_resolve_keycode(const cross_layer_hrm_config_t *config, layer_state_t active_layers) {
    for (int8_t layer = CROSS_LAYER_HRM_MAX_LAYERS - 1; layer >= 0; layer--) {
        if (!(active_layers & ((layer_state_t)1 << layer))) {
            continue;
        }

        uint16_t keycode = pgm_read_word(&config->layer_keycodes[layer]);
        if (keycode != KC_NO) {
            return keycode;
        }
    }

    return KC_NO;
}

bool process_cross_layer_hrm(uint16_t keycode, keyrecord_t *record) {
    int8_t index = cross_layer_hrm_find_index(keycode);
    if (index < 0) {
        return true;
    }

    cross_layer_hrm_runtime_t *runtime = &cross_layer_hrm_runtime[index];
    const cross_layer_hrm_config_t *config = cross_layer_hrm_registry[index];

    if (record->event.pressed) {
        runtime->layer_snapshot = layer_state | default_layer_state;
    }

    if (record->tap.count == 0) {
        if (!record->event.pressed) {
            runtime->keycode        = KC_NO;
            runtime->layer_snapshot = 0;
            runtime->registered     = false;
        }
        return true;
    }

    if (record->event.pressed) {
        runtime->keycode = cross_layer_hrm_resolve_keycode(config, runtime->layer_snapshot);
        runtime->registered = false;

        if (runtime->keycode != KC_NO) {
            register_code16(runtime->keycode);
            runtime->registered = true;
        }
    } else {
        if (runtime->keycode != KC_NO && runtime->registered) {
            unregister_code16(runtime->keycode);
        }

        runtime->keycode        = KC_NO;
        runtime->layer_snapshot = 0;
        runtime->registered     = false;
    }

    return false;
}
