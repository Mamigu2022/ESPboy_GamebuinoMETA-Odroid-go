#include "Toolbox.h"

Toolbox* Toolbox::instance = nullptr;
Toolbox* Toolbox::getInstance()
{
	if(!instance) instance = new Toolbox();
	return instance;
}

void Toolbox::update()
{
	int8_t x = currentTool % 4;
	int8_t y = currentTool / 4;

	if(mode == ToolboxMode::SelectCategory)
	{
		if(gb.buttons.repeat(BUTTON_DOWN, 1)) mode = ToolboxMode::SelectTool;

		if(gb.buttons.repeat(BUTTON_LEFT, 4))
		{
			currentTool = 0;
			currentCategory--;
			if(currentCategory == 255) currentCategory += CATEGORYAMOUNT;
		}

		if(gb.buttons.repeat(BUTTON_RIGHT, 4))
		{
			currentTool = 0;
			currentCategory++;
			if(currentCategory == CATEGORYAMOUNT) currentCategory -= CATEGORYAMOUNT;
		}
	}
	else if(mode == ToolboxMode::SelectTool)
	{
		if(gb.buttons.repeat(BUTTON_UP, 4))
		{
			if(y == 1) y = 0;
			else mode = ToolboxMode::SelectCategory;
		}
		else if(gb.buttons.repeat(BUTTON_DOWN, 4))
		{
			if(calculateCategoryToolAmount() > 4)
			{
				y = 1;
				if(x >= calculateCategoryToolAmount() - 4) x = calculateCategoryToolAmount() - 5;
			}
		}

		if(gb.buttons.repeat(BUTTON_LEFT, 4))
		{
			x--;
			if(x < 0) x += min(calculateCategoryToolAmount() - (4 * y), 4);
		}
		else if(gb.buttons.repeat(BUTTON_RIGHT, 4))
		{
			x++;
			if(x >= min(calculateCategoryToolAmount() - (4 * y), 4)) x = 0;	
		}

		currentTool = x + (y * 4);
	}
}

void Toolbox::draw()
{
	gb.display.setColor(COLOR_BLACK);
	gb.display.fillRect(0, 0, gb.display.width(), gb.display.height());

	gb.display.setColor(COLOR_WHITE);
	gb.display.setCursor(2, 2);
	gb.display.print("TOOLBOX");

	uint8_t x = 0;
	uint8_t y = 0;

	uint8_t toolCounter = 0;

	for(uint8_t i = 0; i < TOOLAMOUNT; i++)
	{
		if(tools[i].getCategory() != currentCategory) continue;

		tools[i].getImage()->setFrame(tools[i].getFrame());
		gb.display.drawImage(8 + 4 + (x * 16) + tools[i].getOffset().x, 10 + 4 + (y * 16) + tools[i].getOffset().y, *tools[i].getImage());

		if(toolCounter == currentTool)
		{
			currentToolGlobal = i;

			gb.display.setColor((mode == ToolboxMode::SelectTool)?COLOR_WHITE:COLOR_GREY);
			gb.display.drawBitmap(8 + (x * 16), 10 + (y * 16), cursorBitmap);

			if(mode == ToolboxMode::SelectTool) drawDescription(tools[i].getDescription());
		}

		toolCounter++;

		x = ++x % 4;
		if(x == 0) y++;
	}

	if(mode == ToolboxMode::SelectCategory)
	{
		gb.display.setColor(COLOR_WHITE);
		arrowCounter = ++arrowCounter % 8;

		drawDescription(categoryDescriptions[currentCategory]);
	}
	else
	{
		gb.display.setColor(COLOR_GREY);
		arrowCounter = 0;
	}

	gb.display.setCursor(38 - ((arrowCounter > 3)?1:0), 2);
	gb.display.print("\x11");

	gb.display.setCursor(42, 2);
	gb.display.print(categoryNames[currentCategory]);

	gb.display.setCursor(74 + ((arrowCounter > 3)?1:0), 2);
	gb.display.print("\x10");
}

void Toolbox::drawDescription(char* description)
{
	gb.display.setColor(COLOR_WHITE);
	gb.display.setCursor(2, 45);
	for(uint8_t j = 0; j < strlen(description); j++)
	{
		if(description[j] == '\n') gb.display.setCursor(2, gb.display.getCursorY() + 6);
		else gb.display.print(description[j]);
	}
}

uint8_t Toolbox::calculateCategoryToolAmount()
{
	uint8_t result = 0;

	for(uint8_t i = 0; i < TOOLAMOUNT; i++)
	{
		if(tools[i].getCategory() == currentCategory) result++;
	}

	return result;
}