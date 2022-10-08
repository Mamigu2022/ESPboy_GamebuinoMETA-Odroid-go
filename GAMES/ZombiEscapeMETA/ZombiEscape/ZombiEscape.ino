#include <Gamebuino-Meta.h>
#define GAMEMAKERS 0
#define TITLESCREEN 1
#define SELECTPLAYER 2
#define LVLINTRO 3
#define GAME 4
#define ADJUST 5
#define TRANSITION 6
#define GAMEOVER 7
#define THEEND 8
#define TIPSHARDMODE 9

#define SCREENHEIGHT 64
#define SCREENWIDTH 80

//TODO
//son a vérifier

//NICE TO HAVE
//levels bonus
// - port (bateau a voile, bite amarrage, bateau de peche, cordage)
// - special Paris (tour eiffel, arc de triomphe, notre dame)
// - special desert(Pyramide, oasis, chameaux
// - special jungle ()
// - nuages 
// - mer (lol)
// - egouts (tortue ninja, )
//particules shoot
//insérer 'civils' qui se transforment en zombi si on ne les sauve pas
//compteur de civils sauvés
//ajouter obstacles (type d'ennemy?)

//###########################
//##### INFO Global #########
//###########################
bool isDebug = false;
int debugValue = 0;
int globalTimer;
/*InfoSprite*/  typedef struct{Image sprite; int spriteWidth; int spriteHeight;}InfoSprite;
/*Element*/     typedef struct{int type; int x; int y; int timer; bool isGoingToLeft;}Element;
Element bonus[15];

//###########################
//##### INFO Player #########
//###########################
/*PlayerInfo*/  typedef struct{int xInTheWorld; int x; int y; int speed_; int life; int ammo; int hitboxXmin; int hitboxXmax; int hitboxYmin; int hitboxYmax; int timer; bool isGoingToLeft; bool isRunning; int weaponType; bool isShooting; int fireTimer; bool isReloading;} PlayerInfo;
/*WeaponInfo*/  typedef struct{int weaponRangeX; int weaponRangeY; int maxAmmo; int fireTimer; int maxNbBullet; int damage;}WeaponInfo;
PlayerInfo player;
WeaponInfo weapon[3]; //gun, m16, shotgun

//###########################
//##### INFO Ennemy #########
//###########################
/*EnnemyType*/  typedef struct{int type; int maxLife; int walkingSpeed; int movingSpeed; int hitboxXmin; int hitboxXmax; int hitboxYmin; int hitboxYmax; }EnnemyType; //[walkingSpeed : Timer between 2 moves][movingSpeed : Distance when moving]
/*EnnemyInfo*/  typedef struct{int type; int state; int x; int y; int life; int timer; int timerDamage; int timerAnim; bool isDead; bool isGoingToLeft;}EnnemyInfo; //[type 1:normal 2:small 3:big][state 0:running 1:stunt]

//###########################
//##### INFO Game ###########
//###########################
typedef struct {
  int nbOfLevel;
  int gameStatus;
  int playerMaxLife;
  bool isFemale;
  bool hardMode;
  bool continueAsEnnemy;
  InfoSprite backgroundImg[41];
  EnnemyType ennemyType[5];
  InfoSprite ennemyImg[10];
  InfoSprite playerImg[9];
} GameInfo;

typedef struct {
  int level;
  int xScreen;
  int xWorld;
  int worldSize;
  int nbOfSprites;
  int levelBackground[40];
} LevelInfo;

typedef struct {
  int stage;
  int start;
  int finish;  
  int tmpStart;
  int nbOfEnnemies;
  int nbOfAliveEnnemies;
  EnnemyInfo ennemy[50];  
} StageInfo;

typedef struct {
  int8_t weapon;
  int8_t bonus;
  int8_t playerDamage;
  int8_t music;
} SoundInfo;
  
  GameInfo game;
  LevelInfo level;
  StageInfo stage;
  SoundInfo sounds;


//###########################
//##### Game Setup ##########
//###########################
void setup(){
  gb.begin();
  game_init();
  player_init();
  ennemy_init();
  player_initWeapon();
  outputScreen_initPlayerSprites();
  outputScreen_initEnnemiesSprites();
  outputScreen_initBackgroundSprites();  
  loop();
}


//###########################
//##### Game Loop ###########
//###########################
void loop(){
  while(1){
    if(gb.update()){
      game_manageGlobalCounter();
      switch ( game.gameStatus )
      {
         //################## GameMakers Logo ##################
         case GAMEMAKERS:
            outputScreen_gamemakers();
            button_check(GAMEMAKERS);
            break;

         //################## Title ##################  
         case TITLESCREEN:
            outputScreen_clear();
            outputScreen_title();
            button_check(TITLESCREEN);
            break;

         //################## Title ##################  
         case SELECTPLAYER:
            outputScreen_clear();
            outputScreen_selectPlayer();
            button_check(SELECTPLAYER);
            break;

         //################## Level Intro ##################  
         case LVLINTRO:
            outputScreen_clear();
            outputScreen_levelIntro();
            button_check(LVLINTRO);            
            break;

         //################## Game ##################
         case GAME:
            outputScreen_clear();
            outputLights_clear();  

            game_initLoop();
            button_check(GAME);       
            
            outputScreen_drawBackground();
            ennemy_move();
            
            player_checkShot();
            ennemy_checkDamage();
            player_checkDamage();
            player_checkBonus();
            ennemy_displayOrderV();
            outputScreen_ennemies(0);
            outputScreen_drawPlayer();
            outputScreen_ennemies(1);
            outputScreen_bonus();
            outputScreen_drawHUD();

            if(!game_checkGameOver()){
              if(!game_checkGameEnd()){
                game_checkStageEnd();
              }
            }
             
            if(isDebug==true){
              debug_DrawHitbox();
              debug_writeValue();
            }
            break;

         case ADJUST:
            outputScreen_clear();
            outputLights_clear();
            outputScreen_drawBackground();
            outputScreen_ennemies(0);
            outputScreen_drawPlayer();
            outputScreen_ennemies(1);
            outputScreen_drawHUD();
            outputScreen_bonus();
            outputScreen_goNextStage();            
            game_adjustCamera();
            player.isGoingToLeft = false;
            player.isShooting = false;
            break;

         //################## Transition between stages ##################  
         case TRANSITION:
            outputScreen_clear();
            outputLights_clear();  

            game_initLoop();
            button_check(GAME); 

            outputScreen_drawBackground();
            
            player_checkShot();
            player_checkBonus();
            outputScreen_ennemies(0);
            outputScreen_drawPlayer();
            outputScreen_ennemies(1);
            outputScreen_drawHUD();
            outputScreen_bonus();
            outputScreen_goNextStage();

            if(!game_checkLevelEnd()){
              game_checkInterStage();  
            }         
            break;

         //################## GameOver ##################  
         case GAMEOVER:
            outputScreen_clear();
            outputLights_clear();  

            game_initLoop();
            button_check(GAMEOVER);       
            
            outputScreen_drawBackground();
            button_check(GAMEOVER);
            ennemy_move();
            
            ennemy_displayOrderV();
            outputScreen_ennemies(0);
            outputScreen_ennemies(1);
            outputScreen_bonus();

            outputScreen_gameOver();
             
            if(isDebug==true){
              debug_DrawHitbox();
              debug_writeValue();
            }            
            break;

         //################## The End ##################  
         case THEEND:
            outputScreen_clear();
            outputLights_clear();  

            game_TheEndMove();
            outputScreen_drawTheEnd();
            button_check(THEEND);           
            break;

         //################## Tips Hard Mode ##################  
         case TIPSHARDMODE:
            outputScreen_clear();
            outputLights_clear();  

            outputScreen_hardModeTips();
            button_check(TIPSHARDMODE);           
            break;      
                              
         default:
            game.gameStatus = GAMEMAKERS;
      }
    }  
  }
}


