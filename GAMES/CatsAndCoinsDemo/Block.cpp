#include "Block.h"

#include "Camera.h"
#include "Level.h"
#include "Coin.h"

Block::Block(uint8_t subType, Point position)
{
	type = ObjectType::Block;
	solid = true;

	this->subType = subType;
	this->position = position;

	setState(false);
};

void Block::update()
{
	if(Coin::getTotalAmount(1 + subType % 3) != 0 && Coin::getCollectedAmount(1 + subType % 3) == Coin::getTotalAmount(1 + subType % 3)) setState(true);
}

void Block::draw()
{
	blocksSpriteSheet.setFrame((subType % 3) + (active?3:0));
	gb.display.drawImage(position.x - CAMERA->getPosition().x, position.y - CAMERA->getPosition().y, blocksSpriteSheet);
}

void Block::reset()
{
	setState(false);
}

void Block::setState(bool state)
{
	if(state) active = (subType < 3)?true:false;
	else active = (subType > 2)?true:false;
}