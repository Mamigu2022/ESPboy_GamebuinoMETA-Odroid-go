void ennemy_init(){
  
  //dead
  game.ennemyType[0].type=0;
  game.ennemyType[0].maxLife=0;
  game.ennemyType[0].walkingSpeed=0; 
  game.ennemyType[0].movingSpeed=0;  
  game.ennemyType[0].hitboxXmin=0;
  game.ennemyType[0].hitboxXmax=0;
  game.ennemyType[0].hitboxYmin=0;
  game.ennemyType[0].hitboxYmax=0; 
    
  //normal
  game.ennemyType[1].type=1;
  game.ennemyType[1].maxLife=4;
  game.ennemyType[1].walkingSpeed=1; 
  game.ennemyType[1].movingSpeed=1;  
  game.ennemyType[1].hitboxXmin=2;
  game.ennemyType[1].hitboxXmax=5;
  game.ennemyType[1].hitboxYmin=2;
  game.ennemyType[1].hitboxYmax=7; 

  //small
  game.ennemyType[2].type=2;
  game.ennemyType[2].maxLife=2;
  game.ennemyType[2].walkingSpeed=2;
  game.ennemyType[2].movingSpeed=2;
  game.ennemyType[2].hitboxXmin=4;
  game.ennemyType[2].hitboxXmax=5;
  game.ennemyType[2].hitboxYmin=4;
  game.ennemyType[2].hitboxYmax=7;

  //big
  game.ennemyType[3].type=3;
  game.ennemyType[3].maxLife=18;
  game.ennemyType[3].walkingSpeed=2;
  game.ennemyType[3].movingSpeed=2;
  game.ennemyType[3].hitboxXmin=1;
  game.ennemyType[3].hitboxXmax=6;
  game.ennemyType[3].hitboxYmin=3;
  game.ennemyType[3].hitboxYmax=13;

  //human
  game.ennemyType[4].type=4;
  game.ennemyType[4].maxLife=1;
  game.ennemyType[4].walkingSpeed=2;
  game.ennemyType[4].movingSpeed=1;  
  game.ennemyType[4].hitboxXmin=2;
  game.ennemyType[4].hitboxXmax=5;
  game.ennemyType[4].hitboxYmin=2;
  game.ennemyType[4].hitboxYmax=7; 
}

void ennemy_initNextLevel(){
  stage.stage = 1;
  ennemy_setNbOfEnnemy();
  ennemy_setEnnemiesPositions(); 
}


void ennemy_initLoop(){}



//############ PRIVATE FUNCTIONS ############
void ennemy_setNbOfEnnemy(){
  
  
  if(level.level == 1){
    stage.nbOfEnnemies = 4;
  }
  
  if(level.level == 2){
    stage.nbOfEnnemies = 4;
  }
  
  if(level.level == 3){
    stage.nbOfEnnemies = 4;
  }
  
  if(level.level == 4){
    stage.nbOfEnnemies = 4;
  }
  
  if(level.level == 5){
    stage.nbOfEnnemies = 4;
  }
}

void ennemy_setEnnemiesPositions(){
  stage.nbOfEnnemies = stage.nbOfEnnemies+(level.level-1)+(stage.stage-1);
  stage.nbOfAliveEnnemies = stage.nbOfEnnemies;
  for(int j=0;j<stage.nbOfEnnemies;j++){
    stage.ennemy[j].type = 1;                                                 //=== TYPE ===//
    stage.ennemy[j].state = 1;                                                //=== STATUS ===//
    if(j%2==0){stage.ennemy[j].x = level.xWorld-(10)-((j/6)*8)-(((j/2)%2)*4);}//=== POSITION X comming from left ===//
    else{stage.ennemy[j].x = level.xWorld+(90)+((j/6)*8)+(((j/2)%2)*4);}      //=== POSITION X comming from right ===//
    stage.ennemy[j].y = 15 + (((j%8)/2)*8) + ((j/8)%2)*4;                     //=== POS Y ===//
    stage.ennemy[j].life = game.ennemyType[stage.ennemy[j].type].maxLife;     //=== LIFE ===//
    stage.ennemy[j].timer = 0;                                                //=== TIMERS ===//
    stage.ennemy[j].timerDamage = 0;                                          //=== TIMERS ===//
    stage.ennemy[j].timerAnim = 0;                                            //=== TIMERS ===//
    stage.ennemy[j].isDead = 0;                                               //=== DEATH ===//
    stage.ennemy[j].isGoingToLeft = 0;                                        //=== DIRECTION ===//
  }  

  if(stage.stage>=3){
    for(int j = 0; j<stage.stage-2;j++){
      stage.ennemy[stage.nbOfEnnemies+j].type = 2;
      stage.ennemy[stage.nbOfEnnemies+j].state = 1;
      if(j%2==0){stage.ennemy[stage.nbOfEnnemies+j].x = level.xWorld-(40)-((j/6)*8)-(((j/2)%2)*4);}  //comming from left
      else{      stage.ennemy[stage.nbOfEnnemies+j].x = level.xWorld+(120)+((j/6)*8)+(((j/2)%2)*4);} //comming from right
      stage.ennemy[stage.nbOfEnnemies+j].y = 15 + (((j%8)/2)*8) + ((j/8)%2)*4; 
      stage.ennemy[stage.nbOfEnnemies+j].life = game.ennemyType[stage.ennemy[stage.nbOfEnnemies+j].type].maxLife;
      stage.ennemy[stage.nbOfEnnemies+j].timer = 0;
      stage.ennemy[stage.nbOfEnnemies+j].timerDamage = 0;
      stage.ennemy[stage.nbOfEnnemies+j].timerAnim = 0;
      stage.ennemy[stage.nbOfEnnemies+j].isDead = 0;
      stage.ennemy[stage.nbOfEnnemies+j].isGoingToLeft = 0;
    }
    stage.nbOfEnnemies = stage.nbOfEnnemies+stage.stage-2;
    stage.nbOfAliveEnnemies = stage.nbOfEnnemies;
  }

  if(stage.stage>=5){
    for(int j = 0; j<(level.level/2)+1;j++){
      stage.ennemy[stage.nbOfEnnemies+j].type = 3;
      stage.ennemy[stage.nbOfEnnemies+j].state = 1;
      if(j%2==1){stage.ennemy[stage.nbOfEnnemies+j].x = level.xWorld-(40)-((j/6)*8)-(((j/2)%2)*4);}  //comming from left
      else{      stage.ennemy[stage.nbOfEnnemies+j].x = level.xWorld+(120)+((j/6)*8)+(((j/2)%2)*4);} //comming from right
      stage.ennemy[stage.nbOfEnnemies+j].y = 15 + (((j%8)/2)*8) + ((j/8)%2)*4; 
      stage.ennemy[stage.nbOfEnnemies+j].life = game.ennemyType[stage.ennemy[stage.nbOfEnnemies+j].type].maxLife;
      stage.ennemy[stage.nbOfEnnemies+j].timer = 0;
      stage.ennemy[stage.nbOfEnnemies+j].timerDamage = 0;
      stage.ennemy[stage.nbOfEnnemies+j].timerAnim = 0;
      stage.ennemy[stage.nbOfEnnemies+j].isDead = 0;
      stage.ennemy[stage.nbOfEnnemies+j].isGoingToLeft = 0;
    }
    stage.nbOfEnnemies = stage.nbOfEnnemies+(level.level/2)+1;
    stage.nbOfAliveEnnemies = stage.nbOfEnnemies;
  }

  
}

void ennemy_move(){
  ennemy_displayOrderH();
  for(int j = 0; j<stage.nbOfEnnemies; j++){
    if(stage.ennemy[j].isDead!=1){         //=== If ennemy is not dead ===  
      if(stage.ennemy[j].timerDamage == 0){//=== If ennemy is not stunt === 
        if(stage.ennemy[j].timer==0 ){     //=== Timer define movement speed ===
          //=== Define speed ===
          stage.ennemy[j].timer=game.ennemyType[stage.ennemy[j].type].walkingSpeed;
          if(stage.ennemy[j].type==3){   //Big Ennemy is running faster an faster when shot
              if(stage.ennemy[j].life>8){stage.ennemy[j].timer=stage.ennemy[j].timer+2;}
              if(stage.ennemy[j].life>10){stage.ennemy[j].timer=stage.ennemy[j].timer+4;}
              if(stage.ennemy[j].life>12){stage.ennemy[j].timer=stage.ennemy[j].timer+6;}
              if(stage.ennemy[j].life>14){stage.ennemy[j].timer=stage.ennemy[j].timer+8;}          
          }
  
          //=== Legs anim ===
          if(stage.ennemy[j].timerAnim==0){stage.ennemy[j].timerAnim=1;}
          else{stage.ennemy[j].timerAnim=0;}
  
          //=== Is running back ===
          stage.ennemy[j].state = 0;


          //Best next position
          int dirNext = 0;
          // 0 1 2
          // 7 X 3
          // 6 5 4
          int tmpx = stage.ennemy[j].x;
          int tmpy = stage.ennemy[j].y;
          
          //=== Define Horizontal movement ===
          if(stage.ennemy[j].x >= player.xInTheWorld){
            dirNext=7;
            tmpx = stage.ennemy[j].x-game.ennemyType[stage.ennemy[j].type].movingSpeed;
            /*
            stage.ennemy[j].isGoingToLeft = 1;
            */
          }else{
            dirNext = 3;
            tmpx = stage.ennemy[j].x+game.ennemyType[stage.ennemy[j].type].movingSpeed;
            /*
            stage.ennemy[j].isGoingToLeft = 0;
            */
          }
          
          //=== Define Vertical movement ===
          if(abs(stage.ennemy[j].x - player.xInTheWorld)<20){
            if(stage.ennemy[j].y >= player.y){
              if(dirNext==3){dirNext=2;}
              if(dirNext==7){dirNext=0;}
              tmpy = stage.ennemy[j].y-game.ennemyType[stage.ennemy[j].type].movingSpeed;
            }else{
              if(dirNext==3){dirNext=4;}
              if(dirNext==7){dirNext=6;}
              tmpy = stage.ennemy[j].y+game.ennemyType[stage.ennemy[j].type].movingSpeed;
            }
          }
          
          //if(checkOtherEnnemiesPosition(j, tmpx, stage.ennemy[j].y)){}
          //if(checkOtherEnnemiesPosition(j, stage.ennemy[j].x, tmpy)){}
          bool check = checkOtherEnnemiesPosition(dirNext, j, tmpx, tmpy);

          for(int i=0; i<8; i++){
            if(check==false){
              if(i%2==1){dirNext = (dirNext-i)%8;}
              else{dirNext = (dirNext+i)%8;}
            
              switch(dirNext){
                case 0:
                  tmpx = stage.ennemy[j].x-game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  tmpy = stage.ennemy[j].y-game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  break;
                  
                case 1:
                  tmpy = stage.ennemy[j].y-game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  break;
                  
                case 2:
                  tmpx = stage.ennemy[j].x+game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  tmpy = stage.ennemy[j].y-game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  break;
                  
                case 3:
                  tmpx = stage.ennemy[j].x+game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  break;
                  
                case 4:
                  tmpx = stage.ennemy[j].x+game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  tmpy = stage.ennemy[j].y+game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  break;
                  
                case 5:
                  tmpy = stage.ennemy[j].y+game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  break;
                  
                case 6:
                  tmpx = stage.ennemy[j].x-game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  tmpy = stage.ennemy[j].y+game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  break;
                  
                case 7:
                  tmpx = stage.ennemy[j].x-game.ennemyType[stage.ennemy[j].type].movingSpeed;
                  break;
              }
              check = checkOtherEnnemiesPosition(dirNext, j, tmpx, tmpy);
            }
          }
          if(check==true){
              if(tmpx<stage.ennemy[j].x){stage.ennemy[j].isGoingToLeft = 1;}
              else{stage.ennemy[j].isGoingToLeft = 0;}
              stage.ennemy[j].x = tmpx; 
              stage.ennemy[j].y = tmpy;  
          }
        }else{
          stage.ennemy[j].timer=stage.ennemy[j].timer-1;
        }
      }else{
        stage.ennemy[j].timerDamage = stage.ennemy[j].timerDamage - 1;  
      }
    }
  }
}



void ennemy_displayOrderV(){
  EnnemyInfo temp;
  for(int j = 0; j<stage.nbOfEnnemies; j++){
    for(int k = j+1; k<stage.nbOfEnnemies; k++){
      if(stage.ennemy[j].y + game.ennemyImg[stage.ennemy[j].type].spriteHeight > stage.ennemy[k].y + game.ennemyImg[stage.ennemy[k].type].spriteHeight){
        temp = stage.ennemy[j];
        stage.ennemy[j]=stage.ennemy[k]; 
        stage.ennemy[k]=temp;    
      }
    }    
  }
}

void ennemy_displayOrderH(){
  EnnemyInfo temp;
  for(int j = 0; j<stage.nbOfEnnemies; j++){
    for(int k = j+1; k<stage.nbOfEnnemies; k++){
      int ennemy1x = 0;
      int ennemy2x = 0;
      if(player.isGoingToLeft==0){
        if(stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin - level.xWorld <= player.x + player.hitboxXmin){
          ennemy1x = (2000) + ((stage.ennemy[j].x + game.ennemyImg[stage.ennemy[j].type].spriteWidth/2)*-1);          
        }else{
          ennemy1x = stage.ennemy[j].x + game.ennemyImg[stage.ennemy[j].type].spriteWidth/2;         
        }
        if(stage.ennemy[k].x + game.ennemyType[stage.ennemy[k].type].hitboxXmin - level.xWorld <= player.x + player.hitboxXmin){
          ennemy2x = (2000) + ((stage.ennemy[k].x + game.ennemyImg[stage.ennemy[k].type].spriteWidth/2)*-1);          
        }else{
          ennemy2x = stage.ennemy[k].x + game.ennemyImg[stage.ennemy[k].type].spriteWidth/2;         
        }        
      }else{
        if(stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin - level.xWorld <= player.x + player.hitboxXmin){
          ennemy1x = (stage.ennemy[j].x + game.ennemyImg[stage.ennemy[j].type].spriteWidth/2)*-1;          
        }else{
          ennemy1x = stage.ennemy[j].x + game.ennemyImg[stage.ennemy[j].type].spriteWidth/2;         
        }
        if(stage.ennemy[k].x + game.ennemyType[stage.ennemy[k].type].hitboxXmin - level.xWorld <= player.x + player.hitboxXmin){
          ennemy2x = (stage.ennemy[k].x + game.ennemyImg[stage.ennemy[k].type].spriteWidth/2)*-1;          
        }else{
          ennemy2x = stage.ennemy[k].x + game.ennemyImg[stage.ennemy[k].type].spriteWidth/2;         
        }         
      }

      
      if( ennemy1x > ennemy2x){
      //if(stage.ennemy[j].x > stage.ennemy[k].x){
        temp = stage.ennemy[j];
        stage.ennemy[j]=stage.ennemy[k]; 
        stage.ennemy[k]=temp;    
      }
    }    
  }
}

bool checkOtherEnnemiesPosition(int dirNext, int current, int checkX, int checkY){
  bool noCollision = true;
  for(int j=0;j<stage.nbOfEnnemies;j++){
    if(j!=current){
      if(noCollision == true){
        if(stage.ennemy[j].isDead == 0){
          switch(dirNext){
            //check top left
            case 0:
              if(
              checkY<14
              or  
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmin, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmin, j)
              ){noCollision=false;}
              break; 

            //check top left
            //check top right
            case 1:
              if(
              checkY<14
              or  
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmin, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmin, j)
              or
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmax, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmin, j)
              ){noCollision=false;}
              break;  

            //check top right
            case 2:
              if(
              checkY<14
              or  
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmax, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmin, j)
              ){noCollision=false;}
              break;  

            //check top right
            //check bottom right
            case 3:
              if(
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmax, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmin, j)
              or
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmax, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmax, j)
              ){noCollision=false;}
              break;  

            //check bottom right
            case 4:
              if(
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmax, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmax, j)
              ){noCollision=false;}
              break;  

            //check bottom right
            //check bottom left
            case 5:
              if(
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmax, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmax, j)
              or
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmin, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmax, j)
              ){noCollision=false;}
              break;  

            //check bottom left 
            case 6:
              if(
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmin, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmax, j)
              ){noCollision=false;}
              break;  

            //check bottom left    
            //check top left      
            case 7:
              if(
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmin, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmax, j)
              or
              isPixelInTheBox(checkX + game.ennemyType[stage.ennemy[current].type].hitboxXmin, checkY + game.ennemyType[stage.ennemy[current].type].hitboxYmin, j)
              ){noCollision=false;}
              break;  
          }
        }
      }
    }
  }
  return noCollision;
}

bool isPixelInTheBox(int checkX, int checkY, int j){
  bool returnCheck = false;
  if( checkX >= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin-1
    && checkX <= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmax+1
    && checkY >= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmin-1
    && checkY <= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmax+1)
    {
      returnCheck = true;
    } 
  return returnCheck;
}

void ennemy_checkDamage(){
  if(player.isShooting){
    int hit = 0; //manage number of ennemies hit in one time
    for(int j=0;j<stage.nbOfEnnemies;j++){
      if(hit<weapon[player.weaponType].maxNbBullet){
        bool ennemyHit = 0; //one ennemy can be hit only one time in a round
        if(stage.ennemy[j].isDead!=1){     
          if(stage.ennemy[j].timerDamage==0){
            for(int k=0; k<=weapon[player.weaponType].weaponRangeY; k = k +3){
              for(int l=k; l<weapon[player.weaponType].weaponRangeX; l = l +2){
                if(ennemyHit==0){
                  
                  int checkX;
                  if(player.isGoingToLeft==0){
                    checkX = player.x-2 + game.playerImg[3].spriteWidth + l;
                  }else{
                    checkX = player.x-6-l;
                  }  
  
                  int checkYup;
                  checkYup = player.y+6+k;
                  
                  int checkYdown;
                  checkYdown = player.y+6-k;
                  
                  if(ennemyHit==0
                      && checkX >= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin - level.xWorld
                      && checkX <= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmax - level.xWorld
                      && checkYup >= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmin
                      && checkYup <= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmax){
                          ennemyHit=1;
                          hit = hit + 1;
                          ennemy_hurt(j);
                   }
  
                  if(ennemyHit==0
                      && checkX >= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin - level.xWorld
                      && checkX <= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmax - level.xWorld
                      && checkYdown >= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmin
                      && checkYdown <= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmax){
                          ennemyHit=1;
                          hit = hit +1;
                          ennemy_hurt(j);
                  }
                }
              }
            }
          }
        }
      }
    }
  }  
}


void ennemy_hurt(int j){
  //ennemy life
  stage.ennemy[j].life = stage.ennemy[j].life - weapon[player.weaponType].damage;
  //recul
  if(stage.ennemy[j].isGoingToLeft==1){stage.ennemy[j].x = stage.ennemy[j].x + 3;}
  else{stage.ennemy[j].x = stage.ennemy[j].x - 3;}
  
  if(stage.ennemy[j].life>0){
    stage.ennemy[j].timerDamage = 10;
  }else{
    item_initBonus(stage.ennemy[j].x, stage.ennemy[j].y + game.ennemyImg[stage.ennemy[j].type].spriteHeight-8);
    stage.ennemy[j].y = stage.ennemy[j].y + game.ennemyImg[stage.ennemy[j].type].spriteHeight-4;
    stage.ennemy[j].x = stage.ennemy[j].x - 4;
    stage.ennemy[j].type=0;
    stage.ennemy[j].isDead=1;
    stage.nbOfAliveEnnemies = stage.nbOfAliveEnnemies - 1;
  }  
}


