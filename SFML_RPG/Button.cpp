#include "Button.h"

using namespace sf;

Button::Button(float x, float y, float w, float h, const Font& font_, std::string text, Color idleColor, Color hoverColor, Color activeColor) : font(font_) {
	this->buttonShape.setPosition(Vector2f(x, y));
	this->buttonShape.setSize(Vector2f(w, h));
	//Font initialized using the initializer list because it's a const
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(
		this->buttonShape.getPosition().x / 2.f - this->text.getGlobalBounds().width / 2.f,
		this->buttonShape.getPosition().y / 2.f - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
}

Button::~Button() {

}

void Button::update(const Vector2f mousePos) {
	//Update the booleans for hover and active
	if (this->buttonShape.getGlobalBounds().contains(mousePos)) {

	}
}

void Button::render(RenderTarget* target) {
	target->draw(this->buttonShape);
}