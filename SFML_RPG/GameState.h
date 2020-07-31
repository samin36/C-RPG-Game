#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
using namespace sf;

class GameState : public State
{
private: 


public:
	GameState(RenderWindow* window);
	virtual ~GameState();

	//Must define State's pure virtual functions
	void endState();
	void updateKeybinds(const float& dt = 0);
	void render(RenderTarget* target = nullptr);
	void update(const float& dt);
};

#endif