#pragma once

#include "Globals.h"
#include "Player.h"
#include "Cursor.h"

#define UI UserInterface::getInstance()

class UserInterface
{  
public:
	static UserInterface* getInstance();
	
	void update();

	void drawGameHud();
	void drawEditHud();
	void drawHardwareInfo();

	Player* player;
	Cursor* cursor;

private:
	static UserInterface* instance;

	void drawCoinNumber(uint8_t coinType, Point position);

	uint16_t previousCoinAmounts[3] = { 0, 0, 0 };

	uint8_t coinNumberVisibleCounter = 0;
	uint8_t coinVisibleType = 0;
};