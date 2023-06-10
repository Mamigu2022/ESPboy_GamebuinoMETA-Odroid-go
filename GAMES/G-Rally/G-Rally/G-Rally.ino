#include <Gamebuino-Meta.h>
#include "assets/indexed.h"
#include "assets/maps.h"

#define GAMEMAKERS 0
#define TITLESCREEN 1
#define MENU 2
#define MAPSELECTION 3
#define CARSELECTION 4
#define GAME 5
#define GAMECHECK 6
#define REPLAY 7
#define GAMEOVER 8
#define WINNER 9

#define CREDITS 98
#define MENUPAUSE 99

#define SCREENHEIGHT 128
#define SCREENWIDTH 160

#ifndef _swap_int16_t
#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }
#endif

//###########################
//##### INFO Global #########
//###########################
typedef struct{
  int16_t gameStatus; 
  int16_t globalTimer;
  int16_t pause; //keep in memory what was the gameStatus before pause
  int16_t menuOption;
  int16_t menuPauseOption;
}GameInfo;
GameInfo game;

typedef struct{
  int16_t type; 
  int16_t pos;
  int16_t x;
  int16_t y;
  int16_t squareSize;
  int16_t previousX;
  int16_t previousY;
}CarInfo;
CarInfo car01;

typedef struct{
  int16_t x;
  int16_t y;
  bool isActive;
}CursorInfo;
CursorInfo cur;

typedef struct{
  int16_t x;
  int16_t y;
  int16_t pos;
}ReplayInfo;
ReplayInfo replay[300];
int replayCounter;

typedef struct{
  int16_t x;
  int16_t y;
  int16_t pos;
  String title;
  int16_t bestScore;
  int16_t palette;
  bool isNight;
}MapInfo;
MapInfo maps[100];
int mapSelected=0;
int amountOfMap=31;  //!\\ //!\\//!\\//!\\//!\\//!\\

typedef struct {
  int8_t weapon;
  int8_t bonus;
  int8_t playerDamage;
  int8_t music;
}SoundInfo;
SoundInfo sounds;

Color road;
Color speedKiller1;
Color speedKiller2;
Color handlingKiller1;
Color handlingKiller2;
Color instantDeath1;
Color instantDeath2;
Color checkpoint;
Color finish;

bool displayGrid = false;

//###########################
//##### Game Setup ##########
//###########################
void setup(){
  gb.begin();
  game_init();
  game_carInit();
  game_initMapInfos();
  gb.display.setPalette(PALETTE);
  gb.display.setFontSize(2);
}


//###########################
//##### Game Loop ###########
//###########################
void loop(){
    if(gb.update()){
      game_manageGlobalCounter();
      
      switch ( game.gameStatus )
      {
         //####################################
         case GAMEMAKERS:
            outputScreen_gamemakers();
            button_check(GAMEMAKERS);
            break;

         //#################################### 
         case TITLESCREEN:
            outputScreen_clear();
            outputScreen_title();
            button_check(TITLESCREEN);
            break;

         //#################################### 
         case CREDITS:
            outputScreen_clear();
            outputScreen_credits();
            button_check(CREDITS);
            break;

         //####################################  
         case MENU:
            outputScreen_clear();
            outputScreen_menu();
            button_check(MENU);
            break;
            
          //####################################  
         case CARSELECTION:
            outputScreen_clear();
            outputScreen_carSelection();
            button_check(CARSELECTION);
            break;    
                   
         //####################################  
         case MAPSELECTION:
            outputScreen_clear();
            outputScreen_mapSelection();
            button_check(MAPSELECTION);
            break;
            
         //####################################  
         case GAME:
            outputScreen_clear();
            outputScreen_map();
            outputScreen_night();
            outputScreen_grid();
            outputScreen_trajectory();
            outputScreen_car();
            outputScreen_cursor();
            button_check(GAME);
            break;

         //####################################  
         case GAMECHECK:
            game.gameStatus=GAME;
            car01.x=car01.x+car01.previousX+cur.x;
            car01.y=car01.y+car01.previousY+cur.y;
            car01.previousX=car01.previousX+cur.x;
            car01.previousY=car01.previousY+cur.y;
    
            game_resetCursor();
            game_recordReplay();
         
            outputScreen_clear();
            outputScreen_map();
            game_checkSpeedKiller();
            game_checkHandlingKiller();
            game_checkInstantDeath();
            game_checkOutOfScreen();
            game_checkCheckpoint();
            game_checkFinish();
            outputScreen_night();
            outputScreen_car();
            break;
            
         //####################################  
         case GAMEOVER:
            outputScreen_clear();
            outputScreen_map();
            outputScreen_trajectory();
            outputScreen_car();
            outputScreen_gameOver();
            button_check(GAMEOVER);
            break;
            
         //####################################  
         case WINNER:
            outputScreen_clear();
            outputScreen_map();
            outputScreen_trajectory();
            outputScreen_car();
            outputScreen_winner();
            button_check(WINNER);
            break;
         //####################################  
         case REPLAY:
            outputScreen_clear();
            outputScreen_map();
            outputScreen_carReplay();
            game_replayFrameManager();
            button_check(REPLAY);
            break;
                    
         //####################################  
         case MENUPAUSE:
            outputScreen_clear();
            outputScreen_map();
            outputScreen_trajectory();
            outputScreen_car();
            outputScreen_menuPause();
            button_check(MENUPAUSE);
            break;

         //####################################                     
         default:
            game.gameStatus = GAMEMAKERS;
            break;
      }
    }  
  }
