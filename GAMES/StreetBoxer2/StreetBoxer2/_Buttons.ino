void button_check(int typeCheck){
  switch(typeCheck){
     //####################################
     //########### Skip Logo ##############
     //####################################
     case GAMEMAKERS:
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=TITLESCREEN;
      }
     break;    
    
     //####################################
     //########### Skip title #############
     //####################################
     case TITLESCREEN:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=SELECTNBPLAYER;
      }
     break;    
    
     //####################################
     //########### Controls P1 ############
     //####################################
     case CONTROLSP1:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.gameStatus=CONTROLSP2;
      }
     break; 

     //####################################
     //########### Controls P2 ############
     //####################################
     case CONTROLSP2:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.nbPlayer = 1;
        game.gameStatus=SELECTNBPLAYER;
      }
     break;  

     //####################################
     //########### Credits ################
     //####################################
     case CREDITS:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.nbPlayer = 1;
        game.gameStatus=SELECTNBPLAYER;
      }
     break;      
    
     //###########################################################
     //############# Buttons select Nb Player ####################
     //###########################################################
     case SELECTNBPLAYER:      
      if(gb.buttons.pressed(BUTTON_A)){
        switch(game.nbPlayer){
          case 0:
          break;

          case 1:
            outputScreen_init1PlayerSprites();
            game.gameStatus=SELECTPLAYER1;
          break;

          case 2:
            outputScreen_init2PlayersSprites();
            game.gameStatus=SELECTPLAYER1;
          break;

          case 3:
            game.gameStatus=CONTROLSP1;
          break;

          case 4:
            game.gameStatus=CREDITS;
          break;
        }
      }

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.nbPlayer = game.nbPlayer - 1;
        if(game.nbPlayer<=0){game.nbPlayer=4;}
      }

      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.nbPlayer = game.nbPlayer + 1;
        if(game.nbPlayer>=5){game.nbPlayer=1;}
      } 

     break;    
    
     //###########################################################
     //############# Buttons select Player 1 #####################
     //###########################################################
     case SELECTPLAYER1:      
      if(gb.buttons.pressed(BUTTON_A)){
        if(game.selectedPlayer1 == NBPERSOS){game.selectedPlayer1 = random(0,4);} 
        if(game.nbPlayer==1){
          player1.x=36; 
          player1.y=27;
        }else{
          player1.x=30; 
          player1.y=32;
        }
        player1.type = game.selectedPlayer1; 
        player1.life = playerType[game.selectedPlayer1].maxLife; 
        player1.power = playerType[game.selectedPlayer1].maxPower; 
        player1.typeDamage = 0;
        player1.timerPower = 0;
        player1.lockPower = 0;
        player1.timerHit = 0;
        player1.timerProtect = 0;  
        player1.timerWalk = 0; 
        player1.isGoingToLeft = true; 
        player1.feetPosition = 0;
        player1.isShooting = false; 
        player1.isProtecting = false;
        game.gameStatus=SELECTPLAYER2;
      }

      if(gb.buttons.pressed(BUTTON_B)){
        game.gameStatus=SELECTNBPLAYER;
      }
      

      if(gb.buttons.pressed(BUTTON_LEFT)){    
        game.selectedPlayer1 = game.selectedPlayer1 - 1;
        if(game.selectedPlayer1 < 0){game.selectedPlayer1 = NBPERSOS;}
      }

      if(gb.buttons.pressed(BUTTON_RIGHT)){    
        game.selectedPlayer1 = game.selectedPlayer1 + 1;
        if(game.selectedPlayer1 > NBPERSOS){game.selectedPlayer1 = 0;}
      } 

     break;    


     //##################################################################
     //############# Buttons select Player 2 or CPU #####################
     //##################################################################
     case SELECTPLAYER2:      
      if(gb.buttons.pressed(BUTTON_A)){
        if(game.selectedPlayer2 == NBPERSOS){game.selectedPlayer2 = random(0,4);}
        if(game.nbPlayer==1){
          player2.x=36; 
          player2.y=18;
        }else{
          player2.x=40; 
          player2.y=32;
        }
        player2.type = game.selectedPlayer2; 
        player2.life = playerType[game.selectedPlayer2].maxLife; 
        player2.power = playerType[game.selectedPlayer2].maxPower; 
        player2.typeDamage = 0;
        player2.timerPower = 0;
        player2.lockPower = 0;
        player2.timerHit = 0;
        player2.timerProtect = 0;
        player2.timerWalk = 0;
        player2.isGoingToLeft = true; 
        player2.feetPosition = 0;
        player2.isShooting = false; 
        player2.isProtecting = false;
        
        game.gameStatus=ANIMFIGHT;

      }

      if(gb.buttons.pressed(BUTTON_B)){
        game.gameStatus=SELECTPLAYER1;
      }

      if(gb.buttons.pressed(BUTTON_LEFT)){    
        game.selectedPlayer2 = game.selectedPlayer2 - 1;
        if(game.selectedPlayer2 < 0){game.selectedPlayer2 = NBPERSOS;}
        if(game.nbPlayer==1){
          if(game.selectedPlayer2 == game.selectedPlayer1){game.selectedPlayer2 = game.selectedPlayer2 - 1;}
        }
        if(game.selectedPlayer2 < 0){game.selectedPlayer2 = NBPERSOS;}
      }

      if(gb.buttons.pressed(BUTTON_RIGHT)){    
        game.selectedPlayer2 = game.selectedPlayer2 + 1;
        if(game.selectedPlayer2 > NBPERSOS){game.selectedPlayer2 = 0;}
        if(game.nbPlayer==1){
          if(game.selectedPlayer2 == game.selectedPlayer1){game.selectedPlayer2 = game.selectedPlayer2 + 1;}
        }
        if(game.selectedPlayer2 > NBPERSOS){game.selectedPlayer2 = 0;}
      } 
     break;    
    
     //####################################################################
     //############# Buttons Player - One player game #####################
     //####################################################################
     case GAME1PLAYER:
      //##################
      //##### PLAYER #####   
      //##################  
      if(gb.buttons.pressed(BUTTON_A)){ //hit if enougth power (right arm)
        if(player1.power>10){
          if(player1.timerHit==0 and player1.isProtecting==false){
            player1.timerHit = (5-playerType[player1.type].maxHitSpeed)*2;
            player1.timerHit = player1.timerHit * -1;
            player1.power = player1.power -10;
            player1.timerPower = playerType[player1.type].waitPower; //wait before increasing power again
          }
        }
      }

      if(gb.buttons.pressed(BUTTON_B)){ //hit if enougth power (left arm)
        if(player1.power>10){
          if(player1.timerHit==0 and player1.isProtecting==false){
            player1.timerHit = (5-playerType[player1.type].maxHitSpeed)*2;
            player1.power = player1.power -10;
            player1.timerPower = playerType[player1.type].waitPower; //wait before increasing power again
          }
        }
      }

      if(gb.buttons.repeat(BUTTON_LEFT, 0) || gb.buttons.repeat(BUTTON_RIGHT, 0) || gb.buttons.repeat(BUTTON_DOWN, 0) || gb.buttons.repeat(BUTTON_UP, 0)){  //protect
        if(player1.timerHit==0){
          if(player1.lockPower==0){
            if(player1.power>0){
              player1.isProtecting=true; 
              if(player1.timerProtect>20){
                player1.power = player1.power - 1;
                if(player1.power == 0){
                  player1.lockPower = 15;
                  player1.isProtecting=false;
                }
              }
              player1.timerProtect = player1.timerProtect + 1;
            }else{
              player1.isProtecting=false; 
            }
          }
        } 
      }
      
      if(gb.buttons.released(BUTTON_LEFT) || gb.buttons.released(BUTTON_RIGHT) || gb.buttons.released(BUTTON_DOWN) || gb.buttons.released(BUTTON_UP)){  
        player1.timerProtect = 0;
        player1.isProtecting=false;
      }

      //###############
      //##### CPU ##### 
      //###############    
      if(padPlayer2.btnA_pressed==true){ //hit if enougth power (right arm)
        if(player2.power>10){
          if(player2.timerHit==0 and player2.isProtecting==false){
            player2.timerHit = (5-playerType[player2.type].maxHitSpeed)*2;
            player2.timerHit = player2.timerHit * -1;
            player2.power = player2.power -10;
            player2.timerPower = playerType[player2.type].waitPower; //wait before increasing power again
          }
        }
      }

      if(padPlayer2.btnB_pressed==true){ //hit if enougth power (left arm)
        if(player2.power>10){
          if(player2.timerHit==0 and player2.isProtecting==false){
            player2.timerHit = (5-playerType[player2.type].maxHitSpeed)*2;
            player2.power = player2.power -10;
            player2.timerPower = playerType[player2.type].waitPower; //wait before increasing power again
          }
        }
      }

      if(padPlayer2.btnLEFT_released>0 || padPlayer2.btnRIGHT_released>0 || padPlayer2.btnDOWN_released>0 || padPlayer2.btnUP_released>0){  //protect
        if(player2.timerHit==0){
          if(player2.lockPower==0){
            if(player2.power>0){
              player2.isProtecting=true; 
              if(player2.timerProtect>20){
                player2.power = player2.power - 1;
                if(player2.power == 0){
                  player2.lockPower = 15;
                  player2.isProtecting=false;
                }
              }
              player2.timerProtect = player2.timerProtect + 1;
            }else{
              player2.isProtecting=false; 
            }
          }
        } 
      }
      
      if(padPlayer2.btnLEFT_released==0 && padPlayer2.btnRIGHT_released==0 && padPlayer2.btnDOWN_released==0 && padPlayer2.btnUP_released==0){  
        player2.timerProtect = 0;
        player2.isProtecting=false;
      }



     break;    
    
     //####################################################################
     //############# Buttons Player - Two player game #####################
     //####################################################################
     case GAME2PLAYER:
     
      //##### PLAYER 1 Protect #####
      if(gb.buttons.repeat(BUTTON_UP, 0)){
        if(player1.timerHit==0){
          if(player1.lockPower==0){
            if(player1.power>0){
              player1.isProtecting=true; 
              if(player1.timerProtect>20){
                player1.power = player1.power - 1;
                if(player1.power == 0){
                  player1.lockPower = 15;
                  player1.isProtecting=false; 
                }
              }
              player1.timerProtect = player1.timerProtect + 1;
            }else{
              player1.isProtecting=false; 
            }
          }
        } 
      }
      
      //##### PLAYER 1 Protect stop protect #####
      if(gb.buttons.released(BUTTON_UP)){
        player1.timerProtect = 0;
        player1.isProtecting=false;
      }

      //##### PLAYER 1 attack #####      
      if(gb.buttons.pressed(BUTTON_DOWN)){ 
        if(player1.power>10){
          if(player1.timerHit==0 and player1.isProtecting==false){
            player1.timerHit = (5-playerType[player1.type].maxHitSpeed)*2;
            player1.power = player1.power -10;
            player1.timerPower = playerType[player1.type].waitPower; //wait before increasing power again
          }
        }
      }

      //##### PLAYER 2 Protect #####
      if(gb.buttons.repeat(BUTTON_A, 0)){  
        //protect
        if(player2.timerHit==0){
          if(player2.lockPower==0){
            if(player2.power>0){
              player2.isProtecting=true; 
              if(player2.timerProtect>20){
                player2.power = player2.power - 1;
                if(player2.power == 0){
                  player2.lockPower = 15;
                  player2.isProtecting=false;
                }
              }
              player2.timerProtect = player2.timerProtect + 1;
            }else{
              player2.isProtecting=false; 
            }
          }
        } 
      }

      //##### PLAYER 2 Stop Protect #####
      if(gb.buttons.released(BUTTON_A)){  
        player2.timerProtect = 0;
        player2.isProtecting=false;
      }

      //##### PLAYER 2 Attack #####
      if(gb.buttons.pressed(BUTTON_B)){    
        //hit if enougth power
        if(player2.power>10){
          if(player2.timerHit==0 and player2.isProtecting==false){
            player2.timerHit = (5-playerType[player2.type].maxHitSpeed)*2;
            player2.power = player2.power -10;
            player2.timerPower = playerType[player2.type].waitPower; //wait before increasing power again
          }
        }
      } 
     break;     

     //##################################
     case WINNER:
      if(gb.buttons.pressed(BUTTON_A) || gb.buttons.pressed(BUTTON_B) || gb.buttons.pressed(BUTTON_UP) || gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_DOWN) || gb.buttons.pressed(BUTTON_RIGHT) ){ 
        game.gameStatus = TITLESCREEN; 
      }
     break;  

    
     //##################################
     case MENU:

     break;  
  }
}
