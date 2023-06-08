#include "Health.h"

#include "Camera.h"
#include "Effect.h"

Health::Health(Point position)
{
	type = ObjectType::Health;

	this->position = position;
}

void Health::update()
{
	frame = ++frame % 12;
}

void Health::draw()
{
	if(active)
	{
		healthSpriteSheet.setFrame(frame / 3);
		gb.display.drawImage(position.x + 1 - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, healthSpriteSheet);
	}
}

void Health::interact()
{
	EFFECT->showBling(position, 1);
	gb.sound.stop(coinSoundTrack);
	coinSoundTrack = gb.sound.play(coinSound);

	active = false;
}

void Health::reset()
{
	active = true;
}