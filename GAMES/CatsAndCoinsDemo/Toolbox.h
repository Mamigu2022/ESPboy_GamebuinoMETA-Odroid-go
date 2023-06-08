#pragma once

#include "Globals.h"
#include "Tool.h"

#define TOOLBOX Toolbox::getInstance()

enum class ToolboxMode
{
	SelectCategory,
	SelectTool
};

class Toolbox
{
public:
	static Toolbox* getInstance();

	void update();
	void draw();
	Tool getCurrentTool(){ return tools[currentToolGlobal]; }

private:
	static Toolbox* instance;

	void drawDescription(char* description);
	uint8_t calculateCategoryToolAmount();

	static const uint8_t TOOLAMOUNT = 20;
	Tool tools[TOOLAMOUNT] =
	{
		// ObjectType, SubType, Category, Image, Frame, ToolboxOffset, ToolboxDescription
		Tool(1, 0, 0, &groundSpriteSheet, 12, Point(0, 0), "Ground: Place\nsolid tiles."),
		Tool(2, 0, 0, &platformSpriteSheet, 0, Point(0, 0), "Platform: Place\njump through tiles."),
		Tool(3, 0, 0, &spikesSpriteSheet, 0, Point(0, 0), "Spikes: Place\npainful tiles."),
		Tool(4, 0, 0, &plantsSpriteSheet, 0, Point(0, 3), "Plant: Place\ndecoration tiles."),
		Tool(8, 0, 0, &backWallSpriteSheet, 0, Point(0, 0), "BackWall: Add\nbackground to any\ntile."),
		Tool(9, 0, 1, &coinsSpriteSheet, 0, Point(1, 1), "GoldCoin: Getting\nall will reveal\nExitSign."),
		Tool(9, 1, 1, &coinsSpriteSheet, 1, Point(1, 1), "RedCoin: Getting\nall will show/hide\nRedBlocks."),
		Tool(9, 2, 1, &coinsSpriteSheet, 2, Point(1, 1), "GreenCoin: Getting\nall will show/hide\nGreenBlocks."),
		Tool(9, 3, 1, &coinsSpriteSheet, 3, Point(1, 1), "BlueCoin: Getting\nall will show/hide\nBlueBlocks."),
		Tool(10, 0, 1, &healthSpriteSheet, 0, Point(1, 0), "Health: Restores\n1/2 heart."),
		Tool(11, 0, 2, &blocksSpriteSheet, 0, Point(0, 0), "RedBlock H: Shows\nwhen you get all\nRedCoins."),
		Tool(11, 1, 2, &blocksSpriteSheet, 1, Point(0, 0), "GreenBlock H: Shows\nwhen you get all\nGreenCoins."),
		Tool(11, 2, 2, &blocksSpriteSheet, 2, Point(0, 0), "BlueBlock H: Shows\nwhen you get all\nBlueCoins."),
		Tool(11, 3, 2, &blocksSpriteSheet, 3, Point(0, 0), "RedBlock S: Hides\nwhen you get all\nRedCoins."),
		Tool(11, 4, 2, &blocksSpriteSheet, 4, Point(0, 0), "GreenBlock S: Hides\nwhen you get all\nGreenCoins."),
		Tool(11, 5, 2, &blocksSpriteSheet, 5, Point(0, 0), "BlueBlock S: Hides\nwhen you get all\nBlueCoins."),
		Tool(12, 0, 2, &crateSprite, 0, Point(0, 0), "Crate: Can contain\nCoin (not yet)."),
		Tool(13, 0, 3, &wormSpriteSheet, 0, Point(-1, 0), "Worm: Moves slowly,\nTurns around on\ncollision."),
		Tool(14, 0, 3, &birdSpriteSheet, 0, Point(-1, 0), "Bird: Moves slowly,\nTurns around on\ncollision."),
		Tool(15, 0, 3, &rangeLimiterSprite, 0, Point(0, 0), "RangeLimiter")
	};

	ToolboxMode mode = ToolboxMode::SelectTool;
	uint8_t currentCategory = 0;
	uint8_t currentTool = 0;
	uint8_t currentToolGlobal = 0;

	uint8_t arrowCounter = 0;

	static const uint8_t CATEGORYAMOUNT = 4;
	char* categoryNames[CATEGORYAMOUNT] =
	{
		" Tiles  ",
		"Pickups ",
		"CoinObjs",
		"Enemies "
	};

	char* categoryDescriptions[CATEGORYAMOUNT] =
	{
		"-Tiles category-\nLevel building\nblocks.",
		"-Pickups category-\nCollectable\nobjects.",
		"-CoinObjs category-\nCoin related\nobjects.",
		"-Enemies category-\nEnemy objects."
	};

	const uint8_t cursorBitmap[34] =
	{
	  16, 16,
	  0b11100000,0b00000111,
	  0b10000000,0b00000001,
	  0b10000000,0b00000001,
	  0b00000000,0b00000000,
	  0b00000000,0b00000000,
	  0b00000000,0b00000000,
	  0b00000000,0b00000000,
	  0b00000000,0b00000000,
	  0b00000000,0b00000000,
	  0b00000000,0b00000000,
	  0b00000000,0b00000000,
	  0b00000000,0b00000000,
	  0b00000000,0b00000000,
	  0b10000000,0b00000001,
	  0b10000000,0b00000001,
	  0b11100000,0b00000111
	};
};