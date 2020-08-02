#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
using namespace sf;

class GameState : public State
{
private: 
	Entity player;

	//Functions
	void initKeybinds();

public:
	GameState(RenderWindow* window, const std::map<std::string, int>& supportedKeys);
	virtual ~GameState();

	//Must define State's pure virtual functions
	void endState();
	void updateInput(const float& dt = 0);
	void render(RenderTarget* target = nullptr);
	void update(const float& dt);
};

#endif