#include "GameState.h"
using namespace sf;
GameState::GameState(RenderWindow* window, const std::map<std::string, int>& supportedKeys) : State(window, supportedKeys) {
	this->initKeybinds();
}

GameState::~GameState() {

}


void GameState::update(const float& dt) {
	this->updateInput(dt);
	this->player.update(dt);
}

void GameState::render(RenderTarget* target) {
	if (!target)
		target = this->window;
	this->player.render(target);
}

void GameState::updateInput(const float& dt) {
	this->checkForQuit();

	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		this->player.move(dt, -1.f, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player.move(dt, 1.f, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player.move(dt, 0.f, -1.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player.move(dt, 0.f, 1.f);
	}
}

void GameState::initKeybinds() {
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys.at("Left"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys.at("Right"));
	this->keybinds.emplace("MOVE_UP", this->supportedKeys.at("Up"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys.at("Down"));

}

void GameState::endState() {
	std::cout << "Ending GameState" << std::endl;
}