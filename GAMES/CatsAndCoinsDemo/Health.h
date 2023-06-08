#pragma once

#include "Globals.h"
#include "BaseObject.h"

class Health : public BaseObject
{  
public:
	Health(Point position);

	void update() override;
	void draw() override;

	void interact() override;

	void reset() override;

private:
	uint8_t frame = 0;
};