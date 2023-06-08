#include "Bling.h"

#include "Camera.h"

bool Bling::show(Point position, uint8_t type)
{
	this->position = position;
	this->type = type;
	frame = 0;
	
	active = true;
return 0;
}

void Bling::update()
{
	frame++;
	if(frame == 12) active = false;
}

void Bling::draw()
{
	if(type == 0) bling1SpriteSheet.setFrame(frame / 2);
	else if(type == 1) bling2SpriteSheet.setFrame(frame / 2);

	gb.display.drawImage(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, (type == 0)?bling1SpriteSheet:bling2SpriteSheet);
}
