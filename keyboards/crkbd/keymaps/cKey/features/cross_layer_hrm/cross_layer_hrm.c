#include "cross_layer_hrm.h"
#include "../tap_dance/tap_dance.h"

#define DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(slot) \
    const cross_layer_hrm_config_t cross_layer_hrm_slot_##slot __attribute__((weak)) = {0}

DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(0);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(1);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(2);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(3);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(4);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(5);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(6);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(7);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(8);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(9);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(10);
DEFINE_EMPTY_CROSS_LAYER_HRM_SLOT(11);

static const cross_layer_hrm_config_t *const cross_layer_hrm_slots[CROSS_LAYER_HRM_SLOT_COUNT] = {
    &cross_layer_hrm_slot_0,
    &cross_layer_hrm_slot_1,
    &cross_layer_hrm_slot_2,
    &cross_layer_hrm_slot_3,
    &cross_layer_hrm_slot_4,
    &cross_layer_hrm_slot_5,
    &cross_layer_hrm_slot_6,
    &cross_layer_hrm_slot_7,
    &cross_layer_hrm_slot_8,
    &cross_layer_hrm_slot_9,
    &cross_layer_hrm_slot_10,
    &cross_layer_hrm_slot_11,
};

static uint16_t     cross_layer_hrm_pressed_keycodes[CROSS_LAYER_HRM_SLOT_COUNT] = {0};
static layer_state_t cross_layer_hrm_pressed_layers[CROSS_LAYER_HRM_SLOT_COUNT]   = {0};
static bool          cross_layer_hrm_registered[CROSS_LAYER_HRM_SLOT_COUNT]       = {0};

static int8_t cross_layer_hrm_find_slot(uint16_t keycode) {
    if (!IS_QK_MOD_TAP(keycode)) {
        return -1;
    }

    uint8_t tap_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);

    for (uint8_t i = 0; i < CROSS_LAYER_HRM_SLOT_COUNT; i++) {
        const cross_layer_hrm_config_t *config = cross_layer_hrm_slots[i];
        if (config->placeholder != 0 && tap_keycode == config->placeholder) {
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

bool is_cross_layer_hrm_key(uint16_t keycode) {
    return cross_layer_hrm_find_slot(keycode) >= 0;
}

bool process_cross_layer_hrm(uint16_t keycode, keyrecord_t *record) {
    int8_t slot = cross_layer_hrm_find_slot(keycode);
    if (slot < 0) {
        return true;
    }

    if (record->event.pressed) {
        cross_layer_hrm_pressed_layers[slot] = layer_state | default_layer_state;
    }

    if (record->tap.count == 0) {
        if (!record->event.pressed) {
            cross_layer_hrm_pressed_keycodes[slot] = KC_NO;
            cross_layer_hrm_pressed_layers[slot]   = 0;
            cross_layer_hrm_registered[slot]       = false;
        }
        return true;
    }

    if (record->event.pressed) {
        uint16_t resolved_keycode = cross_layer_hrm_resolve_keycode(cross_layer_hrm_slots[slot], cross_layer_hrm_pressed_layers[slot]);
        cross_layer_hrm_pressed_keycodes[slot] = resolved_keycode;

        cross_layer_hrm_registered[slot] = false;

        if (resolved_keycode != KC_NO) {
            if (is_retroactive_mod_enabled()) {
                tap_code16_with_mods(resolved_keycode, get_active_tap_dance_mods());
                consume_retroactive_mod();
            } else if (get_active_tap_dance_mods()) {
                tap_code16_with_mods(resolved_keycode, get_active_tap_dance_mods());
            } else {
                register_code16(resolved_keycode);
                cross_layer_hrm_registered[slot] = true;
            }
        }
    } else {
        uint16_t resolved_keycode = cross_layer_hrm_pressed_keycodes[slot];
        bool     registered       = cross_layer_hrm_registered[slot];
        cross_layer_hrm_pressed_keycodes[slot] = KC_NO;
        cross_layer_hrm_pressed_layers[slot]   = 0;
        cross_layer_hrm_registered[slot]       = false;

        if (resolved_keycode != KC_NO && registered) {
            unregister_code16(resolved_keycode);
        }
    }

    return false;
}
