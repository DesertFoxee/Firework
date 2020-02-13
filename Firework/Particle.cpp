#include "Particle.h"

Particle::Particle(sf::Vector2f position ,float time_limit , float radius) :Object() {
	this->loc = position;
	this->time_life = time_limit;
	shape.setPosition(loc);
	shape.setFillColor(sf::Color(200, 100, 100));
	shape.setRadius(radius);
}

void Particle::init(sf::Vector2f position  , float time_limit, float radius) {
	this->loc = position;
	this->time_life = time_limit;
	shape.setPosition(loc);
	shape.setFillColor(sf::Color(200, 100, 100));
	shape.setRadius(radius);
}

void Particle::update() {

	vec += acc;
	loc += vec;

	shape.setPosition(loc);

	acc *= 0.f;
}

void Particle::draw(sf::RenderWindow& windows) {
	windows.draw(shape);
}

void Particle::applyForce(sf::Vector2f force) {
	acc += force;
}
