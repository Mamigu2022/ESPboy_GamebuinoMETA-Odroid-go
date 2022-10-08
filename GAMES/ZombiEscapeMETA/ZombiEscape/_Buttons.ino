void button_check(int typeCheck){
  switch(typeCheck){
     //################# GAMEMAKERS SCREEN #################
     case GAMEMAKERS:
      if(gb.buttons.pressed(BUTTON_A)){
        globalTimer = 0;
        game.gameStatus=TITLESCREEN;
      }
     break;    
    
     //################# TITLE SCREEN #################
     case TITLESCREEN:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.hardMode = false; 
        globalTimer = 0;
        game.gameStatus=SELECTPLAYER;
      }

      if(gb.buttons.pressed(BUTTON_A) && gb.buttons.pressed(BUTTON_DOWN)){
        game.hardMode = true;    
        game.playerMaxLife = 1;
        player.life = 1;   
      }  

     break;    
    
     //################# SELECTPLAYER #################
     case SELECTPLAYER:      
      if(gb.buttons.pressed(BUTTON_A)){ 
        level.level=1;
        globalTimer = 0;
        game.gameStatus=LVLINTRO;
      }

      if(gb.buttons.pressed(BUTTON_LEFT)){    
         game.isFemale = false;
         outputScreen_initPlayerSprites();
         if(game.hardMode==false){
           player.speed_ = 2;
           game.playerMaxLife = 3;
           player.life = 3;
           }
      }

      if(gb.buttons.pressed(BUTTON_RIGHT)){    
         game.isFemale = true;
         outputScreen_initPlayerSprites();
         if(game.hardMode==false){
           player.speed_ = 3;
           game.playerMaxLife = 2;
           player.life = 2;
         }
      } 

     break;

     //################# LEVEL INTRO SCREEN #################
     case LVLINTRO: //level intro
      if(gb.buttons.pressed(BUTTON_A)){
        globalTimer = 0;
        game_initNextLevel();
        item_init();
        ennemy_initNextLevel();
        player_initNextLevel();      
        game_setBackground();
        game.gameStatus=GAME;
      }
     break;

     //################# GAME #################
     case GAME:
      //==== GUN isShooting ====
      if(gb.buttons.pressed(BUTTON_A) && player.ammo>0 && player.isReloading==0 && player.fireTimer==0){
        switch(player.weaponType){
          case 0:
            player.fireTimer = weapon[player.weaponType].fireTimer;
            outputSound_gunisShooting();
            outputLight_gunFire();
            player.isShooting=1;
            player.ammo--;    
          break;
  
          //Machine Gun
          case 1:
          break;
      
          //Shot Gun
          case 2:
            player.fireTimer = weapon[player.weaponType].fireTimer;
            outputSound_gunisShooting();
            outputLight_gunFire();
            player.isShooting=1;
            player.ammo--;         
          break;
        }                     
      }

      if(gb.buttons.repeat(BUTTON_A,1) && player.ammo>0 && player.isReloading==0 && player.fireTimer==0){
        switch(player.weaponType){
          case 0: 
          break;
  
          //Machine Gun
          case 1:
            outputSound_gunisShooting();
            if(globalTimer%2==1){outputLight_gunFire();}
            player.isShooting=1;
            player.ammo--;           
          break;
      
          //Shot Gun
          case 2:         
          break;
        }                     
      }

      //==== PLAYER LEGS ANIMATION ====  
      if(gb.buttons.repeat(BUTTON_RIGHT,1) || gb.buttons.repeat(BUTTON_LEFT,1) || gb.buttons.repeat(BUTTON_UP,1) || gb.buttons.repeat(BUTTON_DOWN,1)){
        if(player.isRunning == true){
          player.isRunning = false;
        }else{
          player.isRunning = true;
        }
      }else{
        player.isRunning = false;  
      }

      //==== MOVE PLAYER UP ====
      if(gb.buttons.repeat(BUTTON_UP,1)){
        if(player.y>15){
          player.y = player.y - player.speed_;
        }       
      }

      //==== MOVE PLAYER DOWN
      if(gb.buttons.repeat(BUTTON_DOWN,1)){
        if(player.y<52){
          player.y = player.y + player.speed_;
        }       
      }

      //==== MOVE PLAYER RIGHT ====
      if(gb.buttons.repeat(BUTTON_RIGHT,1)){
        player.isGoingToLeft = 0;
        if(player.xInTheWorld > stage.tmpStart+32 && player.xInTheWorld < stage.finish-32 && level.xWorld+SCREENWIDTH < stage.finish){ 
          player.xInTheWorld = player.xInTheWorld + player.speed_;
          level.xWorld = level.xWorld + player.speed_;
          if(stage.tmpStart<stage.start){
             stage.tmpStart=stage.tmpStart+player.speed_;
          }
        }else{
          if(player.xInTheWorld+player.speed_<=stage.finish-8){
            player.xInTheWorld = player.xInTheWorld + player.speed_;
            player.x=player.x+player.speed_;
          }
        }
      }else {
        //==== MOVE PLAYER LEFT ====
        if(gb.buttons.repeat(BUTTON_LEFT,1)){
          player.isGoingToLeft = 1;
          if(player.xInTheWorld > stage.tmpStart+32 && player.xInTheWorld < stage.finish-32 && level.xWorld > stage.tmpStart){
            level.xWorld = level.xWorld - player.speed_;
            player.xInTheWorld = player.xInTheWorld - player.speed_;
          }else{
            if(player.xInTheWorld+player.speed_>=stage.tmpStart+4){
              player.x=player.x-player.speed_;
              player.xInTheWorld = player.xInTheWorld - player.speed_;
            }
          }
        }
      }

      //==== PLAYER RELOAD GUN ====
      if((gb.buttons.pressed(BUTTON_B) || player.isReloading == true) && (player.fireTimer==0 || player.ammo==0)){
        player.isReloading = false;
        if(player.ammo<weapon[player.weaponType].maxAmmo){
          player.isReloading = true;
          player.ammo++;
          player.fireTimer = weapon[player.weaponType].fireTimer;
        }
      } 

     break;

     //################# GAME OVER #################
     case GAMEOVER: 
     if(globalTimer >= SCREENHEIGHT/2+3){
       if(game.hardMode==false){
         if(gb.buttons.pressed(BUTTON_A)){
           game.continueAsEnnemy = true;
           outputScreen_initPlayerContinue();
           player.life = game.playerMaxLife;;
           game.gameStatus=GAME;
         }else{
           if(gb.buttons.pressed(BUTTON_B)){
             game_init();
             player_init();
             ennemy_init();
             player_initWeapon();
             globalTimer = 0;
           }
         }
       }else{
        if(gb.buttons.pressed(BUTTON_A)){
          game_init();
          player_init();
          ennemy_init();
          player_initWeapon();
          globalTimer = 0;
        }
       }
     }
     break;

     //################# THE END #################
     case THEEND:  
     if(globalTimer>= 300){
       if(gb.buttons.pressed(BUTTON_A)){ 
          if(game.continueAsEnnemy==true){
            game_init();
            player_init();
            ennemy_init();
            player_initWeapon();
            globalTimer = 0;
          }else{
            game.gameStatus=TIPSHARDMODE;
          }
       } 
     }
     break;    
     
     //################# GAME OVER #################
     case TIPSHARDMODE:  
     if(globalTimer>=100){
       if(gb.buttons.pressed(BUTTON_A)){
        game_init();
        player_init();
        ennemy_init();
        player_initWeapon();
        globalTimer = 0;
       }
     }
     break; 
  }
}
