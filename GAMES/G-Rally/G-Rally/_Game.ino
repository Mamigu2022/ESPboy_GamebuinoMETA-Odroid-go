void game_init(){
  game.gameStatus = GAMEMAKERS;
  game.globalTimer = 0;
  game.pause=0;
  game.menuOption=1;
  game.menuPauseOption=0;
}

void game_carInit(){
  car01.type=0;
  car01.squareSize=5;
}


//###################################################
//###################################################
//###################################################
void game_manageGlobalCounter(){
  switch ( game.gameStatus ){
     //#################################### 
     case GAMEMAKERS:
       
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = TITLESCREEN;
        }
        
        break;

     //####################################  
     case TITLESCREEN:
     
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = MENU;
        }
        break;
     //####################################  
     case MENU:
        game.globalTimer = game.globalTimer +1;
        if(game.globalTimer>29){game.globalTimer=0;}
        break;
        
     //####################################  
     case CREDITS:
        break;

     //####################################  
     case MAPSELECTION:
        break;

     //####################################  
     case CARSELECTION:
        break;
        
     //####################################  
     case GAME:

        break;
        
     //####################################  
     case GAMECHECK:
        break;
                
     //####################################  
     case GAMEOVER:
        break;     
        
     //####################################  
     case WINNER:
        break;  

     //####################################  
     case REPLAY:
        game.globalTimer = game.globalTimer +1;
        if(game.globalTimer>5){game.globalTimer=0;}
        break; 
             
     //####################################  
     case MENUPAUSE:
        break;

                          
     default:
        game.gameStatus = GAMEMAKERS;
        break;
  }
}




//###################################################
//###################################################
//###################################################
void game_initMapInfos(){
  for(int i=0;i<amountOfMap;i++){
    if(i==0)  {maps[i].x=8;    maps[i].y=14;   maps[i].pos=4;  maps[i].bestScore=7;  maps[i].palette=0; maps[i].isNight=false; maps[i].title="Driving License - 1/3";}
    if(i==1)  {maps[i].x=8;    maps[i].y=32;   maps[i].pos=4;  maps[i].bestScore=9;  maps[i].palette=0; maps[i].isNight=false; maps[i].title="Driving License - 2/3";}
    if(i==2)  {maps[i].x=8;    maps[i].y=58;   maps[i].pos=4;  maps[i].bestScore=9;  maps[i].palette=0; maps[i].isNight=false; maps[i].title="Driving License - 3/3";}
    if(i==3)  {maps[i].x=12;   maps[i].y=112;  maps[i].pos=4;  maps[i].bestScore=26; maps[i].palette=0; maps[i].isNight=false; maps[i].title="The Training";}
    if(i==4)  {maps[i].x=74;   maps[i].y=10;   maps[i].pos=4;  maps[i].bestScore=24; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Cut the Curve";}
    if(i==5)  {maps[i].x=10;   maps[i].y=120;  maps[i].pos=0;  maps[i].bestScore=35; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Turn around";}
    if(i==6)  {maps[i].x=156;  maps[i].y=10;   maps[i].pos=10; maps[i].bestScore=27; maps[i].palette=0; maps[i].isNight=false; maps[i].title="The River";}
    if(i==7)  {maps[i].x=80;   maps[i].y=10;   maps[i].pos=4;  maps[i].bestScore=28; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Shortcut";}
    if(i==8)  {maps[i].x=75;   maps[i].y=21;   maps[i].pos=4;  maps[i].bestScore=36; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Golf";}

    //mountain
    if(i==9)   {maps[i].x=6;    maps[i].y=60;   maps[i].pos=0;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Mountain sickness";}
    if(i==10)  {maps[i].x=108;  maps[i].y=94;   maps[i].pos=4;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Santa";}
    if(i==11)  {maps[i].x=152;  maps[i].y=72;   maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Lost in snow";}
    if(i==12)  {maps[i].x=30;   maps[i].y=6;    maps[i].pos=4;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Ski Station";}

    //Jungle
    if(i==13)  {maps[i].x=140;  maps[i].y=100;  maps[i].pos=4;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Welcome to Jungle";}
    if(i==14)  {maps[i].x=92;   maps[i].y=82;   maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Green hell";}
    if(i==15)  {maps[i].x=56;   maps[i].y=118;  maps[i].pos=4;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="The Village";}
    if(i==16)  {maps[i].x=26;   maps[i].y=106;  maps[i].pos=4;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Floods";}

    //Desert    
    if(i==17)  {maps[i].x=76;   maps[i].y=10;   maps[i].pos=4;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Paris - Dakar";}
    if(i==18)  {maps[i].x=108;  maps[i].y=118;  maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Choose your way";}
    if(i==19)  {maps[i].x=96;   maps[i].y=84;   maps[i].pos=6;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Pyramids";}
    if(i==20)  {maps[i].x=40;   maps[i].y=118;  maps[i].pos=4;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Sphynx";}

    //Island
    if(i==21)  {maps[i].x=108;  maps[i].y=10;   maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Skull Island";}
    if(i==22)  {maps[i].x=100;  maps[i].y=14;   maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Pirats!";}
    if(i==23)  {maps[i].x=94;   maps[i].y=108;  maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Lost island";}
    if(i==24)  {maps[i].x=76;   maps[i].y=8;    maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Island Drift";}

    //Volcano
    if(i==25)  {maps[i].x=6;    maps[i].y=116;  maps[i].pos=0;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Volcano";}
    if(i==26)  {maps[i].x=72;   maps[i].y=60;   maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Devil";}
    if(i==27)  {maps[i].x=88;   maps[i].y=120;  maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Labyrinth";}
    if(i==28)  {maps[i].x=70;   maps[i].y=118;  maps[i].pos=10; maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Balrog";}

    //WTF
    if(i==29)  {maps[i].x=100;  maps[i].y=114;  maps[i].pos=4;  maps[i].bestScore=10; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Rainbow!!";}
    if(i==30)  {maps[i].x=45;   maps[i].y=116;  maps[i].pos=10; maps[i].bestScore=33; maps[i].palette=0; maps[i].isNight=false; maps[i].title="Star Wars!!";}

  }
}


void game_initCarPosition(){
  car01.previousX=0;
  car01.previousY=0;
  car01.x=maps[mapSelected].x; 
  car01.y=maps[mapSelected].y; 
  car01.pos=maps[mapSelected].pos;
}

void game_setPalette(int paletteSelected){
  if(paletteSelected==0){gb.display.setPalette(PALETTE);}
  if(paletteSelected==1){gb.display.setPalette(PALETTENIGHT);}
}

void game_resetPalette(){
  outputScreen_clear();
  gb.display.setPalette(PALETTE);
}

void game_initActiveColors(){
  if(mapSelected==0){  Image Map000(Map000Data);  gb.display.drawImage(0,0,Map000,0,0,10,1);} 
  if(mapSelected==1){  Image Map000(Map000Data);  gb.display.drawImage(0,0,Map000,0,0,10,1);} 
  if(mapSelected==2){  Image Map000(Map000Data);  gb.display.drawImage(0,0,Map000,0,0,10,1);} 
  if(mapSelected==3){  Image Map001(Map001Data);  gb.display.drawImage(0,0,Map001,0,0,10,1);} 
  if(mapSelected==4){  Image Map002(Map002Data);  gb.display.drawImage(0,0,Map002,0,0,10,1);} 
  if(mapSelected==5){  Image Map003(Map003Data);  gb.display.drawImage(0,0,Map003,0,0,10,1);} 
  if(mapSelected==6){  Image Map004(Map004Data);  gb.display.drawImage(0,0,Map004,0,0,10,1);} 
  if(mapSelected==7){  Image Map005(Map005Data);  gb.display.drawImage(0,0,Map005,0,0,10,1);}
  if(mapSelected==8){  Image Map006(Map006Data);  gb.display.drawImage(0,0,Map006,0,0,10,1);}
  if(mapSelected==9){  Image Map007(Map007Data);  gb.display.drawImage(0,0,Map007,0,0,10,1);}
  if(mapSelected==10){ Image Map008(Map008Data);  gb.display.drawImage(0,0,Map008,0,0,10,1);}
  if(mapSelected==11){ Image Map009(Map009Data);  gb.display.drawImage(0,0,Map009,0,0,10,1);} 
  if(mapSelected==12){ Image Map010(Map010Data);  gb.display.drawImage(0,0,Map010,0,0,10,1);} 
  if(mapSelected==13){ Image Map011(Map011Data);  gb.display.drawImage(0,0,Map011,0,0,10,1);} 
  if(mapSelected==14){ Image Map012(Map012Data);  gb.display.drawImage(0,0,Map012,0,0,10,1);} 
  if(mapSelected==15){ Image Map013(Map013Data);  gb.display.drawImage(0,0,Map013,0,0,10,1);} 
  if(mapSelected==16){ Image Map014(Map014Data);  gb.display.drawImage(0,0,Map014,0,0,10,1);} 
  if(mapSelected==17){ Image Map015(Map015Data);  gb.display.drawImage(0,0,Map015,0,0,10,1);} 
  if(mapSelected==18){ Image Map016(Map016Data);  gb.display.drawImage(0,0,Map016,0,0,10,1);} 
  if(mapSelected==19){ Image Map017(Map017Data);  gb.display.drawImage(0,0,Map017,0,0,10,1);} 
  if(mapSelected==20){ Image Map018(Map018Data);  gb.display.drawImage(0,0,Map018,0,0,10,1);} 
  if(mapSelected==21){ Image Map019(Map019Data);  gb.display.drawImage(0,0,Map019,0,0,10,1);} 
  if(mapSelected==22){ Image Map020(Map020Data);  gb.display.drawImage(0,0,Map020,0,0,10,1);} 
  if(mapSelected==23){ Image Map021(Map021Data);  gb.display.drawImage(0,0,Map021,0,0,10,1);} 
  if(mapSelected==24){ Image Map022(Map022Data);  gb.display.drawImage(0,0,Map022,0,0,10,1);} 
  if(mapSelected==25){ Image Map023(Map023Data);  gb.display.drawImage(0,0,Map023,0,0,10,1);} 
  if(mapSelected==26){ Image Map024(Map024Data);  gb.display.drawImage(0,0,Map024,0,0,10,1);} 
  if(mapSelected==27){ Image Map025(Map025Data);  gb.display.drawImage(0,0,Map025,0,0,10,1);} 
  if(mapSelected==28){ Image Map026(Map026Data);  gb.display.drawImage(0,0,Map026,0,0,10,1);} 
  if(mapSelected==29){ Image Map027(Map027Data);  gb.display.drawImage(0,0,Map027,0,0,10,1);} 
  if(mapSelected==30){ Image Map028(Map028Data);  gb.display.drawImage(0,0,Map028,0,0,10,1);}  
  road = gb.display.getPixelColor(0,0);
  speedKiller1 = gb.display.getPixelColor(1,0);
  speedKiller2 = gb.display.getPixelColor(2,0);
  handlingKiller1 = gb.display.getPixelColor(3,0);
  handlingKiller2 = gb.display.getPixelColor(4,0);
  instantDeath1 = gb.display.getPixelColor(5,0);
  instantDeath2 = gb.display.getPixelColor(6,0);
  checkpoint = gb.display.getPixelColor(7,0);
  finish = gb.display.getPixelColor(8,0); 
}

void game_resetReplay(){
  for(int i = 0; i<300; i++){
    replay[i].x=0;
    replay[i].y=0;
    replay[i].pos=99;
  }
  replayCounter=0;
  replay[0].x=car01.x;
  replay[0].y=car01.y;
}

void game_resetCursor(){
  cur.x=0;
  cur.y=0;
  cur.isActive=true;
}

void game_setCarPosition(){
  int16_t xxx = car01.previousX+cur.x;
  int16_t yyy = car01.previousY+cur.y;
  
  if(xxx==0 and yyy<0){car01.pos=0;}
  if(xxx>0 and yyy<0 and abs(xxx)<abs(yyy)){car01.pos=1;}
  if(xxx>0 and yyy<0 and abs(xxx)==abs(yyy)){car01.pos=2;}
  if(xxx>0 and yyy<0 and abs(xxx)>abs(yyy)){car01.pos=3;}
  if(xxx>0 and yyy==0){car01.pos=4;}
  if(xxx>0 and yyy>0 and abs(xxx)>abs(yyy)){car01.pos=5;}
  if(xxx>0 and yyy>0 and abs(xxx)==abs(yyy)){car01.pos=6;}
  if(xxx>0 and yyy>0 and abs(xxx)<abs(yyy)){car01.pos=7;}
  if(xxx==0 and yyy>0){car01.pos=8;}
  if(xxx<0 and yyy>0 and abs(xxx)<abs(yyy)){car01.pos=9;}
  if(xxx<0 and yyy>0 and abs(xxx)==abs(yyy)){car01.pos=10;}
  if(xxx<0 and yyy>0 and abs(xxx)>abs(yyy)){car01.pos=11;}
  if(xxx<0 and yyy==0){car01.pos=12;}
  if(xxx<0 and yyy<0 and abs(xxx)>abs(yyy)){car01.pos=13;}
  if(xxx<0 and yyy<0 and abs(xxx)==abs(yyy)){car01.pos=14;}
  if(xxx<0 and yyy<0 and abs(xxx)<abs(yyy)){car01.pos=15;}
}

void game_recordReplay(){
  replayCounter++;
  replay[replayCounter].x=car01.x;
  replay[replayCounter].y=car01.y;
  replay[replayCounter-1].pos=car01.pos;
}

void game_replayFrameManager(){
  if(game.globalTimer==0){
    replayCounter=replayCounter+1;
    if(replay[replayCounter].x==0 and replay[replayCounter].y==0 and replay[replayCounter].pos==99){game.gameStatus = WINNER;}
  }
}

//###################################################
//###################################################
//###################################################
/*
Color road;
Color speedKiller1;
Color speedKiller2;
Color handlingKiller1;
Color handlingKiller2;
Color instantDeath1;
Color instantDeath2;
Color checkpoint;
Color finish;
 */

void game_checkSpeedKiller(){
  if(gb.display.getPixelColor(car01.x,car01.y)==speedKiller1){
    car01.previousX=0;
    car01.previousY=0;
  }
  if(gb.display.getPixelColor(car01.x,car01.y)==speedKiller2){
    car01.previousX=0;
    car01.previousY=0;
  }
}

void game_checkHandlingKiller(){
  if(gb.display.getPixelColor(car01.x,car01.y)==handlingKiller1){
    cur.isActive=false;
  }
  if(gb.display.getPixelColor(car01.x,car01.y)==handlingKiller2){
    cur.isActive=false;
  }
}

void game_checkOutOfScreen(){
  if(car01.x<0){game.gameStatus = GAMEOVER;}
  if(car01.x>160){game.gameStatus = GAMEOVER;}
  if(car01.y<0){game.gameStatus = GAMEOVER;}
  if(car01.y>128){game.gameStatus = GAMEOVER;}
}

void game_checkInstantDeath(){
  for(int16_t i = 1;i<100;i++){
    if(replay[i].x!=0 and replay[i].y!=0){
      if(collideLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y,instantDeath1)){game.gameStatus = GAMEOVER;}
      if(collideLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y,instantDeath2)){game.gameStatus = GAMEOVER;}
    }
  }
}

void game_checkCheckpoint(){
  for(int16_t i = 1;i<100;i++){
    if(replay[i].x!=0 and replay[i].y!=0){
      if(collideLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y,checkpoint)){/*Count number of checkpoints (??)*/}
    }
  }  
}

void game_checkFinish(){
  for(int16_t i = 1;i<100;i++){
    if(replay[i].x!=0 and replay[i].y!=0){
      if(collideLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y,finish)){game.gameStatus = WINNER;}
    }
  }   
}



//###################################################
//###################################################
//###################################################
bool collideLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, Color toBeChecked) {
  bool isCollision=false;
  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    _swap_int16_t(x0, y0);
    _swap_int16_t(x1, y1);
  }

  if (x0 > x1) {
    _swap_int16_t(x0, x1);
    _swap_int16_t(y0, y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0<=x1; x0++) {
    if (steep) {
      if(y0>0 and y0<160 and x0>0 and x0<128){
        if(gb.display.getPixelColor(y0, x0)==toBeChecked){isCollision=true;}
      }
    } else {
      if(x0>0 and x0<160 and y0>0 and y0<128){
        if(gb.display.getPixelColor(x0, y0)==toBeChecked){isCollision=true;}
      }
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
  return isCollision;
}

bool checkCollide(int16_t x1, int16_t y1, int16_t w1, int16_t h1, int16_t x2, int16_t y2, int16_t w2, int16_t h2){
  return (x2<x1+w1 && x2+w2>x1 && y2<y1+h1 && y2+h2>y1);
}
