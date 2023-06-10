void playerType_init(){
  //P1 Red
  playerType[0].type = 0;
  playerType[0].maxLife = 5*2;
  playerType[0].maxWalkingSpeed = 2;
  playerType[0].maxHitSpeed = 2;

  //P2 Blue
  playerType[1].type = 0;
  playerType[1].maxLife = 5*2;
  playerType[1].maxWalkingSpeed = 2;
  playerType[1].maxHitSpeed = 2;
}

void player_initLoop(){

}


void player1_checkDamage(int checkType){
  if(checkType == GAME1PLAYER){
    if(player2.timerHit==(5-playerType[player2.type].maxHitSpeed)*2){
      if(player2.x-1==player1.x+0 && player1.isProtecting==false){player1.typeDamage = 1;player1.timerDamage = 6;  player1.life=player1.life-1;}
      if(player2.x-1==player1.x+1 && player1.isProtecting==false){player1.typeDamage = 2;player1.timerDamage = 8;  player1.life=player1.life-1;}
      if(player2.x-1==player1.x+2 && player1.isProtecting==false){player1.typeDamage = 2;player1.timerDamage = 8;  player1.life=player1.life-1;}
      if(player2.x-1==player1.x+3 && player1.isProtecting==false){player1.typeDamage = 3;player1.timerDamage = 10; player1.life=player1.life-2;}
      if(player2.x-1==player1.x+4 && player1.isProtecting==false){player1.typeDamage = 2;player1.timerDamage = 8;  player1.life=player1.life-1;}
      if(player2.x-1==player1.x+5 && player1.isProtecting==false){player1.typeDamage = 2;player1.timerDamage = 8;  player1.life=player1.life-1;}
      if(player2.x-1==player1.x+6 && player1.isProtecting==false){player1.typeDamage = 1;player1.timerDamage = 6;  player1.life=player1.life-1;}
    }   
  }

  if(checkType == GAME2PLAYER){
    if(player2.timerHit==(5-playerType[player2.type].maxHitSpeed)*2){
      if(player2.y==player1.y-2 && player1.isProtecting==false){player1.typeDamage = 1;player1.timerDamage = 6;  player1.life=player1.life-1;}
      if(player2.y==player1.y-1 && player1.isProtecting==false){player1.typeDamage = 2;player1.timerDamage = 8;  player1.life=player1.life-1;}
      if(player2.y==player1.y   && player1.isProtecting==false){player1.typeDamage = 3;player1.timerDamage = 10; player1.life=player1.life-2;}
      if(player2.y==player1.y+1 && player1.isProtecting==false){player1.typeDamage = 2;player1.timerDamage = 8;  player1.life=player1.life-1;}
      if(player2.y==player1.y+2 && player1.isProtecting==false){player1.typeDamage = 1;player1.timerDamage = 6;  player1.life=player1.life-1;}
    }
  }
}

void player2_checkDamage(int checkType){
  if(checkType == GAME1PLAYER){
    if(player1.timerHit==(5-playerType[player1.type].maxHitSpeed)*2){
      if(player1.x+8==player2.x+0 && player2.isProtecting==false){player2.typeDamage = 1;player2.timerDamage = 6;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x+8==player2.x+1 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x+8==player2.x+2 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x+8==player2.x+3 && player2.isProtecting==false){player2.typeDamage = 3;player2.timerDamage = 10; player2.life=player2.life-2; ennemy_manageStrategy();}
      if(player1.x+8==player2.x+4 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x+8==player2.x+5 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x+8==player2.x+6 && player2.isProtecting==false){player2.typeDamage = 1;player2.timerDamage = 6;  player2.life=player2.life-1; ennemy_manageStrategy();}
    }
  
    if(player1.timerHit==((5-playerType[player1.type].maxHitSpeed)*2)*-1){
      if(player1.x-1==player2.x+0 && player2.isProtecting==false){player2.typeDamage = 1;player2.timerDamage = 6;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x-1==player2.x+1 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x-1==player2.x+2 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x-1==player2.x+3 && player2.isProtecting==false){player2.typeDamage = 3;player2.timerDamage = 10; player2.life=player2.life-2; ennemy_manageStrategy();}
      if(player1.x-1==player2.x+4 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x-1==player2.x+5 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1; ennemy_manageStrategy();}
      if(player1.x-1==player2.x+6 && player2.isProtecting==false){player2.typeDamage = 1;player2.timerDamage = 6;  player2.life=player2.life-1; ennemy_manageStrategy();} 
    }
  }

  if(checkType == GAME2PLAYER){
    if(player1.timerHit==(5-playerType[player1.type].maxHitSpeed)*2){
      if(player1.y==player2.y-2 && player2.isProtecting==false){player2.typeDamage = 1;player2.timerDamage = 6;  player2.life=player2.life-1;}
      if(player1.y==player2.y-1 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1;}
      if(player1.y==player2.y   && player2.isProtecting==false){player2.typeDamage = 3;player2.timerDamage = 10; player2.life=player2.life-2;}
      if(player1.y==player2.y+1 && player2.isProtecting==false){player2.typeDamage = 2;player2.timerDamage = 8;  player2.life=player2.life-1;}
      if(player1.y==player2.y+2 && player2.isProtecting==false){player2.typeDamage = 1;player2.timerDamage = 6;  player2.life=player2.life-1;}
    }
  }  
}

//####################################
//########### 1 PLAYER ###############
//####################################
void player_move1Player(){
  int moveMin = 20;
  int moveMax = SCREENWIDTH -28;
  int tmpmove = 0;
  //player1
  if(player1.timerHit==0 && player1.timerDamage==0 && player1.life>0){
    switch(playerType[player1.type].maxWalkingSpeed){
      case 1: 
        if(player1.timerWalk==0){
          player1.timerWalk=2;
          tmpmove=1;
        }else{
          player1.timerWalk=player1.timerWalk-1;
          tmpmove=0;        
        }
        break;
      case 2: 
        if(player1.timerWalk==0){
          player1.timerWalk=1;
          tmpmove=1;
        }else{
          player1.timerWalk=player1.timerWalk-1;
          tmpmove=0;        
        }    
        break;
      case 3: tmpmove=1; break;
      case 4: tmpmove=2; break;
    }
    if(player1.isGoingToLeft==true){
      player1.x = player1.x-tmpmove;
      if(player1.x<moveMin){
        player1.x=moveMin;
        player1.isGoingToLeft=false;
      }
    }else{
      player1.x = player1.x+tmpmove;
      if(player1.x>moveMax){
        player1.x=moveMax;
        player1.isGoingToLeft=true;
      }  
    }
    if(tmpmove>0){
      player1.feetPosition = player1.feetPosition + 1;
      if(player1.feetPosition>6){
        player1.feetPosition = 0;
      }
    }
  }
  
  //player2
  if(player2.timerHit==0 && player2.timerDamage==0 && player2.life>0){
    switch(playerType[player2.type].maxWalkingSpeed){
      case 1: 
        if(player2.timerWalk==0){
          player2.timerWalk=2;
          tmpmove=1;
        }else{
          player2.timerWalk=player2.timerWalk-1;
          tmpmove=0;        
        }
        break;
      case 2: 
        if(player2.timerWalk==0){
          player2.timerWalk=1;
          tmpmove=1;
        }else{
          player2.timerWalk=player2.timerWalk-1;
          tmpmove=0;        
        }    
        break;
      case 3: tmpmove=1; break;
      case 4: tmpmove=2; break;
    }  
    if(player2.isGoingToLeft==false){
      player2.x = player2.x-tmpmove;
      if(player2.x<moveMin){
        player2.x=moveMin;
        player2.isGoingToLeft=true;
        ennemy_manageStrategy();
      }
    }else{
      player2.x = player2.x+tmpmove;
      if(player2.x>moveMax){
        player2.x=moveMax;
        player2.isGoingToLeft=false;
        ennemy_manageStrategy();
      }  
    }
    if(tmpmove>0){
      player2.feetPosition = player2.feetPosition + 1;
      if(player2.feetPosition>6){
        player2.feetPosition = 0;
      }
    }  
  }  
}


//####################################
//########### 2 PLAYER ###############
//####################################
void player_move2Player(){
  int moveMin = 15;
  int moveMax = SCREENHEIGHT -15;
  int tmpmove = 0;
  //player1
  if(player1.timerHit==0 && player1.timerDamage==0 && player1.life>0){
    
    switch(playerType[player1.type].maxWalkingSpeed){
      case 1: 
        if(player1.timerWalk==0){
          player1.timerWalk=2;
          tmpmove=1;
        }else{
          player1.timerWalk=player1.timerWalk-1;
          tmpmove=0;        
        }
        break;
      case 2: 
        if(player1.timerWalk==0){
          player1.timerWalk=1;
          tmpmove=1;
        }else{
          player1.timerWalk=player1.timerWalk-1;
          tmpmove=0;        
        }    
        break;
      case 3: tmpmove=1; break;
      case 4: tmpmove=2; break;
    }
    if(player1.isGoingToLeft==true){
      player1.y = player1.y-tmpmove;
      if(player1.y<moveMin){
        player1.y=moveMin;
        player1.isGoingToLeft=false;
      }
    }else{
      player1.y = player1.y+tmpmove;
      if(player1.y>moveMax){
        player1.y=moveMax;
        player1.isGoingToLeft=true;
      }  
    }
  }
  
  //player2
  if(player2.timerHit==0 && player2.timerDamage==0 && player2.life>0){
    switch(playerType[player2.type].maxWalkingSpeed){
      case 1: 
        if(player2.timerWalk==0){
          player2.timerWalk=2;
          tmpmove=1;
        }else{
          player2.timerWalk=player2.timerWalk-1;
          tmpmove=0;        
        }
        break;
      case 2: 
        if(player2.timerWalk==0){
          player2.timerWalk=1;
          tmpmove=1;
        }else{
          player2.timerWalk=player2.timerWalk-1;
          tmpmove=0;        
        }    
        break;
      case 3: tmpmove=1; break;
      case 4: tmpmove=2; break;
    }  
    if(player2.isGoingToLeft==false){
      player2.y = player2.y-tmpmove;
      if(player2.y<moveMin){
        player2.y=moveMin;
        player2.isGoingToLeft=true;
      }
    }else{
      player2.y = player2.y+tmpmove;
      if(player2.y>moveMax){
        player2.y=moveMax;
        player2.isGoingToLeft=false;
      }  
    }  
  }
}        

