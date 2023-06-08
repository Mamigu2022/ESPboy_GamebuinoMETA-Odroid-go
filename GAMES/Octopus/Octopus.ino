#include <Gamebuino-Meta.h>
#define TITLESCREEN 1
#define MENU 2
#define GAME 3
#define GAMEOVER 4

#define CONTROLS 97
#define CREDITS 98
#define MENUPAUSE 99

#define SCREENHEIGHT 64
#define SCREENWIDTH 80



//###########################
//##### INFO Global #########
//###########################
typedef struct{
  int gameStatus; 
  int globalTimer;
  int pause;
  int menuOption;
  int menuPauseOption;
  int backgroundOption;
}GameInfo;
GameInfo game;

typedef struct{
  int life; 
  int pos;
  int timer;
  int score;
  int combo;
  bool hasGold;
  bool isCatched;
}PlayerInfo;
PlayerInfo player;

typedef struct{
  int currentPos;
  int maxPos;
  int currentTimer;
  int maxTimer;
  bool reverse;
  bool alternative;
}OctopusInfo;
OctopusInfo octo[5];


typedef struct {
  int8_t tic;
  int8_t tac;
  int8_t toc;
  int8_t music;
}SoundInfo;
SoundInfo sounds;


int strategies[5][10];



//###########################
//##### Game Setup ##########
//###########################
void setup(){
  gb.begin();
  game_init();
  player_init();
  ennemy_init();
}


//###########################
//##### Game Loop ###########
//###########################
void loop(){
  while(1){
    ESP.wdtFeed();
    if(gb.update()){
      game_manageGlobalCounter();
      outputLights_clear();
      
      switch ( game.gameStatus )
      {
         //#################################### 
         case TITLESCREEN:
            outputScreen_clear();
            outputScreen_title();
            button_check(TITLESCREEN);
            break;


         //#################################### 
         case CONTROLS:
            outputScreen_clear();
            outputScreen_controls();
            button_check(CONTROLS);
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
         case GAME:
            outputScreen_clear();
            outputScreen_game();
            outputScreen_score();
            outputLight_bonus();
            outputLight_catched();
            button_check(GAME);
            ennemy_moveOcto();
            ennemy_checkCatched();
            break;
            
         //####################################  
         case MENUPAUSE:
            outputScreen_clear();
            outputScreen_menuPause();
            button_check(MENUPAUSE);
            break;
            
         //####################################  
         case GAMEOVER:
            outputScreen_clear();
            outputScreen_gameover();
            outputScreen_score();
            button_check(GAMEOVER);
            ennemy_moveOcto();
            break;
            
         //####################################                     
         default:
            game.gameStatus = TITLESCREEN;
            break;
      }
    }  
  }
}
