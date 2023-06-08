#include "Player.h"

#include "Camera.h"
#include "Level.h"

void Player::update()
{
	if(hurt)
	{
		hurtCounter--;

		if(hurtCounter > 47) return;

		if(hurtCounter % 2) hurtShow = !hurtShow;
		if(hurtCounter == 0) hurt = false;
	}

	if(!crouching && gb.buttons.repeat(BUTTON_LEFT, 1))
	{
		if(!LEVEL->checkTilemapCollision(collider, Point(-2, 0), TILE_GROUND)) position.x -= 2;
		else if(!LEVEL->checkTilemapCollision(collider, Point(-1, 0), TILE_GROUND)) position.x -= 1;

		direction = DIR_LEFT;

		state = PLAYERSTATE_MOVING;
	}
	else if(!crouching && gb.buttons.repeat(BUTTON_RIGHT, 1))
	{
		if(!LEVEL->checkTilemapCollision(collider, Point(2, 0), TILE_GROUND)) position.x += 2;
		else if(!LEVEL->checkTilemapCollision(collider, Point(1, 0), TILE_GROUND)) position.x += 1;
		
		direction = DIR_RIGHT;

		state = PLAYERSTATE_MOVING;
	}
	else state = PLAYERSTATE_IDLING;

	if(grounded)
	{
		if(gb.buttons.repeat(BUTTON_DOWN, 1)) crouching = true;
		else crouching = false;

		if(gb.buttons.pressed(BUTTON_A))
		{
			if(crouching && LEVEL->checkTilemapCollision(collider, Point(0, 1), TILE_PLATFORM) && !LEVEL->checkTilemapCollision(collider, Point(0, 1), TILE_GROUND))
			{
				position.y++;

				ySpeed = 1;

				grounded = false;
				crouching = false;
			}
			else if(!crouching) jump();
		}

		if(!LEVEL->checkTilemapCollision(collider, Point(0, 1), TILE_GROUND) && !LEVEL->checkTilemapCollision(collider, Point(0, 1), TILE_PLATFORM))
		{
			grounded = false;
			ghostJumpAvailable = true;
		}
	}
	
	if(!grounded)
	{
		if(!gb.buttons.repeat(BUTTON_A, 1)) jumpCounter = 0;
		ySpeed = ((jumpCounter > 0)?-4:min(ySpeed + 1, 7));
		jumpCounter = max(jumpCounter - 1, 0);

		if(ySpeed < 0)
		{
			if(LEVEL->checkTilemapCollision(collider, Point(0, ySpeed), TILE_GROUND))
			{
				position.y = ((position.y + collider.getTop() + ySpeed) / 8 * 8) + 8 - collider.getTop();
				
				ySpeed = 0;
				jumpCounter = 0;
			}
			else position.y += ySpeed;
		}
		else
		{
			if(ghostJumpAvailable && ySpeed < 4)
			{
				if(gb.buttons.pressed(BUTTON_A))
				{
					jump();
					ghostJumpAvailable = false;
				}
			}

			if(LEVEL->checkTilemapCollision(collider, Point(0, ySpeed), TILE_GROUND))
			{
				position.y = ((position.y + collider.getBottom() + ySpeed) / 8 * 8) - 14;

				if(LEVEL->checkCrateCollision(collider, ySpeed)) ySpeed = -6;
				else
				{	
					ySpeed = 0;
					grounded = true;
					gb.sound.play(landSound);
					ghostJumpAvailable = false;
				}
			}
			else if(LEVEL->checkTilemapCollision(collider, Point(0, ySpeed), TILE_PLATFORM))
			{
				bool currentlyOnPlatform = LEVEL->checkTilemapCollision(collider, Point(0, 0), TILE_PLATFORM);

				int16_t currentYPos = (position.y + collider.getBottom()) / 8;
				int16_t nextYPos = (position.y + collider.getBottom() + ySpeed) / 8;

				if(!currentlyOnPlatform || nextYPos != currentYPos)
				{
					position.y = ((position.y + collider.getBottom() + ySpeed) / 8 * 8) - 14;
					
					ySpeed = 0;
					grounded = true;
					gb.sound.play(landSound);
					ghostJumpAvailable = false;
				}
				else position.y += ySpeed;
			}
			else
			{
				position.y += ySpeed;
			}
		}
	}

	LEVEL->checkPickupCollision(collider2);

	LEVEL->checkEnemyCollision(collider, ySpeed);

	CAMERA->setPosition(Point(position.x - 32, position.y - 26));

	if(LEVEL->checkTilemapCollision(collider, Point(0, 0), TILE_SPIKES)) setHurt();
}

void Player::draw()
{
	if(hurt)
	{
		if(!hurtShow) return;
		else if(hurtCounter > 46)
		{
			gb.display.drawImage(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, playerHurtSprite, 16 * direction, 16);
			return;
		}
	}
	
	if(grounded)
	{
		if(!crouching) gb.display.drawImage(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, (state == PLAYERSTATE_IDLING)?playerIdlingSpriteSheet:playerWalkingSpriteSheet, 16 * direction, 16);
		else gb.display.drawImage(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, playerCrouchingSpriteSheet, 16 * direction, 16);
	}
	else gb.display.drawImage(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, (ySpeed <= 0)?playerJumpingSpriteSheet:playerFallingSpriteSheet, 16 * direction, 16);
}

void Player::setHurt()
{
	if(!hurt)
	{
		hurt = true;
		hurtShow = true;
		hurtCounter = 50;
		health--;
		CAMERA->shake(10);
		gb.sound.play(painSound);
	}
}

void Player::stomp()
{
	position.y = ((position.y + collider.getBottom() + ySpeed) / 8 * 8) - 14;

	ySpeed = -6;
}

void Player::jump()
{
	ySpeed = -4;
				
	grounded = false;
	gb.sound.play(jumpSound);

	jumpCounter = 6;
}