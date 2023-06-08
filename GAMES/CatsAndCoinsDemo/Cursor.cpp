#include "Cursor.h"

#include "Camera.h"
#include "Toolbox.h"
#include "Level.h"

void Cursor::update()
{
	// MOVEMENT
	if(gb.buttons.repeat(BUTTON_UP, 4)) position.y = max(position.y - 1, 0);
	if(gb.buttons.repeat(BUTTON_DOWN, 4)) position.y = min(position.y + 1, LEVEL->getHeight() - 1);
	if(gb.buttons.repeat(BUTTON_LEFT, 4)) position.x = max(position.x - 1, 0);
	if(gb.buttons.repeat(BUTTON_RIGHT, 4)) position.x = min(position.x + 1, LEVEL->getWidth() - 1);

	// ACTION
	Tool tool = TOOLBOX->getCurrentTool();

  if(tool.getType() < 9) // Tiles
  {
  	uint16_t tile = (position.y * LEVEL->getWidth()) + position.x;

  	if(gb.buttons.pressed(BUTTON_A)) // Set mode by checking tile at current position
		{
			if(tool.getType() != TILE_BACK) mode = (LEVEL->getTile(tile, true) != tool.getType())?CursorMode::Add:CursorMode::Remove;
			else mode = (!(LEVEL->getTile(tile) & tool.getType()))?CursorMode::Add:CursorMode::Remove;
		}

  	if(gb.buttons.repeat(BUTTON_A, 1)) // Add or remove tile
  	{
  		if(mode == CursorMode::Add)
			{
				// Remove object at position in case there is one, only if tool is specific type
				if(tool.getType() == TILE_GROUND || tool.getType() == TILE_SPIKES)
				{
					BaseObject* object = LEVEL->findObject(Point(position.x * 8, position.y * 8));
					if(object != nullptr) LEVEL->removeObject(Point(position.x * 8, position.y * 8));
				}

				// Set tile
				if(tool.getType() != TILE_BACK) LEVEL->setTile(tile, (LEVEL->getTile(tile) & TILE_BACK) | tool.getType());
				else LEVEL->setTile(tile, LEVEL->getTile(tile) | tool.getType());
			}
  		else LEVEL->removeTile(tile, tool.getType());
  	}
  }
  else if(tool.getType() >= 9) // Objects
  {
  	uint16_t tile = (position.y * LEVEL->getWidth()) + position.x;

  	if(LEVEL->getTile(tile) != TILE_GROUND && LEVEL->getTile(tile) != TILE_SPIKES)
  	{
	  	if(gb.buttons.pressed(BUTTON_A)) // Set mode by checking object at current position
			{
				BaseObject* object = LEVEL->findObject(Point(position.x * 8, position.y * 8));

				if(object != nullptr && tool.isType(object)) mode = CursorMode::Remove;
				else mode = CursorMode::Add;
			}
	  	if(gb.buttons.repeat(BUTTON_A, 1)) // Add or remove object
	  	{
	  		if(mode == CursorMode::Add) LEVEL->addObject(static_cast<ObjectType>(tool.getType() - 9), tool.getSubType(), Point(position.x * 8, position.y * 8));
	  		else LEVEL->removeObject(Point(position.x * 8, position.y * 8));
	  	}
  	}
  }

  CAMERA->setPosition(Point((position.x * 8) - 32, (position.y * 8) - 24));
}

void Cursor::draw()
{
	blinkCounter = ++blinkCounter % 16;

	Tool tool = TOOLBOX->getCurrentTool();

	uint16_t tile = (position.y * LEVEL->getWidth()) + position.x;

  if(blinkCounter > 7)
  {
  	if(gb.buttons.repeat(BUTTON_A, 1))
  	{
  		if(mode == CursorMode::Remove && !(tool.getType() > 8 && (LEVEL->getTile(tile, true) == TILE_GROUND || LEVEL->getTile(tile, true) == TILE_SPIKES))) gb.display.drawImage((position.x * 8) - CAMERA->getPosition().x, (position.y * 8) - CAMERA->getPosition().y, cursorCrossSprite);
  	}
  	else
  	{
  		BaseObject* object = LEVEL->findObject(Point(position.x * 8, position.y * 8));

  		bool condition1 = (tool.getType() < 8 && tool.getType() == LEVEL->getTile(tile, true)); // If tile at position equals tool type
			bool condition2 = (tool.getType() == TILE_BACK && LEVEL->getTile(tile) & TILE_BACK); // If both tool and tile are TILE_BACK
			bool condition3 = (object != nullptr)?(tool.getType() > 8 && tool.isType(object)):false; // If object at position equals tool type

  		if(condition1 || condition2 || condition3) gb.display.drawImage((position.x * 8) - CAMERA->getPosition().x, (position.y * 8) - CAMERA->getPosition().y, cursorCrossSprite);
  		else if(!(tool.getType() > 8 && (LEVEL->getTile(tile, true) == TILE_GROUND || LEVEL->getTile(tile, true) == TILE_SPIKES)))
  		{
  			tool.getImage()->setFrame(tool.getFrame());
  			gb.display.drawImage((position.x * 8) + tool.getOffset().x - CAMERA->getPosition().x, (position.y * 8) + tool.getOffset().y - CAMERA->getPosition().y, *tool.getImage());
  		}
  	}
  }

  // If tool is object and cursor is over a tile then the cursor should blink to indicate it's not possible to place an object there
  bool blinkCursor = (tool.getType() > 8 && (LEVEL->getTile(tile, true) == TILE_GROUND || LEVEL->getTile(tile, true) == TILE_SPIKES));
	if(!blinkCursor || blinkCounter > 7) gb.display.drawImage((position.x * 8) - 1 - CAMERA->getPosition().x, (position.y * 8) - 1 - CAMERA->getPosition().y, cursorSprite);
}