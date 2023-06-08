#include "Globals.h"
#include "GameManager.h"
#include "UserInterface.h"
#include "Level.h"
#include "Camera.h"
#include "Toolbox.h"
#include "Effect.h"
#include "Player.h"
#include "Cursor.h"
#include "Texts.h"

Player player = Player(Point(31, 234), DIR_RIGHT);
Cursor cursor;

uint8_t menuBackgroundScroll = 0;

void stateIntro();
void stateControls1();
void stateControls2();
void stateGame();

typedef void (*FunctionPointer)();
FunctionPointer gameLoop[] =
{
  stateIntro,
  stateControls1,
  stateControls2,
  stateGame
};

void setup()
{
	gb.begin();

	gb.display.setFont(font3x5Custom);

	UI->player = &player;
	UI->cursor = &cursor;
}

void loop()
{
	if(gb.update()) gameLoop[(uint8_t) GAMEMANAGER->getState()]();
}

void stateIntro()
{
	gb.display.fill(COLOR_BLUE);

	gb.display.drawImage(2, 2, menuTitleSprite);
	
	gb.display.setColor(COLOR_WHITE);
	
	gb.display.setCursor(2, 16);
	gb.display.print(gb.language.get(introLine1));

	gb.display.setCursor(2, 22);
	gb.display.print(gb.language.get(introLine2));

	gb.display.setCursor(2, 28);
	gb.display.print(gb.language.get(introLine3));

	gb.display.setCursor(2, 34);
	gb.display.print(gb.language.get(introLine4));

	gb.display.setCursor(2, 40);
	gb.display.print(gb.language.get(introLine5));

	gb.display.setCursor(2, 46);
	gb.display.print(gb.language.get(introLine6));

	gb.display.setCursor(2, 52);
	gb.display.print(gb.language.get(introLine7));

	gb.display.drawImage(70, 53, menuButtonSpriteSheet);

	GAMEMANAGER->update();

	if(gb.buttons.pressed(BUTTON_A) && GAMEMANAGER->fadeState == STATE_IDLING)
	{
		GAMEMANAGER->setState(GameState::Controls1, false);
		gb.sound.play(nextSound);
	}
}

void stateControls1()
{
	gb.display.fill(COLOR_BLUE);

	gb.display.drawImage(2, 2, controlsBarSprite);

	controlsIconsSpriteSheet.setFrame(0);
	gb.display.drawImage(2, 12, controlsIconsSpriteSheet);

	controlsIconsSpriteSheet.setFrame(3);
	gb.display.drawImage(2, 20, controlsIconsSpriteSheet);

	controlsIconsSpriteSheet.setFrame(1);
	gb.display.drawImage(2, 28, controlsIconsSpriteSheet);

	controlsIconsSpriteSheet.setFrame(1);
	gb.display.drawImage(2, 36, controlsIconsSpriteSheet);

	controlsIconsSpriteSheet.setFrame(3);
	gb.display.drawImage(14, 36, controlsIconsSpriteSheet);

	controlsIconsSpriteSheet.setFrame(5);
	gb.display.drawImage(2, 44, controlsIconsSpriteSheet);

	gb.display.setColor(COLOR_BLACK);
	
	gb.display.setCursor(16, 3);
	gb.display.print(gb.language.get(controls1Title));

	gb.display.setColor(COLOR_WHITE);

	gb.display.setCursor(10, 13);
	gb.display.print(gb.language.get(controls1Line1));

	gb.display.setCursor(10, 21);
	gb.display.print(gb.language.get(controls1Line2));

	gb.display.setCursor(10, 29);
	gb.display.print(gb.language.get(controls1Line3));

	gb.display.setCursor(10, 37);
	gb.display.print(gb.language.get(controls1Line4));

	gb.display.setCursor(10, 45);
	gb.display.print(gb.language.get(controls1Line5));

	gb.display.setCursor(14, 51);
	gb.display.print(gb.language.get(controls1Line6));

	gb.display.drawImage(70, 53, menuButtonSpriteSheet);

	GAMEMANAGER->update();

	if(gb.buttons.pressed(BUTTON_A) && GAMEMANAGER->fadeState == STATE_IDLING)
	{
		GAMEMANAGER->setState(GameState::Controls2, false);
		gb.sound.play(nextSound);
	}
}

void stateControls2()
{
	gb.display.fill(COLOR_BLUE);

	gb.display.drawImage(2, 2, controlsBarSprite);

	controlsIconsSpriteSheet.setFrame(2);
	gb.display.drawImage(2, 12, controlsIconsSpriteSheet);

	controlsIconsSpriteSheet.setFrame(3);
	gb.display.drawImage(2, 20, controlsIconsSpriteSheet);

	controlsIconsSpriteSheet.setFrame(4);
	gb.display.drawImage(2, 34, controlsIconsSpriteSheet);

	controlsIconsSpriteSheet.setFrame(5);
	gb.display.drawImage(2, (gb.language.get(languageCode) == "en")?42:48, controlsIconsSpriteSheet);

	gb.display.setColor(COLOR_BLACK);
	
	gb.display.setCursor(16, 3);
	gb.display.print(gb.language.get(controls2Title));

	gb.display.setColor(COLOR_WHITE);

	gb.display.setCursor(10, 13);
	gb.display.print(gb.language.get(controls2Line1));

	gb.display.setCursor(10, 21);
	gb.display.print(gb.language.get(controls2Line2));

	gb.display.setCursor(14, 27);
	gb.display.print(gb.language.get(controls2Line3));

	gb.display.setCursor(10, 35);
	gb.display.print(gb.language.get(controls2Line4));

	gb.display.setCursor(14, 41);
	gb.display.print(gb.language.get(controls2Line5));

	gb.display.setCursor(10, (gb.language.get(languageCode) == "en")?43:49);
	gb.display.print(gb.language.get(controls2Line6));

	gb.display.setCursor(14, (gb.language.get(languageCode) == "en")?49:55);
	gb.display.print(gb.language.get(controls2Line7));

	gb.display.drawImage(70, 53, menuButtonSpriteSheet);

	GAMEMANAGER->update();

	if(gb.buttons.pressed(BUTTON_A) && GAMEMANAGER->fadeState == STATE_IDLING)
	{
		GAMEMANAGER->setState(GameState::Game, true);
		gb.sound.play(okSound);
	}
}

void stateGame()
{
	gb.display.fill((Color) 0x6e19);

	gb.display.drawImage(12, 16, cloudSprite);
	gb.display.drawImage(52, 32, cloudSprite);

	if(gb.buttons.pressed(BUTTON_MENU))
	{
		if(GAMEMANAGER->getMode() == GameMode::Playing)
		{
			GAMEMANAGER->setMode(GameMode::Editing);

			cursor.setPosition(Point(((player.getPosition().x + 6) / 8), ((player.getPosition().y) / 8)));

    		LEVEL->resetObjects();

    		LEVEL->playing = false;
		}
		else
		{
			GAMEMANAGER->setMode(GameMode::Playing);

			player.update();

			LEVEL->playing = true;
		}
	}

	CAMERA->update();

	if(GAMEMANAGER->getMode() == GameMode::Playing)
	{
		player.update();
		LEVEL->update();
		
		LEVEL->draw();
		player.draw();

		EFFECT->updateAndDraw();

		UI->update();
		UI->drawGameHud();
	}
	if(GAMEMANAGER->getMode() == GameMode::Editing)
	{
		if(gb.buttons.repeat(BUTTON_B, 1))
		{
			TOOLBOX->update();
			TOOLBOX->draw();
		}
		else
		{
			LEVEL->update();
		
			LEVEL->draw();
			player.draw();
		
			cursor.update();
			cursor.draw();

			UI->drawEditHud();
		}
	}

	GAMEMANAGER->update();
}