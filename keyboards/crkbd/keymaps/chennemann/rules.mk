# Enable Achordion for better Home Row Mods
SRC += achordion.c

KEY_OVERRIDE_ENABLE = yes
SRC += overrides.c

CAPS_WORD_ENABLE = yes
SRC += caps_word.c

LEADER_ENABLE = no
SRC += leader.c
SRC += leader_sequences.c

DEFAULT_FOLDER = crkbd/rev1

TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes

CONVERT_TO=promicro_rp2040



# ####################
# ### Space Saving ###
# ####################

CONSOLE_ENABLE     = no
SWAP_HANDS_ENABLE  = no
UNICODE_ENABLE     = no

RGBLIGHT_ENABLE = no
RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no
