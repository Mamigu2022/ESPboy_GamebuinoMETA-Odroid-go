#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H
#include "Gamebuino-Meta.h"

extern const uint8_t 
      coinWav[], 
      enemyHitWav[], 
      enemyHit2Wav[], 
      playerHitWav[], 
      portalOpenedWav[], 
      heartWav[], 
      arcadeOffWav[], 
      skillUpWav[], 
      rerollWav[], 
      lackOfGoldWav[],
      explosionWav[],
      skipWav[],
      burnedWav[],
      frozenWav[],
      thunderWav[];

extern const uint16_t
coinWavSize, enemyHitWavSize, enemyHit2WavSize, playerHitWavSize, portalOpenedWavSize, heartWavSize,
arcadeOffWavSize, skillUpWavSize, rerollWavSize, lackOfGoldWavSize, explosionWavSize, skipWavSize, 
coinWavSizeSize, burnedWavSize, thunderWavSize;


#define COIN 0
#define ENEMY_HIT 1
#define ENEMY_HIT2 2
#define PLAYER_HIT 3
#define PORTAL_OPENED 4
#define HEART 5
#define ARCADE_OFF 6
#define SKILL_UP 7
#define REROLL 8
#define LACK_OF_GOLD 9
#define EXPLOSION 10
#define SKIP 11
#define BURNED 12
#define FROZEN 13
#define THUNDER 14



class SoundManager {
  public:
    byte track = -1;
    
    void playFX(byte trackNumber);
  private:
    const uint8_t* tracks[15] = { 
      coinWav, 
      enemyHitWav, 
      enemyHit2Wav, 
      playerHitWav, 
      portalOpenedWav, 
      heartWav, 
      arcadeOffWav, 
      skillUpWav, 
      rerollWav, 
      lackOfGoldWav,
      explosionWav,
      skipWav,
      burnedWav,
      frozenWav,
      thunderWav
    };
    const uint16_t sze[15]={
      coinWavSize, enemyHitWavSize, enemyHit2WavSize, playerHitWavSize, portalOpenedWavSize, heartWavSize,
      arcadeOffWavSize, skillUpWavSize, rerollWavSize, lackOfGoldWavSize, explosionWavSize, skipWavSize, 
      coinWavSizeSize, burnedWavSize, thunderWavSize
      };

};

extern SoundManager soundManager;

#endif
