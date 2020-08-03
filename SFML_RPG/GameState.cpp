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
	std::ifstream inputFileStream("./Config/gamestateKeybinds.ini");
	std::string actionName, actionKey;
	while (inputFileStream.is_open() && inputFileStream >> actionName >> actionKey) {
		this->keybinds[actionName] = this->supportedKeys.at(actionKey);
	}
	inputFileStream.close();
}

void GameState::endState() {
	std::cout << "Ending GameState" << std::endl;
}