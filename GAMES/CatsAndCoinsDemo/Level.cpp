#include "Level.h"

#include "Camera.h"
#include "UserInterface.h"
#include "Coin.h"
#include "Health.h"
#include "Block.h"
#include "Crate.h"
#include "Worm.h"
#include "Bird.h"
#include "RangeLimiter.h"

Level* Level::instance = nullptr;
Level* Level::getInstance()
{
	if(!instance) instance = new Level();
	return instance;
}

Level::Level()
{
	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		objects[i] = nullptr;	
	}

	// Blocks
	addObject(ObjectType::Block, 0, Point(22 * 8, 23 * 8));
	addObject(ObjectType::Block, 0, Point(22 * 8, 24 * 8));
	addObject(ObjectType::Block, 0, Point(23 * 8, 24 * 8));

	addObject(ObjectType::Block, 5, Point(3 * 8, 28 * 8));
	addObject(ObjectType::Block, 5, Point(3 * 8, 29 * 8));
	addObject(ObjectType::Block, 5, Point(3 * 8, 30 * 8));

	// Coins
	addObject(ObjectType::Coin, 0, Point(2 * 8, 15 * 8));
	addObject(ObjectType::Coin, 0, Point(3 * 8, 15 * 8));
	addObject(ObjectType::Coin, 0, Point(4 * 8, 15 * 8));
	addObject(ObjectType::Coin, 0, Point(5 * 8, 15 * 8));
	addObject(ObjectType::Coin, 0, Point(2 * 8, 16 * 8));
	addObject(ObjectType::Coin, 0, Point(3 * 8, 16 * 8));
	addObject(ObjectType::Coin, 0, Point(4 * 8, 16 * 8));
	addObject(ObjectType::Coin, 0, Point(5 * 8, 16 * 8));

	addObject(ObjectType::Coin, 0, Point(27 * 8, 28 * 8));
	addObject(ObjectType::Coin, 0, Point(28 * 8, 28 * 8));
	addObject(ObjectType::Coin, 0, Point(29 * 8, 28 * 8));
	addObject(ObjectType::Coin, 0, Point(30 * 8, 28 * 8));
	addObject(ObjectType::Coin, 0, Point(27 * 8, 29 * 8));
	addObject(ObjectType::Coin, 0, Point(28 * 8, 29 * 8));
	addObject(ObjectType::Coin, 0, Point(29 * 8, 29 * 8));
	addObject(ObjectType::Coin, 0, Point(30 * 8, 29 * 8));

	addObject(ObjectType::Coin, 0, Point(27 * 8, 17 * 8));
	addObject(ObjectType::Coin, 0, Point(28 * 8, 17 * 8));
	addObject(ObjectType::Coin, 0, Point(29 * 8, 17 * 8));
	addObject(ObjectType::Coin, 0, Point(27 * 8, 18 * 8));
	addObject(ObjectType::Coin, 0, Point(28 * 8, 18 * 8));
	addObject(ObjectType::Coin, 0, Point(29 * 8, 18 * 8));

	addObject(ObjectType::Coin, 1, Point(1 * 8, 28 * 8));
	addObject(ObjectType::Coin, 1, Point(2 * 8, 28 * 8));
	addObject(ObjectType::Coin, 1, Point(1 * 8, 29 * 8));
	addObject(ObjectType::Coin, 1, Point(2 * 8, 29 * 8));

	addObject(ObjectType::Coin, 3, Point(7 * 8, 21 * 8));
	addObject(ObjectType::Coin, 3, Point(8 * 8, 21 * 8));
	addObject(ObjectType::Coin, 3, Point(7 * 8, 22 * 8));
	addObject(ObjectType::Coin, 3, Point(8 * 8, 22 * 8));

	addObject(ObjectType::Coin, 3, Point(29 * 8, 22 * 8));
	addObject(ObjectType::Coin, 3, Point(30 * 8, 22 * 8));
	addObject(ObjectType::Coin, 3, Point(29 * 8, 23 * 8));
	addObject(ObjectType::Coin, 3, Point(30 * 8, 23 * 8));

	// Crates
	addObject(ObjectType::Crate, 0, Point(1 * 8, 18 * 8));
	addObject(ObjectType::Crate, 0, Point(1 * 8, 19 * 8));
	addObject(ObjectType::Crate, 0, Point(2 * 8, 19 * 8));

	addObject(ObjectType::Crate, 0, Point(6 * 8, 18 * 8));
	addObject(ObjectType::Crate, 0, Point(7 * 8, 17 * 8));
	addObject(ObjectType::Crate, 0, Point(7 * 8, 18 * 8));
	addObject(ObjectType::Crate, 0, Point(8 * 8, 18 * 8));

	addObject(ObjectType::Crate, 0, Point(19 * 8, 30 * 8));

	// Health
	addObject(ObjectType::Health, 0, Point(9 * 8, 18 * 8));

	// Enemies
	addObject(ObjectType::Worm, 0, Point(21 * 8, 30 * 8));

	addObject(ObjectType::Bird, 0, Point(17 * 8, 21 * 8));
}

void Level::update()
{
	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr && (objects[i]->getType() != ObjectType::Worm || playing) && (objects[i]->getType() != ObjectType::Bird || playing)) objects[i]->update();
	}

	Coin::updateWaveEffect();
	spikeCounter = ++spikeCounter % 12;
}

void Level::draw()
{
	for (uint8_t y = 0; y < height; y++)
	{
		for (uint8_t x = 0; x < width; x++)
		{
			uint16_t tile = (y * width) + x;

			if(getTile(tile) == 0) continue;
			if((x * 8) - CAMERA->getPosition().x <= -8 || (x * 8) - CAMERA->getPosition().x >= 80) continue;
			if((y * 8) - CAMERA->getPosition().y <= -8 || (y * 8) - CAMERA->getPosition().y >= 64) continue; 

			if((getTile(tile) & TILE_BACK) && getTile(tile, true) != TILE_GROUND)
			{
				backWallSpriteSheet.setFrame(calculateBackTileFrame(tile));
				gb.display.drawImage((x * 8) - CAMERA->getPosition().x, (y * 8) - CAMERA->getPosition().y, backWallSpriteSheet);
			}

			if((getTile(tile, true) == TILE_GROUND))
			{
				if((getTile(tile) & TILE_BACK)) groundSpriteSheet.clearTransparentColor();
				else groundSpriteSheet.setTransparentColor((Color) 0x738C);

				groundSpriteSheet.setFrame(calculateGroundTileFrame(tile));
				gb.display.drawImage((x * 8) - CAMERA->getPosition().x, (y * 8) - CAMERA->getPosition().y, groundSpriteSheet);
			}
			else if((getTile(tile, true) == TILE_PLATFORM))
			{
				platformSpriteSheet.setFrame(calculatePlatformTileFrame(tile));
				gb.display.drawImage((x * 8) - CAMERA->getPosition().x, (y * 8) - CAMERA->getPosition().y, platformSpriteSheet);
			}
			else if((getTile(tile, true) == TILE_SPIKES))
			{
				spikesSpriteSheet.setFrame((((((x * 8) + (y * 8)) * 2) / 8) + (spikeCounter / 2)) % 3);
				gb.display.drawImage((x * 8) - CAMERA->getPosition().x, (y * 8) - CAMERA->getPosition().y, spikesSpriteSheet);
			}
			else if((getTile(tile, true) == TILE_PLANT))
			{
				plantsSpriteSheet.setFrame(((y % 2 == 0 && x % 2 == 0) || (y % 2 != 0 && x % 2 != 0))?0:1);
				gb.display.drawImage((x * 8) - CAMERA->getPosition().x, (y * 8) + 3 - CAMERA->getPosition().y, plantsSpriteSheet);
			}
		}
	}

	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr && (objects[i]->getType() == ObjectType::Coin || objects[i]->getType() == ObjectType::Health)) objects[i]->draw();
	}

	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr && objects[i]->getType() != ObjectType::Coin && objects[i]->getType() != ObjectType::Health) objects[i]->draw();
	}
}

bool Level::checkTilemapCollision(Collider collider, Point offset, uint8_t tileType)
{
	int16_t tile;

	if(tileType == TILE_GROUND || tileType == TILE_SPIKES)
	{
		// Check top-left
		tile = (((collider.getTop() + collider.getPosition()->y + offset.y) / 8) * width) + ((collider.getLeft() + collider.getPosition()->x + offset.x) / 8);
		if(tile > 0 && tile < width * height)
		{
			if(tileType == TILE_GROUND && getTile(tile, true) == TILE_GROUND) return true;
			if(tileType == TILE_SPIKES && getTile(tile, true) == TILE_SPIKES) return true;
		}

		// Check top-right
		tile = (((collider.getTop() + collider.getPosition()->y + offset.y) / 8) * width) + ((collider.getRight() + collider.getPosition()->x + offset.x) / 8);
		if(tile > 0 && tile < width * height)
		{
			if(tileType == TILE_GROUND && getTile(tile, true) == TILE_GROUND) return true;
			if(tileType == TILE_SPIKES && getTile(tile, true) == TILE_SPIKES) return true;
		}

		// Check middle-left
		tile = (((collider.getTop() + collider.getPosition()->y + offset.y + ((collider.getTop() + collider.getBottom()) / 2)) / 8) * width) + ((collider.getLeft() + collider.getPosition()->x + offset.x) / 8);
		if(tile > 0 && tile < width * height)
		{
			if(tileType == TILE_GROUND && getTile(tile, true) == TILE_GROUND) return true;
			if(tileType == TILE_SPIKES && getTile(tile, true) == TILE_SPIKES) return true;
		}

		// Check middle-right
		tile = (((collider.getTop() + collider.getPosition()->y + offset.y + ((collider.getTop() + collider.getBottom()) / 2)) / 8) * width) + ((collider.getRight() + collider.getPosition()->x + offset.x) / 8);
		if(tile > 0 && tile < width * height)
		{
			if(tileType == TILE_GROUND && getTile(tile, true) == TILE_GROUND) return true;
			if(tileType == TILE_SPIKES && getTile(tile, true) == TILE_SPIKES) return true;
		}

		if(tileType == TILE_GROUND)
		{
			for(uint16_t i = 0; i < OBJECTMAX; i++)
			{
				if(objects[i] != nullptr && objects[i]->getActive() && objects[i]->isSolid())
				{
					if(collider.hitTest(objects[i]->getCollider(), offset)) return true;
				}
			}
		}
	}
	else // TILE_PLATFORM
	{
		for(uint16_t i = 0; i < OBJECTMAX; i++)
		{
			if(objects[i] != nullptr && objects[i]->getActive() && objects[i]->isJumpThrough())
			{
				Collider objCollider = objects[i]->getCollider();

				bool bottomLeft = objCollider.hitTest(Point(collider.getPosition()->x + collider.getLeft() + offset.x, collider.getPosition()->y + collider.getBottom() + offset.y));
				bool bottomRight = objCollider.hitTest(Point(collider.getPosition()->x + collider.getRight() + offset.x, collider.getPosition()->y + collider.getBottom() + offset.y));

				if(bottomLeft || bottomRight) return true;
			}
		}
	}

	// Check bottom-left
	tile = (((collider.getBottom() + collider.getPosition()->y + offset.y) / 8) * width) + ((collider.getLeft() + collider.getPosition()->x + offset.x) / 8);
	if(tile > 0 && tile < width * height)
	{
		if(tileType == TILE_GROUND && getTile(tile, true) == TILE_GROUND) return true;
		if(tileType == TILE_PLATFORM && getTile(tile, true) == TILE_PLATFORM) return true;
		if(tileType == TILE_SPIKES && getTile(tile, true) == TILE_SPIKES) return true;
	}

	// Check bottom-right
	tile = (((collider.getBottom() + collider.getPosition()->y + offset.y) / 8) * width) + ((collider.getRight() + collider.getPosition()->x + offset.x) / 8);
	if(tile > 0 && tile < width * height)
	{
		if(tileType == TILE_GROUND && getTile(tile, true) == TILE_GROUND) return true;
		if(tileType == TILE_PLATFORM && getTile(tile, true) == TILE_PLATFORM) return true;
		if(tileType == TILE_SPIKES && getTile(tile, true) == TILE_SPIKES) return true;
	}

	return false;
}

void Level::checkPickupCollision(Collider collider)
{
	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr && objects[i]->getActive())
		{
			if((objects[i]->getType() == ObjectType::Health || objects[i]->getType() == ObjectType::Coin))
			{
				if(collider.hitTest(objects[i]->getCollider()))
				{
					if(objects[i]->getType() == ObjectType::Health) UI->player->setHealth(UI->player->getHealth() + 1);
					objects[i]->interact();
				}
			}
		}
	}
}

bool Level::checkCrateCollision(Collider collider, int16_t yOffset)
{
	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr)
		{
			if(objects[i]->getType() == ObjectType::Crate && objects[i]->getActive())
			{
				if(collider.hitTest(objects[i]->getCollider(), Point(0, yOffset)))
				{
					objects[i]->interact();
					return true;
				}
			}
		}
	}

	return false;
}

bool Level::checkEnemyCollision(Collider collider, int16_t yOffset)
{
	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr)
		{
			if((objects[i]->getType() == ObjectType::Worm || objects[i]->getType() == ObjectType::Bird) && objects[i]->getActive())
			{
				if(collider.hitTest(objects[i]->getCollider(), Point(0, yOffset)))
				{
					objects[i]->interact();
					return true;
				}
			}
		}
	}

	return false;
}

bool Level::checkRangeLimiterCollision(Collider collider, int16_t xOffset)
{
	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr)
		{
			if(objects[i]->getType() == ObjectType::RangeLimiter && objects[i]->getActive())
			{
				if(collider.hitTest(objects[i]->getCollider(), Point(xOffset, 0))) return true;
			}
		}
	}

	return false;
}

BaseObject* Level::findObject(Point position)
{
	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr)
		{
			if(objects[i]->getPosition().x == position.x && objects[i]->getPosition().y == position.y) return objects[i];
		}
	}

	return nullptr;
}

void Level::addObject(ObjectType type, uint8_t subType, Point position)
{
	BaseObject* object = findObject(position);

	if(object != nullptr)
	{
		if(object->getType() == type && object->getSubType() == subType) return;
		else removeObject(position);
	}

	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] == nullptr)
		{
			switch(type)
			{
				case ObjectType::Coin: objects[i] = new Coin(subType, position); break;
				case ObjectType::Health: objects[i] = new Health(position); break;
				case ObjectType::Block: objects[i] = new Block(subType, position); break;
				case ObjectType::Crate: objects[i] = new Crate(position); break;
				case ObjectType::Worm: objects[i] = new Worm(position); break;
				case ObjectType::Bird: objects[i] = new Bird(position); break;
				case ObjectType::RangeLimiter: objects[i] = new RangeLimiter(position); break;
			}

			return;
		}
	}
}

void Level::removeObject(Point position)
{
	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr)
		{
			if(objects[i]->getPosition().x == position.x && objects[i]->getPosition().y == position.y)
			{
				delete objects[i];
				objects[i] = nullptr;
			}
		}
	}
}

void Level::resetObjects()
{
	for(uint16_t i = 0; i < OBJECTMAX; i++)
	{
		if(objects[i] != nullptr) objects[i]->reset();
	}
}

uint8_t Level::calculateGroundTileFrame(uint16_t tile)
{
	uint8_t frame = 0;

	uint16_t offsetTile = 0;

	// Above
	offsetTile = tile - ((tile >= width)?width:0);
	frame += 0b0001 * ((getTile(offsetTile, true) == TILE_GROUND)?1:0);

	// Below
	offsetTile = tile + ((tile + width < width * height)?width:0);
	frame += 0b0010 * ((getTile(offsetTile, true) == TILE_GROUND)?1:0);

	// Left
	offsetTile = tile - ((tile % width != 0)?1:0);
	frame += 0b0100 * ((getTile(offsetTile, true) == TILE_GROUND)?1:0);

	// Right
	offsetTile = tile + ((tile % width != width - 1)?1:0);
	frame += 0b1000 * ((getTile(offsetTile, true) == TILE_GROUND)?1:0);

	if(frame > 13) frame -= 2;

	// Extra checks for corner tiles, don't check tiles in top row though
	if(tile >= width)
	{
		// Extra up-left check
		if(frame == 5 || frame == 7 || frame == 13)
		{
			offsetTile = tile - ((tile % width != 0)?(width + 1):0);
			if(getTile(offsetTile, true) != TILE_GROUND)
			{
				if(frame == 5) frame = 14;
				else if(frame == 7) frame = 15;
				else if(frame == 13) frame = 16;
			}
		}

		// Extra up-right check
		if(frame == 9 || frame == 11 || frame == 13 || frame == 16)
		{
			offsetTile = tile - ((tile % width != width - 1)?(width - 1):0);
			if(getTile(offsetTile, true) != TILE_GROUND)
			{
				if(frame == 9) frame = 17;
				else if(frame == 11) frame = 18;
				else if(frame == 13) frame = 19;
				else if(frame == 16) frame = 20;
			}
		}
	}

	// Randomize middle tile
	if(frame == 13 && !((tile - (tile / 10)) % 11)) frame = 21;

	return frame;
}

uint8_t Level::calculatePlatformTileFrame(uint16_t tile)
{
	uint8_t frame = 0;

	uint16_t offsetTile = 0;

	// Left
	offsetTile = tile - ((tile % width != 0)?1:0);
	frame += 0b0001 * ((getTile(offsetTile, true) == TILE_PLATFORM)?1:0);

	// Right
	offsetTile = tile + ((tile % width != width - 1)?1:0);
	frame += 0b0010 * ((getTile(offsetTile, true) == TILE_PLATFORM)?1:0);

	return frame;
}

uint8_t Level::calculateBackTileFrame(uint16_t tile)
{
	uint8_t frame = 0;

	uint16_t offsetTile = 0;

	// Above
	offsetTile = tile - ((tile >= width)?width:0);
	frame += 0b0001 * ((getTile(offsetTile) & TILE_BACK)?1:0);

	// Below
	offsetTile = tile + ((tile + width < width * height)?width:0);
	frame += 0b0010 * ((getTile(offsetTile) & TILE_BACK)?1:0);

	// Left
	offsetTile = tile - ((tile % width != 0)?1:0);
	frame += 0b0100 * ((getTile(offsetTile) & TILE_BACK)?1:0);

	// Right
	offsetTile = tile + ((tile % width != width - 1)?1:0);
	frame += 0b1000 * ((getTile(offsetTile) & TILE_BACK)?1:0);

	if(frame == 0b0000) frame = 0;
	else if(frame == 0b0001) frame = 1;
	else if(frame == 0b0010) frame = 2;
	else if(frame == 0b0100) frame = 3;
	else if(frame == 0b0101) frame = 4;
	else if(frame == 0b0110) frame = 5;
	else if(frame == 0b1000) frame = 6;
	else if(frame == 0b1001) frame = 7;
	else if(frame == 0b1010) frame = 8;
	else if(frame == 0b1100 || frame == 0b1110) frame = ((tile - (tile / 10)) % 11)?9:10;
	else if(frame == 0b0011 || frame == 0b0111 || frame == 0b1011 || frame == 0b1101 || frame == 0b1111) frame = ((tile - (tile / 10)) % 11)?11:12;

	return frame;
}