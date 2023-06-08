#pragma once

#include "Globals.h"
#include "BaseObject.h"

class Tool
{
public:
	Tool(uint8_t type, uint8_t subType, uint8_t category, Image* image, uint8_t frame, Point offset, char description[]) : type(type), subType(subType), category(category), image(image), frame(frame), offset(offset), description(description){}

	uint8_t getType(){ return type; }
	uint8_t getSubType(){ return subType; }
	uint8_t getCategory(){ return category; }
	bool isType(BaseObject* object){ return (type - 9 == (uint8_t) object->getType() && subType == object->getSubType()); }
	Image* getImage(){ return image; }
	uint8_t getFrame(){ return frame; }
	Point getOffset(){ return offset; }
	char* getDescription(){ return description; }

private:
	uint8_t type = 0;
	uint8_t subType = 0;
	uint8_t category = 0;
	Image* image = nullptr;
	uint8_t frame = 0;
	Point offset;
	char* description;
};