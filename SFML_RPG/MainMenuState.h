#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"
using namespace sf;

class MainMenuState : public State {
protected:
	//Variables
	RectangleShape background;
	Font font;

	//Functions
	void initFonts();
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

