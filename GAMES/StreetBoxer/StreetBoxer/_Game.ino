void game_init(){
  game.gameStatus = GAMEMAKERS;
  game.globalTimer = 0;
  game.globalLoopCounter = 0;
  game.nbPlayer = 1;
  game.selectedPlayer1 = NBPERSOS;
  game.selectedPlayer2 = NBPERSOS;
}

void game_manageGlobalCounter(){
  switch ( game.gameStatus ){
     //#################################### 
     case GAMEMAKERS:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = TITLESCREEN;
        }
        break;

     //####################################  
     case TITLESCREEN:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = SELECTNBPLAYER;
        }
        break;

     //####################################  
     case CONTROLSP1:
        break;

     //####################################  
     case CONTROLSP2:
        break;
        
     //####################################  
     case CREDITS:
        break;
        
     //####################################   
     case SELECTNBPLAYER:
        break;
        
     //####################################  
     case SELECTPLAYER1:
        break;

     //####################################  
     case SELECTPLAYER2:
        break;

     //####################################  
     case ANIMFIGHT:
        if(game.globalTimer<60){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          if(game.nbPlayer == 1){
             game.gameStatus=GAME1PLAYER;
          }else{
             game.gameStatus=GAME2PLAYER;
          }
        }
     
        break;

     //####################################  
     case GAME1PLAYER:
        break;

     //####################################  
     case GAME2PLAYER:
        game.globalTimer = game.globalTimer + 1;
        if(game.globalTimer>1){game.globalTimer=0;}
        break;
        
     //####################################  
     case KO1PLAYER:
        game.globalTimer = game.globalTimer + 1;
        if(game.globalTimer>50){
          game.globalTimer=0;
          game.gameStatus = WINNER;
        }
        break;
        
     //####################################  
     case KO2PLAYER:
        game.globalTimer = game.globalTimer + 1;
        if(game.globalTimer>50){
          game.globalTimer=0;
          game.gameStatus = WINNER;
        }
        break;

     //####################################  
     case WINNER:
        game.globalTimer = game.globalTimer + 1;
        if(game.globalTimer>29){
          game.globalTimer=0;
        }
        break;

     //####################################  
     case MENU:
        break;

                          
     default:
        game.gameStatus = GAMEMAKERS;
  }  

  game.globalLoopCounter = game.globalLoopCounter + 1;
  if(game.globalLoopCounter>1000){game.globalLoopCounter = 0;}
}


void game_CheckKO(){
  if(player1.life<=0 || player2.life<=0){
    if(game.gameStatus==GAME1PLAYER){
      game.gameStatus=KO1PLAYER;
    }

    if(game.gameStatus==GAME2PLAYER){
      game.gameStatus=KO2PLAYER;
    }    
  }
}





//####################################
//########### 1 PLAYER ###############
//####################################
void game_initLoop1Player(){
  player1.isProtecting=false;
  player2.isProtecting=false;
}

void game_timers1Player(){
  if(player1.timerHit>0){player1.timerHit = player1.timerHit - 1;}
  if(player1.timerHit<0){player1.timerHit = player1.timerHit + 1;}
  if(player1.timerDamage>0){player1.timerDamage = player1.timerDamage - 1;}
  if(player1.timerWalk>0){player1.timerWalk = player1.timerWalk -1;}
  
  if(player2.timerHit>0){player2.timerHit = player2.timerHit - 1;}
  if(player2.timerDamage>0){player2.timerDamage = player2.timerDamage - 1;}
  if(player2.timerWalk>0){player2.timerWalk = player2.timerWalk -1;}
}



//####################################
//########### 2 PLAYERS ##############
//####################################

void game_initLoop2Player(){
  player1.isProtecting=false;
  player2.isProtecting=false;
}

void game_timers2Player(){
  if(player1.timerHit>0){player1.timerHit = player1.timerHit - 1;}
  if(player1.timerWalk>0){player1.timerWalk = player1.timerWalk -1;}
  if(player1.timerDamage>0){player1.timerDamage = player1.timerDamage - 1;}
  
  if(player2.timerHit>0){player2.timerHit = player2.timerHit - 1;}
  if(player2.timerWalk>0){player2.timerWalk = player2.timerWalk -1;}
  if(player2.timerDamage>0){player2.timerDamage = player2.timerDamage - 1;}
}
