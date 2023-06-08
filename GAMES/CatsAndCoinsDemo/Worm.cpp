#include "Worm.h"

#include "Camera.h"
#include "Level.h"
#include "UserInterface.h"

Worm::Worm(Point position)
{
	type = ObjectType::Worm;

	this->position = position;
	startPosition = position;

	collider.setDimensions(Rect(0, 0, 8, 8));
}

void Worm::update()
{
	if(flashCounter > 0) flashCounter--;

	if(alive)
	{
		frame = ++frame % 16;

		if(movementSlowdown == 0)
		{
			if(!LEVEL->checkTilemapCollision(collider, Point(direction, 0), TILE_GROUND) && !LEVEL->checkRangeLimiterCollision(collider, direction)) position.x += direction;
			else direction *= -1;
		}
		movementSlowdown = ++movementSlowdown % 2;

		if(grounded && !LEVEL->checkTilemapCollision(collider, Point(0, 1), TILE_GROUND) && !LEVEL->checkTilemapCollision(collider, Point(0, 1), TILE_PLATFORM)) grounded = false;
		
		if(!grounded)
		{
			ySpeed = min(ySpeed + 1, 7);

			if(ySpeed < 0)
			{
				if(LEVEL->checkTilemapCollision(collider, Point(0, ySpeed), TILE_GROUND))
				{
					position.y = ((position.y + collider.getTop() + ySpeed) / 8 * 8) + 8 - collider.getTop();
					
					ySpeed = 0;
				}
				else position.y += ySpeed;
			}
			else
			{
				if(LEVEL->checkTilemapCollision(collider, Point(0, ySpeed), TILE_GROUND))
				{
					position.y = ((position.y + collider.getBottom() + ySpeed) / 8 * 8) - 8;

					ySpeed = 0;
					grounded = true;
				}
				else if(LEVEL->checkTilemapCollision(collider, Point(0, ySpeed), TILE_PLATFORM))
				{
					bool currentlyOnPlatform = LEVEL->checkTilemapCollision(collider, Point(0, 0), TILE_PLATFORM);

					int16_t currentYPos = (position.y + collider.getBottom()) / 8;
					int16_t nextYPos = (position.y + collider.getBottom() + ySpeed) / 8;

					if(!currentlyOnPlatform || nextYPos != currentYPos)
					{
						position.y = ((position.y + collider.getBottom() + ySpeed) / 8 * 8) - 8;
						
						ySpeed = 0;
						grounded = true;
					}
					else position.y += ySpeed;
				}
				else position.y += ySpeed;
			}
		}
	}
	else if(flashCounter == 0)
	{
		position.x += direction;

		ySpeed = min(ySpeed + 1, 7);
		position.y += ySpeed;
	}
}

void Worm::draw()
{
	if(active)
	{
		if(alive)
		{
			wormSpriteSheet.setFrame(frame / 4);
			gb.display.drawImage(position.x - 1 - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, wormSpriteSheet, 10 * direction, 8);
		}
		else
		{
			if(flashCounter > 0) wormSpriteSheet.setFrame(4);
			else wormSpriteSheet.setFrame(1);
			
			gb.display.drawImage(position.x - 1 - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, wormSpriteSheet, 10 * direction, -8);
		}
	}
}

void Worm::interact()
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

void Worm::reset()
{
	active = true;
	alive = true;
	ySpeed = 0;
	position = startPosition;
}