#include "Crate.h"

#include "Camera.h"
#include "Effect.h"

Crate::Crate(Point position)
{
	type = ObjectType::Crate;
	solid = true;

	this->position = position;
}

void Crate::update()
{
	if(flashCounter > 0) flashCounter--;
	if(flashCounter == 1)
	{
		EFFECT->showCratePiece(Point(position.x, position.y), Point(-1, -random(4, 6)), 0);
		EFFECT->showCratePiece(Point(position.x, position.y + 4), Point(-2, -random(1, 4)), 1);
		EFFECT->showCratePiece(Point(position.x + 4, position.y), Point(1, -random(4, 6)), 2);
		EFFECT->showCratePiece(Point(position.x + 4, position.y + 4), Point(2, -random(1, 4)), 3);
	}
}

void Crate::draw()
{
	if(active) gb.display.drawImage(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, crateSprite);
	else if(flashCounter > 1)
	{
		gb.display.setColor(COLOR_WHITE);
		gb.display.fillRect(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, 8, 8);
	}
}

void Crate::interact()
{
	active = false;
	gb.sound.play(killSound);
	flashCounter = 4;
}

void Crate::reset()
{
	active = true;
}