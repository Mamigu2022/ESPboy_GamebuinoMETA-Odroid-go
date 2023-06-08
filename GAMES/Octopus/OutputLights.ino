void outputLights_clear(){
  gb.lights.clear();
}

void outputLight_fullYellow(){
  gb.lights.fill(YELLOW);
}

void outputLight_fullBlue(){
  gb.lights.fill(BLUE);
  
}

void outputLight_fullRed(){
  gb.lights.fill(RED);
  
}

void outputLight_fullGreen(){
  gb.lights.fill(GREEN);
}

void outputLight_bonus(){
  if (player.pos == 0 && player.timer > 0) {
    if(player.timer%2==0){
      outputLight_fullYellow();
    }
  }
}

void outputLight_catched(){
  if (player.pos == 6 && player.timer > 0) {
    if(player.timer%2==0){
      outputLight_fullRed();
    }
  }
}
