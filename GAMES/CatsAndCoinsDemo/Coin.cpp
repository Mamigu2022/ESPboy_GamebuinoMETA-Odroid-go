#include "Coin.h"

#include "Camera.h"
#include "Effect.h"

const int8_t Coin::yOffsets[12] = { -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 0, 0 };

uint8_t Coin::yOffsetCounter = 0;
uint16_t Coin::collectedAmount[COINTYPEAMOUNT] = { 0, 0, 0, 0 };
uint16_t Coin::totalAmount[COINTYPEAMOUNT] = { 0, 0, 0, 0 };

Coin::Coin(uint8_t subType, Point position)
{
	type = ObjectType::Coin;

	this->subType = subType;
	this->position = position;

	totalAmount[subType]++;
}
Coin::~Coin(){ totalAmount[subType]--; }

void Coin::draw()
{
	if(active)
	{
		coinsSpriteSheet.setFrame(subType);
		gb.display.drawImage(position.x + 1 - CAMERA->getPosition().x, position.y + 1 - CAMERA->getPosition().y + yOffsets[((((position.x + position.y) * 2) / 8) + yOffsetCounter) % 12], coinsSpriteSheet);
	}
}

void Coin::interact()
{
	collectedAmount[subType]++;

	EFFECT->showBling(position, 0);
	gb.sound.stop(coinSoundTrack);
	coinSoundTrack = gb.sound.play(coinSound);

	active = false;
}

void Coin::reset()
{
	if(!active)
	{
		active = true;
		collectedAmount[subType]--;
	}
}