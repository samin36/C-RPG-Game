#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"

using namespace sf;

class MainMenuState : public State {
private:
	//Variables
	RectangleShape background;

	//Functions
	void initKeybinds();
public:
	MainMenuState(RenderWindow* window, std::map<std::string, int>& supportedKeys);
	virtual ~MainMenuState();

	//Must define State's pure virtual functions
	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(RenderTarget* target = nullptr);
};

#endif

