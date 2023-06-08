#include "Camera.h"

#include "Level.h"

Camera* Camera::instance = nullptr;
Camera* Camera::getInstance()
{
	if(!instance) instance = new Camera();
	return instance;
}

void Camera::update()
{
	if(shakeCounter > 0)
	{
		shakeCounter--;

		if(shakeCounter == 0) offset = Point(0, 0);
		else offset = Point(random(-1, 2), random(-1, 2));
	}
}

void Camera::setPosition(Point newPosition)
{
	position.x = clamp(newPosition.x, 0, (LEVEL->getWidth() * 8) - gb.display.width());
	position.y = clamp(newPosition.y, 0, (LEVEL->getHeight() * 8) - gb.display.height());
}

uint8_t Camera::getOutOfBounds()
{
	uint8_t bounds = 0;

	if(position.y + offset.y < 0) bounds += 0b0001;
	if(position.y + offset.y > (LEVEL->getHeight() * 8) - gb.display.height()) bounds += 0b0010;
	if(position.x + offset.x < 0) bounds += 0b0100;
	if(position.x + offset.x > (LEVEL->getWidth() * 8) - gb.display.width()) bounds += 0b1000;

	return bounds;
}