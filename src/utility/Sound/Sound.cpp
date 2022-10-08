/*
This file is part of the Gamebuino-Meta library,
Copyright (c) Aadalie 2017

This is free software: you can redistribute it and/or modify
it under the tAudio_Handlererms of the GNU Lesser General Public License (LGPL)
as published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

This is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License (LGPL) for more details.

You should have received a copy of the GNU Lesser General Public
License (LGPL) along with the library.
If not, see <http://www.gnu.org/licenses/>.

Authors:
 - Aurelien Rodot
 - Sorunome
*/

#include "Sound.h"
#include "Pattern.h"
#include "Tone.h"
#include "Raw.h"
#include "../Sound-SD/Sound-SD.h"

namespace Gamebuino_Meta {

#if SOUND_ENABLE_FX


const Gamebuino_Meta::Sound_FX playOKFX[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 110, -6, 11, 126, 2},
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE, 0, 150, -25, -3, 47, 3},
};

const Gamebuino_Meta::Sound_FX playCancelFX[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE, 1, 120, 3, 8, 126, 2},
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE, 0, 130, -13, 10, 169, 3},
};

const Gamebuino_Meta::Sound_FX playTickFX[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE, 0, 196, -35, -3, 142, 1},
};

#else  // SOUND_ENABLE_FX

const uint16_t playOKPattern[] = {0x0005,0x138,0x168,0x0000};
const uint16_t playCancelPattern[] = {0x0005,0x168,0x138,0x0000};
const uint16_t playTickP[] = {0x0045,0x168,0x0000};

#endif  // SOUND_ENABLE_FX

uint8_t globalVolume = 6;
bool muted = false;

#if SOUND_CHANNELS > 0
Sound_Channel channels[SOUND_CHANNELS];
Sound_Handler* handlers[SOUND_CHANNELS];

FX_Channel fx_channel = { 0 };


bool tcIsSyncing() {
 return(1);
}


void tcStart() {
}


void tcReset() {
}


void tcDisable() {
}


void tcConfigure(uint32_t sampleRate) {
}


int8_t findEmptyChannel() {
	for (uint8_t i = 0; i < SOUND_CHANNELS; i++) {
		if (!channels[i].use) {
			if (handlers[i]) {
				delete handlers[i];
				handlers[i] = 0;
			}
			return i;
		}
	}
	return -1;
}
#endif

Sound_Handler::Sound_Handler(Sound_Channel* _channel) {
	channel = _channel;
}

Sound_Handler::~Sound_Handler() {
	
}

uint32_t Sound_Handler::getPos() {
	return 0xFFFFFFFF;
}

void Sound_Handler::setChannel(Sound_Channel* _channel) {
	channel = _channel;
}

int8_t Sound::play(const char* filename, bool loop) {
#if SOUND_CHANNELS > 0
	int8_t i = findEmptyChannel();
	if (i < 0 || i >= SOUND_CHANNELS) {
		return -1; // no free channels atm
	}
	channels[i].loop = loop;
	handlers[i] = new Sound_Handler_Wav(&(channels[i]));
	if (!((Sound_Handler_Wav*)handlers[i])->init(filename)) {
		delete handlers[i];
		handlers[i] = 0;
		return -1;
	}
	return i;
#else // SOUND_CHANNELS
	return -1;
#endif // SOUND_CHANNELS
return i;
}

int8_t Sound::play(char* filename, bool loop) {
	return play((const char*)filename, loop);
}

int8_t Sound::play(const uint16_t* buffer, bool loop) {
#if SOUND_CHANNELS > 0
	int8_t i = findEmptyChannel();
	if (i < 0 || i >= SOUND_CHANNELS) {
		return -1; // no free channels atm
	}
	channels[i].loop = loop;
	handlers[i] = new Sound_Handler_Pattern(&(channels[i]), (uint8_t*)buffer);
	return i;
#else // SOUND_CHANNELS
	return -1;
#endif // SOUND_CHANNELS
}

int8_t Sound::play(uint16_t* buffer, bool loop) {
	return play((const uint16_t*)buffer, loop);
}

int8_t Sound::play(const uint8_t* buf, uint32_t len, bool loop) {
#if SOUND_CHANNELS > 0
	int8_t i = findEmptyChannel();
	if (i < 0 || i >= SOUND_CHANNELS) {
		return -1; // no free channels atm
	}
	channels[i].loop = loop;
	handlers[i] = new Sound_Handler_Raw(&(channels[i]), (uint8_t*)buf, len);
	return i;
#else // SOUND_CHANNELS
	return -1;
#endif // SOUND_CHANNELS
}

int8_t Sound::play(uint8_t* buf, uint32_t len, bool loop) {
	return play((const uint8_t*)buf, len, loop);
}

int8_t Sound::play(Sound_Handler* handler, bool loop) {
#if SOUND_CHANNELS > 0
	int8_t i = findEmptyChannel();
	if (i < 0 || i >= SOUND_CHANNELS) {
		return -1; // no free channels atm
	}
	channels[i].loop = loop;
	handlers[i] = handler;
	handlers[i]->setChannel(&(channels[i]));
	return i;
#else // SOUND_CHANNELS
	return -1;
#endif // SOUND_CHANNELS
}

// Get optimized away if fx is not used
uint32_t fx_sound_buffer[SOUND_FX_BUFFERSIZE/4];

void init_fx_channel() {
#if SOUND_CHANNELS > 0
	if (fx_channel.handler == nullptr){
		fx_channel.size = SOUND_FX_BUFFERSIZE;
		fx_channel.buffer = (int8_t*)fx_sound_buffer;
		memset(fx_channel.buffer, 0, fx_channel.size);
		fx_channel.index = 0;
		fx_channel.handler = new Sound_Handler_FX(&fx_channel);
	}
#endif // SOUND_CHANNELS
}

void Sound::fx(const Sound_FX & fx) {
#if SOUND_CHANNELS > 0
	init_fx_channel();
	fx_channel.handler->play(fx);
#endif // SOUND_CHANNELS
}


void Sound::fx(const Sound_FX * const fx) {
#if SOUND_CHANNELS > 0
	init_fx_channel();
	fx_channel.handler->play(fx,0);
#endif // SOUND_CHANNELS
}


int8_t Sound::tone(uint32_t frequency, int32_t duration) {
#if SOUND_CHANNELS > 0
	int8_t i = findEmptyChannel();
	if (i < 0 || i >= SOUND_CHANNELS) {
		return -1; // no free channels atm
	}
	channels[i].loop = duration == 0;
	handlers[i] = new Sound_Handler_Tone(&(channels[i]), frequency, duration, i);
	return i;
#else // SOUND_CHANNELS
	return -1;
#endif // SOUND_CHANNELS
}

void Sound::stop(int8_t i) {
#if SOUND_CHANNELS > 0
	if (i >= SOUND_CHANNELS || i < 0) {
		return;
	}
	channels[i].use = false;
	if (handlers[i]) {
		delete handlers[i];
		handlers[i] = 0;
	}
#endif // SOUND_CHANNELS
}


int8_t Sound::playOK() {
#if SOUND_ENABLE_FX
	fx(playOKFX);
	return -1;  // There only is one FX_Channel, and playing Sounf_fx cannot fail (the latest sound_fx is played)
#else  // SOUND_ENABLE_FX
	return play(playOKPattern);
#endif  // SOUND_ENABLE_FX
}


int8_t Sound::playCancel() {
#if SOUND_ENABLE_FX
	fx(playCancelFX);
	return -1;  // There only is one FX_Channel, and playing Sounf_fx cannot fail (the latest sound_fx is played)
#else  // SOUND_ENABLE_FX
	return play(playCancelPattern);
#endif  // SOUND_ENABLE_FX
}


int8_t Sound::playTick() {
#if SOUND_ENABLE_FX
	fx(playTickFX);
	return -1;  // There only is one FX_Channel, and playing Sounf_fx cannot fail (the latest sound_fx is played)
#else  // SOUND_ENABLE_FX
	return play(playTickP);
#endif  // SOUND_ENABLE_FX
}

bool efx_only = false;


void Sound::update() {
#if SOUND_CHANNELS > 0
	for (uint8_t i = 0; i < SOUND_CHANNELS; i++) {
		if (channels[i].use) {
			if (!efx_only || (!channels[i].loop && channels[i].type == Sound_Channel_Type::square)) {
				handlers[i]->update();
			}
		} else if (handlers[i]) {
			delete handlers[i];
			handlers[i] = 0;
		}
	}

	if (fx_channel.handler) {
		fx_channel.handler->update();
	}
#endif // SOUND_CHANNELS
}


void Sound::mute() {
	muted = true;
}


void Sound::unmute() {
	muted = false;
}


bool Sound::isMute() {
	return muted;
}


void Sound::startEfxOnly() {
	efx_only = true;
}


void Sound::stopEfxOnly() {
	efx_only = false;
}


bool Sound::isPlaying(int8_t i) {
#if SOUND_CHANNELS > 0
	if (i < 0 || i >= SOUND_CHANNELS) {
		return false;
	}
	return channels[i].use;
#else // SOUND_CHANNELS
	return false;
#endif // SOUND_CHANNELS
}


void Sound::setVolume(uint8_t volume) {
	globalVolume = constrain(volume, 0, 8);
}


uint8_t Sound::getVolume() {
	return globalVolume;
}


uint32_t Sound::getPos(int8_t i) {
#if SOUND_CHANNELS > 0
	if (!isPlaying(i) || !(handlers[i])) {
		return 0xFFFFFFFF;
	}
	return handlers[i]->getPos();
#else // SOUND_CHANNELS
	return 0xFFFFFFFF;
#endif // SOUND_CHANNELS
}

#if SOUND_CHANNELS > 0

#ifdef __cplusplus
extern "C" {
#endif

static void Audio_Handler (void) __attribute__((optimize("-O3")));

uint16_t flowdown = 0;


//void Audio_Handler (void) {
static void IRAM_ATTR Audio_Handler(void) {
	if (!globalVolume || muted) {
		return;
	}
	int16_t output = 0;
	for (uint8_t i = 0; i < SOUND_CHANNELS; i++) {
		if (channels[i].use) {
			switch (channels[i].type) {
			case Sound_Channel_Type::raw:
				if (efx_only) {
					break;
				}
				if (channels[i].index < channels[i].total - 1) {
					output += (channels[i].buffer[channels[i].index++] - 0x80);
				} else if (!channels[i].last) {
					channels[i].index = 0;
					output += (channels[i].buffer[channels[i].index++] - 0x80);
				} else if (channels[i].loop) {
					handlers[i]->rewind();
				} else {
					channels[i].use = false;
				}
				break;
			case Sound_Channel_Type::square:
				if (efx_only && channels[i].loop) {
					break;
				}
				if (channels[i].index++ >= channels[i].total) {
					channels[i].last = !channels[i].last;
					channels[i].index = 0;
				}
				if (channels[i].last) {
					output -= channels[i].amplitude;
				} else {
					output += channels[i].amplitude;
				}
				break;
			}
		}
	}

	if (fx_channel.handler != nullptr) {
		output += fx_channel.buffer[fx_channel.index];
		fx_channel.index++;
		if (fx_channel.index >= fx_channel.size) {
			fx_channel.index = 0;
		}
	}

	if (output) {
		//we multiply by 4 to use the whole 0..1024 DAC range even with 8-bit 0..255 waves
		//then we attenuate the signal. The attenuation is not linear because human ear's response isn't ;)
		//we use a >> instead of division for better performances as this interrupt runs quite often
		//RAW VALUE		VOLUME		OUTPUT
		//255			8			1024	//amplify sound to use full DAC range
											//might cause clipping if several sounds are played simultaneously
		//255			7			512
		//255			6			255		//keep sound as original
		//255			5			127		//reduced volume
		
		//output = (output * 4) >> (8 - globalVolume);
		//offset the signed value to be centered around 512
		//as the 10-bit DAC output is between 0 and 1024
		
		// we need to slowly fade up our zero-level to not have any plop when starting to play sound
		if (flowdown < 512) {
			flowdown++;
		}
		output += flowdown;
		if (output < 0) {
			output = 0;
		}
		//analogWrite(A0, output);
		sigmaDeltaWrite(0, output&255);
	} 
	else {
		// we need to output 0 when not in use to not have weird sound effects with the neoLeds as the interrupt isn't 100% constant there.
		// however, jumping down from 512 (zero-positin) to 0 would give a plop
		// so instead we gradually decrease instead
		//analogWrite(A0, flowdown); // zero-position
		//sigmaDeltaWrite(0, 0);
		sigmaDeltaWrite(0, flowdown&255);
		if (flowdown > 0) {
			flowdown--;
		}
	}
}


#ifdef __cplusplus
}
#endif



void dacConfigure(uint32_t sampleRate) {
  noInterrupts();
  sigmaDeltaSetup(0, sampleRate);
  sigmaDeltaAttachPin(D3);
  sigmaDeltaEnable();
  timer1_attachInterrupt(Audio_Handler);
  timer1_enable(TIM_DIV1, TIM_EDGE, TIM_LOOP);
  timer1_write(80000000 / (sampleRate-1));
  interrupts(); 
}


#endif // SOUND_CHANNELS

void Sound::begin() {
#if SOUND_CHANNELS > 0
	dacConfigure(SOUND_FREQ);
	//tcConfigure(SOUND_FREQ);
	//tcStart();
#endif
}

} // Gamebuino_Meta
