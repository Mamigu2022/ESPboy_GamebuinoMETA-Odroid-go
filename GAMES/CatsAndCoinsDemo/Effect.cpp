#include "Effect.h"

Effect* Effect::instance = nullptr;
Effect* Effect::getInstance()
{
	if(!instance) instance = new Effect();
	return instance;
}

void Effect::showBling(Point position, uint8_t type)
{
	for(uint8_t i = 0; i < 8; i++)
	{
		if(blings[i].show(position, type)) break;
	}
}

void Effect::showCratePiece(Point position, Point velocity, uint8_t frame)
{
	for(uint8_t i = 0; i < 16; i++)
	{
		if(!cratePieces[i].getActive())
		{
			cratePieces[i].show(position, velocity, frame);
			break;
		}
	}
}

void Effect::updateAndDraw()
{
	for(uint8_t i = 0; i < 8; i++)
	{
		if(blings[i].getActive())
		{
			blings[i].update();
			blings[i].draw();
		}
	}

	for(uint8_t i = 0; i < 16; i++)
	{
		if(cratePieces[i].getActive())
		{
			cratePieces[i].update();
			cratePieces[i].draw();
		}
	}
}