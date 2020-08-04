#include "MainMenuState.h"
#include "Game.h"
using namespace sf;
MainMenuState::MainMenuState(RenderWindow* window, std::unordered_map<std::string, int>& supportedKeys) : State(window, supportedKeys) {
	this->initKeybinds();
	this->initFonts();
	this->initButtons();

	this->background.setPosition(Vector2f(0.f, 0.f));
	this->background.setSize(Vector2f((float) window->getSize().x, (float) window->getSize().y));
	this->background.setFillColor(Color::Color(128, 0, 128, 255));

}

MainMenuState::~MainMenuState() {
	for (auto& pair : this->buttons) {
		delete pair.second;
	}
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

void MainMenuState::initButtons() {
	this->buttons["NEW_GAME_BTN"] = new Button(100, 100, 150, 50, this->font, "New Game", Color::Color(50, 50, 50, 255), Color::Color(150, 150, 150, 220), Color::White);
	this->buttons["EXIT_STATE_BTN"] = new Button(100, 300, 150, 50, this->font, "Quit", Color::Color(100, 100, 100, 200), Color::Color(150, 150, 150, 255), Color::Color(20, 20, 20, 200));

}

void MainMenuState::endState() {
	std::cout << "Ending MainMenuState" << std::endl;
}

void MainMenuState::update(const float& dt) {
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::updateInput(const float& dt) {
	this->checkForQuit();

}

void MainMenuState::updateButtons() {
	for (auto& pair : this->buttons) {
		pair.second->update(this->mousePosView);
	}

	//Quit the game
	if (this->buttons["EXIT_STATE_BTN"]->isPressed()) {
		this->quit = true;
	}

	if (this->buttons["NEW_GAME_BTN"]->isPressed()) {
		//Game::states.push(new GameState(this->window, this->supportedKeys));
	}
}

void MainMenuState::renderButtons(RenderTarget* target) {
	for (auto& pair : this->buttons) {
		pair.second->render(target);
	}
}

void MainMenuState::render(RenderTarget* target) {
	if (!target) {
		target = this->window;
	}
	target->draw(background);
	this->renderButtons(target);
}