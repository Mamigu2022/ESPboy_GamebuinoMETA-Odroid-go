///////////////
// display defines
///////////////


//UNCOMMENT DESIRED DISPLAY MODE here !
//=====================================
#define DISPLAY_MODE DISPLAY_MODE_RGB565
//#define DISPLAY_MODE DISPLAY_MODE_INDEX
//#define DISPLAY_MODE DISPLAY_MODE_INDEX_HALFRES
//#define DISPLAY_MODE DISPLAY_MODE_INDEX_128x128

#ifndef DISPLAY_MODE
  #error DISPLAY MODE UNDEFINED!
#endif

#define DISPLAY_DEFAULT_BACKGROUND_COLOR Color::black
#define DISPLAY_DEFAULT_COLOR Color::white
#define DEFAULT_FONT_SIZE 1 //should depend on resolution and internal game design


///////////////
// save defines
///////////////
#define CHECKBYTES "1234"
#define SAVEFILE_NAME "/oublie.cfg"  //set config file name before compile to avoid names collisions 
#define USE_SDFAT 1
#define SAVECONF_DEFAULT_BLOBSIZE 32
#define SAVEBLOCK_NUM 64


///////////////
// sound defines
///////////////
#define SOUND_GAINFACTOR 4  //4 is a standart GAMEBUINO META gain fator to play FX sounds
#define SOUND_SETZERO 0 //no zero alignment is provided in standard GAMEBUINO META but sometimes wav sounds better with it
#define SOUND_CHANNELS 3
#define SOUND_FREQ 24000
#define SOUND_BUFFERSIZE (2048 * SOUND_FREQ / 24000)
#define SOUND_ENABLE_FX 1
#define SOUND_FX_BUFFERSIZE (2048 * SOUND_FREQ / 24000)


///////////////
// language defines
///////////////
#define LANGUAGE_DEFAULT_SIZE 0

///////////////
// Fault Handler defines
///////////////
#define HARDFAULT_DEBUG_HANDLER 0

///////////////
// GUI defines
///////////////
#define GUI_ENABLE_POPUP 1


/*
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

#ifndef DEFAULT_FONT_SIZE
  #error DEFAULT_FONT_SIZE UNDEFINED!
#endif
*/
