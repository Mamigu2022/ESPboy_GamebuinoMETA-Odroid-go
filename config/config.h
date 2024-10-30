#ifndef _CONFIG_GAMEBUINO_META_
#define _CONFIG_GAMEBUINO_META_

#include "config-default.h"
#include <Arduino.h>

#define SAVETYPE_INT 0
#define SAVETYPE_BLOB 1

#define DISPLAY_MODE_RGB565 0
#define DISPLAY_MODE_INDEX 1
#define DISPLAY_MODE_INDEX_HALFRES 2
#define DISPLAY_MODE_INDEX_128x128 3

#ifndef DISPLAY_CONSTRUCTOR
#if DISPLAY_MODE == DISPLAY_MODE_RGB565
#define DISPLAY_CONSTRUCTOR Image(160, 128, ColorMode::rgb565)
#endif
#if DISPLAY_MODE == DISPLAY_MODE_INDEX
#define DISPLAY_CONSTRUCTOR Image(160, 128, ColorMode::index)
#endif
#if DISPLAY_MODE == DISPLAY_MODE_INDEX_HALFRES
#define DISPLAY_CONSTRUCTOR Image(80, 64, ColorMode::index)
#endif
#if DISPLAY_MODE == DISPLAY_MODE_INDEX_128x128
#define DISPLAY_CONSTRUCTOR Image(128, 128, ColorMode::index)
#endif
#endif // DISPLAY_CONSTRUCTOR

#ifndef DISPLAY_CONSTRUCTOR
#error "Define correct DISPLAY MODE of your skech in Arduino IDE ESPboy_GamebuinoMETA libraries folder: [..ESPboy_GamebuinoMETA/src/config/config-default.h]"
#endif

#define SYSTEM_DEFAULT_FONT_SIZE DEFAULT_FONT_SIZE

#include <stdlib.h>
#include <malloc.h>
#define gb_malloc(x) malloc(x)
#define gb_free(x) free(x)
#define gb_memalign(x, y) memalign(x, y)


#ifndef constrain
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#endif

#ifndef abs
#define abs(x) ((x)>0?(x):-(x))
#endif

#ifndef max_
#define max_(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef min_
#define min_(x,y) ((x)<(y)?(x):(y))
#endif


#define SETTING_VOLUME 3
#define SETTING_VOLUME_MUTE 0
#define SETTING_DEFAULTNAME 2
#define SETTING_LANGUAGE 3
#define SETTING_SETUP 5


#endif // _CONFIG_GAMEBUINO_META_
