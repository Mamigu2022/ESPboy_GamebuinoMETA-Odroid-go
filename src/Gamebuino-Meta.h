/*
This file is part of the Gamebuino-Meta library,
Copyright (c) Aadalie 2014, 2016-2017

Authors:
 - Aurelien Rodot
 - Sorunome
*/


#ifndef _GAMEBUINO_META_H_
#define	_GAMEBUINO_META_H_


#include <Arduino.h>
#include "config/config.h"
#include "utility/Graphics.h"
#include "utility/Buttons.h"
#include "utility/Sound.h"
#include "utility/Gui.h"
#include "utility/Collide.h"

#include "utility/Display-ST7735.h"
#include "utility/Image.h"
#include "utility/Language.h"
#include "utility/Save.h"
#include "utility/Lights.h"

#include "utility/ESPboyLED.h"
#include "utility/ESPboyLogo.h"

//#include <Adafruit_MCP23017.h> 
//#include <Adafruit_MCP4725.h>
//#include <ESP8266WiFi.h> 

#if USE_LITTLEFS
#include "LittleFS.h"
#endif

//#include "utility/ESPboyLib/ESPboyOTA2.h"
//#include "utility/ESPboyLib/ESPboyTerminalGUI.h"

namespace Gamebuino_Meta {

#define PAD_LEFT        0x01
#define PAD_UP          0x02
#define PAD_DOWN        0x04
#define PAD_RIGHT       0x08
#define PAD_ACT         0x10
#define PAD_ESC         0x20
#define PAD_LFT         0x40
#define PAD_RGT         0x80
#define PAD_ANY         0xff

#define MCP23017address 0 
#define MCP4725address  0x60
#define CSTFTPIN        8 


#define wrap(i, imax) ((imax+i)%(imax))

class Gamebuino {
public:
	Display_ST7735 tft;
    Gui gui;
    //Adafruit_MCP23017 mcp;
    //Adafruit_MCP4725 dac;
    ESPboyLED myLED;
    Lights lights = Lights(&myLED);
	Buttons buttons;
	Sound sound;
	Save save;
	Language language;
	Collide collide;
	//ESPboyTerminalGUI *terminalGUIobj = NULL;
    //ESPboyOTA2 *OTA2obj = NULL;
    Image display = DISPLAY_CONSTRUCTOR;
    
    Gamebuino();
    
    uint8_t getKeys();
    bool frameEndFlag;
	uint8_t getCpuLoad();
    uint8_t getTimePerFrame();
	uint16_t getFreeRam();
	uint32_t frameCount;
	uint32_t frameDurationMicros;
	uint32_t frameStartMicros;
    
    void getDefaultName(char* string);
	void begin();
	void startScreen();
	bool update();
	bool updateNoDisplay();
	void waitForUpdate();
	void updateDisplay();
	void setFrameRate(uint8_t fps);
	void pickRandomSeed();
	Gamebuino_Meta::Color createColor(uint8_t r, uint8_t g, uint8_t b);
	
    bool collidePointRect(int16_t x1, int16_t y1 ,int16_t x2 ,int16_t y2, int16_t w, int16_t h);  // deprecated. Use collide.pointRect() instead
	bool collideRectRect(int16_t x1, int16_t y1, int16_t w1, int16_t h1 ,int16_t x2 ,int16_t y2, int16_t w2, int16_t h2);  // deprecated. Use collide.rectRect() instead
	bool collideBitmapBitmap(int16_t x1, int16_t y1, const uint8_t* b1, int16_t x2, int16_t y2, const uint8_t* b2);
	
	void setScreenRotation(Rotation r);
	Rotation getScreenRotation();
    bool inited = false;
	
private:
    uint8_t timePerFrame;
	uint32_t nextFrameMillis;
	void drawLogo(Graphics& g, int8_t x, int8_t y, uint8_t scale);
	void drawESPboyLogo(Graphics& g);
	
	
	
};
} // namespace Gamebuino_Meta


using Gamebuino_Meta::Gamebuino;
extern Gamebuino gb;

#endif	// _GAMEBUINO_META_H_
