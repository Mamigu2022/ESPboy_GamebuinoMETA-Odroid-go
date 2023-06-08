void ennemy_init(){
  octo[0].currentPos=0; octo[0].maxPos=4; octo[0].currentTimer=10; octo[0].maxTimer=30; octo[0].reverse=false; octo[0].alternative=false;
  octo[1].currentPos=0; octo[1].maxPos=5; octo[1].currentTimer=15; octo[1].maxTimer=25; octo[1].reverse=false; octo[1].alternative=false;
  octo[2].currentPos=0; octo[2].maxPos=4; octo[2].currentTimer=0; octo[2].maxTimer=30; octo[2].reverse=false; octo[2].alternative=false;
  octo[3].currentPos=0; octo[3].maxPos=3; octo[3].currentTimer=0; octo[3].maxTimer=25; octo[3].reverse=false; octo[3].alternative=false;
}

void ennemy_moveOcto(){
  for(int i=0; i<4; i++){
    octo[i].currentTimer=octo[i].currentTimer+1;
    if(octo[i].currentTimer==octo[i].maxTimer){
      outputSound_tic();
      
      octo[i].currentTimer=0;
      if(octo[i].reverse==false){
        octo[i].currentPos = octo[i].currentPos + 1;
        if(octo[i].currentPos==octo[i].maxPos-octo[i].alternative){
          octo[i].reverse=true;
        }
      }else{
        octo[i].currentPos = octo[i].currentPos - 1;
        if(octo[i].currentPos==0){
          octo[i].reverse=false;
          if(i==0){
            if(octo[0].alternative==true){octo[0].alternative=false;}
            else{octo[0].alternative=true;}
          }
        }
      }
    }
  }
}

void ennemy_checkCatched(){
  if(player.isCatched==false){
    if(player.pos==1 && octo[0].currentPos==octo[0].maxPos && octo[0].alternative==true){player.isCatched=true;}
    if(player.pos==2 && octo[0].currentPos==octo[0].maxPos && octo[0].alternative==false){player.isCatched=true;}
    if(player.pos==3 && octo[1].currentPos==octo[1].maxPos){player.isCatched=true;}
    if(player.pos==4 && octo[2].currentPos==octo[2].maxPos){player.isCatched=true;}
    if(player.pos==5 && octo[3].currentPos==octo[3].maxPos){player.isCatched=true;}
    if(player.isCatched==true){
      player.life = player.life-1;
      player.pos=6;
      player.timer=30;
      if(player.life==0){
        game.gameStatus = GAMEOVER;
      }
    }
  }
}
