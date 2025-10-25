# Enable Half-Duplex Serial communication between the two halves
SERIAL_DRIVER = vendor

CONSOLE_ENABLE = yes


# Disable Bootmagic as the Corne has a dedicated Reset Button
# https://docs.qmk.fm/features/bootmagic#advanced-bootmagic
BOOTMAGIC_ENABLE = no


# Disable OLED as it is not currently used
# https://docs.qmk.fm/features/oled_driver
OLED_ENABLE = no


# Disable the RGB Lighting feature
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no


# Activate Tap Dance for fine grained control of thumb keys
TAP_DANCE_ENABLE = yes

# Activate Key Overrides for fine grained control of Modded Keypresses
# https://docs.qmk.fm/features/key_overrides
KEY_OVERRIDE_ENABLE = yes


SRC += keymap_extras/keymap_ckey.c
SRC += features/tap_dance/tap_dance.c
SRC += features/selection/select_word.c

CAPS_WORD_ENABLE = yes
SRC += features/caps_word/caps_word.c
