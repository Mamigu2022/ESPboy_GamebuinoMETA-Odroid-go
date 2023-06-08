#pragma once

#include "Globals.h"
#include "BaseObject.h"

class Block : public BaseObject
{  
public:
	Block(uint8_t subType, Point position);

	void update() override;
	void draw() override;

	void reset() override;

private:
	void setState(bool state);
};