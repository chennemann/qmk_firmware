// Copyright 2021-2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file select_word.c
 * @brief Select word implementation
 *
 * For full documentation, see
 * <https://getreuer.info/posts/keyboards/select-word>
 */

#include "select_word.h"

// clang-format off
enum {
    STATE_NONE,        // No selection.
    STATE_SELECTED,    // Macro released with something selected.
    STATE_WORD,        // Macro held with word(s) selected.
    STATE_FIRST_LINE,  // Macro held with one line selected.
    STATE_LINE         // Macro held with multiple lines selected.
};

enum {
    DIRECTION_NONE,         // No direction
    DIRECTION_FORWARDS,     // Selection expands forwards.
    DIRECTION_BACKWARDS,    // Selection expands backwards.
};
// clang-format on

static uint8_t state = STATE_NONE;
static uint8_t direction = DIRECTION_NONE;

// Idle timeout timer to disable Select Word after a period of inactivity.
#if SELECT_WORD_TIMEOUT > 0
static uint16_t idle_timer = 0;

void select_word_task(void) {
  if (state && timer_expired(timer_read(), idle_timer)) {
    state = STATE_NONE;
  }
}
#endif  // SELECT_WORD_TIMEOUT > 0




bool process_select_word(uint16_t keycode, keyrecord_t* record, uint16_t sel_forwards_keycode, uint16_t sel_backwards_keycode) {
    if (keycode == KC_LSFT || keycode == KC_RSFT) {
        return true;
    }

    // Reset idle timer.
#if SELECT_WORD_TIMEOUT > 0
    idle_timer = record->event.time + SELECT_WORD_TIMEOUT;
#endif  // SELECT_WORD_TIMEOUT > 0


    if (keycode == sel_forwards_keycode && record->event.pressed) {
        direction= DIRECTION_FORWARDS;
    } else if (keycode == sel_backwards_keycode && record->event.pressed) {
        direction= DIRECTION_BACKWARDS;
    }


    const bool is_selection_key = keycode == sel_forwards_keycode || keycode == sel_backwards_keycode;
    const bool is_direction_key = keycode == KC_UP || keycode == KC_DOWN || keycode == KC_LEFT || keycode == KC_RIGHT || keycode == KC_HOME || keycode == KC_END;

    if (is_selection_key && record->event.pressed) {
        const uint8_t mods = get_mods();
        const bool shifted = mods & MOD_MASK_SHIFT;

        if (!shifted) {  // Select word.
            set_mods(MOD_BIT(KC_LCTL));  // Hold Left Ctrl.
            if (state == STATE_NONE) {
                // On first use, tap Ctrl+Right then Ctrl+Left (or with Alt on Mac) to
                // ensure the cursor is positioned at the beginning of the word.
                send_keyboard_report();
                if (direction == DIRECTION_FORWARDS) {
                    tap_code(KC_RGHT);
                    tap_code(KC_LEFT);
                } else if (direction == DIRECTION_BACKWARDS) {
                    tap_code(KC_LEFT);
                    tap_code(KC_RGHT);
                }
            }

            register_mods(MOD_BIT(KC_LSFT));
            if (direction == DIRECTION_FORWARDS) {
                register_code(KC_RGHT);
            } else if (direction == DIRECTION_BACKWARDS) {
                register_code(KC_LEFT);
            }
            state = STATE_WORD;
        } else {  // Select line.
            if (state == STATE_NONE) {
                // Tap Home, then Shift + End.
                send_keyboard_report();
                if (direction == DIRECTION_FORWARDS) {
                    tap_code(KC_END);
                    tap_code(KC_HOME);
                } else if (direction == DIRECTION_BACKWARDS) {
                    tap_code(KC_HOME);
                    tap_code(KC_END);
                }
                register_mods(MOD_BIT(KC_LSFT));
                if (direction == DIRECTION_FORWARDS) {
                    tap_code(KC_END);
                } else if (direction == DIRECTION_BACKWARDS) {
                    tap_code(KC_HOME);
                }
                set_mods(mods);
                state = STATE_FIRST_LINE;
            } else {
                register_mods(MOD_BIT(KC_LSFT));
                if (direction == DIRECTION_FORWARDS) {
                    tap_code(KC_DOWN);
                    tap_code(KC_END);
                } else if (direction == DIRECTION_BACKWARDS) {
                    tap_code(KC_UP);
                    tap_code(KC_END);
                    tap_code(KC_HOME);
                }
                state = STATE_LINE;
            }
        }
        set_mods(mods);
        return false;
    }

    if (is_direction_key && record->event.pressed) {
        if (state == STATE_SELECTED) {
            clear_mods();
            register_mods(MOD_BIT(KC_LSFT));
            register_code(keycode);
            return false;
        }
    }

  // `sel_keycode` was released, or another key was pressed.
  switch (state) {
        case STATE_WORD:
            unregister_code(KC_RGHT);
            unregister_code(KC_LEFT);
            unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL));
            state = STATE_SELECTED;
            break;

        case STATE_FIRST_LINE:
            state = STATE_SELECTED;
            break;

        case STATE_LINE:
            unregister_code(KC_UP);
            unregister_code(KC_DOWN);
            unregister_mods(MOD_BIT(KC_LSFT));
            state = STATE_SELECTED;
            break;

        case STATE_SELECTED:
            if (keycode == KC_ESC) {
                if (direction == DIRECTION_FORWARDS) {
                    tap_code(KC_RIGHT);
                } else if (direction == DIRECTION_BACKWARDS) {
                    tap_code(KC_LEFT);
                }
                state = STATE_NONE;
                return false;
            }
            if (is_direction_key) {
                unregister_code(keycode);
                unregister_mods(MOD_BIT(KC_LSFT));
                return true;
            }
            if (is_selection_key) {
                break;
            }

        // Fallthrough intended.
        default:
            state = STATE_NONE;
    }

    return true;
}
