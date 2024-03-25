#pragma once
#include QMK_KEYBOARD_H

#include "layers.h"
#include "keymap_german.h"

// ----------------------
// --- Keycode Legend ---
// ----------------------
//   UKC = User Keycode
//   ZM = Zoom
//   CB = Combo


// ---------------------
// --- User Keycodes ---
// ---------------------

enum my_keycodes {
    UKC_STARTING_POINT = SAFE_RANGE,

    UKC_CAPS_WORD,
    UKC_NUM_LOCK
};


// ------------
// --- Mods ---
// ------------

#define MT_LG(k) MT(MOD_LGUI, k)
#define MT_LA(k) MT(MOD_LALT, k)
#define MT_LC(k) MT(MOD_LCTL, k)
#define MT_LS(k) MT(MOD_LSFT, k)
#define MT_RG(k) MT(MOD_RGUI, k)
#define MT_RA(k) MT(MOD_RALT, k)
#define MT_RC(k) MT(MOD_RCTL, k)
#define MT_RS(k) MT(MOD_RSFT, k)