#pragma once
#include QMK_KEYBOARD_H

#include "layers.h"
#include "custom_keycodes.h"
#include "keymap_ckey.h"

// ------------
// --- Mods ---
// ------------

#define MT_LG(key) MT(MOD_LGUI, key)
#define MT_LA(key) MT(MOD_LALT, key)
#define MT_LC(key) MT(MOD_LCTL, key)
#define MT_LS(key) MT(MOD_LSFT, key)
#define MT_RG(key) MT(MOD_RGUI, key)
#define MT_RA(key) MT(MOD_RALT, key)
#define MT_RC(key) MT(MOD_RCTL, key)
#define MT_RS(key) MT(MOD_RSFT, key)