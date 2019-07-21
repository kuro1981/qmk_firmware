#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// #define _QWERTY 0
// #define _LOWER 1
// #define _RAISE 2
// #define _ADJUST 16

enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _EUCALYN,
    _KEYPAD,
    _AUX,
    _KAUX,
    _LOWER,
    _RAISE,
    _PADFUNC,
    _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EUCALYN,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_EISU LALT(KC_GRV)
#define KC_SFSP  SFT_T(KC_SPC)
#define KC_____   _______
#define ___       _______
#define KC_XXXX   XXXXXXX
#define KC_LOWER  MO(_LOWER)
#define KC_RAISE  MO(_RAISE)
#define KC_SFBS   SFT_T(KC_BSLS)
#define KC_LOES  LT(_LOWER, KC_ESC)
#define KC_ADJ    MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  Del |                    |   `  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| LOESC| SFTSP| Space|||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT_kc( \
    ESC,  1,    2,    3,    4,    5,    LBRC,                        RBRC, 6,    7,    8,    9,    0,    EQL, \
    TAB,  Q,    W,    E,    R,    T,    MINS,                        EQL , Y,    U,    I,    O,    P,    MINS, \
    TAB,  A,    S,    D,    F,    G,    DEL ,                        GRV,  H,    J,    K,    L,    SCLN, QUOT, \
    LSFT, Z,    X,    C,    V,    B,    SPC ,                        SPC , N,    M,    COMM, DOT,  SLSH, SFBS, \
    LCTL,  LALT, LGUI,EISU,     LOES,  SFSP ,SPC,               BSPC,ENT , RAISE,      LEFT, DOWN, UP,   RGHT  \
  ),

    /* EUCALYN
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Space|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| LOESC| SFTSP| Space||||||||      | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_EUCALYN] = LAYOUT_kc( \
    ESC,  1,    2,    3,    4,    5,    LBRC,                        RBRC, 6,    7,    8,    9,    0,    EQL, \
    TAB,  Q,    W, COMM,  DOT, SCLN,    MINS,                        EQL , M,    R,    D,    Y,    P,    MINS, \
    TAB,  A,    O,    E,    I,    U,    DEL ,                        GRV,  G,    T,    K,    S,    N,    QUOT, \
    LSFT, Z,    X,    C,    V,    F,    SPC ,                        SPC , B,    H,    J,    L, SLSH,    SFBS, \
    LCTL, LALT, LGUI, EISU,     LOES,  SFSP ,SPC,               BSPC,ENT , RAISE,      LEFT, DOWN, UP,   RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |      |      |      |      |      |      |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |      |      |      |      |      |  Del |                    | Bksp | Left | Down |  Up  | Right|   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      | Space|                    | Space|      |      |      |      |      | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|      ||||||||      | Enter|Adjust|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT_kc(
    XXXX, F1,   F2,   F3,   F4,   F5,   LCBR,                        XXXX, F6,   F7,   F8,   F9,   F10,  F11,  \
    XXXX, SLCK, PAUS, INS,  DEL,  PERC, UNDS,                         XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, F12, \
    TAB,  XXXX, XXXX, XXXX, XXXX, XXXX, DEL ,                        BSPC, LEFT, DOWN, UP,   RGHT, XXXX, ENT , \
    LSFT, XXXX, XXXX, XXXX, XXXX, XXXX, SPC ,                        PSCR, XXXX, XXXX, XXXX, XXXX, XXXX, RSFT, \
    LCTL, LALT, LGUI, EISU,       LOWER, ____,____,            ____, ____, ADJ,        HOME, PGDN, PGUP, END   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Space|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU ||||||||Adjust| Space|      ||||||||      | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT_kc(
    XXXX, EXLM,   AT, HASH,  DLR, PERC, LCBR,                        RCBR, F6,   F7,   F8,   F9,   F10,  F12,  \
    XXXX, XXXX, XXXX, XXXX, XXXX, PERC, UNDS,                        PLUS, CIRC, AMPR, ASTR, LPRN, RPRN, PIPE, \
    ____, XXXX, XXXX, XXXX, XXXX, XXXX, DEL ,                        BSPC, H,    J,    K,    L,    COLN, DQT , \
    ____, XXXX, XXXX, XXXX, XXXX, XXXX, SPC ,                        ____, N,    M,    LT,   GT,   QUES, RSFT, \
    LCTL, LALT, LGUI, EISU,       ADJ , ____, ____,            ____, ____, ____,       HOME, PGDN, PGUP, END   \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EUCALYN,  QWERTY, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, AG_SWAP,                      XXXXXXX, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, BL_TOGG, BL_BRTG, BL_INC , BL_DEC , AG_NORM,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

static int current_default_layer;

uint32_t default_layer_state_set_kb(uint32_t state) {
    // 1<<_QWERTY  - 1 == 1 - 1 == _QWERTY (=0)
    // 1<<_COLEMAK - 1 == 2 - 1 == _COLEMAK (=1)
    current_default_layer = state - 1;
    // 1<<_DVORAK  - 2 == 4 - 2 == _DVORAK (=2)
    if ( current_default_layer == 3 ) current_default_layer -= 1;
    // 1<<_EUCALYN - 5 == 8 - 5 == _EUCALYN (=3)
    if ( current_default_layer == 7 ) current_default_layer -= 4;
    // 1<<_KEYPAD  - 12 == 16 - 12 == _KEYPAD (=4)
    if ( current_default_layer == 15 ) current_default_layer -= 11;
    return state;
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case EUCALYN:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_EUCALYN);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
