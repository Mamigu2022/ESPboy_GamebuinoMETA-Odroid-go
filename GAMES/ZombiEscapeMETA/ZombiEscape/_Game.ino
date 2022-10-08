void game_init(){
  game.nbOfLevel = 5;
  level.level = 0;
  if(game.hardMode==false){
    game.playerMaxLife = 3;
  }else{
    game.playerMaxLife = 1;
  }
  game.continueAsEnnemy = false;
  game.isFemale = false;
  game.hardMode = false;
  game.gameStatus = GAMEMAKERS;
  globalTimer = 0;
}

void game_initNextLevel(){
  level.xScreen = 0;
  level.xWorld = 0;
  stage.stage = 1;
  stage.start = 0;
  stage.finish = 0;  
  stage.tmpStart = 0;
}

void game_manageGlobalCounter(){
  switch ( game.gameStatus ){
     //################## GameMakers Logo ##################
     case GAMEMAKERS:
        if(globalTimer<30){
          globalTimer = globalTimer +1;
        }else{
          globalTimer = 0;
          game.gameStatus = TITLESCREEN;
        }
        break;

     //################## Title ##################  
     case TITLESCREEN:
        if(globalTimer<30){
          globalTimer = globalTimer +1;
        }else{
          globalTimer = 0;
          level.level=1;
          game.gameStatus = SELECTPLAYER;
        }
        break;

     //################## Selection Player Type ##################  
     case SELECTPLAYER:
        globalTimer = globalTimer +1;
        if(globalTimer>6){globalTimer=0;}
        break;
        
     //################## Level Intro ##################  
     case LVLINTRO:
        break;

     //display Game   
     case GAME:  
        globalTimer = globalTimer +1;
        if(globalTimer>10){globalTimer=0;}     
        break;

     //display Transition between stages   
     case ADJUST:
        
        break;

     //display Transition between stages   
     case TRANSITION:
        globalTimer = globalTimer +1;
        if(globalTimer>10){globalTimer=0;}
        break;

     //display GameOver  
     case GAMEOVER:
        if(globalTimer<SCREENHEIGHT/2+3){globalTimer = globalTimer + 1;}
        break;

     case THEEND:
        if(globalTimer<400){globalTimer = globalTimer + 1;}
        else{globalTimer = 300;}
        break;  

     case TIPSHARDMODE:
        if(globalTimer<100){globalTimer = globalTimer + 1;}
        break;  
                          
     default:
        game.gameStatus = GAMEMAKERS;
  }         
}

void game_initLoop(){
    stage.start = (stage.stage-1)*120;
    stage.finish = stage.stage * 120;
    if(stage.finish>level.worldSize){stage.finish=level.worldSize;}

    player_initLoop();
    ennemy_initLoop();
}


//############ CHECK FUNCTIONS ############
bool game_checkGameOver(){
  if(player.life == 0){
    game.gameStatus = GAMEOVER;
    return true;}
  else{return false;}
}

bool game_checkLevelEnd(){
  if(player.xInTheWorld+16 > level.worldSize){
    level.level=level.level+1;
    if(level.level<=game.nbOfLevel){
      game.gameStatus=LVLINTRO;
    }else{
      game.gameStatus=THEEND;
    }
     
    return true; 
  }
  else{return false;}
}

bool game_checkGameEnd(){
  if(level.level==game.nbOfLevel+1){return true;}
  else{return false;}
}

bool game_checkInterStage(){
  if(stage.tmpStart>=stage.start){
    item_init();
    ennemy_setNbOfEnnemy();
    ennemy_setEnnemiesPositions();
    game.gameStatus=GAME;
  }
 return (0);
}

void game_adjustCamera(){
  if(player.x+8> SCREENWIDTH/2){
    level.xWorld = level.xWorld + 2;
    player.x = player.x - 2;
  }else{
    stage.tmpStart = level.xWorld;
    game.gameStatus=TRANSITION;
  }
}


void game_checkStageEnd(){
  if(stage.nbOfAliveEnnemies<=0){
    stage.stage = stage.stage + 1;
    game.gameStatus=ADJUST; 
  }
}


void game_TheEndMove(){
  
}


//############ PRIVATE FUNCTIONS ############

void game_setBackground(){
  if(level.level == 1){
    level.nbOfSprites = 20;
    level.levelBackground[0]=1;
    level.levelBackground[1]=2;
    level.levelBackground[2]=3;
    level.levelBackground[3]=4;
    level.levelBackground[4]=5;
    level.levelBackground[5]=6;
    level.levelBackground[6]=3;
    level.levelBackground[7]=4;
    level.levelBackground[8]=5;
    level.levelBackground[9]=2;
    level.levelBackground[10]=6;
    level.levelBackground[11]=1;
    level.levelBackground[12]=4;
    level.levelBackground[13]=3;
    level.levelBackground[14]=5;
    level.levelBackground[15]=6;
    level.levelBackground[16]=2;
    level.levelBackground[17]=1;
    level.levelBackground[18]=3;
    level.levelBackground[19]=6;
  }
  
  if(level.level == 2){
    level.nbOfSprites = 36;
    level.levelBackground[0]=15;
    level.levelBackground[1]=16;
    level.levelBackground[2]=17;
    level.levelBackground[3]=19;
    level.levelBackground[4]=18;
    level.levelBackground[5]=7;
    level.levelBackground[6]=20;
    level.levelBackground[7]=19;
    level.levelBackground[8]=17;
    level.levelBackground[9]=16;
    level.levelBackground[10]=19;
    level.levelBackground[11]=18;
    level.levelBackground[12]=22;
    level.levelBackground[13]=21;
    level.levelBackground[14]=23;
    level.levelBackground[15]=20;
    level.levelBackground[16]=19;
    level.levelBackground[17]=8;
    level.levelBackground[18]=18;
    level.levelBackground[19]=0;
    level.levelBackground[20]=8;
    level.levelBackground[21]=0;
    level.levelBackground[22]=20;
    level.levelBackground[23]=8;
    level.levelBackground[24]=7;
    level.levelBackground[25]=8;
    level.levelBackground[26]=18;
    level.levelBackground[27]=0,
    level.levelBackground[28]=19;
    level.levelBackground[29]=17;
    level.levelBackground[30]=16;
    level.levelBackground[31]=19;
    level.levelBackground[32]=18;
    level.levelBackground[33]=0;
    level.levelBackground[34]=0;
    level.levelBackground[35]=0;
}
  
  if(level.level == 3){
    level.nbOfSprites = 32;
    level.levelBackground[0]=8;
    level.levelBackground[1]=8;
    level.levelBackground[2]=8;
    level.levelBackground[3]=15;
    level.levelBackground[4]=8;
    level.levelBackground[5]=8;
    level.levelBackground[6]=8;
    level.levelBackground[7]=19;
    level.levelBackground[8]=0;
    level.levelBackground[9]=9;
    level.levelBackground[10]=0;
    level.levelBackground[11]=19;
    level.levelBackground[12]=16;
    level.levelBackground[13]=17;
    level.levelBackground[14]=14;
    level.levelBackground[15]=17;
    level.levelBackground[16]=16;
    level.levelBackground[17]=19;
    level.levelBackground[18]=18;
    level.levelBackground[19]=0;
    level.levelBackground[20]=20;
    level.levelBackground[21]=19;
    level.levelBackground[22]=10;
    level.levelBackground[23]=11;
    level.levelBackground[24]=12;
    level.levelBackground[25]=19;
    level.levelBackground[26]=8;
    level.levelBackground[27]=8;
    level.levelBackground[28]=13;
    level.levelBackground[29]=8;
    level.levelBackground[30]=8;
    level.levelBackground[31]=0;
  }
  
  if(level.level == 4){
    level.nbOfSprites = 33;
    level.levelBackground[0]=24;
    level.levelBackground[1]=8;
    level.levelBackground[2]=26;
    level.levelBackground[3]=24;
    level.levelBackground[4]=32;
    level.levelBackground[5]=32;
    level.levelBackground[6]=25;
    level.levelBackground[7]=16;
    level.levelBackground[8]=25;
    level.levelBackground[9]=17;
    level.levelBackground[10]=32;
    level.levelBackground[11]=32;
    level.levelBackground[12]=27;
    level.levelBackground[13]=32;
    level.levelBackground[14]=32;
    level.levelBackground[15]=8;
    level.levelBackground[16]=8;
    level.levelBackground[17]=29;
    level.levelBackground[18]=16;
    level.levelBackground[19]=32;
    level.levelBackground[20]=28;
    level.levelBackground[21]=30;
    level.levelBackground[22]=31;
    level.levelBackground[23]=27;
    level.levelBackground[24]=17;
    level.levelBackground[25]=24;
    level.levelBackground[26]=32;
    level.levelBackground[27]=32;
    level.levelBackground[28]=26;
    level.levelBackground[29]=32;
    level.levelBackground[30]=32;
    level.levelBackground[31]=24;
    level.levelBackground[32]=16;
  }

  if(level.level == 5){
    level.nbOfSprites = 27;
    level.levelBackground[0]=33;
    level.levelBackground[1]=34;
    level.levelBackground[2]=34;
    level.levelBackground[3]=33;
    level.levelBackground[4]=34;
    level.levelBackground[5]=38;
    level.levelBackground[6]=36;
    level.levelBackground[7]=33;
    level.levelBackground[8]=39;
    level.levelBackground[9]=36;
    level.levelBackground[10]=37;
    level.levelBackground[11]=33;
    level.levelBackground[12]=35;
    level.levelBackground[13]=34;
    level.levelBackground[14]=35;
    level.levelBackground[15]=36;
    level.levelBackground[16]=37;
    level.levelBackground[17]=38;
    level.levelBackground[18]=36;
    level.levelBackground[19]=34;
    level.levelBackground[20]=34;
    level.levelBackground[21]=39;
    level.levelBackground[22]=36;
    level.levelBackground[23]=34;
    level.levelBackground[24]=33;
    level.levelBackground[25]=34;
    level.levelBackground[26]=40;
  }
  /*
    if(level.level == ){
    level.nbOfSprites = 32;
    level.levelBackground[0]=;
    level.levelBackground[1]=;
    level.levelBackground[2]=;
    level.levelBackground[3]=;
    level.levelBackground[4]=;
    level.levelBackground[5]=;
    level.levelBackground[6]=;
    level.levelBackground[7]=;
    level.levelBackground[8]=;
    level.levelBackground[9]=;
    level.levelBackground[10]=;
    level.levelBackground[11]=;
    level.levelBackground[12]=;
    level.levelBackground[13]=;
    level.levelBackground[14]=;
    level.levelBackground[15]=;
    level.levelBackground[16]=;
    level.levelBackground[17]=;
    level.levelBackground[18]=;
    level.levelBackground[19]=;
    level.levelBackground[20]=;
    level.levelBackground[21]=;
    level.levelBackground[22]=;
    level.levelBackground[23]=;
    level.levelBackground[24]=;
    level.levelBackground[25]=;
    level.levelBackground[26]=;
    level.levelBackground[27]=;
    level.levelBackground[28]=;
    level.levelBackground[29]=;
    level.levelBackground[30]=;
    level.levelBackground[31]=;
  }
  */
  level.worldSize = SCREENWIDTH/2;
  for(int i=0;i<level.nbOfSprites;i++){level.worldSize = level.worldSize + game.backgroundImg[level.levelBackground[i]].spriteWidth;}
}
