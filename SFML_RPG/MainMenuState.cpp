#include "MainMenuState.h"
using namespace sf;
MainMenuState::MainMenuState(RenderWindow* window, std::map<std::string, int>& supportedKeys) : State(window, supportedKeys) {
	this->background.setPosition(Vector2f(0.f, 0.f));
	this->background.setSize(Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(Color::Color(128, 0, 128, 255));
	this->initKeybinds();
}

MainMenuState::~MainMenuState() {

}

void MainMenuState::endState() {
	std::cout << "Ending MainMenuState" << std::endl;
}

void MainMenuState::update(const float& dt) {
	this->updateInput(dt);
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();

}

void MainMenuState::initKeybinds() {
	std::ifstream inputFileStream("./Config/mainmenustateKeybinds.ini");
	std::string actionName, actionKey;
	while (inputFileStream.is_open() && inputFileStream >> actionName >> actionKey) {
		this->keybinds[actionName] = this->supportedKeys.at(actionKey);
	}
	inputFileStream.close();
}

void MainMenuState::render(RenderTarget* target) {
	if (!target) {
		target = this->window;
	}
	target->draw(background);
}