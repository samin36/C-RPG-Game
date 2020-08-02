#ifndef ENTITY_H
#define ENTITY_H

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

class Entity {
protected:
	RectangleShape shape; 
	float speed;

public:
	Entity();
	virtual ~Entity();

	//Functions
	virtual void move(const float& dt, const float x, const float y);
	virtual void update(const float& dt);
	virtual void render(RenderTarget* target = nullptr);
};

#endif ENTITY_H
