void outputSound_init(){
  sounds.weapon = -1;
  sounds.bonus = -1;
  sounds.playerDamage = -1;
  sounds.music = -1;
}

void outputSound_gunisShooting(){
  if(gb.sound.isPlaying(sounds.weapon)){
    gb.sound.stop(sounds.weapon);
  }
  sounds.weapon = gb.sound.playTick();
}

void outputSound_PlayerHurt(){
  if(gb.sound.isPlaying(sounds.playerDamage)){
    gb.sound.stop(sounds.playerDamage);
  }
  sounds.playerDamage = gb.sound.playCancel();
  
}

void outputSound_bonus(){
  if(gb.sound.isPlaying(sounds.bonus)){
    gb.sound.stop(sounds.bonus);
  }
  sounds.bonus = gb.sound.playOK();
  
}

