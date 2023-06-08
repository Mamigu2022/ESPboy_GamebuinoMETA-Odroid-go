void outputSound_init(){
  sounds.tic = -1;
  sounds.tac = -1;
  sounds.toc = -1;
  sounds.music = -1;
}

void outputSound_tic(){
  if(gb.sound.isPlaying(sounds.tic)){
    gb.sound.stop(sounds.tic);
  }
  sounds.tic = gb.sound.playTick();
}

void outputSound_toc(){
  if(gb.sound.isPlaying(sounds.toc)){
    gb.sound.stop(sounds.toc);
  }
  sounds.toc = gb.sound.playCancel();
  
}

void outputSound_tac(){
  if(gb.sound.isPlaying(sounds.tac)){
    gb.sound.stop(sounds.tac);
  }
  sounds.tac = gb.sound.playOK();
  
}
