#pragma once

#include "Globals.h"
#include "BaseObject.h"

class RangeLimiter : public BaseObject
{  
public:
	RangeLimiter(Point position);

	void draw() override;
};