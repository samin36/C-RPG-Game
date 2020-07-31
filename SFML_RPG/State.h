#ifndef STATE_H
#define STATE_H

#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace sf;

//Will be used to keep track of resources such as textures etc.
class State {
private:
	RenderWindow* window;
	std::vector<Texture> textures;
	bool quit;

public:
	State(RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;
	virtual void checkForQuit();
	virtual void endState() = 0;
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(RenderTarget* target = nullptr) = 0;
};


#endif

