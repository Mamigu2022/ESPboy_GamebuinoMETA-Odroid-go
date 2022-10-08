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

#include "globals.h"

extern const int ADJUST_OFFSET_Y;
extern const int BALL_STOPS_X;
extern void setMenuMode();

// Simulate old TV
const unsigned int FPS = 24;

unsigned int noise;
const unsigned int NOISE_LIMIT = 256;

void playCredits() {

  helper.drawBitmap((WIDTH - LOGO_WIDTH) / 2, (HEIGHT - LOGO_HEIGHT) / 2, LOGO_BITMAP, LOGO_WIDTH, LOGO_HEIGHT, 0);
  // Paint ball
  helper.drawMaskedBitmap(BALL_STOPS_X, (HEIGHT - LOGO_HEIGHT) / 2 - SMALL_BALL_SIZE - 2,
                          SMALL_BALL_BITMAP ,
                          SMALL_BALL_MASK_BITMAP, SMALL_BALL_SIZE, SMALL_BALL_SIZE,  0);
#ifdef ARDUBOY_2  
                          
  helper.print(STRING_BY_IGVINA, 35, 52);
#endif

#ifdef GAMEBUINO_META  
                          
  helper.print(STRING_BY_IGVINA, 52, 98);
#endif

  helper.print(STRING_GAME_VERSION, WIDTH - 24, HEIGHT - 8);

  if (helper.everyXFrames(FPS / 2) && noise < NOISE_LIMIT) {
    noise *= 2;
  }
  if (noise < NOISE_LIMIT){
  helper.addNoise(noise == 1 ? 2 : noise);
  }

  // Go to main menu if any key is pressed
#ifdef ARDUBOY_2  
  if (helper.justPressed(0xFF)) {
#endif

#ifdef GAMEBUINO_META  
  if (gb.buttons.pressed(BUTTON_A) || gb.buttons.pressed(BUTTON_B)) {
#endif  
    setMenuMode();
  }
}

void initCredits() {
  noise = 1;
  helper.createNoiseArray(noise); 
  helper.setFrameRate(FPS);

}

