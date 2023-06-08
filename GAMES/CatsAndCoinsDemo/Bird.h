#pragma once

#include "Globals.h"
#include "BaseObject.h"

class Bird : public BaseObject
{  
public:
	Bird(Point position);

	void update() override;
	void draw() override;

	void interact() override;

	void reset() override;

private:
	int8_t direction = DIR_RIGHT;

	Point startPosition;
	int8_t startDirection = DIR_RIGHT;

	uint8_t frame = 0;

	bool alive = true;

	int8_t ySpeed = 0;

	uint8_t flashCounter = 0;

	uint8_t movementSlowdown = 0;
};