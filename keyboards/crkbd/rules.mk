
# Enable Achordion for better Home Row Mods
SRC += features/achordion.c

KEY_OVERRIDE_ENABLE = yes
SRC += features/overrides.c

CAPS_WORD_ENABLE = yes
SRC += features/caps_word.c


DEFAULT_FOLDER = crkbd/rev1

COMBO_ENABLE = yes
LEADER_ENABLE = yes

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
