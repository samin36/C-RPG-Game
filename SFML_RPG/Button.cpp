#include "Button.h"

using namespace sf;

Button::Button(float x, float y, float w, float h, const Font& font_, std::string text, Color idleColor, Color hoverColor, Color activeColor) : font(font_) {
	this->buttonShape.setPosition(Vector2f(x, y));
	this->buttonShape.setSize(Vector2f(w, h));
	//Font initialized using the initializer list because it's a const
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(Color::Green);
	this->text.setCharacterSize(20);

	this->text.setPosition(Vector2f((x - this->text.getGlobalBounds().width / 2.f) + w / 2.f, (y - this->text.getGlobalBounds().height) + h / 2.f));
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	//Initialize button state
	this->buttonState = BTN_IDLE;
}

Button::~Button() {

}

const bool Button::isPressed() const {
	return this->buttonState == BTN_ACTIVE;
}


void Button::update(const Vector2f mousePos) {
	//By default, the buttonState is idle
	this->buttonState = BTN_IDLE;

	//Update the booleans for hover and active

	//Hover
	if (this->buttonShape.getGlobalBounds().contains(mousePos)) {
		this->buttonState = BTN_HOVER;

		//Pressed
		if (Mouse::isButtonPressed(Mouse::Left)) {
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState) {
		case BTN_IDLE:
			this->buttonShape.setFillColor(this->idleColor);
			break;
		case BTN_HOVER:
			this->buttonShape.setFillColor(this->hoverColor);
			break;
		case BTN_ACTIVE:
			this->buttonShape.setFillColor(this->activeColor);
			break;
		default:
			this->buttonShape.setFillColor(Color::Red);
			break;
		}
}

void Button::render(RenderTarget* target) {
	target->draw(this->buttonShape);
	target->draw(this->text);
}