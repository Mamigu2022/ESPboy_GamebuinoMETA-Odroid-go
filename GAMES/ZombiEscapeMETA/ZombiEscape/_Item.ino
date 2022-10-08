void item_init(){
  for(int i=0;i<15;i++){
    bonus[i].type = 99;
    bonus[i].x = 0;
    bonus[i].y = 0;
    bonus[i].timer = 0;
    bonus[i].isGoingToLeft = false;
  }  
}

void item_initBonus(int x, int y){
  if(game.hardMode==false){
    int freeItem = 0;
    for(int i = 0; i<15; i++){
      if(bonus[i].type==99){
        if(freeItem == 0){
          freeItem=i;
        }
      }
    }
    
    int randValue = random(0,50);
    
    //life
    if(randValue>=0 and randValue<5){
      bonus[freeItem].type=0;
      bonus[freeItem].x = x;
      bonus[freeItem].y = y;
    }
  
    //Invincible
    if(randValue>=10 and randValue<12){
      bonus[freeItem].type=1;
      bonus[freeItem].x = x;
      bonus[freeItem].y = y;
    }
  
    //gun
    if(randValue>=20 and randValue<23){
      bonus[freeItem].type=2;
      bonus[freeItem].x = x;
      bonus[freeItem].y = y;
    }
  
    //machineGun
    if(randValue>=30 and randValue<34){
      bonus[freeItem].type=3;
      bonus[freeItem].x = x;
      bonus[freeItem].y = y;
    }
  
    //shotGun
    if(randValue>=40 and randValue<42){
      bonus[freeItem].type=4;
      bonus[freeItem].x = x;
      bonus[freeItem].y = y;
    }
  }
}
