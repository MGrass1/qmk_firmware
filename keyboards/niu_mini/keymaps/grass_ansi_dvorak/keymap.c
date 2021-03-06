#include QMK_KEYBOARD_H
enum {
	_DVORAK   = 0, // Standard layer
	_LOWER    = 1, // Hold layer
	_RAISE    = 2, // Hold layer
	_WILDCARD = 3, // Hold layer
	_NUM      = 4  // Hold layer
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUM MO(_NUM)
#define WILD MO(_WILDCARD)
#define CSE LCTL(LSFT(KC_ESC))
#define CAD LCTL(LALT(KC_DEL))
#define ALTINS LALT(KC_INS)
#define ESC_CTL MT(MOD_LCTL, KC_ESC)
#define LSFT_F6 LSFT(KC_F6)

enum unicode_names {
    ARING = 0,
    ARING_CAPS = 1,
    AUMLAUT = 2,
    AUMLAUT_CAPS = 3,
    UMLAUT = 4,
    UMLAUT_CAPS = 5,
};

const uint32_t PROGMEM unicode_map[] = {
    [ARING]        = 0xE5, // å
    [ARING_CAPS]   = 0xC5, // Å
    [AUMLAUT]      = 0xE4, // ä
    [AUMLAUT_CAPS] = 0xC4, // Ä
    [UMLAUT]       = 0xF6, // ö
    [UMLAUT_CAPS]  = 0xD6, // Ö
};

#define KC_ARIN XP(ARING, ARING_CAPS)
#define KC_AUML XP(AUMLAUT, AUMLAUT_CAPS)
#define KC_UMLA XP(UMLAUT, UMLAUT_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Dvorak
	 * ,-----------------------------------------------------------------------------------.
	 * | TAB  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * | ESC  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |ENTER |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |SHIFT |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Ctrl |  GUI | ALT  | WILD |LOWER |    Space    |  NUM | RAISE|ALT GR| GUI  | CTRL |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_DVORAK] = LAYOUT_planck_mit(
		KC_TAB,  KC_QUOTE, KC_COMMA, KC_DOT,  KC_P,  KC_Y,   KC_F,  KC_G,  KC_C,    KC_R,    KC_L,    KC_BSPC,
		ESC_CTL, KC_A,     KC_O,     KC_E,    KC_U,  KC_I,   KC_D,  KC_H,  KC_T,    KC_N,    KC_S,    KC_ENT,
		KC_LSFT, KC_SCLN,  KC_Q,     KC_J,    KC_K,  KC_X,   KC_B,  KC_M,  KC_W,    KC_V,    KC_Z,    KC_RSFT,
		KC_LCTL, KC_LGUI,  KC_LALT,  WILD,    LOWER,     KC_SPC,    NUM ,  RAISE,   KC_ALGR, KC_RGUI, KC_RCTL
    ),

	/* Lower
	 * ,-----------------------------------------------------------------------------------.
	 * |      |  !   |  @   |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |      |  {   |   }  |  [   |   ]  |   /  |   \  |   ?  |   +  |   =  |   -  |      |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      | Cut  | Copy |Paste |      |   ~  |   `  |   |  |   å  |   ä  |   ö  |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |      |      |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_LOWER] = LAYOUT_planck_mit(
		KC_TRNS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
		KC_TRNS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_SLSH, KC_BSLS, KC_QUES, KC_PLUS, KC_EQL,  KC_MINS, KC_TRNS,
		KC_TRNS, KC_CUT , KC_COPY, KC_PSTE, KC_TRNS, KC_TILD, KC_GRV , KC_PIPE, KC_ARIN, KC_AUML, KC_UMLA, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	/* Raise
	 * ,-----------------------------------------------------------------------------------.
	 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |      |  F11 |  F12 |      |      |      | PgUp |  End |  Up  | Home | Del  |  \   |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      |      |      |      |      |      | PgDn | Left | Down | Right| Ins  |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |      |      |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_RAISE] = LAYOUT_planck_mit(
		KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_TRNS,
		KC_TRNS, KC_F11 , KC_F12 , KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_END , KC_UP  , KC_HOME, KC_DEL , KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS , KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
	/* Wild
	 * ,-----------------------------------------------------------------------------------.
	 * |      | CAD  |      |      |      |      |      |      |      |      |      |      |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |      |AltIns|      |      |      |      |      |      |      |      |      |      |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      |CSEsc |      |      |      |      |      |      |      |      |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |      |      |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_WILDCARD] = LAYOUT_planck_mit(
		KC_TRNS, CAD    , LSFT_F6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, ALTINS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, CSE    , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UC_M_OS, UC_M_LN, UC_M_WI, UC_M_WC, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[_NUM] = LAYOUT_planck_mit(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	)
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}
