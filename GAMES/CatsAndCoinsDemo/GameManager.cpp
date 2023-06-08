#include "GameManager.h"

GameManager* GameManager::instance = nullptr;
GameManager* GameManager::getInstance()
{
	if(!instance) instance = new GameManager();
	return instance;
}

void GameManager::setState(GameState newState, bool fade)
{
	if(fade)
	{
		nextState = newState;
		fadeState = STATE_CLOSING;
	}
	else state = newState;
}

void GameManager::update()
{
	if(fadeState == STATE_OPENING)
	{
		if(stateCounter > -1) stateCounter--;
		else fadeState = STATE_IDLING;

		gb.display.setColor(COLOR_BLACK);
		if(steps[stateCounter] > 0)
		{
			gb.display.fillRect(0, 0, 80, steps[stateCounter]);
			gb.display.fillRect(0, 64 - steps[stateCounter], 80, steps[stateCounter]);
		}
	}
	else if(fadeState == STATE_CLOSING)
	{
		if(stateCounter < 6) stateCounter++;
		else
		{
			fadeState = STATE_WAITING;
			state = nextState;
		}

		gb.display.setColor(COLOR_BLACK);
		if(steps[stateCounter] > 0)
		{
			gb.display.fillRect(0, 0, 80, steps[stateCounter]);
			gb.display.fillRect(0, 64 - steps[stateCounter], 80, steps[stateCounter]);
		}
	}
	else if(fadeState == STATE_WAITING)
	{
		if(waitCounter == 7)
		{
			fadeState = STATE_OPENING;
			waitCounter = 0;
		}
		else
		{
			waitCounter++;
		}

		gb.display.setColor(COLOR_BLACK);
		gb.display.fillRect(0, 0, 80, 64);
	}
}