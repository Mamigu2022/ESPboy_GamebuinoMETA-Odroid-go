#pragma once

#include "Globals.h"
#include "BaseObject.h"

#define LEVEL Level::getInstance()

#define TILE_NONE 0
#define TILE_GROUND 1
#define TILE_PLATFORM 2
#define TILE_SPIKES 3
#define TILE_PLANT 4
#define TILE_OTHER1 5
#define TILE_OTHER2 6
#define TILE_OTHER3 7
#define TILE_BACK 8

class Level
{
public:
	static Level* getInstance();
	
	void update();
	void draw();

	bool checkTilemapCollision(Collider collider, Point offset, uint8_t tileType);
	bool checkPlatformCollision(Collider collider, int16_t offset = 0);

	void checkPickupCollision(Collider collider);
	bool checkCrateCollision(Collider collider, int16_t yOffset);
	bool checkEnemyCollision(Collider collider, int16_t yOffset);
	bool checkRangeLimiterCollision(Collider collider, int16_t xOffset);

	uint8_t getTile(uint16_t tile, bool excludeBack = false){ return (tilemap[tile] & (excludeBack?0b0111:0b1111)); }
	void setTile(uint16_t tile, uint8_t value){ tilemap[tile] = value; }
	void removeTile(uint16_t tile, uint8_t value){ if(value == getTile(tile, true)) tilemap[tile] &= 0b1000; else if(value == TILE_BACK) tilemap[tile] &= 0b0111; }

	BaseObject* findObject(Point position);
	void addObject(ObjectType type, uint8_t subType, Point position);
	void removeObject(Point position);
	void resetObjects();

	uint8_t getWidth(){ return width; }
	uint8_t getHeight(){ return height; }

	bool playing = true;

private:
	static Level* instance;

	Level();

	uint8_t calculateGroundTileFrame(uint16_t tile);
	uint8_t calculatePlatformTileFrame(uint16_t tile);
	uint8_t calculateBackTileFrame(uint16_t tile);
	
	uint8_t width = 32;
	uint8_t height = 32;

	uint8_t tilemap[1024] =
	{
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,8,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,8,8,0,1,1,1,1,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,
		9,10,10,9,9,9,9,9,9,1,1,1,0,0,2,2,0,0,0,0,0,0,0,0,0,0,4,1,1,1,1,1,
		9,8,8,8,8,8,8,8,8,9,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
		9,12,8,8,8,8,8,8,8,9,1,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,
		9,9,9,9,9,9,9,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,
		1,1,1,1,1,1,1,9,9,9,8,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,9,
		1,1,1,1,1,1,0,8,8,8,8,8,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,12,8,8,9,
		1,1,1,1,1,0,0,0,8,8,8,8,8,0,1,1,1,4,0,0,0,0,0,0,0,0,1,1,9,9,9,9,
		1,1,1,1,1,0,0,0,0,8,8,8,8,8,9,1,1,1,0,0,0,0,0,0,2,10,9,9,9,9,9,9,
		1,0,0,0,0,0,0,0,0,12,9,11,11,9,1,1,1,1,1,0,0,0,0,0,0,8,8,8,8,8,8,9,
		1,0,0,0,0,0,0,0,1,1,9,9,9,9,9,1,1,1,1,0,0,0,2,2,8,8,8,8,8,8,8,9,
		1,1,1,0,4,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,4,0,8,8,8,8,12,12,8,9,9,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9
	};

	static const uint16_t OBJECTMAX = 512;
	BaseObject* objects[OBJECTMAX];

	uint8_t spikeCounter = 0;
};