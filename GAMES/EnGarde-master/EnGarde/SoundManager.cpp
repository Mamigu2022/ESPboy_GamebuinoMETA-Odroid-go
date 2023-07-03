#include "SoundManager.h"
#include "snd.h"

void SoundManager::playFX(byte trackNumber) {
  if (track != -1) {
    gb.sound.stop(track);
  }

  track = gb.sound.play(tracks[trackNumber], sze[trackNumber], false);
}

SoundManager soundManager;
