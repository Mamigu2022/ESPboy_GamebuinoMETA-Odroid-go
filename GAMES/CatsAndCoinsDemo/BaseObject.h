#pragma once

#include "Globals.h"

enum class ObjectType
{
	Coin,
	Health,
	Block,
	Crate,
	Worm,
	Bird,
	RangeLimiter
};

class BaseObject
{  
public:
	virtual ~BaseObject(){}

	virtual void update(){}
	virtual void draw(){}

	ObjectType getType(){ return type; }
	uint8_t getSubType(){ return subType; }

	Point getPosition(){ return position; }
	void setPosition(Point newPosition){ position = newPosition; }

	Collider getCollider(){ return collider; }
	Collider setCollider(Rect dimensions){ collider = Collider(&position, dimensions); return collider;}

	bool getActive(){ return active; }
	virtual void setActive(bool value){ active = value; }

	virtual void interact(){}

	bool isSolid(){ return solid; }
	bool isJumpThrough(){ return jumpThrough; }

	virtual void reset(){}

protected:
	ObjectType type = ObjectType::Coin;
	uint8_t subType = 0;

	Point position;
	Collider collider = Collider(&position, Rect(0, 0, 8, 8));

	bool active = true;
	bool solid = false;
	bool jumpThrough = false;
};
