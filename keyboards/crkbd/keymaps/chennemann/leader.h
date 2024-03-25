#pragma once
#include QMK_KEYBOARD_H

typedef void *(*leader_func_t)(uint16_t);


// Check to see if we are leading
bool is_leading(void);
// Start leader sequence
void start_leading(void);
// Stop leader sequence
void stop_leading(void);

// Process keycode for leader sequences
bool process_leader(uint16_t keycode, const keyrecord_t *record);