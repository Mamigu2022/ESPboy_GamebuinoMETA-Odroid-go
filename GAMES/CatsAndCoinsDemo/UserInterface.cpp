#include "UserInterface.h"
#include "Coin.h"

#include "Camera.h"

UserInterface* UserInterface::instance = nullptr;
UserInterface* UserInterface::getInstance()
{
	if(!instance) instance = new UserInterface();
	return instance;
}

void UserInterface::update()
{
	for(uint8_t i = 0; i < 3; i++)
	{
		if(previousCoinAmounts[i] != Coin::getCollectedAmount(i + 1))
		{
			coinNumberVisibleCounter = 75;
			coinVisibleType = i + 1;
			break;
		}
	}

	if(coinNumberVisibleCounter > 0) coinNumberVisibleCounter--;

	for(uint8_t i = 0; i < 3; i++)
	{
		previousCoinAmounts[i] = Coin::getCollectedAmount(i + 1);
	}
}

void UserInterface::drawGameHud()
{
	// Draw hearts
	for(uint8_t i = 0; i < 3; i++)
	{
		hudHeartsSpriteSheet.setFrame(clamp(player->getHealth() - (i * 2), 0, 2));
		gb.display.drawImage(1 + (i * 8), 1, hudHeartsSpriteSheet);
	}

	// Draw gold coins amount
	drawCoinNumber(0, Point(gb.display.width(), 1));

	// Draw colored coins amount
	if(coinNumberVisibleCounter > 0) drawCoinNumber(coinVisibleType, Point(gb.display.width(), 9));

	// Draw black borders when camera shakes and goes outside of level bounds
	uint8_t bounds = CAMERA->getOutOfBounds();

	if(bounds != 0)
	{
		gb.display.setColor(COLOR_BLACK);
		if(bitRead(bounds, 0) == 1) gb.display.drawFastHLine(0, 0, gb.display.width());
		if(bounds & 0b0010) gb.display.drawFastHLine(0, gb.display.height() - 1, gb.display.width());
		if(bounds & 0b0100) gb.display.drawFastVLine(0, 0, gb.display.height());
		if(bounds & 0b1000) gb.display.drawFastVLine(gb.display.width() - 1, 0, gb.display.height());
	}
}

void UserInterface::drawEditHud()
{
	char number[3];

	// Draw 'X:'
	hudTextSpriteSheet.setFrame(12);
	gb.display.drawImage(1, 1, hudTextSpriteSheet);
	hudTextSpriteSheet.setFrame(11);
	gb.display.drawImage(5, 1, hudTextSpriteSheet);

	// Put cursor X position in char array
	sprintf(number, "%d", cursor->getPosition().x);
	uint8_t length = strlen(number);

	// Print char array
	for(uint8_t i = 0; i < length; i++)
	{
		hudTextSpriteSheet.setFrame(number[i] - '/');
		gb.display.drawImage(9 + ((3 - length) * 4) + (i * 4), 1, hudTextSpriteSheet);
	}

	// Draw 'Y:'
	hudTextSpriteSheet.setFrame(13);
	gb.display.drawImage(25, 1, hudTextSpriteSheet);
	hudTextSpriteSheet.setFrame(11);
	gb.display.drawImage(29, 1, hudTextSpriteSheet);

	// Put cursor Y position in char array
	sprintf(number, "%d", cursor->getPosition().y);
	length = strlen(number);

	// Print char array
	for(uint8_t i = 0; i < length; i++)
	{
		hudTextSpriteSheet.setFrame(number[i] - '/');
		gb.display.drawImage(33 + ((3 - length) * 4) + (i * 4), 1, hudTextSpriteSheet);
	}
}

void UserInterface::drawHardwareInfo()
{
	gb.display.setColor(COLOR_WHITE);
	gb.display.setCursor(1, gb.display.height() - 6);
	gb.display.print("CPU: ");
	gb.display.print(gb.getCpuLoad());
	gb.display.print(" RAM: ");
	gb.display.print(gb.getFreeRam());
}

void UserInterface::drawCoinNumber(uint8_t coinType, Point position)
{
	// Draw coin
	hudCoinsSpriteSheet.setFrame(coinType);
	gb.display.drawImage(position.x - 8, position.y, hudCoinsSpriteSheet);

	// Put coin "collected/total" text in char array
	char string[10];
	sprintf(string, "%d/%d", Coin::getCollectedAmount(coinType), Coin::getTotalAmount(coinType));
	uint8_t length = strlen(string);

	position.x -= 10 + (length * 4);

	// Print char array
	for(uint8_t i = 0; i < length; i++)
	{
		hudTextSpriteSheet.setFrame(string[i] - '/');
		gb.display.drawImage(position.x, position.y, hudTextSpriteSheet);

		position.x += 4;
	}
}