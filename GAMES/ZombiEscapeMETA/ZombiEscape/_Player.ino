void player_init(){
  player.life = game.playerMaxLife;
  player.hitboxXmin = 2;
  player.hitboxXmax = 5;
  player.hitboxYmin = 3;
  player.hitboxYmax = 7;
  player.weaponType = 0;  
  player.speed_ = 2;
}

void player_initWeapon(){
  //gun [G]
  weapon[0].weaponRangeX = 30;
  weapon[0].weaponRangeY = 0;
  weapon[0].maxAmmo = 6;
  weapon[0].fireTimer = 2; 
  weapon[0].maxNbBullet = 1;
  weapon[0].damage = 2;

  //MachineGun [M]
  weapon[1].weaponRangeX = 30;
  weapon[1].weaponRangeY = 0;
  weapon[1].maxAmmo = 20;
  weapon[1].fireTimer = 0;
  weapon[1].maxNbBullet = 3;
  weapon[1].damage = 1;

  //shotgun [S]
  weapon[2].weaponRangeX = 8;
  weapon[2].weaponRangeY = 5;
  weapon[2].maxAmmo = 2;
  weapon[2].fireTimer = 8;
  weapon[2].maxNbBullet = 3;
  weapon[2].damage = 4;
  
}

void player_initNextLevel(){
  player.xInTheWorld = 10;
  player.x = 10;
  player.y = 32;
  player.ammo = weapon[player.weaponType].maxAmmo;
  player.timer = 0;
  player.isShooting = 0;
  player.isGoingToLeft = false;
  player.isRunning = true; 
  player.isReloading = false;  
}

void player_initLoop(){
  player.isShooting=0;  
  if(player.timer>0){player.timer = player.timer-1;} //invincible timer
}

void player_checkBonus(){
  for(int i = 0; i<15; i++){
    if(bonus[i].type!=99){
      int check = 0;
      //player.x + player.hitboxXmin
      //player.x + player.hitboxXmax
      //player.y + player.hitboxYmin+2
      //player.y + player.hitboxYmax+2

      //bonus[i].x
      //bonus[i].x+7
      //bonus[i].y
      //bonus[i].y+5
      
      
      for(int n=0 ; n<8; n=n+2){
        for(int m=0 ; m<5; m=m+2){
          if(check == 0
             && bonus[i].x + n - level.xWorld >= player.x + player.hitboxXmin
             && bonus[i].x + n - level.xWorld <= player.x + player.hitboxXmax
             && bonus[i].y + m >= player.y + player.hitboxYmin+5
             && bonus[i].y + m <= player.y + player.hitboxYmax+5
          ){
            check = 1;
          }            
        }
      }

      if(check == 1){
        outputLight_bonus();
        outputSound_bonus();
        switch(bonus[i].type){
          case 0 :
            if(player.life < game.playerMaxLife){player.life = player.life +1;}
            bonus[i].type=99;
            bonus[i].x = 0;
            bonus[i].y = 0;
          break;

          case 1 :
            player.timer = 50;
            bonus[i].type=99;
            bonus[i].x = 0;
            bonus[i].y = 0;
          break;

          case 2 :
            player.weaponType = 0;
            player.ammo = weapon[player.weaponType].maxAmmo;
            player.isReloading = false;
            bonus[i].type=99;
            bonus[i].x = 0;
            bonus[i].y = 0;
          break;

          case 3 :
            player.weaponType = 1;
            player.ammo = weapon[player.weaponType].maxAmmo;
            player.isReloading = false;            
            bonus[i].type=99;
            bonus[i].x = 0;
            bonus[i].y = 0;
          break;

          case 4 :
            player.weaponType = 2;
            player.ammo = weapon[player.weaponType].maxAmmo;
            player.isReloading = false; 
            bonus[i].type=99;
            bonus[i].x = 0;
            bonus[i].y = 0;
          break;

                    
        }
      }
    }
  }
}


void player_checkDamage(){
  if(player.timer == 0){
    int hit = 0; //to avoid to be hit 2 time
    for(int j = 0; j<stage.nbOfEnnemies; j++){
      if(hit == 0){
        if(stage.ennemy[j].isDead==0){         //=== If ennemy is not dead === 
          if(stage.ennemy[j].timerDamage==0){       //=== If ennemy is not stunt ===
            //check top left
            if(hit == 0
               && player.x + player.hitboxXmin >= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin - level.xWorld
               && player.x + player.hitboxXmin <= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmax - level.xWorld
               && player.y + player.hitboxYmin >= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmin
               && player.y + player.hitboxYmin <= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmax
            ){
              hit = 1;
            }
            
            //check top right
            if(hit == 0
               && player.x + player.hitboxXmax >= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin - level.xWorld
               && player.x + player.hitboxXmax <= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmax - level.xWorld
               && player.y + player.hitboxYmin >= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmin
               && player.y + player.hitboxYmin <= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmax
            ){
              hit = 1;
            }
             
            //check bottom right
            if(hit == 0
               && player.x + player.hitboxXmax >= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin - level.xWorld
               && player.x + player.hitboxXmax <= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmax - level.xWorld
               && player.y + player.hitboxYmax >= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmin
               && player.y + player.hitboxYmax <= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmax
            ){
              hit = 1;
            }  
    
            //check bottom left
            if(hit == 0
               && player.x + player.hitboxXmin >= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin - level.xWorld
               && player.x + player.hitboxXmin <= stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmax - level.xWorld
               && player.y + player.hitboxYmax >= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmin
               && player.y + player.hitboxYmax <= stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmax
            ){
              hit = 1;
            } 
          }        
        }
      }    
    }

    if(hit==1){
      player.life = player.life - 1;
      player.timer = 30; 
      outputLight_playerDamage();
      outputSound_PlayerHurt();
    }    
  }  
}

void player_checkShot(){
  if(player.fireTimer>0){
    player.fireTimer = player.fireTimer - 1;
  }
}

        

