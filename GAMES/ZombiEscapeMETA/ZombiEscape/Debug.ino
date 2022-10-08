//#################### DEBUG #################################
void debug_writeValue(){
  gb.display.setColor(WHITE);
  gb.display.cursorX = 1;
  gb.display.cursorY = 55;
  gb.display.println("Debug");
  gb.display.cursorX = 26;
  gb.display.cursorY = 55; 
  gb.display.println(debugValue);
}



void debug_DrawHitbox(){
  if(false){
  //hitbox Player
  int hitbox_PlayerX = player.x + player.hitboxXmin;
  int hitbox_PlayerY = player.y + player.hitboxYmin;
  gb.display.setColor(WHITE);
  gb.display.fillRect(hitbox_PlayerX,hitbox_PlayerY, player.hitboxXmax-player.hitboxXmin, player.hitboxYmax-player.hitboxYmin);
  
  //hitbox Ennemies
  gb.display.setColor(RED);
  for(int j = 0; j<stage.nbOfEnnemies; j++){
    /**/
    int hitbox_EnnemyX = stage.ennemy[j].x + game.ennemyType[stage.ennemy[j].type].hitboxXmin - level.xWorld;
    int hitbox_EnnemyY = stage.ennemy[j].y + game.ennemyType[stage.ennemy[j].type].hitboxYmin ;
    gb.display.fillRect(hitbox_EnnemyX,
                        hitbox_EnnemyY,
                        game.ennemyType[stage.ennemy[j].type].hitboxXmax - game.ennemyType[stage.ennemy[j].type].hitboxXmin,
                        game.ennemyType[stage.ennemy[j].type].hitboxYmax - game.ennemyType[stage.ennemy[j].type].hitboxYmin);
    /** /
    gb.display.setColor(WHITE);
    gb.display.cursorX = stage.ennemy[j].x - level.xWorld;
    gb.display.cursorY = stage.ennemy[j].y;
    gb.display.println(j);
    /**/
  }
  

  //hitbox Items
  /*
  gb.display.setColor(GREEN);
  for(int i = 0; i < 15; i++){
    if(bonus[i].type!=99){
      for(int n=0 ; n<8; n=n+2){
        for(int m=0 ; m<5; m=m+2){
          gb.display.drawPixel(bonus[i].x + n - level.xWorld,bonus[i].y + m);          
        }
      }
    }  
  }
  */
  


  //hitbox PlayerWeapon
  gb.display.setColor(YELLOW);
  for(int k=0; k<=weapon[player.weaponType].weaponRangeY; k = k +3){
    for(int l=0; l<weapon[player.weaponType].weaponRangeX; l = l +2){
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

        gb.display.drawPixel(checkX,checkYup);
        gb.display.drawPixel(checkX,checkYdown);
        
    }
  } 
  }  
}


            
            
            

