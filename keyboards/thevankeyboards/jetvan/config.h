#ifndef CONFIG_H
#define CONFIG_H
#include "config_common.h"

#define VENDOR_ID     0xFEAE
#define PRODUCT_ID    0x8858
#define DEVICE_VER    0x0001
#define MANUFACTURER  evangs
#define PRODUCT       JetVan
#define DESCRIPTION   JetVan 40%

#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { D7, B5, F7, D4 }
#define MATRIX_COL_PINS { D2, D3, D5, D6, B4, B6, F6, F5, F4, F1, F0, B3 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_LEVELS 1
#define BACKLIGHT_PIN B7

#define DEBOUNCE 5
#define TAPPING_TERM 150

#define USB_MAX_POWER_CONSUMPTION 100
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
//#define PERMISSIVE_HOLD
#define RGB_DI_PIN D0
#define RGBLED_NUM 10
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#endif
