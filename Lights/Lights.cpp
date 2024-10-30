/*
Lights class for ported Gamebuino META lib
for www.ESPboy.com project by RomanS
*/

#include "Lights.h"


Lights::Lights(ESPboyLED *localLED){
  LEDld = localLED;
};


void Lights::clear(){
  LEDld -> setRGB (0,0,0);
};


void Lights::fill(Gamebuino_Meta::Color clrSet){
  uint8_t r = ((uint16_t)clrSet >> 8) & 0xF8; r |= (r >> 5); r>>=2;
  uint8_t g = ((uint16_t)clrSet >> 3) & 0xFC; g |= (g >> 6); g>>=2;
  uint8_t b = ((uint16_t)clrSet << 3) & 0xF8; b |= (b >> 5); b>>=2;
  LEDld -> setRGB (r,g,b);
};


void Lights::drawPixel(uint8_t x, uint8_t y, Gamebuino_Meta::Color clrSet){
  if(!x && !y) this->fill (clrSet);
}


void Lights::drawPixel(uint8_t x, uint8_t y, const Gamebuino_Meta::ColorIndex clrSet){
  if(!x && !y) this->fill ((Gamebuino_Meta::Color) clrSet);
}

void Lights::setRGB(uint8_t r, uint8_t g, uint8_t b){
  LEDld -> setRGB (r,g,b);
}

void Lights::setColor(Gamebuino_Meta::ColorIndex colorIndex){
  fill(Gamebuino_Meta::Color{(Gamebuino_Meta::Color)colorIndex});
};