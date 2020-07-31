#include "GameState.h"
using namespace sf;
GameState::GameState(RenderWindow* window) : State(window) {}

GameState::~GameState() {

}


void GameState::update(const float& dt) {
	this->updateKeybinds(dt);
	std::cout << "Hello from GameState: " << std::endl;
}

void GameState::render(RenderTarget* target) {

}

void GameState::updateKeybinds(const float& dt) {
	this->checkForQuit();
}

void GameState::endState() {
	std::cout << "Ending GameState" << std::endl;
}