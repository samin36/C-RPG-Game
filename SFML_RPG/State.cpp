#include "State.h"

using namespace sf;

State::State(RenderWindow* window, const std::map<std::string, int>& supportedKeys_) : supportedKeys(supportedKeys_) {
	this->window = window;
	this->quit = false;
}

State::~State() {

}

void State::checkForQuit(){
	//Every child state must define CLOSE in order to quit
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->quit = true;
	}
}

const bool& State::getQuit() const {
	return this->quit;
}

void State::updateMousePositions() {
	this->mousePosScreen = Mouse::getPosition();
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
}