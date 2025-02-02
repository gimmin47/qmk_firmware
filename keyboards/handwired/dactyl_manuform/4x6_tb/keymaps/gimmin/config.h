
#pragma once

#define EE_HANDS

#define PMW3389_CS_PIN F7
#define POINTING_DEVICE_INVERT_Y
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_LAYER_STATE_ENABLE

#define TAPPING_TOGGLE 1
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
//#define RETRO_TAPPING
#define TAPPING_FORCE_HOLD

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#define NO_ACTION_ONESHOT
#define LAYER_STATE_8BIT

#define USER_CPI 1600
#define SNIPE_CPI 500
#define MIN_CPI 100
#define MAX_CPI 16000
#define CPI_DELTA 100
#define FAST_TAPPING_TERM 100
