#include "../../keymap_extras/keymap_ckey.h"

// -----------------------------------------------------------------------------
// Configuration
// -----------------------------------------------------------------------------

// Chordal Hold: keys on opposite hands may resolve home-row mods as holds.
// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R',
                   'L', 'L', 'L',     'R', 'R', 'R'
);
// clang-format on

#define HOME_ROW_MOD_MAX_LAYERS 32
#define HOME_ROW_MOD_COUNT 8

typedef struct {
    uint16_t        mod_tap_keycode;
    const uint16_t *layer_keycodes;
} home_row_mod_config_t;

/*
 * Tap actions by layer
 * --------------------
 * Add or change designated entries to configure what a home-row key sends
 * when tapped on that layer. The highest active layer with a non-KC_NO entry
 * wins. KC_NO and omitted entries fall through to the next active layer.
 *
 * Example:
 *   [_BYOU] = CK____A,  sends A on the base layer
 *   [_NUM]  = CK____L,  sends L while the number layer is active
 *   [_NAV]  = CK_C__F,  sends Ctrl+F while the navigation layer is active
 *
 * The table below binds each mapping to the corresponding mod-tap keycode
 * declared in home_row_mods.h.
 */
// clang-format off
static const uint16_t PROGMEM home_gl_layers[HOME_ROW_MOD_MAX_LAYERS] = {
    [_BYOU] = CK____C,
    [_NUM]  = CK____I,
    [_NAV]  = KC_NO,
};

static const uint16_t PROGMEM home_al_layers[HOME_ROW_MOD_MAX_LAYERS] = {
    [_BYOU] = CK____I,
    [_NUM]  = CK____H,
    [_NAV]  = KC_NO,
};

static const uint16_t PROGMEM home_sl_layers[HOME_ROW_MOD_MAX_LAYERS] = {
    [_BYOU] = CK____E,
    [_NUM]  = CK____J,
    [_NAV]  = CK_C__E,
};

static const uint16_t PROGMEM home_cl_layers[HOME_ROW_MOD_MAX_LAYERS] = {
    [_BYOU] = CK____A,
    [_NUM]  = CK____L,
    [_NAV]  = CK_C__F,
};

static const uint16_t PROGMEM home_cr_layers[HOME_ROW_MOD_MAX_LAYERS] = {
    [_BYOU] = CK____H,
    [_NUM]  = CK____4,
};

static const uint16_t PROGMEM home_sr_layers[HOME_ROW_MOD_MAX_LAYERS] = {
    [_BYOU] = CK____T,
    [_NUM]  = CK____5,
};

static const uint16_t PROGMEM home_ar_layers[HOME_ROW_MOD_MAX_LAYERS] = {
    [_BYOU] = CK____S,
    [_NUM]  = CK____6,
};

static const uint16_t PROGMEM home_gr_layers[HOME_ROW_MOD_MAX_LAYERS] = {
    [_BYOU] = CK____N,
    [_NUM]  = KC_NO,
    [_NAV]  = CK__END,
};

static const home_row_mod_config_t home_row_mods[HOME_ROW_MOD_COUNT] = {
    {
        .mod_tap_keycode = HOME_GL,
        .layer_keycodes  = home_gl_layers,
    },
    {
        .mod_tap_keycode = HOME_AL,
        .layer_keycodes  = home_al_layers,
    },
    {
        .mod_tap_keycode = HOME_SL,
        .layer_keycodes  = home_sl_layers,
    },
    {
        .mod_tap_keycode = HOME_CL,
        .layer_keycodes  = home_cl_layers,
    },
    {
        .mod_tap_keycode = HOME_CR,
        .layer_keycodes  = home_cr_layers,
    },
    {
        .mod_tap_keycode = HOME_SR,
        .layer_keycodes  = home_sr_layers,
    },
    {
        .mod_tap_keycode = HOME_AR,
        .layer_keycodes  = home_ar_layers,
    },
    {
        .mod_tap_keycode = HOME_GR,
        .layer_keycodes  = home_gr_layers,
    },
};
// clang-format on

// -----------------------------------------------------------------------------
// Cross-layer tap resolution
// -----------------------------------------------------------------------------

typedef struct {
    uint16_t      keycode;
    layer_state_t layer_snapshot;
    bool          registered;
} home_row_mod_runtime_t;

static home_row_mod_runtime_t home_row_mod_runtime[HOME_ROW_MOD_COUNT] = {0};

static int8_t find_home_row_mod(uint16_t keycode) {
    if (!IS_QK_MOD_TAP(keycode)) {
        return -1;
    }

    for (uint8_t i = 0; i < HOME_ROW_MOD_COUNT; i++) {
        if (home_row_mods[i].mod_tap_keycode == keycode) {
            return i;
        }
    }
    return -1;
}

static uint16_t resolve_tap_keycode(const home_row_mod_config_t *config, layer_state_t active_layers) {
    for (int8_t layer = HOME_ROW_MOD_MAX_LAYERS - 1; layer >= 0; layer--) {
        if (!(active_layers & ((layer_state_t)1 << layer))) {
            continue;
        }

        const uint16_t keycode = pgm_read_word(&config->layer_keycodes[layer]);
        if (keycode != KC_NO) {
            return keycode;
        }
    }
    return KC_NO;
}

bool process_home_row_mods(uint16_t keycode, keyrecord_t *record) {
    const int8_t index = find_home_row_mod(keycode);
    if (index < 0) {
        return true;
    }

    home_row_mod_runtime_t      *runtime = &home_row_mod_runtime[index];
    const home_row_mod_config_t *config  = &home_row_mods[index];

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
        runtime->keycode    = resolve_tap_keycode(config, runtime->layer_snapshot);
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

// -----------------------------------------------------------------------------
// Interrupted-hold report timing
// -----------------------------------------------------------------------------

/*
 * Give an interrupted home-row mod a modifier-only report before reporting
 * the interrupting key, matching a conventional physical modifier chord.
 */
static matrix_row_t pending_home_row_mods[MATRIX_ROWS] = {0};
static bool         batch_interrupted_home_row_mod     = false;

static bool has_pending_home_row_mod(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        if (pending_home_row_mods[row]) {
            return true;
        }
    }
    return false;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (find_home_row_mod(keycode) >= 0) {
        const matrix_row_t key_mask = (matrix_row_t)1 << record->event.key.col;
        if (record->event.pressed) {
            pending_home_row_mods[record->event.key.row] |= key_mask;
        } else {
            pending_home_row_mods[record->event.key.row] &= ~key_mask;
        }
    } else if (record->event.pressed && has_pending_home_row_mod()) {
        batch_interrupted_home_row_mod = true;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    batch_interrupted_home_row_mod = false;
}

void register_mods(uint8_t mods) {
    if (!mods) {
        return;
    }
    add_mods(mods);
    send_keyboard_report();
    if (batch_interrupted_home_row_mod) {
        wait_ms(10);
    }
}
