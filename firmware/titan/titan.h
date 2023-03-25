#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT( \
	     K01,                 K05,      K07, K08,      \
	K10, K11, K12, K13, K14, K15, K16, K17, K18, \
	               K23,      K25, K26, K27, K28  \
) { \
	{ KC_NO, K01,   KC_NO, KC_NO, KC_NO, K05,   KC_NO, K07,   K08 }, \
	{ K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18 }, \
	{ KC_NO, KC_NO, KC_NO, K23,   KC_NO, K25,   K26,   K27,   K28 }  \
}

#endif