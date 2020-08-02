#include "Entity.h"

using namespace sf;

Entity::Entity() {
	this->shape.setPosition(Vector2f(0.f, 0.f));
	this->shape.setSize(Vector2f(50.f, 50.f));
	this->shape.setFillColor(Color(0, 255, 0, 255));
	this->speed = 300.f;
}

Entity::~Entity() {

}

void Entity::move(const float&dt, const float xDir, const float yDir) {
	this->shape.move(xDir * this->speed * dt, yDir * this->speed * dt);
}

void Entity::update(const float& dt) {
}

void Entity::render(RenderTarget* target) {
	target->draw(this->shape);
}