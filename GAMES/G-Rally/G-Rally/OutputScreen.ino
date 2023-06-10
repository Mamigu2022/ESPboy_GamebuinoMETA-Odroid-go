

void outputScreen_clear(){
  gb.display.clear();
}

//#################################
//##### FULLSCREEN GAMEMAKERS #####
//#################################
void outputScreen_gamemakers(){
  gb.display.setColor(BLACK);
  Image GameMakers(GamemakersData);
  gb.display.drawImage(0,0,GameMakers,160,128); 
}


//#################################
//##### FULLSCREEN TITRE ##########
//#################################
void outputScreen_title(){
  gb.display.setColor(LIGHTBLUE);
  gb.display.fillRect(0,0,160,80);
  Image Title(TitleData);
  Image Bkg_Tree(Bkg_TreeData);
  Image Bkg_Ground(Bkg_GroundData);
  Image Bkg_Car(Bkg_CarData);
  gb.display.drawImage(0,74,Bkg_Ground);
  gb.display.drawImage(0,0,Bkg_Tree);
  gb.display.drawImage(22,1,Title);
  gb.display.drawImage(7,39,Bkg_Car);
}

//###################################
//##### FULLSCREEN CREDITS ##########
//###################################
void outputScreen_credits(){
  Image Credits(Credits_Data);
  gb.display.drawImage(0,0,Credits,160,128);
}

//######################################
//############# MENU ###################
//######################################
void outputScreen_menu(){
  gb.display.setColor(LIGHTBLUE);
  gb.display.fillRect(0,0,160,128);

  outputScreen_background();
  
  Image Title(TitleData);
  gb.display.drawImage(22,1,Title);

  if(game.menuOption == 1){gb.display.setColor(WHITE);}else{gb.display.setColor(BLACK);}
  gb.display.setCursor(130, 52);
  gb.display.println("Race!");

  if(game.menuOption == 2){gb.display.setColor(WHITE);}else{gb.display.setColor(BLACK);}
  gb.display.setCursor(110, 62);
  gb.display.println("Select Car");

  if(game.menuOption == 3){gb.display.setColor(WHITE);}else{gb.display.setColor(BLACK);}
  gb.display.setCursor(110, 72);
  gb.display.println("Select Map");

  if(game.menuOption == 4){gb.display.setColor(WHITE);}else{gb.display.setColor(BLACK);}
  gb.display.setCursor(122, 82);
  gb.display.println("Credits");

  if(game.menuOption == 1){
    Image Flag(FlagData);
    Image Game_CarSelection(Game_CarSelectionData);
    outputScreen_map();
    gb.display.setColor(BLACK);
    gb.display.drawRect(9,50,42,35);
    gb.display.drawImage(55,55,Flag,0,(game.globalTimer%3)*26,27,26);
    gb.display.drawImage(30,75,Game_CarSelection,0,car01.type*27,40,27);
  }
  if(game.menuOption == 2){
    Image Game_CarSelection(Game_CarSelectionData);
    gb.display.drawImage(12,50,Game_CarSelection,0,2*27,40,27);
    gb.display.drawImage(50,50,Game_CarSelection,0,1*27,40,27);
    gb.display.drawImage(30,70,Game_CarSelection,0,0*27,40,27);
    gb.display.setColor(BLACK);
    gb.display.drawLine(0,45,50,45);
    gb.display.drawLine(0,99,70,99);
  }
  if(game.menuOption == 3){
    Image WorldMap(WorldMapData);
    gb.display.drawImage(-10,45,WorldMap);
    gb.display.setColor(BLACK);
    gb.display.drawLine(0,45,50,45);
    gb.display.drawLine(0,99,70,99);
  }
  if(game.menuOption == 4){
    Image CreditsIco(CreditsIcoData);
    gb.display.drawImage(32,60,CreditsIco);
    gb.display.setColor(BLACK);
    gb.display.drawLine(0,45,50,45);
    gb.display.drawLine(0,99,70,99);
  }
}


//###########################
//##### Game ################
//###########################
void outputScreen_map(){
  if(mapSelected==0){
    Image Map000(Map000Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);} 
  } 
  else if(mapSelected==1){
    Image Map000(Map000Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  } 
  else if(mapSelected==2){
    Image Map000(Map000Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  } 
  else if(mapSelected==3){
    Image Map000(Map001Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }   
  else if(mapSelected==4){
    Image Map000(Map002Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }
  else if(mapSelected==5){
    Image Map000(Map003Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }
  else if(mapSelected==6){
    Image Map000(Map004Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}   
  }
  else if(mapSelected==7){
    Image Map000(Map005Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }
  else if(mapSelected==8){
    Image Map000(Map006Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }
  else if(mapSelected==9){
    Image Map000(Map007Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==10){
    Image Map000(Map008Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==11){
    Image Map000(Map009Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==12){
    Image Map000(Map010Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==13){
    Image Map000(Map011Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==14){
    Image Map000(Map012Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==15){
    Image Map000(Map013Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==16){
    Image Map000(Map014Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==17){
    Image Map000(Map015Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==18){
    Image Map000(Map016Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==19){
    Image Map000(Map017Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==20){
    Image Map000(Map018Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==21){
    Image Map000(Map019Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==22){
    Image Map000(Map020Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==23){
    Image Map000(Map021Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==24){
    Image Map000(Map022Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==25){
    Image Map000(Map023Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==26){
    Image Map000(Map024Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==27){
    Image Map000(Map025Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==28){
    Image Map000(Map026Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==29){
    Image Map000(Map027Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,50,Map000,40,34);}
    else                              {gb.display.drawImage(0,-2, Map000,160,130);}  
  }  
  else if(mapSelected==30){
    Image Map000(Map028Data);  
    if(game.gameStatus==MAPSELECTION) {gb.display.drawImage(40,59,Map000,80,65);}
    else if(game.gameStatus==MENU)    {gb.display.drawImage(10,49,Map000,40,34);}
    else                              {gb.display.drawImage(0,-1, Map000);}  
  }

  /*
  if(mapSelected==11){
    if(game.gameStatus==MAPSELECTION) {Image Map003(Map003Data);  gb.display.drawImage(40,60,Map003,0,1,80,64);}
    else if(game.gameStatus==MENU)    {Image Map003(Map003Data);  gb.display.drawImage(10,50,Map003,40,34);}
    else                              {Image Map003(Map003Data);  gb.display.drawImage(0,-2,Map003,160,130);} 
  }
*/
  //here
}

void outputScreen_background(){
  Image Background001(Background001Data);
  Image Background002(Background002Data);
  gb.display.drawImage(0,20,Background001);
  gb.display.drawImage(61,97,Background002);
  gb.display.drawImage(61,0,Background002,-97,-31);
}

void outputScreen_night(){
  if(maps[mapSelected].isNight==true){
    /*
      if(car01.pos==0) {Image Light00(Light00Data); gb.display.drawImage(car01.x-12,  car01.y-42, Light00); fillRectForNight(car01.x-12,  car01.y-42,Light00Data[0],Light00Data[1]);}
      if(car01.pos==1) {Image Light01(Light01Data); gb.display.drawImage(car01.x+1,   car01.y-39, Light01); fillRectForNight(car01.x+1,   car01.y-39,Light01Data[0],Light01Data[1]);}
      if(car01.pos==2) {Image Light02(Light02Data); gb.display.drawImage(car01.x+3,   car01.y-35, Light02); fillRectForNight(car01.x+3,   car01.y-35,Light02Data[0],Light02Data[1]);}
      if(car01.pos==3) {Image Light03(Light03Data); gb.display.drawImage(car01.x+5,   car01.y-28, Light03); fillRectForNight(car01.x+5,   car01.y-28,Light03Data[0],Light03Data[1]);}
      if(car01.pos==4) {Image Light04(Light04Data); gb.display.drawImage(car01.x+6,   car01.y-12, Light04); fillRectForNight(car01.x+6,   car01.y-12,Light04Data[0],Light04Data[1]);}
      if(car01.pos==5) {Image Light05(Light05Data); gb.display.drawImage(car01.x+4,   car01.y+1,  Light05); fillRectForNight(car01.x+4,   car01.y+1, Light05Data[0],Light05Data[1]);}
      if(car01.pos==6) {Image Light06(Light06Data); gb.display.drawImage(car01.x+3,   car01.y+3,  Light06); fillRectForNight(car01.x+3,   car01.y+3, Light06Data[0],Light06Data[1]);}
      if(car01.pos==7) {Image Light07(Light07Data); gb.display.drawImage(car01.x+1,   car01.y+4,  Light07); fillRectForNight(car01.x+1,   car01.y+4, Light07Data[0],Light07Data[1]);}
      if(car01.pos==8) {Image Light08(Light08Data); gb.display.drawImage(car01.x-12,  car01.y+5,  Light08); fillRectForNight(car01.x-12,  car01.y+5, Light08Data[0],Light08Data[1]);}
      if(car01.pos==9) {Image Light09(Light09Data); gb.display.drawImage(car01.x-25,  car01.y+4,  Light09); fillRectForNight(car01.x-25,  car01.y+4, Light09Data[0],Light09Data[1]);}
      if(car01.pos==10){Image Light10(Light10Data); gb.display.drawImage(car01.x-35,  car01.y+3,  Light10); fillRectForNight(car01.x-35,  car01.y+3, Light10Data[0],Light10Data[1]);}
      if(car01.pos==11){Image Light11(Light11Data); gb.display.drawImage(car01.x-39,  car01.y+1,  Light11); fillRectForNight(car01.x-39,  car01.y+1, Light11Data[0],Light11Data[1]);}
      if(car01.pos==12){Image Light12(Light12Data); gb.display.drawImage(car01.x-42,  car01.y-12, Light12); fillRectForNight(car01.x-42,  car01.y-12,Light12Data[0],Light12Data[1]);}
      if(car01.pos==13){Image Light13(Light13Data); gb.display.drawImage(car01.x-39,  car01.y-27, Light13); fillRectForNight(car01.x-39,  car01.y-27,Light13Data[0],Light13Data[1]);}
      if(car01.pos==14){Image Light14(Light14Data); gb.display.drawImage(car01.x-35,  car01.y-35, Light14); fillRectForNight(car01.x-35,  car01.y-35,Light14Data[0],Light14Data[1]);}
      if(car01.pos==15){Image Light15(Light15Data); gb.display.drawImage(car01.x-27,  car01.y-39, Light15); fillRectForNight(car01.x-27,  car01.y-39,Light15Data[0],Light15Data[1]);}
      */
      int xlight=0;
      int ylight=0;
      if(car01.pos==0) {xlight=23;   ylight=55;}
      if(car01.pos==1) {xlight=9;    ylight=51;}
      if(car01.pos==2) {xlight=0;    ylight=47;}
      if(car01.pos==3) {xlight=-5;   ylight=37;}
      
      if(car01.pos==4) {xlight=-9;   ylight=23;}
      if(car01.pos==5) {xlight=-5;   ylight=9;}
      if(car01.pos==6) {xlight=0;    ylight=0;}
      if(car01.pos==7) {xlight=9;    ylight=-5;}
      
      if(car01.pos==8) {xlight=23;   ylight=-9;}
      if(car01.pos==9) {xlight=37;   ylight=-5;}
      if(car01.pos==10){xlight=47;   ylight=0;}
      if(car01.pos==11){xlight=51;   ylight=9;}
      
      if(car01.pos==12){xlight=55;   ylight=23;}
      if(car01.pos==13){xlight=51;   ylight=37;}
      if(car01.pos==14){xlight=47;   ylight=47;}
      if(car01.pos==15){xlight=37;   ylight=51;}
      
      Image Light(LightData);
      gb.display.drawImage(car01.x-xlight,  car01.y-ylight, Light);
      fillRectForNight(car01.x-xlight,  car01.y-ylight,47,47);
  }
}

void fillRectForNight(int lightX, int lightY, int lightWidth, int lightHeight){
  gb.display.setColor(BLACK);
  //rect top
  if(lightY>0){gb.display.fillRect(0,0,SCREENWIDTH,lightY);}
  //rect left
  if(lightX>0){gb.display.fillRect(0,lightY,lightX,lightHeight);}
  //rect right
  if(lightX+lightWidth<SCREENWIDTH){gb.display.fillRect(lightX+lightWidth,lightY,SCREENWIDTH-(lightX+lightWidth),lightHeight);}
  //rect bottom
  if(lightY+lightHeight<SCREENHEIGHT){gb.display.fillRect(0,lightY+lightHeight,SCREENWIDTH,SCREENHEIGHT-(lightY+lightHeight));}
}

void outputScreen_trajectory(){
  gb.display.setColor(GRAY);
  for(int i = 1;i<100;i++){
    if(replay[i].x!=0 and replay[i].y!=0){
      gb.display.drawLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y);
    }
  }
}

void outputScreen_grid(){
  if(displayGrid==true){ 
    int jj=maps[0].y%car01.squareSize;
    int ii=maps[0].x%car01.squareSize;
    gb.display.setColor(RED);
    for(int j=jj;j<128;j=j+car01.squareSize){
      for(int i=ii;i<160;i=i+car01.squareSize){
        gb.display.drawPixel(i,j);
      }
    }
    displayGrid=false;
  }
}

void outputScreen_car(){
  if(car01.x>-10 and car01.y>-10){
  Image Game_Car = Image(Game_CarData);
  gb.display.drawImage(car01.x-5,car01.y-5,Game_Car,11*car01.pos,11*car01.type,11,11);
  }
}

void outputScreen_carReplay(){
  Image Game_Car = Image(Game_CarData);
  int16_t pos = replay[replayCounter].pos;
  if(pos==99){pos = replay[replayCounter-1].pos;}
  gb.display.drawImage(replay[replayCounter].x-5,replay[replayCounter].y-5,Game_Car,11*pos,11*car01.type,11,11);
}

void outputScreen_cursor(){
  gb.display.setColor(WHITE);
  int16_t xx = car01.x+car01.previousX+cur.x;
  int16_t yy = car01.y+car01.previousY+cur.y;
  gb.display.drawPixel(xx-1,yy);
  gb.display.drawPixel(xx,yy-1);
  gb.display.drawPixel(xx+1,yy);
  gb.display.drawPixel(xx,yy+1);
}


//###########################
//### PAUSE / GAME OVER #####
//###########################
void outputScreen_gameOver(){
  gb.display.setColor(BLACK);
  gb.display.fillRect(43,38,74,44);
  
  gb.display.setColor(RED);
  gb.display.setFontSize(2);
  gb.display.setCursor(45,41);
  gb.display.println("GAME OVER");

  gb.display.setFontSize(1);
  
  if(game.menuPauseOption==0){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(62,60);
  gb.display.println("Try Again");
  
  if(game.menuPauseOption==1){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(56,70);
  gb.display.println("Back to Menu");
}

void outputScreen_winner(){
  gb.display.setColor(BLACK);
  gb.display.fillRect(43,38,74,64);
  
  gb.display.setColor(YELLOW);
  gb.display.setFontSize(2);
  gb.display.setCursor(45,41);
  gb.display.println("FINISHED!");

  gb.display.setColor(WHITE);
  gb.display.setFontSize(1);
  gb.display.setCursor(50,54);
  gb.display.println("Your score:");
  gb.display.setCursor(98,54);
  gb.display.println(replayCounter);

  if(game.menuPauseOption==0){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(68,70);
  gb.display.println("Replay");
  
  if(game.menuPauseOption==1){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(62,80);
  gb.display.println("Next Race");
  
  if(game.menuPauseOption==2){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(56,90);
  gb.display.println("Back to Menu");
  
}

void outputScreen_menuPause(){
  gb.display.setColor(BLACK);
  gb.display.fillRect(48,38,64,54);
  
  gb.display.setColor(LIGHTGREEN);
  gb.display.setFontSize(2);
  gb.display.setCursor(61,41);
  gb.display.println("PAUSE");

  gb.display.setFontSize(1);
  
  if(game.menuPauseOption==0){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(64,60);
  gb.display.println("Continue");
  
  if(game.menuPauseOption==1){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(70,70);
  gb.display.println("Reset");

  if(game.menuPauseOption==2){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(56,80);
  gb.display.println("Back to Menu");
}

//###########################
//##### CAR SELECTION #######
//###########################
void outputScreen_carSelection(){
  gb.display.setColor(LIGHTBLUE);
  gb.display.fillRect(0,0,160,128);
  
  outputScreen_background();
  
  Image Title(TitleData);
  gb.display.drawImage(22,1,Title);
  
  gb.display.setColor(WHITE);
  gb.display.setCursor(105,35);
  gb.display.println("Car Selection");

  Image Game_CarSelection(Game_CarSelectionData);
  gb.display.drawImage(60,60,Game_CarSelection,0,car01.type*27,40,27);

  gb.display.setColor(BLACK);
  gb.display.fillRect(25,90,110,30);

  gb.display.setColor(WHITE);
  gb.display.setCursor(30,97);
  gb.display.println("Acceleration: ");  
  gb.display.setCursor(30,107);
  gb.display.println("Break: "); 
}


//###########################
//##### MAP SELECTION #######
//###########################
void outputScreen_mapSelection(){
  gb.display.setColor(LIGHTBLUE);
  gb.display.fillRect(0,0,160,128);

  outputScreen_background();
  
  Image Title(TitleData);
  gb.display.drawImage(22,1,Title);
  
  gb.display.setColor(WHITE);
  gb.display.setCursor(105,35);
  gb.display.println("Map Selection");

  gb.display.setCursor(40,52);
  gb.display.println(maps[mapSelected].title);  
  
  outputScreen_map();

  gb.display.setColor(BLACK);
  gb.display.drawRect(39,59,82,66);
}
