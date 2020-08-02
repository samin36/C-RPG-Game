#include "State.h"

using namespace sf;

State::State(RenderWindow* window, const std::map<std::string, int>& supportedKeys_) : supportedKeys(supportedKeys_) {
	this->window = window;
	this->quit = false;
}

State::~State() {

}

void State::checkForQuit(){
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		this->quit = true;
	}
}

const bool& State::getQuit() const {
	return this->quit;
}