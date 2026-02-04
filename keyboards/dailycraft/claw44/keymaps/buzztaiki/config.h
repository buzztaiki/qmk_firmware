#pragma once

#define MASTER_LEFT

// https://docs.qmk.fm/tap_hold
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

#define TAPPING_TERM 175
#define QUICK_TAP_TERM TAPPING_TERM

// https://docs.qmk.fm/features/combo
#define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
#define COMBO_TERM_PER_COMBO
