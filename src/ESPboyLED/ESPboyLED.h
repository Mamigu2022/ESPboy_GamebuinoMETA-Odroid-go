/*
ESPboy LED class
for www.ESPboy.com project by RomanS
*/
#pragma once

#include <Arduino.h>
//#include <Adafruit_MCP23017.h> //to control LED lock

#ifndef ESPboy_LED
#define ESPboy_LED

#define LEDPIN 2
#define LEDLOCK 4

class ESPboyLED{
private:
  //Adafruit_MCP23017 *mcp; 
  uint8_t LEDr, LEDg, LEDb, LEDflagOnOff;
  void ledset(uint8_t rled, uint8_t gled, uint8_t bled);
  
public: 
  void begin();
  void off();
  void on();
  uint8_t getState();
  
  void setRGB (uint8_t red, uint8_t green, uint8_t blue);
  void setR (uint8_t red);
  void setG (uint8_t green);
  void setB (uint8_t blue);
  
  uint32_t getRGB();
  uint8_t getR();
  uint8_t getG();
  uint8_t getB();
};  

#endif
