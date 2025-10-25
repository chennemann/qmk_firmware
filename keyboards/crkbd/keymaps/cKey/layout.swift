layout:
  qmk_keyboard: corne_rotated
  qmk_layout: LAYOUT_split_3x6_3
layers:
  Base:
    - ["Esc", "B", "Y", "O", "U", "+",                                "=", "L", "D", "W", "V", "Bspace"]
    - ["Tab", "<win> C", "<alt> I", "<sft> E", "<ctr> A", ",",        ".", "<ctr> H", "<sft> T", "<alt> S", "<win> N", "'"]
    - ["Q",  "G", "X", "J", "K", "-",                                 "?", "R",   "M", "F", "P", "Z"]
    - [null, "<sft> <ent>", "SYM",                                    "DIA", "NUM <spc>", null]

  SYMBOL:
    - ["Esc", "'", "<", ">", "&", "´",                                "`", "€", "[", "]", "%", "Bspace"]
    - ["Tab", "!", "-", "+", "=", "#",                                "~", ":", "(", ")", "?", "\""]
    - [null,  "^", "/", "*", "\\", "_",                               "|", "$", "{", "}", "@", null]
    - [null, null, {type: held},                                      "DIA", "NUM <spc>", null]
    
  NUMBER:
    - ["Esc", null, null, null, null, null,                           "=", "7", "8", "9", "%", "Bspace"]
    - ["Tab", null, "-", "+", "=", "#",                               ".", "4", "5", "6", ",", null]
    - [null,  null, "/", "*", null, null,                             "0", "1", "2", "3", "0", null]
    - [null, "<sft> <spc>", "SYM",                                    null, {type: held}, null]
    
  DIACRITICS:
    - ["Esc", "´", "`", "ö", "ü", "^",                                null, null, null, null, null, "Bspace"]
    - ["Tab", "c", "î", "é", "ä", "â",                                null, null, "t", "ß", "n", null]
    - [null,  null, null, "è", "a", "a",                              null, null, null, null, null, null]
    - [null, "<sft> <spc>", "SYM",                                    {type: held}, null, null]
