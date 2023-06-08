#pragma once

#include "Globals.h"

class Collider
{
public:
	Collider(){}
	Collider(Point* position, Rect dimensions);

	bool hitTest(Point colliderPoint);
	bool hitTest(Collider collider, Point offset = Point(0, 0));

	void setDimensions(Rect dimensions);
	Point* getPosition(){ return position; }
	uint8_t getTop(){ return top; }
	uint8_t getBottom(){ return bottom; }
	uint8_t getLeft(){ return left; }
	uint8_t getRight(){ return right; }

private:
    Point* position;
    uint8_t top, bottom, left, right;
};