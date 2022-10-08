/*
   Copyright (C) 2016 Ignacio Vina (@igvina)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#pragma once


//#define ARDUBOY_2
#define GAMEBUINO_META

//#define DEMO_MODE


#ifdef ARDUBOY_2
#include <Arduboy2.h>
#endif

#ifdef GAMEBUINO_META
#include <Gamebuino-Meta.h>
extern Gamebuino gb;
#define WIDTH 128
#define HEIGHT 128
extern const byte font5x7[];
#endif


#define MIRROR 1

const int NOISE_SIZE = 64;

class Customlib
{
  public:
#ifdef ARDUBOY_2
    Customlib(Arduboy2 &arduboy);
#endif

#ifdef GAMEBUINO_META
    Customlib();
#endif

    /// Poll the hardware buttons and tracks state over time
    /**
      This must be called before any of the other button member functions.  It should be called either in your main `loop()` or as part of the frame system (called pre-frame).
    */
    void poll();
    void display();
    void setFrameRate(int rate);
    boolean pressed(uint8_t buttons);
    boolean notPressed(uint8_t buttons);
    boolean justPressed(uint8_t button);
    // x, y -> int8_t (-128 to 127), x = 128 will fail, but we should check offscreen
    // w, h -> uint8_t (0-255) screen (128,64) and always positive
#ifdef ARDUBOY_2
    void drawMaskedBitmap(int8_t x, int8_t y, const uint8_t *bitmap, const uint8_t *mask, uint8_t w, uint8_t h, uint8_t mirror);
    void drawBitmap(int8_t x, int8_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t maxW, uint8_t mirror);
    void drawBitmap(int8_t x, int8_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t mirror);
#endif
#ifdef GAMEBUINO_META
    void drawMaskedBitmap(int16_t x, int16_t y, Image *bitmap, const uint8_t *mask, int16_t w, int16_t h, uint8_t mirror);
    void drawBitmap(int16_t x, int16_t y, Image *bitmap, int16_t w, int16_t h, uint8_t maxW, uint8_t mirror);
    void drawBitmap(int16_t x, int16_t y, Image *bitmap, int16_t w, int16_t h, uint8_t mirror);    
#endif 
    void drawNoiseCircle(uint8_t x0, uint8_t y0, uint8_t r);
    void print(uint8_t number);
    void print(const char* text, uint8_t x, uint8_t y);
    void addNoise(int noise);
    void createNoiseArray(int noise);
    void mirrorScreen();
    bool everyXFrames(uint8_t frames);
    void invert(boolean inv);

  private:
    uint8_t currentButtonState = 0;
    uint8_t previousButtonState = 0;
#ifdef ARDUBOY_2
    Arduboy2 *arduboy;
#endif

    unsigned char *sBuffer;
#ifdef ARDUBOY_2
    uint8_t noiseLevel = 0;
    //TODO Test performance from preloaded noise on PROGMEM
    uint8_t noiseArray[NOISE_SIZE];
#endif
#ifdef GAMEBUINO_META   
    int noiseLevel = 0;
    //TODO Test performance from preloaded noise on PROGMEM
    int noiseArray[NOISE_SIZE];
    
#endif
};
