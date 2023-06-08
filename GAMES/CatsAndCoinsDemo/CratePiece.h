#pragma once

#include "Globals.h"

class CratePiece
{
public:
	void show(Point position, Point velocity, uint8_t frame);
	
	void update();
	void draw();

	bool getActive(){ return active; }

private:
	Point position;
	Point velocity;
	uint8_t timer = 0;
	uint8_t frame = 0;

	bool active = false;
};