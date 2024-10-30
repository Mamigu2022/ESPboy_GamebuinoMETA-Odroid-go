/*
Lights class for ported Gamebuino META lib
for www.ESPboy.com project by RomanS
*/

#include <Arduino.h>
#include "../ESPboyLED.h"
#include "../../Gamebuino-Meta.h"

#ifndef Lghts
#define Lghts

class Lights{

private:
  ESPboyLED *LEDld;

public: 
  Lights (ESPboyLED *localLED);
  void clear();
  void fill(Gamebuino_Meta::Color clrSet);
  void setColor(Gamebuino_Meta::ColorIndex colorIndex);
  void setRGB(uint8_t r, uint8_t g, uint8_t b);
  void drawPixel(uint8_t x, uint8_t y, Gamebuino_Meta::Color clrSet);
  void drawPixel(uint8_t x, uint8_t y, const Gamebuino_Meta::ColorIndex clrSet);
};  

#endif
