#pragma once

#include "Globals.h"
#include "BaseObject.h"

class Crate : public BaseObject
{  
public:
	Crate(Point position);

	void update() override;
	void draw() override;

	void interact() override;

	void reset() override;

private:
	uint8_t flashCounter = 0;
};