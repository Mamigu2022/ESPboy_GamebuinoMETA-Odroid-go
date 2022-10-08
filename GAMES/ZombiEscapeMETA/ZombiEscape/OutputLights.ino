void outputLights_clear(){
  gb.lights.clear();
}

void outputLight_gunFire(){
  gb.lights.fill(YELLOW);
}

void outputLight_playerDamage(){
  if(game.continueAsEnnemy){gb.lights.fill(LIGHTGREEN);}
  else{gb.lights.fill(RED);}
  
}

void outputLight_bonus(){
  gb.lights.fill(GREEN);
}
