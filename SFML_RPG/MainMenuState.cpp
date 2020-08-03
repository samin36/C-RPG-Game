#include "MainMenuState.h"
using namespace sf;
MainMenuState::MainMenuState(RenderWindow* window, std::map<std::string, int>& supportedKeys) : State(window, supportedKeys) {
	this->initKeybinds();
	this->initFonts();


	this->background.setPosition(Vector2f(0.f, 0.f));
	/*this->background.setSize(Vector2f((float) window->getSize().x, (float) window->getSize().y));*/
	this->background.setSize(Vector2f(50.f, 50.f));
	this->background.setFillColor(Color::Color(128, 0, 128, 255));
}

MainMenuState::~MainMenuState() {

}

void MainMenuState::initKeybinds() {
	std::ifstream inputFileStream("./Config/mainmenustateKeybinds.ini");
	std::string actionName, actionKey;
	while (inputFileStream.is_open() && inputFileStream >> actionName >> actionKey) {
		this->keybinds[actionName] = this->supportedKeys.at(actionKey);
	}
	inputFileStream.close();
}

void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("./Fonts/FiraCode.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::endState() {
	std::cout << "Ending MainMenuState" << std::endl;
}

void MainMenuState::update(const float& dt) {
	this->updateMousePositions();
	this->updateInput(dt);
	this->background.setPosition(Vector2f(this->mousePosView));
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();

}


void MainMenuState::render(RenderTarget* target) {
	if (!target) {
		target = this->window;
	}
	target->draw(background);
}