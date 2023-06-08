#include "Bird.h"

#include "Camera.h"
#include "Level.h"
#include "UserInterface.h"

Bird::Bird(Point position)
{
	type = ObjectType::Bird;

	this->position = position;
	startPosition = position;
	startDirection = direction;

	collider.setDimensions(Rect(0, 0, 8, 8));
}

void Bird::update()
{
	if(flashCounter > 0) flashCounter--;

	if(alive)
	{
		frame = ++frame % 12;

		if(!LEVEL->checkTilemapCollision(collider, Point(direction, 0), TILE_GROUND) && !LEVEL->checkRangeLimiterCollision(collider, direction)) position.x += direction;
		else direction *= -1;
	}
	else if(flashCounter == 0)
	{
		position.x += direction;

		ySpeed = min(ySpeed + 1, 7);
		position.y += ySpeed;
	}
}

void Bird::draw()
{
	if(active)
	{
		if(alive)
		{
			birdSpriteSheet.setFrame(frame / 3);
			gb.display.drawImage(position.x - 1 - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, birdSpriteSheet, 10 * direction, 10);
		}
		else
		{
			if(flashCounter > 0) birdSpriteSheet.setFrame(4);
			else birdSpriteSheet.setFrame(1);
			
			gb.display.drawImage(position.x - 1 - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, birdSpriteSheet, 10 * direction, -10);
		}
	}
}

void Bird::interact()
{
	if(!alive) return;

	if(!UI->player->getGrounded() && UI->player->getYSpeed() > 0)
	{
		UI->player->stomp();

		alive = false;
		flashCounter = 4;

		gb.sound.play(killSound);

		ySpeed = -4;
	}
	else UI->player->setHurt();
}

void Bird::reset()
{
	active = true;
	alive = true;
	ySpeed = 0;
	position = startPosition;
	direction = startDirection;
}