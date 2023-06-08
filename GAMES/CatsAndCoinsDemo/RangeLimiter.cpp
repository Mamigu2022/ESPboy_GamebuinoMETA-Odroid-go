#include "RangeLimiter.h"

#include "Camera.h"
#include "Effect.h"

RangeLimiter::RangeLimiter(Point position)
{
	type = ObjectType::RangeLimiter;

	this->position = position;
}

void RangeLimiter::draw()
{
	if(GAMEMANAGER->getMode() == GameMode::Editing) gb.display.drawImage(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, rangeLimiterSprite);
}