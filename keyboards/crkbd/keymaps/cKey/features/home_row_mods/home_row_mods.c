#include "home_row_mods.h"

static const uint16_t PROGMEM home_gl_layers[CROSS_LAYER_HRM_MAX_LAYERS] = {[_BYOU] = CK____C, [_NUM] = CK____I, [_NAV] = KC_NO};
static const uint16_t PROGMEM home_al_layers[CROSS_LAYER_HRM_MAX_LAYERS] = {[_BYOU] = CK____I, [_NUM] = CK____H, [_NAV] = KC_NO};
static const uint16_t PROGMEM home_sl_layers[CROSS_LAYER_HRM_MAX_LAYERS] = {[_BYOU] = CK____E, [_NUM] = CK____J, [_NAV] = CK_C__E};
static const uint16_t PROGMEM home_cl_layers[CROSS_LAYER_HRM_MAX_LAYERS] = {[_BYOU] = CK____A, [_NUM] = CK____L, [_NAV] = CK_C__F};
static const uint16_t PROGMEM home_cr_layers[CROSS_LAYER_HRM_MAX_LAYERS] = {[_BYOU] = CK____H, [_NUM] = CK____4};
static const uint16_t PROGMEM home_sr_layers[CROSS_LAYER_HRM_MAX_LAYERS] = {[_BYOU] = CK____T, [_NUM] = CK____5};
static const uint16_t PROGMEM home_ar_layers[CROSS_LAYER_HRM_MAX_LAYERS] = {[_BYOU] = CK____S, [_NUM] = CK____6};
static const uint16_t PROGMEM home_gr_layers[CROSS_LAYER_HRM_MAX_LAYERS] = {[_BYOU] = CK____N, [_NUM] = KC_NO, [_NAV] = CK__END};

#define HRM_CONFIG(name, keycode) static const cross_layer_hrm_config_t name = {.mt_keycode = keycode, .layer_keycodes = name##_layers}

HRM_CONFIG(home_gl, HOME_GL);
HRM_CONFIG(home_al, HOME_AL);
HRM_CONFIG(home_sl, HOME_SL);
HRM_CONFIG(home_cl, HOME_CL);
HRM_CONFIG(home_cr, HOME_CR);
HRM_CONFIG(home_sr, HOME_SR);
HRM_CONFIG(home_ar, HOME_AR);
HRM_CONFIG(home_gr, HOME_GR);

const cross_layer_hrm_config_t *const cross_layer_hrm_registry[] = {
    &home_gl, &home_al, &home_sl, &home_cl, &home_cr, &home_sr, &home_ar, &home_gr, NULL,
};

/*
 * Give an interrupted home-row mod a modifier-only report before reporting
 * the interrupting key, matching a conventional physical modifier chord.
 */
static matrix_row_t pending_hrm_rows[MATRIX_ROWS] = {0};
static bool         batch_interrupted_hrm_report  = false;

static bool is_home_row_mod(uint16_t keycode) {
    switch (keycode) {
        case HOME_GL:
        case HOME_AL:
        case HOME_SL:
        case HOME_CL:
        case HOME_CR:
        case HOME_SR:
        case HOME_AR:
        case HOME_GR:
            return true;
        default:
            return false;
    }
}

static bool has_pending_home_row_mod(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        if (pending_hrm_rows[row]) {
            return true;
        }
    }
    return false;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (is_home_row_mod(keycode)) {
        const matrix_row_t key_mask = (matrix_row_t)1 << record->event.key.col;
        if (record->event.pressed) {
            pending_hrm_rows[record->event.key.row] |= key_mask;
        } else {
            pending_hrm_rows[record->event.key.row] &= ~key_mask;
        }
    } else if (record->event.pressed && has_pending_home_row_mod()) {
        batch_interrupted_hrm_report = true;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    batch_interrupted_hrm_report = false;
}

void register_mods(uint8_t mods) {
    if (!mods) {
        return;
    }
    add_mods(mods);
    send_keyboard_report();
    if (batch_interrupted_hrm_report) {
        wait_ms(10);
    }
}
