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

	std::unordered_map<std::string, Button*> buttons;

	//Functions
	void initFonts();
	void initKeybinds();
	void initButtons();
public:
	MainMenuState(RenderWindow* window, std::unordered_map<std::string, int>& supportedKeys);
	virtual ~MainMenuState();

	void endState();
	void updateButtons();
	void renderButtons(RenderTarget* target);
	//Must define State's pure virtual functions
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(RenderTarget* target = nullptr);
};

#endif

