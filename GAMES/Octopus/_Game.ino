void game_init(){
  game.gameStatus = TITLESCREEN;
  game.globalTimer = 0;
  game.pause=0;
  game.menuOption=1;
  game.menuPauseOption=1;
  game.backgroundOption=0;
}

void player_init(){
  player.life=3; 
  player.pos=0;
  player.timer=0;
  player.score=0;
  player.combo=0;
  player.hasGold=false;
  player.isCatched=false;
}



void game_manageGlobalCounter(){
  switch ( game.gameStatus ){

     //####################################  
     case TITLESCREEN:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = MENU;
        }
        break;
     //####################################  
     case MENU:
        break;
        
     //####################################  
     case CONTROLS:
        break;
        
     //####################################  
     case CREDITS:
        break;

     //####################################  
     case GAME:
        if(player.timer>0){
          player.timer = player.timer-1;
          if(player.timer==0){
            if(player.pos==5){
              player.score=player.score+1;
              player.combo=player.combo+1;
              player.hasGold=true;
              outputLight_fullYellow();
            }
            if(player.pos==6){
              player.pos=0;
              player.isCatched=false;
            }
          }
        }
        break;

     //####################################  
     case MENUPAUSE:
        break;

     //####################################  
     case GAMEOVER:
        if(player.timer>0){
          player.timer = player.timer-1;
          if(player.timer==0){
            player.timer=30;
          }
        }
        break;
                          
     default:
        game.gameStatus = TITLESCREEN;
        break;
  }
}

void game_addBonus(){
  outputSound_tac();
  player.timer=8;
  player.hasGold=false;
  player.score = player.score+player.combo;
  player.combo=0;
}
