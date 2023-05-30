void drawMeta(){
  
  drawLevel();
  
  draw_barre(true); 
  
  
  if(isLives == true){
    drawPL();
  }else if(isLives == false){
    if(dead_anim == true){
      gb.lights.fill(RED);
      dead_f +=1;
      dead.setFrame(dead_f);
      gb.display.drawImage(dead_X, dead_Y, dead);
      if (dead_f > 6){
         dead_anim = false;
      }
    }
    if(dead_anim == false){
      openning_T += 3;
      gb.display.drawImage(0,-64+openning_T,openning);
      if (openning_T >= 61){
        openning_T = 61;
        delay(2000);
        menu_games = 2;
      }
    }
  }
  nextLevel();
}


void drawPL(){
  
  if(level_1[timo_Y/8][timo_X/8] == 6 ||
     level_1[timo_Y/8][timo_X/8] == 7 || 
     level_1[timo_Y/8][timo_X/8] == 8 ||
     level_1[timo_Y/8][timo_X/8] == 9 ||
     timo_X/8 == tima_X/8 && timo_Y/8 == tima_Y/8 ){
    isLives = false;
    dead_X = floor(timo_X/8)*8;
    dead_Y = floor(timo_Y/8)*8;
    gb.sound.fx(sfx_2);
  }
  if(level_1[tima_Y/8][tima_X/8] == 6 ||
     level_1[tima_Y/8][tima_X/8] == 7 || 
     level_1[tima_Y/8][tima_X/8] == 8 ||
     level_1[tima_Y/8][tima_X/8] == 9 ){
     isLives = false;
     dead_X = floor(tima_X/8)*8;
     dead_Y = floor(tima_Y/8)*8;
     gb.sound.fx(sfx_2);
  }
  
  if(level_1[timo_Y/8][timo_X/8] == 4){
    timoOnBase = true; 
  }else{
    timoOnBase = false;
  }
  if(level_1[tima_Y/8][tima_X/8] == 5){
    timaOnBase = true; 
  }else{
    timaOnBase = false;
  }
    
  if(timoOnBase == true){
    gb.display.drawImage(timo_X,timo_Y,timoOk);
    gb.lights.drawPixel(0,0,RED);
    gb.lights.drawPixel(0,1,RED);
    gb.lights.drawPixel(0,2,RED);
    gb.lights.drawPixel(0,3,RED);
    if(base_snd == true){gb.sound.fx(sfx_0);base_snd=false;}
  }else if(timoOnBase == false && openning_l==false){
    gb.display.drawImage(timo_X,timo_Y,timo);
    gb.lights.drawPixel(0,0,BLACK);
    gb.lights.drawPixel(0,1,BLACK);
    gb.lights.drawPixel(0,2,BLACK);
    gb.lights.drawPixel(0,3,BLACK);
    base_snd=true;
  }
    if(timaOnBase == true){
    gb.display.drawImage(tima_X,tima_Y,timaOk,-tima_T,8);
    gb.lights.drawPixel(1,0,BLUE);
    gb.lights.drawPixel(1,1,BLUE);
    gb.lights.drawPixel(1,2,BLUE);
    gb.lights.drawPixel(1,3,BLUE);
    if(base_snd2 == true){gb.sound.fx(sfx_0);base_snd2=false;}
  }else if(timaOnBase == false  && openning_l==false){
    gb.display.drawImage(tima_X,tima_Y,tima,-tima_T,8);
    gb.lights.drawPixel(1,0,BLACK);
    gb.lights.drawPixel(1,1,BLACK);
    gb.lights.drawPixel(1,2,BLACK);
    gb.lights.drawPixel(1,3,BLACK);
    base_snd2=true;
  }
  
}

void drawLevel(){
    for(int rangee = 0;rangee < 10; rangee++){
    for(int colonne = 0; colonne < 8; colonne++){
      if(level_1[colonne][rangee] == 1){
        gb.display.drawImage(rangee*8,colonne*8,block);
      }
      if(level_1[colonne][rangee] == 4){
        gb.display.drawImage(rangee*8,colonne*8,timoBase);
      }
      if(level_1[colonne][rangee] == 5){
        gb.display.drawImage(rangee*8,colonne*8,timaBase);
      }
      if(level_1[colonne][rangee] == 6){
        gb.display.drawImage(rangee*8,colonne*8,pique,8,-8);
      }
      if(level_1[colonne][rangee] == 7){
        gb.display.drawImage(rangee*8,colonne*8,pique);
      }
       if(level_1[colonne][rangee] == 8){
        gb.display.drawImage(rangee*8,colonne*8,pique2,-8,8);
      }
       if(level_1[colonne][rangee] == 9){
        gb.display.drawImage(rangee*8,colonne*8,pique2);
      }
      if(level_1[colonne][rangee] == 10){
        gb.display.drawImage(rangee*8,colonne*8,dblock);
      }
      
      if(level_1[colonne][rangee] == 2){
        timo_X = rangee * 8;
        timo_Y = colonne * 8;
        level_1[colonne][rangee] = 0;
      }
      if(level_1[colonne][rangee] == 3){
        tima_X = rangee * 8;
        tima_Y = colonne * 8;
        level_1[colonne][rangee] = 0;
      }
    }
  }
}

void draw_barre(bool openclose){
  if (openclose == true){
   if(openning_l == true){
      openning_T += 2;
      gb.display.drawImage(0,0-openning_T,openning);
      if (openning_T == 2 || openning_T == 16 || openning_T == 32 || openning_T == 48|| openning_T == 64){gb.sound.fx(sfx_3);}
      if (openning_T < 16){
        gb.lights.drawPixel(0,0,WHITE);gb.lights.drawPixel(1,0,WHITE);
        gb.lights.drawPixel(0,1,WHITE);gb.lights.drawPixel(1,1,WHITE);
        gb.lights.drawPixel(0,2,WHITE);gb.lights.drawPixel(1,2,WHITE);
        gb.lights.drawPixel(0,3,WHITE);gb.lights.drawPixel(1,3,WHITE);
        
       }
      if (openning_T >= 16){
        gb.lights.drawPixel(0,0,WHITE);gb.lights.drawPixel(1,0,WHITE);
        gb.lights.drawPixel(0,1,WHITE);gb.lights.drawPixel(1,1,WHITE);
        gb.lights.drawPixel(0,2,WHITE);gb.lights.drawPixel(1,2,WHITE);
        gb.lights.drawPixel(0,3,BLACK);gb.lights.drawPixel(1,3,BLACK);
        
      }
      if (openning_T >= 32){
        gb.lights.drawPixel(0,0,WHITE);gb.lights.drawPixel(1,0,WHITE);
        gb.lights.drawPixel(0,1,WHITE);gb.lights.drawPixel(1,1,WHITE);
        gb.lights.drawPixel(0,2,BLACK);gb.lights.drawPixel(1,2,BLACK);
        gb.lights.drawPixel(0,3,BLACK);gb.lights.drawPixel(1,3,BLACK);
        
      }
      if (openning_T >= 48){
        gb.lights.drawPixel(0,0,WHITE);gb.lights.drawPixel(1,0,WHITE);
        gb.lights.drawPixel(0,1,BLACK);gb.lights.drawPixel(1,1,BLACK);
        gb.lights.drawPixel(0,2,BLACK);gb.lights.drawPixel(1,2,BLACK);
        gb.lights.drawPixel(0,3,BLACK);gb.lights.drawPixel(1,3,BLACK);
        
      }
      if (openning_T >= 64){
        gb.lights.drawPixel(0,0,BLACK);gb.lights.drawPixel(1,0,BLACK);
        gb.lights.drawPixel(0,1,BLACK);gb.lights.drawPixel(1,1,BLACK);
        gb.lights.drawPixel(0,2,BLACK);gb.lights.drawPixel(1,2,BLACK);
        gb.lights.drawPixel(0,3,BLACK);gb.lights.drawPixel(1,3,BLACK);
        
      }
      if (openning_T >= 61){
        openning_T = 0;
        openning_l = false;
      }
  }
 }
 if (openclose == false){
      //
    openning_T += 2;
    gb.display.drawImage(0,-64+openning_T,openning);
          if (openning_T == 2 || openning_T == 16 || openning_T == 32 || openning_T == 48|| openning_T == 64){gb.sound.fx(sfx_3);}
      if (openning_T < 16){
        gb.lights.drawPixel(0,0,BLACK);gb.lights.drawPixel(1,0,BLACK);
        gb.lights.drawPixel(0,1,BLACK);gb.lights.drawPixel(1,1,BLACK);
        gb.lights.drawPixel(0,2,BLACK);gb.lights.drawPixel(1,2,BLACK);
        gb.lights.drawPixel(0,3,BLACK);gb.lights.drawPixel(1,3,BLACK);
        
      }
      if (openning_T > 16){
        gb.lights.drawPixel(0,0,WHITE);gb.lights.drawPixel(1,0,WHITE);
        gb.lights.drawPixel(0,1,BLACK);gb.lights.drawPixel(1,1,BLACK);
        gb.lights.drawPixel(0,2,BLACK);gb.lights.drawPixel(1,2,BLACK);
        gb.lights.drawPixel(0,3,BLACK);gb.lights.drawPixel(1,3,BLACK);
        
      }
      if (openning_T > 32){
        gb.lights.drawPixel(0,0,WHITE);gb.lights.drawPixel(1,0,WHITE);
        gb.lights.drawPixel(0,1,WHITE);gb.lights.drawPixel(1,1,WHITE);
        gb.lights.drawPixel(0,2,BLACK);gb.lights.drawPixel(1,2,BLACK);
        gb.lights.drawPixel(0,3,BLACK);gb.lights.drawPixel(1,3,BLACK);
        
      }
      if (openning_T > 48){
        gb.lights.drawPixel(0,0,WHITE);gb.lights.drawPixel(1,0,WHITE);
        gb.lights.drawPixel(0,1,WHITE);gb.lights.drawPixel(1,1,WHITE);
        gb.lights.drawPixel(0,2,WHITE);gb.lights.drawPixel(1,2,WHITE);
        gb.lights.drawPixel(0,3,BLACK);gb.lights.drawPixel(1,3,BLACK);
        
      }
      if (openning_T > 60){
        gb.lights.drawPixel(0,0,WHITE);gb.lights.drawPixel(1,0,WHITE);
        gb.lights.drawPixel(0,1,WHITE);gb.lights.drawPixel(1,1,WHITE);
        gb.lights.drawPixel(0,2,WHITE);gb.lights.drawPixel(1,2,WHITE);
        gb.lights.drawPixel(0,3,WHITE);gb.lights.drawPixel(1,3,WHITE);
        
       }
      
      
      
      
    if (openning_T >= 61){
        openning_T = 61;
        delay(2000);
        menu_games = 1;
        level_nb += 1;
       if(level_nb == 21){
         menu_games = 5;
       }
   }
 }
}

void draw_levelName(){
  gb.display.clear();
  gb.display.setCursor(25,32);
  gb.display.print("Level ");
  gb.display.print(level_nb);
  delay(2000);
  menu_games = 2;
}
