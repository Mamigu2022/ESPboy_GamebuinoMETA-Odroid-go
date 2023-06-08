#pragma once

#include "Globals.h"
#include "Bling.h"
#include "CratePiece.h"

#define EFFECT Effect::getInstance()

class Effect
{  
public:
	static Effect* getInstance();
	
	void showBling(Point position, uint8_t type);
	void showCratePiece(Point position, Point velocity, uint8_t frame);
	void updateAndDraw();

private:
	static Effect* instance;
	
	Bling blings[8];
	CratePiece cratePieces[16];
};