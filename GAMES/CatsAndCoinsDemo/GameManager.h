#pragma once

#include "Globals.h"

#define GAMEMANAGER GameManager::getInstance()

#define STATE_IDLING 0
#define STATE_WAITING 1
#define STATE_CLOSING 2
#define STATE_OPENING 3

enum class GameState
{
	Intro,
	Controls1,
	Controls2,
	Game
};

enum class GameMode
{
	Playing,
	Editing
};

class GameManager
{  
public:
	static GameManager* getInstance();

	GameState getState(){ return state; }
	void setState(GameState newState, bool fade);

	GameMode getMode(){ return mode; }
	void setMode(GameMode newMode){ mode = newMode; }

	void update();

	uint8_t fadeState = STATE_WAITING;

private:
	static GameManager* instance;
	
	GameState state = GameState::Intro;
	GameState nextState = GameState::Intro;

	GameMode mode = GameMode::Playing;

	int8_t stateCounter = 6;
	int8_t waitCounter = 0;

	uint8_t steps[7] = {0, 8, 16, 22, 27, 30, 32};
};