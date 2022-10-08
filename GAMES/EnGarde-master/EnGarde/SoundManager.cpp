#include "SoundManager.h"

void coinWav(){
      gb.sound.playOK();
     };
      
     void enemyHitWav(){
      gb.sound.playCancel();
     };
     
     void enemyHit2Wav(){
      gb.sound.playCancel();
     };
     
     void playerHitWav(){
      gb.sound.playCancel();
     };
     
     void portalOpenedWav(){
      tone(100,100);
      delay(100);
      tone(300,100);
      delay(100);
      tone(500,100);
      delay(100);      
     };
     
     void heartWav(){
      gb.sound.playTick();
     };
     
     void arcadeOffWav(){
      gb.sound.playCancel();
     };
     
     void skillUpWav(){
      gb.sound.playOK();
     };
     
     void rerollWav(){
      gb.sound.playOK();
     };
     
     void lackOfGoldWav(){
      gb.sound.playCancel();
     };
     
     void explosionWav(){
      tone (50,1000);
      delay(1000);
     };
     
     void skipWav(){
      gb.sound.playTick();
     };
     
     void burnedWav(){
      tone (50,500);
      delay(500);
     };
     
     void frozenWav(){
      tone (200,500);
      delay(500);
     };
     
     void thunderWav(){
      tone (50,500);
      delay(500);
      tone (150,500);
      delay(500);
      tone (50,500);
      delay(500);
      tone (150,500);
      delay(500);
     };
     


void SoundManager::playFX(byte trackNumber) {
  if (track != -1) {
    gb.sound.stop(track);
  }
 
  switch (trackNumber){
    case 0:
      coinWav();
      break;
    case 1:
      enemyHitWav();
      break;
    case 2:
      enemyHit2Wav();
      break;
    case 3:
      playerHitWav();
      break;    
    case 4:
      portalOpenedWav();
      break;        
    case 5:
      heartWav();
      break;  
    case 6:
      arcadeOffWav();
      break;  
    case 7:
      skillUpWav();
      break;  
    case 8:
      rerollWav();
      break;  
    case 9:
      lackOfGoldWav();
      break;  
    case 10:
      explosionWav();
      break;  
    case 11:
      skipWav();
      break;  
    case 12:
      burnedWav();
      break;  
    case 13:
      frozenWav();
      break;        
    case 14:
      thunderWav();
      break; 
//  track = gb.sound.play(tracks[trackNumber], false);
}
}

    


SoundManager soundManager;
