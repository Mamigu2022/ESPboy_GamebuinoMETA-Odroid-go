#pragma once

#include "Globals.h"

#define PLAYERSTATE_IDLING 0
#define PLAYERSTATE_MOVING 1

class Player
{
public:
	Player(Point position, uint8_t direction) : position(position), direction(direction){}

	void update();
	void draw();
	
	Point getPosition(){ return position; }
	void setPosition(Point newPosition){ position = newPosition; }

	int8_t getHealth(){ return health; }
	void setHealth(uint8_t newHealth){ health = clamp(newHealth, 0, 6); }

	bool getGrounded(){ return grounded; }
	
	int8_t getYSpeed(){ return ySpeed; }
	void setYSpeed(int8_t newYSpeed){ ySpeed = newYSpeed; }

	void setHurt();
	void stomp();

private:
	void jump();

	int8_t state = PLAYERSTATE_IDLING;
	
	Point position;
	int8_t direction;
	
	int8_t ySpeed = 0;
	uint8_t jumpCounter = 0;
	bool ghostJumpAvailable = false;

	bool grounded = true;
	bool crouching = false;

	Collider collider = Collider(&position, Rect(5, 2, 6, 12));
	Collider collider2 = Collider(&position, Rect(3, 0, 10, 14));

	uint8_t health = 6;

	bool hurt = false;
	bool hurtShow = false;
	uint8_t hurtCounter = 0;
};