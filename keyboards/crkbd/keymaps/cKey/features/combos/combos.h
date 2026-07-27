#pragma once

#include "quantum.h"

enum { CKEY_COMBO_COUNT = 39 };

/*
 * QMK's keymap introspection includes keymap.c directly and uses ARRAY_SIZE()
 * on this table, so its complete size must be visible from the keymap
 * translation unit even though the definition lives in combos.c.
 */
extern combo_t key_combos[CKEY_COMBO_COUNT];
