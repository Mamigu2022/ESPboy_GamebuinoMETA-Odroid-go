#include "CratePiece.h"

#include "Camera.h"

void CratePiece::show(Point position, Point velocity, uint8_t frame)
{
	this->position = position;
	this->velocity = velocity;
	this->frame = frame;
	timer = 30;

	active = true;
}

void CratePiece::update()
{
	velocity.y++;
	if(gb.frameCount % 2 == 0) position.x += velocity.x;
	position.y += velocity.y;

	timer--;
	if(timer == 0) active = false;
}

void CratePiece::draw()
{
	cratePiecesSpriteSheet.setFrame(frame);
	gb.display.drawImage(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, cratePiecesSpriteSheet);
}