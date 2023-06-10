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

     //##################################
     case CARSELECTION:
        if(gb.buttons.pressed(BUTTON_LEFT)){car01.type=car01.type-1;}
        if(gb.buttons.pressed(BUTTON_RIGHT)){car01.type=car01.type+1;}
        if(gb.buttons.pressed(BUTTON_A)){game.gameStatus=MENU;}
        if(gb.buttons.pressed(BUTTON_B)){game.gameStatus=MENU;}
        if(car01.type<0){car01.type=2;}
        if(car01.type>2){car01.type=0;}
        if(car01.type==0){car01.squareSize=5;}
        if(car01.type==1){car01.squareSize=6;}
        if(car01.type==2){car01.squareSize=7;}
     break; 
     
     //##################################
     case MAPSELECTION:
        if(gb.buttons.pressed(BUTTON_LEFT)){mapSelected=mapSelected-1;}
        if(gb.buttons.pressed(BUTTON_RIGHT)){mapSelected=mapSelected+1;}
        if(gb.buttons.pressed(BUTTON_A)){game.gameStatus=MENU;}
        if(gb.buttons.pressed(BUTTON_B)){game.gameStatus=MENU;}
        if(mapSelected<0){mapSelected=amountOfMap-1;}
        if(mapSelected>amountOfMap-1){mapSelected=0;}
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
            game_setPalette(maps[mapSelected].palette);
            game_initActiveColors();
            game_initCarPosition();
            game_resetReplay();
            game_resetCursor();
          break;

          case 2:
            game.gameStatus=CARSELECTION;
          break;

          case 3:
            game.gameStatus=MAPSELECTION;
          break;

          case 4:
            game.gameStatus=CREDITS;
          break;
        }
      }

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.menuOption = game.menuOption - 1;
        if(game.menuOption<=0){game.menuOption=4;}
      }

      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.menuOption = game.menuOption + 1;
        if(game.menuOption>=5){game.menuOption=1;}
      }
     break;

      
     //#################################
     //########### Game ################
     //#################################
     case GAME:
        if(cur.isActive==true){
          if(gb.buttons.pressed(BUTTON_UP)){cur.y=cur.y-car01.squareSize;}
          if(gb.buttons.pressed(BUTTON_DOWN)){cur.y=cur.y+car01.squareSize;}
          if(gb.buttons.pressed(BUTTON_LEFT)){cur.x=cur.x-car01.squareSize;}
          if(gb.buttons.pressed(BUTTON_RIGHT)){cur.x=cur.x+car01.squareSize;}
          if(cur.x>car01.squareSize){cur.x=car01.squareSize;}
          if(cur.x<-car01.squareSize){cur.x=-car01.squareSize;}
          if(cur.y>car01.squareSize){cur.y=car01.squareSize;}
          if(cur.y<-car01.squareSize){cur.y=-car01.squareSize;}
        }
        
        game_setCarPosition();
        
        if(gb.buttons.pressed(BUTTON_A)){
          game.gameStatus=GAMECHECK;
        }

        if(gb.buttons.repeat(BUTTON_B,0)){
          displayGrid=true;
        }

        if(gb.buttons.pressed(BUTTON_MENU)){
          game.gameStatus = MENUPAUSE;
        }
     break;

     //#################################
     //########### GAMECHECK ###########
     //#################################
     case GAMECHECK:
     break;

     //####################################  
     case GAMEOVER:
      if(gb.buttons.pressed(BUTTON_A)){
        game_initActiveColors();
        game_initCarPosition();
        game_resetReplay();
        game_resetCursor();
        if(game.menuPauseOption==0){game.gameStatus = GAME;}
        if(game.menuPauseOption==1){game.gameStatus = MENU; game_resetPalette();}
        game.menuPauseOption=0;
      }else{
        if(gb.buttons.pressed(BUTTON_UP)){    
          game.menuPauseOption = game.menuPauseOption - 1;
          if(game.menuPauseOption<0){game.menuPauseOption=0;}
        }
  
        if(gb.buttons.pressed(BUTTON_DOWN)){    
          game.menuPauseOption = game.menuPauseOption + 1;
          if(game.menuPauseOption>1){game.menuPauseOption=1;}
        } 
      }
        break;     
        
     //####################################  
     case WINNER:
      if(gb.buttons.pressed(BUTTON_A)){
        if(game.menuPauseOption==0){
          replayCounter=0;
          game.gameStatus = REPLAY;
        }
        if(game.menuPauseOption==1){
          mapSelected=(mapSelected+1)%amountOfMap;
          game_initActiveColors();
          game_initCarPosition();
          game_resetReplay();
          game_resetCursor();
          game.gameStatus = GAME;
        }
        if(game.menuPauseOption==2){
          game.gameStatus = MENU;
          game_resetPalette();
        }
        game.menuPauseOption=0;
      }else{
        if(gb.buttons.pressed(BUTTON_UP)){    
          game.menuPauseOption = game.menuPauseOption - 1;
          if(game.menuPauseOption<0){game.menuPauseOption=0;}
        }
  
        if(gb.buttons.pressed(BUTTON_DOWN)){    
          game.menuPauseOption = game.menuPauseOption + 1;
          if(game.menuPauseOption>2){game.menuPauseOption=2;}
        } 
      }
        break;  


     //##################################
     case MENUPAUSE:
      if(gb.buttons.pressed(BUTTON_A)){
        if(game.menuPauseOption==0){
          game.gameStatus = GAME;
        }
        if(game.menuPauseOption==1){
          game_initActiveColors();
          game_initCarPosition();
          game_resetReplay();
          game_resetCursor();
          game.gameStatus = GAME;
        }
        if(game.menuPauseOption==2){
          game.gameStatus = MENU;
          game_resetPalette();
        }
        game.menuPauseOption=0;
      }else{
        if(gb.buttons.pressed(BUTTON_B) or gb.buttons.pressed(BUTTON_MENU)){
          game.gameStatus = GAME;
          game.menuPauseOption=0;
        }else{
          if(gb.buttons.pressed(BUTTON_UP)){    
            game.menuPauseOption = game.menuPauseOption - 1;
            if(game.menuPauseOption<0){game.menuPauseOption=0;}
          }
    
          if(gb.buttons.pressed(BUTTON_DOWN)){    
            game.menuPauseOption = game.menuPauseOption + 1;
            if(game.menuPauseOption>2){game.menuPauseOption=2;}
          } 
        }
      }
     break; 
  }
}
