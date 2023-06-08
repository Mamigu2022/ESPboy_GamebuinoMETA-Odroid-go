#pragma once

#include "Globals.h"
#include "BaseObject.h"

class Coin : public BaseObject
{  
public:
	Coin(uint8_t subType, Point position);
	~Coin();

	void draw() override;

	void interact() override;

	void reset() override;

	static void updateWaveEffect(){ yOffsetCounter = ++yOffsetCounter % 12; }

	static uint16_t getCollectedAmount(uint8_t subType){ return collectedAmount[subType]; }
	static uint16_t getTotalAmount(uint8_t subType){ return totalAmount[subType]; }

private:
	static uint8_t yOffsetCounter;
	static const int8_t yOffsets[12];

	static const int8_t COINTYPEAMOUNT = 4;
	static uint16_t collectedAmount[COINTYPEAMOUNT];
	static uint16_t totalAmount[COINTYPEAMOUNT];
};