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

#define DISPLAY_MODE DISPLAY_MODE_INDEX_128x128

#include "globals.h"
#include "Customlib.h"
#include "balls.h"
#include "extra.h"
#include "config.h"
#include "help.h"
#include "credits.h"
#include "gifts.h"
#include "backgrounds.h"
#include "levels.h"
#include "game.h"
#include "menu.h"
#include "utils.h"
#include "logo.h"


#ifdef ARDUBOY_2
//  #include <EEPROM.h>
  #define FPS_DEF FPS_60
#endif

#ifdef GAMEBUINO_META
  #define FPS_DEF FPS_30
#endif


// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  //Serial.begin(115200);
  
#ifdef ARDUBOY_2
  arduboy.boot();

  //Fake delay, use own logo
  arduboy.clear();
  helper.display();
  customDelay(500);
  arduboy.initRandomSeed();
#endif

#ifdef GAMEBUINO_META
  // initialize the Gamebuino object
  gb.begin();
  //gb.display.init(160, 128, ColorMode::index);
#endif

  //Load values, continue level, lives...
  setupEEPROM();
  setLogoMode();
}


void loop() {
#ifdef ARDUBOY_2
  if (!(arduboy.nextFrame()))
    return;
  // To get just pressed keys
  helper.poll();

  // first we clear our screen to black
  arduboy.clear();
#endif

#ifdef GAMEBUINO_META
  // wait until the gamebuino is ready to update at stable 25 FPS
  // this also updates sounds, button presses... everything!
  while(!gb.update());
  
  // clear the previous screen
  gb.display.clear();
#endif

  if (mode == MODE_LOGO) {
    playLogo();
  } else if (mode == MODE_MENU) {
    playMenu();
  } else if (mode == MODE_HELP) {
    playHelp();
  } else if (mode == MODE_CREDITS) {
    playCredits();
  } else playGame();
  
#ifdef ARDUBOY_2
  // Paint screen (not needed on game mode)
  if (mode != MODE_GAME) helper.display();
#endif

}


void setupEEPROM() {

  //Check if mem is not from game -> reset mem with default values
  if (read(EEPROM_GAME_IDU) != (GAME_ID + GAME_VERSION)) {
    write(EEPROM_GAME_IDU, (GAME_ID + GAME_VERSION));
    write(EEPROM_LAST_LEVEL, 0);
    write(EEPROM_LAST_LEVEL, 0);
    write(EEPROM_DIFFICULTY, DIFFICULTY_NORMAL);
    write(EEPROM_SOUND_ON, false);
    write(EEPROM_IMMORTAL, false);
    write(EEPROM_AUTOSAVE, true);
    write(EEPROM_FPS, FPS_DEF);
    write(EEPROM_SHOW_FPS, false);
  }

  level = read(EEPROM_LAST_LEVEL);

  if (level > 0) {
    // Do better to avoid this hack on start of loading game
    lives = read(EEPROM_LAST_LIVES);
    levelLoadedFromEEPROM = true;
    game = GAME_RUNNING;
  } else {
    levelLoadedFromEEPROM = false;
  }

  difficulty = read(EEPROM_DIFFICULTY);
  immortal = read(EEPROM_IMMORTAL);
  autosave = read(EEPROM_AUTOSAVE);
  sound = read(EEPROM_SOUND_ON);
  frameDrop = read(EEPROM_FPS);

#ifdef DEMO_MODE
  showFPS = true;
#else
  showFPS = read(EEPROM_SHOW_FPS);
#endif
}
