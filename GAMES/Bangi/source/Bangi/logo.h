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

#define STATE_ANIMATING_LOGO    0
#define STATE_BOUNCING_BALL     1
#define STATE_ADJUSTING_LOGO    2

uint8_t logoState;


int logoOffsetY;
const int ADJUST_OFFSET_Y = 9;

int logoPosX;

int ballPosX;
int ballPosY;

int ballSpeedX;
int ballSpeedY;

extern void setMenuMode();

//Ready to be visible

const int BALL_START_Y = - SMALL_BALL_SIZE;

const int BALL_GROUND_Y = (HEIGHT + LOGO_HEIGHT) / 2  - SMALL_BALL_SIZE ;

#ifdef ARDUBOY_2
const uint8_t LOGO_FPS = 60;
const uint8_t LOGO_SPEED_X = 1;
const uint8_t LOGO_SPEED_Y = 1;
const uint8_t BALL_SPEED = 2;
const int BALL_START_X = 18;
#endif

#ifdef GAMEBUINO_META
const uint8_t LOGO_FPS = 30;
const uint8_t LOGO_SPEED_X = 2;
const uint8_t LOGO_SPEED_Y = 1;
const uint8_t BALL_SPEED = 4;
const int BALL_START_X = 9;
#endif

const int BALL_STOPS_X = (WIDTH + LOGO_WIDTH)/2 - 4;

void playLogo() {

  // Paint cropped logo
  helper.drawBitmap((WIDTH - LOGO_WIDTH) / 2, (HEIGHT - LOGO_HEIGHT) / 2 - logoOffsetY, LOGO_BITMAP, LOGO_WIDTH, LOGO_HEIGHT, logoPosX, 0);
  
  // Paint ball
  helper.drawMaskedBitmap(ballPosX / SCREEN_MAGNIFICATION, ballPosY / SCREEN_MAGNIFICATION - logoOffsetY,
                          SMALL_BALL_BITMAP ,
                          SMALL_BALL_MASK_BITMAP, SMALL_BALL_SIZE, SMALL_BALL_SIZE,  0);
                
  if (logoState == STATE_ANIMATING_LOGO) {
    if (logoPosX <= LOGO_WIDTH) {
      logoPosX += LOGO_SPEED_X;
    } else {
      logoState = STATE_BOUNCING_BALL;
    }
  } else if (logoState == STATE_BOUNCING_BALL) {

    //NORMAL SPEED AT 60fps-> loopTimes = 2
    for (int j = 0; j < BALL_SPEED ; j++) {
      
      // Animate ball
      ballPosX += ballSpeedX;

      ballSpeedY += GRAVITY_ACCEL;
      ballPosY += ballSpeedY;

      // Check ground reboud
      if (ballPosY / SCREEN_MAGNIFICATION > BALL_GROUND_Y) {
        ballPosY = BALL_GROUND_Y  * SCREEN_MAGNIFICATION;
        ballSpeedY = - BALL_SMALL_SPEED_Y ;
      }
    }
    
    if (ballPosX / SCREEN_MAGNIFICATION > BALL_STOPS_X) {
      ballPosX = BALL_STOPS_X * SCREEN_MAGNIFICATION;
      //ballPosY = ADJUST_OFFSET_Y * SCREEN_MAGNIFICATION;
      logoState = STATE_ADJUSTING_LOGO;
    }
//TODO META
  }else if (logoState == STATE_ADJUSTING_LOGO && helper.everyXFrames(2)) {
    logoOffsetY += LOGO_SPEED_Y;
    if (logoOffsetY >= ADJUST_OFFSET_Y) {
      logoOffsetY = ADJUST_OFFSET_Y;
#ifdef DEMO_MODE     
  resetGame();
  configGame();
  mode = MODE_GAME;
#else
  setMenuMode();
#endif     
    }
  }
}

void setLogoMode() {
#ifdef ARDUBOY_2  
  arduboy.clear();
  helper.display();
#endif
  customDelay(300);
  helper.setFrameRate(LOGO_FPS);
  mode = MODE_LOGO;
  logoPosX = 0;
  ballPosX = BALL_START_X * SCREEN_MAGNIFICATION;
  ballPosY = BALL_START_Y * SCREEN_MAGNIFICATION;
  ballSpeedX = BALL_SMALL_SPEED_X;
  ballSpeedY = 0;
  logoOffsetY = 0;
  logoState = STATE_ANIMATING_LOGO;
}
