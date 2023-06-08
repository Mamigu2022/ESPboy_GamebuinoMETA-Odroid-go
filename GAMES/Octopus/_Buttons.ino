void button_check(int typeCheck){
  switch(typeCheck){    
     //####################################
     //########### Skip title #############
     //####################################
     case TITLESCREEN:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=MENU;
      }
     break;   

     //####################################
     //########### Controls P1 ############
     //####################################
     case CONTROLS:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.gameStatus=MENU;
      }
     break; 

     //####################################
     //########### Credits ################
     //####################################
     case CREDITS:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.gameStatus=MENU;
      }
     break;
     
     //#######################################
     //############# Menu ####################
     //#######################################
     case MENU:      
      if(gb.buttons.pressed(BUTTON_A)){
        switch(game.menuOption){
          case 0:
          break;

          case 1:
            game.gameStatus=GAME;
          break;

          case 2:
            game.gameStatus=CONTROLS;
          break;

          case 3:
            game.gameStatus=CREDITS;
          break;
        }
      }

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.menuOption = game.menuOption - 1;
        if(game.menuOption<=0){game.menuOption=3;}
      }

      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.menuOption = game.menuOption + 1;
        if(game.menuOption>=4){game.menuOption=1;}
      }
      
      if(gb.buttons.pressed(BUTTON_LEFT)){    
        game.backgroundOption=0;
      } 

      if(gb.buttons.pressed(BUTTON_RIGHT)){    
        game.backgroundOption=1;
      } 
     break;


     //##################################
     case GAME:
       if(player.isCatched==false){
        if(gb.buttons.pressed(BUTTON_LEFT)){    
          if(player.pos==5){
            player.timer=0;
          }
          
          if(player.pos>0){
            player.pos = player.pos-1;
            outputSound_toc();
            if(player.pos==0 && player.timer==0 && player.hasGold==true){
              game_addBonus();
            }
          }
        } 
  
        if(gb.buttons.pressed(BUTTON_RIGHT)){
          if(player.pos==5 && player.timer==0){
            player.timer=14;
          }
          if(player.pos<5){
            player.pos = player.pos+1;
            outputSound_toc();
          }
        } 
       }
      if(gb.buttons.pressed(BUTTON_MENU)){
        game.gameStatus = MENUPAUSE;
      }

     break;
     
     //##################################
     case MENUPAUSE:
      if(gb.buttons.pressed(BUTTON_A)){
        if(game.menuPauseOption==0){
          game.gameStatus = GAME;
        }else{
          game_init();
          player_init();
          ennemy_init();
          game.gameStatus = TITLESCREEN;

        }
      }
      if(gb.buttons.pressed(BUTTON_UP)){    
        game.menuPauseOption = game.menuPauseOption - 1;
        if(game.menuPauseOption<0){game.menuPauseOption=1;}
      }

      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.menuPauseOption = game.menuPauseOption + 1;
        if(game.menuPauseOption>1){game.menuPauseOption=0;}
      } 
     break; 

     //####################################  
     case GAMEOVER:
      if(gb.buttons.pressed(BUTTON_MENU) || gb.buttons.pressed(BUTTON_A) || gb.buttons.pressed(BUTTON_B)){
        game_init();
        player_init();
        ennemy_init();
        game.gameStatus = TITLESCREEN;
      }
        break;
  }
}
