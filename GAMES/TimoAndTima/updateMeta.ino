void updateMeta(){
  if(isLives == true && openning_l==false && onBase == false){
    moveTimo();
    moveTima();
  }
    

}

///////////////////////////////////////////////
// GESTION DEPLACEMENT DES PERSONNAGES JOEURS//
///////////////////////////////////////////////
void moveTimo(){
    if(gb.buttons.pressed(BUTTON_MENU)){
      menu_games = 1;
    }
    if(timo_move_ok == true){
    if(gb.buttons.pressed(BUTTON_LEFT)){
      for(int col=timo_X/8;col>=0;col--){
         if(level_1[timo_Y/8][col]==1 || level_1[timo_Y/8][col]==10){
          timo_NX = col*8+timo_T;
          timoD = 1;
          timo_move_ok = false;
          //if(level_1[timo_Y/8][col]==10){level_1[timo_Y/8][col]=0;}
          break;
         }
      }
    }
    if(gb.buttons.pressed(BUTTON_RIGHT) ){
      for(int col=timo_X/8;col>=0;col++){
         if(level_1[timo_Y/8][col]==1 || level_1[timo_Y/8][col]==10){
          timo_NX = col*8-timo_T;
          timoD = 2;
          timo_move_ok = false;
          break;
         }
      }
    }
    if(gb.buttons.pressed(BUTTON_UP)){
      for(int ligne=timo_Y/8;ligne>=0;ligne--){
         if(level_1[ligne][timo_X/8]==1 || level_1[ligne][timo_X/8]==10){
          timo_NY = ligne*8+timo_T;
          timoD = 3;
          timo_move_ok = false;
          break;
         }
      }
    }
    if(gb.buttons.pressed(BUTTON_DOWN)){
      for(int ligne=timo_Y/8;ligne<8;ligne++){
         if(level_1[ligne][timo_X/8]==1 || level_1[ligne][timo_X/8]==10){
          timo_NY = ligne*8-timo_T;
          timoD = 4;
          timo_move_ok = false;
          break;
         }
      }
    }
  }else if(timo_move_ok == false){
    if (timoD == 1){
      timo_X -= tspeed;
      if (timo_X <= timo_NX){
        timo_X = timo_NX;
        if (level_1[timo_Y/8][timo_X/8-1] == 10){
          level_1[timo_Y/8][timo_X/8-1]=0;
          gb.sound.fx(sfx_1);
          }
        timo_move_ok = true;
      }
    } 
    if(timoD == 2){
      timo_X += tspeed;
      if (timo_X >= timo_NX){
        timo_X = timo_NX;
        if (level_1[timo_Y/8][timo_X/8+1] == 10){
          level_1[timo_Y/8][timo_X/8+1]=0;
          gb.sound.fx(sfx_1);
          }
        timo_move_ok = true;
      }
    }
    if (timoD == 3){
      timo_Y -= tspeed;
      if (timo_Y <= timo_NY){
        timo_Y = timo_NY;
        if (level_1[timo_Y/8-1][timo_X/8] == 10){
          level_1[timo_Y/8-1][timo_X/8]=0;
          gb.sound.fx(sfx_1);
          }
        timo_move_ok = true;
      }
    }
    if (timoD == 4){
      timo_Y += tspeed;
      if (timo_Y >= timo_NY){
        timo_Y = timo_NY;
        if (level_1[timo_Y/8+1][timo_X/8] == 10){
          level_1[timo_Y/8+1][timo_X/8]=0;
          gb.sound.fx(sfx_1);
          }
        timo_move_ok = true;
      }
    }
  }
  
}

void moveTima(){
    if(tima_move_ok == true){
    if(gb.buttons.pressed(BUTTON_LEFT)){
      for(int col=tima_X/8;col>=0;col--){
         if(level_1[tima_Y/8][col]==1 || level_1[tima_Y/8][col]==10){
          tima_NX = col*8+tima_T;
          timaD = 1;
          tima_move_ok = false;
          break;
         }
      }
    }
    if(gb.buttons.pressed(BUTTON_RIGHT)){
      for(int col=tima_X/8;col>=0;col++){
         if(level_1[tima_Y/8][col]==1 || level_1[tima_Y/8][col]==10){
          tima_NX = col*8-tima_T;
          timaD = 2;
          tima_move_ok = false;
          break;
         }
      }
    }
    if(gb.buttons.pressed(BUTTON_UP)){
      for(int ligne=tima_Y/8;ligne>=0;ligne--){
         if(level_1[ligne][tima_X/8]==1 || level_1[ligne][tima_X/8]==10){
          tima_NY = ligne*8+tima_T;
          timaD = 3;
          tima_move_ok = false;
          break;
         }
      }
    }
    if(gb.buttons.pressed(BUTTON_DOWN)){
      for(int ligne=tima_Y/8;ligne<8;ligne++){
         if(level_1[ligne][tima_X/8]==1 || level_1[ligne][tima_X/8]==10){
          tima_NY = ligne*8-tima_T;
          timaD = 4;
          tima_move_ok = false;
          break;
         }
      }
    }
  }else if(tima_move_ok == false){
    if (timaD == 1){
      tima_X -= tspeed;
      if (tima_X <= tima_NX){
        tima_X = tima_NX;
        if (level_1[tima_Y/8][tima_X/8-1] == 10){
          level_1[tima_Y/8][tima_X/8-1]=0;
          gb.sound.fx(sfx_1);
          }
        tima_move_ok = true;
      }
    } 
    if(timaD == 2){
      tima_X += tspeed;
      if (tima_X >= tima_NX){
        tima_X = tima_NX;
        if (level_1[tima_Y/8][tima_X/8+1] == 10){
          level_1[tima_Y/8][tima_X/8+1]=0;
          gb.sound.fx(sfx_1);
          }
        tima_move_ok = true;
      }
    }
    if (timaD == 3){
      tima_Y -= tspeed;
      if (tima_Y <= tima_NY){
        tima_Y = tima_NY;
        if (level_1[tima_Y/8-1][tima_X/8] == 10){
          level_1[tima_Y/8-1][tima_X/8]=0;
          gb.sound.fx(sfx_1);
          }
        tima_move_ok = true;
      }
    }
    if (timaD == 4){
      tima_Y += tspeed;
      if (tima_Y >= tima_NY){
        tima_Y = tima_NY;
        if (level_1[tima_Y/8+1][tima_X/8] == 10){
          level_1[tima_Y/8+1][tima_X/8]=0;
          gb.sound.fx(sfx_1);
          }
        tima_move_ok = true;
      }
    }
  }
}

//////////////////////
// chargement level //
//////////////////////
void loadLevel(int nv){
    if(nv == 1){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level1[l][c];
    }
  }      
 }
   if(nv == 2){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level2[l][c];
    }
  }      
 }
   if(nv == 3){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level3[l][c];
    }
  }      
 }
 if(nv == 4){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level4[l][c];
    }
  }      
 }
  if(nv == 5){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level5[l][c];
    }
  }      
 }      
  if(nv == 6){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level6[l][c];
    }
  }      
 }  
  if(nv == 7){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level7[l][c];
    }
  }      
 }  
  if(nv == 8){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level8[l][c];
    }
  }      
 }  
  if(nv == 9){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level9[l][c];
    }
  }      
 }  
  if(nv == 10){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level10[l][c];
    }
  }      
 }
  if(nv == 11){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level11[l][c];
    }
  }      
 }
   if(nv == 12){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level12[l][c];
    }
  }      
 }
   if(nv == 13){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level13[l][c];
    }
  }      
 }
   if(nv == 14){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level14[l][c];
    }
  }      
 }
   if(nv == 15){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level15[l][c];
    }
  }      
 }
   if(nv == 16){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level16[l][c];
    }
  }      
 }
   if(nv == 17){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level17[l][c];
    }
  }      
 }
   if(nv == 18){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level18[l][c];
    }
  }      
 }
   if(nv == 19){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level19[l][c];
    }
  }      
 }
   if(nv == 20){
     for(int l = 0; l < 8; l++){
      for(int c = 0; c < 10;c++){
      level_1[l][c] = level20[l][c];
    }
  }      
 }

}

void nextLevel(){
  if(timoOnBase == true && timaOnBase == true ){
    onBase = true;
    timo_X = floor(timo_X/8)*8;
    timo_Y = floor(timo_Y/8)*8;
    tima_X = floor(tima_X/8)*8;
    tima_Y = floor(tima_Y/8)*8;
    gb.lights.fill(BLACK);
    draw_barre(false);
 }
}
///////////////////////
// Gestion collision //
///////////////////////
