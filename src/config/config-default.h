///////////////
// display defines
///////////////

//!!!!!!!!!!!!!
//UNCOMMENT DISPLAY MODE in config-default.h file in your ARDUINO IDE ESPboy_GamebuinoMeta lib! 

#ifndef DISPLAY_MODE
//#define DISPLAY_MODE DISPLAY_MODE_RGB565
#define DISPLAY_MODE DISPLAY_MODE_INDEX
//#define DISPLAY_MODE DISPLAY_MODE_INDEX_HALFRES
//#define DISPLAY_MODE DISPLAY_MODE_INDEX_128x128
#endif

#ifndef DISPLAY_MODE
#error DISPLAY MODE UNDEFINED!
#endif

#ifndef DISPLAY_DEFAULT_BACKGROUND_COLOR
#define DISPLAY_DEFAULT_BACKGROUND_COLOR Color::black
#endif

#ifndef DISPLAY_DEFAULT_COLOR
#define DISPLAY_DEFAULT_COLOR Color::white
#endif

#define DEFAULT_FONT_SIZE 1


/*
#ifndef DEFAULT_FONT_SIZE
   #if DISPLAY_MODE == DISPLAY_MODE_INDEX
     #define DEFAULT_FONT_SIZE 2
   #endif
   #if DISPLAY_MODE == DISPLAY_MODE_INDEX_128x128
     #define DEFAULT_FONT_SIZE 2
   #endif
   #if DISPLAY_MODE == DISPLAY_MODE_INDEX_HALFRES
     #define DEFAULT_FONT_SIZE 1
   #endif
   #if DISPLAY_MODE == DISPLAY_MODE_RGB565
     #define DEFAULT_FONT_SIZE 1
   #endif
#endif
*/

#ifndef DEFAULT_FONT_SIZE
#error DEFAULT_FONT_SIZE UNDEFINED!
#endif


///////////////
// save defines
///////////////

//#ifndef USE_LITTLEFS
//#define USE_LITTLEFS 1
//#endif

#ifndef SAVEBLOCK_NUM
#define SAVEBLOCK_NUM 40
#endif


///////////////
// sound defines
///////////////

#ifndef SOUND_CHANNELS
#define SOUND_CHANNELS 4
#endif

#ifndef SOUND_FREQ
#define SOUND_FREQ 44100
#endif

#ifndef SOUND_BUFFERSIZE
#define SOUND_BUFFERSIZE (2048 * SOUND_FREQ / 44100)
#endif

#ifndef SOUND_ENABLE_FX
#define SOUND_ENABLE_FX 1
#endif

#ifndef SOUND_FX_BUFFERSIZE
#define SOUND_FX_BUFFERSIZE (2048 * SOUND_FREQ / 44100)
#endif


///////////////
// language defines
///////////////

#ifndef LANGUAGE_DEFAULT_SIZE
#define LANGUAGE_DEFAULT_SIZE 0
#endif

///////////////
// Fault Handler defines
///////////////

#ifndef HARDFAULT_DEBUG_HANDLER
#define HARDFAULT_DEBUG_HANDLER 0
#endif

///////////////
// GUI defines
///////////////

#ifndef GUI_ENABLE_POPUP
#define GUI_ENABLE_POPUP 1
#endif
