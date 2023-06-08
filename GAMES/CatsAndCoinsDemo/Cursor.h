#pragma once

#include "Globals.h"
#include "Tool.h"

enum class CursorMode
{
	Add,
	Remove
};

class Cursor
{
public:
	void draw();
	void update();

	Point getPosition(){ return position; }
	void setPosition(Point newPosition){ position = newPosition; }

private:
	Point position;
	CursorMode mode = CursorMode::Add;

	uint8_t blinkCounter = 0;
};