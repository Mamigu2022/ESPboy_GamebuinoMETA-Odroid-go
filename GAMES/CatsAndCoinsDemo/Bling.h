#pragma once

#include "Globals.h"

class Bling
{
public:
	bool show(Point position, uint8_t type);
	void update();
	void draw();

	bool getActive(){ return active; }

private:
	Point position;
	uint8_t frame = 0;
	uint8_t type = 0;
	bool active = false;
};