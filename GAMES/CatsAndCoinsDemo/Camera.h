#pragma once

#include "Globals.h"
#include "Tool.h"

#define CAMERA Camera::getInstance()

class Camera
{
public:
	static Camera* getInstance();

	void update();

	Point getPosition(){ return Point(position.x + offset.x, position.y + offset.y); }
	void setPosition(Point newPosition);

	void shake(uint8_t duration){ shakeCounter = duration; }

	uint8_t getOutOfBounds();

private:
	static Camera* instance;

	Point position;
	Point offset;

	uint8_t shakeCounter;
};