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
extern void initCredits();

const char STRING_PLAY[] PROGMEM = "PLAY";
const char STRING_CONTINUE[] PROGMEM = "CONTINUE:LVL ";
const char STRING_NEW_GAME[] PROGMEM = "NEW GAME";
const char STRING_SETTINGS[] PROGMEM = "SETTINGS";

#ifdef ARDUBOY_2
const char STRING_SOUND_ON[] PROGMEM = "SOUND:ON";
const char STRING_SOUND_OFF[] PROGMEM = "SOUND:OFF";
#endif 
   
#ifdef GAMEBUINO_META
const char STRING_SOUND_ON[] PROGMEM = "FX SOUND:TONE";
const char STRING_SOUND_OFF[] PROGMEM = "FX SOUND:WAV";
#endif

const char STRING_AUTOSAVE_ON[] PROGMEM = "AUTOSAVE:ON";
const char STRING_AUTOSAVE_OFF[] PROGMEM = "AUTOSAVE:OFF";
const char STRING_20_FPS[] PROGMEM = "FPS:20";
const char STRING_30_FPS[] PROGMEM = "FPS:30";
const char STRING_60_FPS[] PROGMEM = "FPS:60";
const char STRING_SHOW_FPS_ON[] PROGMEM = "SHOW FPS:ON";
const char STRING_SHOW_FPS_OFF[] PROGMEM = "SHOW FPS:OFF";
const char STRING_5_LIVES[] PROGMEM = "LIVES:5";
const char STRING_UNLIMITED_LIVES[] PROGMEM = "LIVES:UNLIMITED";
const char STRING_DIFFICULTY_VERY_EASY[] PROGMEM = "DIFFICULTY:V.EASY";
const char STRING_DIFFICULTY_EASY[] PROGMEM = "DIFFICULTY:EASY";
const char STRING_DIFFICULTY_NORMAL[] PROGMEM = "DIFFICULTY:NORMAL";
const char STRING_DIFFICULTY_HARD[] PROGMEM = "DIFFICULTY:HARD";
const char STRING_DIFFICULTY_VERY_HARD[] PROGMEM = "DIFFICULTY:V.HARD";
const char STRING_DIFFICULTY_ULTRA[] PROGMEM = "DIFFICULTY:ULTRA";
const char STRING_HELP[] PROGMEM = "HELP";
const char STRING_CREDITS[] PROGMEM = "CREDITS";


#define MENU_PLAY         0
#define MENU_NEW_GAME     1
#define MENU_SETTINGS     2
#define MENU_HELP         3
#define MENU_CREDITS      4

#define MENU_ITEMS  5


#define SETTINGS_SETTINGS   0
#define SETTINGS_DIFFICULTY 1
#define SETTINGS_SOUND      2
#define SETTINGS_IMMORTAL   3
#define SETTINGS_AUTOSAVE   4
#define SETTINGS_FPS   5
#define SETTINGS_SHOW_FPS   6

#define SETTINGS_ITEMS  7

uint8_t menuDisplayedOption;
uint8_t settingsDisplayedOption;

uint8_t frame;

void playMenu() {


  // Paint centered logo
  helper.drawBitmap((WIDTH - LOGO_WIDTH) / 2, (HEIGHT - LOGO_HEIGHT) / 2 - ADJUST_OFFSET_Y, LOGO_BITMAP, LOGO_WIDTH, LOGO_HEIGHT, 0);

  // Paint ball
  helper.drawMaskedBitmap(BALL_STOPS_X, (HEIGHT - LOGO_HEIGHT) / 2 - ADJUST_OFFSET_Y - SMALL_BALL_SIZE - 2 ,
                          (frame == 0 || frame == 1) ? SMALL_BALL_BITMAP : SMALL_BALL_ROT_BITMAP,
                          SMALL_BALL_MASK_BITMAP, SMALL_BALL_SIZE, SMALL_BALL_SIZE, (frame == 0 || frame == 2) ? 0 : MIRROR);

  // Rotate ball
  if (helper.everyXFrames(3)) {
    frame = (frame + 1) % 4;
  }

  const char* displayedOptionString =
    menuDisplayedOption == MENU_PLAY ? (game == GAME_STOP ? STRING_PLAY : STRING_CONTINUE) :
    menuDisplayedOption == MENU_NEW_GAME ? STRING_NEW_GAME :
    menuDisplayedOption == MENU_SETTINGS ?
    settingsDisplayedOption == SETTINGS_SOUND ? (sound == true ? STRING_SOUND_ON : STRING_SOUND_OFF) :
    settingsDisplayedOption == SETTINGS_FPS ? (frameDrop == FPS_60 ? STRING_60_FPS : frameDrop == FPS_30? STRING_30_FPS : STRING_20_FPS) :
    settingsDisplayedOption == SETTINGS_IMMORTAL ? (immortal ? STRING_UNLIMITED_LIVES : STRING_5_LIVES) :
    settingsDisplayedOption == SETTINGS_AUTOSAVE ? (autosave ? STRING_AUTOSAVE_ON : STRING_AUTOSAVE_OFF) :
    settingsDisplayedOption == SETTINGS_SHOW_FPS ? (showFPS ? STRING_SHOW_FPS_ON : STRING_SHOW_FPS_OFF) :
    settingsDisplayedOption == SETTINGS_DIFFICULTY ?
    (difficulty == DIFFICULTY_VERY_EASY ? STRING_DIFFICULTY_VERY_EASY :
     difficulty == DIFFICULTY_EASY ? STRING_DIFFICULTY_EASY :
     difficulty == DIFFICULTY_NORMAL ? STRING_DIFFICULTY_NORMAL :
     difficulty == DIFFICULTY_HARD ? STRING_DIFFICULTY_HARD :
     difficulty == DIFFICULTY_VERY_HARD ? STRING_DIFFICULTY_VERY_HARD : STRING_DIFFICULTY_ULTRA) :
    STRING_SETTINGS :
    menuDisplayedOption == MENU_HELP ? STRING_HELP : STRING_CREDITS;

  uint8_t stringLength = strlen_P(displayedOptionString);

  boolean isContinueString = menuDisplayedOption == MENU_PLAY && game == GAME_RUNNING;

  uint8_t extraChars = isContinueString ? getNumberOfChars(level + 1) : 0;

  const unsigned char OFFSET_Y = HEIGHT/2 + 12;

  uint8_t offsetX = (WIDTH - (stringLength + extraChars)  * 6 - 1) / 2;

  helper.print(displayedOptionString, offsetX, OFFSET_Y);

  if (menuDisplayedOption == MENU_PLAY && game == GAME_RUNNING) {
    helper.print((level + 1));
  }

  // Dynamic arrows position
  unsigned char lateral_arrows_offset = 10;

  if (stringLength + extraChars > 15) lateral_arrows_offset = 4;

  helper.drawBitmap(offsetX - RIGHT_ARROW_WIDTH - lateral_arrows_offset, OFFSET_Y - 1, RIGHT_ARROW_BITMAP, RIGHT_ARROW_WIDTH, RIGHT_ARROW_HEIGHT, MIRROR);
  helper.drawBitmap(offsetX + (stringLength + extraChars) * 6 - 1 + lateral_arrows_offset, OFFSET_Y - 1, RIGHT_ARROW_BITMAP, RIGHT_ARROW_WIDTH, RIGHT_ARROW_HEIGHT, 0);

  if (menuDisplayedOption == MENU_SETTINGS) {
    helper.drawBitmap((WIDTH - DOWN_ARROW_WIDTH) / 2, /*HEIGHT - DOWN_ARROW_HEIGHT*/OFFSET_Y + 12 , DOWN_ARROW_BITMAP, DOWN_ARROW_WIDTH, DOWN_ARROW_HEIGHT, 0);
  }

  helper.print(STRING_GAME_VERSION, WIDTH - 24, HEIGHT - 8);

#ifdef ARDUBOY_2
  if (helper.justPressed(RIGHT_BUTTON)) {
#endif    
#ifdef GAMEBUINO_META
  if (gb.buttons.pressed(BUTTON_RIGHT)) {
#endif     
    settingsDisplayedOption = SETTINGS_SETTINGS;
    // New game only visible if game running
    if (game == GAME_STOP && menuDisplayedOption == (MENU_NEW_GAME - 1)) menuDisplayedOption++;
    //Reset settings
    settingsDisplayedOption = SETTINGS_SETTINGS;
    menuDisplayedOption = (menuDisplayedOption + 1) % MENU_ITEMS;
#ifdef ARDUBOY_2
  } else if (helper.justPressed(LEFT_BUTTON)) {
#endif    
#ifdef GAMEBUINO_META
  } else if (gb.buttons.pressed(BUTTON_LEFT)) {
#endif    
    // New game only visible if game running
    if (game == GAME_STOP && menuDisplayedOption == (MENU_NEW_GAME + 1)) menuDisplayedOption--;
    //Reset settings
    settingsDisplayedOption = SETTINGS_SETTINGS;
    menuDisplayedOption = (menuDisplayedOption + MENU_ITEMS - 1) % MENU_ITEMS;
#ifdef ARDUBOY_2
  } else if (helper.justPressed(DOWN_BUTTON)) {
#endif    
#ifdef GAMEBUINO_META
  } else if (gb.buttons.pressed(BUTTON_DOWN)) {
#endif    
    if (menuDisplayedOption == MENU_SETTINGS) settingsDisplayedOption = (settingsDisplayedOption + 1) % SETTINGS_ITEMS;

#ifdef ARDUBOY_2
    // Also include up opcion (even not draw)
  } else if (helper.justPressed(UP_BUTTON)) {
#endif    
#ifdef GAMEBUINO_META
  } else if (gb.buttons.pressed(BUTTON_UP)) {
#endif
    if (menuDisplayedOption == MENU_SETTINGS) settingsDisplayedOption = (settingsDisplayedOption + SETTINGS_ITEMS - 1 ) % SETTINGS_ITEMS;

#ifdef ARDUBOY_2
  } else if (helper.justPressed(A_BUTTON)) {
#endif
#ifdef GAMEBUINO_META
    } else if (gb.buttons.pressed(BUTTON_A)) {
#endif
    switch (menuDisplayedOption) {

      case MENU_PLAY:
        if (game == GAME_STOP) {
          resetGame();
        }

        if (levelLoadedFromEEPROM) {
          levelLoadedFromEEPROM = false;
          initBalls();
        }

        configGame();
        mode = MODE_GAME;
        break;

      case MENU_NEW_GAME:
        resetGame();
        configGame();
        mode = MODE_GAME;
        break;

      case MENU_SETTINGS:

        switch (settingsDisplayedOption) {

          case SETTINGS_SETTINGS:
            break;

          case SETTINGS_DIFFICULTY:
            difficulty = (difficulty + 1) % 6;
            write(EEPROM_DIFFICULTY, difficulty);
            break;

          case SETTINGS_SOUND:
            sound = !sound;
            write(EEPROM_SOUND_ON, sound);
            break;

          case SETTINGS_IMMORTAL:
            immortal = !immortal;
            write(EEPROM_IMMORTAL, immortal);
            break;

          case SETTINGS_AUTOSAVE:
            autosave = !autosave;
            write(EEPROM_AUTOSAVE, autosave);
            // Reset last save
            write(EEPROM_LAST_LEVEL, 0);
            break;

          case SETTINGS_FPS:
            //Change between 1,2,3
            #ifdef ARDUBOY_2
          frameDrop = 1 + (frameDrop + 1) % 3;
          #endif
           //Change between 2,3
          #ifdef GAMEBUINO_META
            frameDrop = 2 + (frameDrop + 1) % 2;
            #endif
            write(EEPROM_FPS, frameDrop);
            break;

          case SETTINGS_SHOW_FPS:
            showFPS = !showFPS;
            write(EEPROM_SHOW_FPS, showFPS);
            break;
        }

        break;

      case MENU_CREDITS:
        initCredits();
        mode = MODE_CREDITS;
        break;

      case MENU_HELP:
        mode = MODE_HELP;
        break;
   
     }
  }
}

void setMenuMode() {
  helper.setFrameRate(15);
  mode = MODE_MENU;
  menuDisplayedOption = MENU_PLAY;
}
