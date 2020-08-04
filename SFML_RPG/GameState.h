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
	GameState(RenderWindow* window, const std::unordered_map<std::string, int>& supportedKeys);
	virtual ~GameState();

	//Must define State's pure virtual functions
	void endState();
	void updateInput(const float& dt = 0);
	void update(const float& dt);
	void render(RenderTarget* target = nullptr);
};

#endif