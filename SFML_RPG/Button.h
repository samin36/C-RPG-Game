#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

using namespace sf;

enum ButtonStates {BTN_IDLE=0, BTN_HOVER, BTN_ACTIVE};

class Button {
private:
	short unsigned buttonState;

	RectangleShape buttonShape;
	const Font& font;
	Text text;

	Color idleColor, hoverColor, activeColor;

public:
	Button(float x, float y, float w, float h, const Font& font_, std::string text, Color idleColor, Color hoverColor, Color activeColor);
	~Button();

	//Accessors
	const bool isPressed() const;

	//Functions
	void update(const Vector2f mousePos);
	void render(RenderTarget* target);

};

#endif