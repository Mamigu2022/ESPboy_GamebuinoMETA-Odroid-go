#include <Gamebuino-Meta.h>
#define GAMEMAKERS 0
#define TITLESCREEN 1
#define SELECTNBPLAYER 2
#define SELECTPLAYER1 3
#define SELECTPLAYER2 4
#define ANIMFIGHT 5
#define GAME1PLAYER 6
#define GAME2PLAYER 7
#define KO1PLAYER 8
#define KO2PLAYER 9
#define WINNER 10

#define CONTROLSP1 96
#define CONTROLSP2 97
#define CREDITS 98
#define MENU 99

#define SCREENHEIGHT 64
#define SCREENWIDTH 80

#define NBPERSOS 5


//###########################
//##### INFO Global #########
//###########################
bool isDebug = false;
int debugValue = 0;

typedef struct{
  Image sprite; 
  int spriteWidth; 
  int spriteHeight;
}ImagesInfo;

typedef struct{
  int gameStatus; 
  int globalTimer;
  int globalLoopCounter;
  int nbPlayer;
  int selectedPlayer1;
  int selectedPlayer2;
}GameInfo;
GameInfo game;

//###########################
//##### INFO Player #########
//###########################
typedef struct{
  int x; 
  int y;
  int type; 
  int life; 
  int power; 
  int timerHit;
  int timerProtect;  //on player protect, decrease power when protecting continuously more than 20 cycles (but not before)
  int timerPower;    //on player hit, wait before increasing power again
  int lockPower;     //if player has 0 power, he has to wait until hit or protect again (10 cycles)
  int typeDamage;    //used to display different images depending where the player was hit
  int timerDamage;   //define the duration of damage image displax
  int timerWalk; 
  bool isGoingToLeft; 
  int feetPosition;
  bool isShooting; 
  bool isProtecting;
} PlayerInfo;
PlayerInfo player1;
PlayerInfo player2;

typedef struct{
  int type;
  int maxLife;
  int maxPower;
  int waitPower;
  int maxWalkingSpeed;
  int maxHitSpeed;
}PlayerType;
PlayerType playerType[5];

typedef struct {
  int type;
  ImagesInfo body;
  ImagesInfo armNormal;
  ImagesInfo armProtect;
  ImagesInfo armHit;
  ImagesInfo fist;
  ImagesInfo back;
}PlayerImg;
PlayerImg playerImg[5];

Image playerSkin[5];

typedef struct {
  bool btnUP_pressed;
  bool btnDOWN_pressed;
  bool btnLEFT_pressed;
  bool btnRIGHT_pressed;
  bool btnA_pressed;
  bool btnB_pressed;
  int btnUP_released;
  int btnDOWN_released;
  int btnLEFT_released;
  int btnRIGHT_released;
  int btnA_released;
  int btnB_released;
}VirtualPad;
VirtualPad padPlayer2;

typedef struct {
  int strategyTimer;
  int currentStrategy;
  int currentMove;
}iaVar;
iaVar iaData;


typedef struct {
  int8_t weapon;
  int8_t bonus;
  int8_t playerDamage;
  int8_t music;
} SoundInfo;
SoundInfo sounds;


int strategies[5][10];



//###########################
//##### Game Setup ##########
//###########################
void setup(){
  gb.begin();
  game_init();
  playerType_init();
  outputScreen_initPlayerSkin();
  ennemy_init();
  //loop();
}


//###########################
//##### Game Loop ###########
//###########################
void loop(){
 // while(1){
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
         case SELECTNBPLAYER:
            outputScreen_clear();
            outputScreen_selectNbPlayer();
            button_check(SELECTNBPLAYER);
            break;

         //####################################  
         case SELECTPLAYER1:
            outputScreen_clear();
            outputScreen_selectPlayer1();
            outputLight_fullBlue();
            button_check(SELECTPLAYER1);
            break;

         //####################################  
         case SELECTPLAYER2:
            outputScreen_clear();
            outputScreen_selectPlayer2();
            outputLight_fullRed();
            button_check(SELECTPLAYER2);
            break;

         //####################################  
         case ANIMFIGHT:
            outputScreen_clear();
            if(game.nbPlayer == 1){
              outputScreen_game1background();
              outputScreen_game1player2();
              outputScreen_game1player1();
              ennemy_initGame();
            }else{
              outputScreen_game2background();
              outputScreen_game2player1();
              outputScreen_game2player2();
            }
            outputScreen_ReadyFight();
            break;

         //####################################  
         case GAME1PLAYER:
            outputScreen_clear();
            game_initLoop1Player();
            player_move1Player();
            game_timers1Player();
            ennemy_ia();
            button_check(GAME1PLAYER);
            player1_checkDamage(GAME1PLAYER);
            player2_checkDamage(GAME1PLAYER);
            player_increasePower();
            outputScreen_game1player();
            game_CheckKO();
            break;

         //####################################  
         case GAME2PLAYER:
            outputScreen_clear();
            game_initLoop2Player();
            player_move2Player();
            game_timers2Player();
            button_check(GAME2PLAYER);
            player1_checkDamage(GAME2PLAYER);
            player2_checkDamage(GAME2PLAYER);
            player_increasePower();
            outputScreen_game2player();
            game_CheckKO();
            break;

         //####################################  
         case KO1PLAYER:
            outputScreen_clear();
            player_move1Player();
            game_timers1Player();
            outputScreen_ko1player();
            break;

         //####################################  
         case KO2PLAYER:
            outputScreen_clear();
            player_move2Player();
            game_timers2Player();
            outputScreen_ko2player();
            break;

         //####################################  
         case WINNER:
            outputScreen_clear();
            outputScreen_winner();
            button_check(WINNER);
            break;
            
         //#################################### 
         case CONTROLSP1:
            outputScreen_clear();
            outputScreen_controlP1();
            button_check(CONTROLSP1);
            break;

         //#################################### 
         case CONTROLSP2:
            outputScreen_clear();
            outputScreen_controlP2();
            button_check(CONTROLSP2);
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
         default:
            game.gameStatus = GAMEMAKERS;
      }
      debugDisplay();
    }  
  }
//}
