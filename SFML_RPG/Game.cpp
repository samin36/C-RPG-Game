#include "Game.h"

using namespace sf;

//Static functions
//Initializer functions
void Game::initWindow() {

	//Creates a SFML window using options from a window.ini file

	std::ifstream inputFileStream("./Config/window.ini");
	
	std::string title = "none";
	VideoMode windowBounds(800, 600);
	unsigned frameRateLimit = 120;
	bool verticalSyncEnabled = false;
	if (inputFileStream.is_open()) {
		std::getline(inputFileStream, title);
		inputFileStream >> windowBounds.width >> windowBounds.height;
		inputFileStream >> frameRateLimit;
		inputFileStream >> verticalSyncEnabled;
	}
	inputFileStream.close();
	
	this->window = new RenderWindow(windowBounds, title);
	this->window->setFramerateLimit(frameRateLimit);
	this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::initKeys() {
	this->supportedKeys.emplace("Escape", Keyboard::Key::Escape);
	this->supportedKeys.emplace("Left", Keyboard::Key::Left);
	this->supportedKeys.emplace("Right", Keyboard::Key::Right);
	this->supportedKeys.emplace("Up", Keyboard::Key::Up);
	this->supportedKeys.emplace("Down", Keyboard::Key::Down);
}

void Game::initStates() {
	this->states.push(new GameState(this->window, this->supportedKeys));
}


//Constructors/Destructors
Game::Game() {
	this->initWindow();
	this->initKeys();
	this->initStates();
	this->dtClock = Clock();
}

Game::~Game() {
	delete this->window;
	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

//Functions
void Game::updateSFMLEvents() {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == Event::Closed) {
			this->window->close();
		}
	}
}

void Game::update() {
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		this->endGame();
	}
}

void Game::updateDt() {
	//Updates the dt variable with the time it takes to update and render one frame
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::render() {
	this->window->clear();

	if (!this->states.empty()) {
		this->states.top()->render(this->window);
	}

	this->window->display();
}

void Game::run() {
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}

void Game::endGame() {
	this->window->close();
}
