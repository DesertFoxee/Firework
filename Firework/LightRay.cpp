#include "LightRay.h"


LightRay::LightRay() :loc(sf::Vector2f(0, 0)) {
	this->angle = 90.f;
}

LightRay::LightRay(sf::Vector2f loc) : loc(loc) {
	this->angle = 90.f;

}

void LightRay::init(sf::Vector2f loc){
	this->loc = loc;
	this->angle = 45.f;
}

void LightRay::addPartical() {
	Object obj;
	obj.loc = this->loc ;
	//float x = Random::floatUniform(0.005f , 0.01f);

	sf::Vector2f vec = Vector2F::rotate(sf::Vector2f(0.005f, 0), Convert::degreeToRadius(angle));
	obj.acc = vec;

	ParticalSys partical(obj, 255, 10);
	list_partical.push_back(partical);
}

void LightRay::applyForce(sf::Vector2f force) {
	for (auto & partical : list_partical) {
		partical.applyForce(force);
	}
}

void LightRay::draw(sf::RenderWindow* windows) {
	for (ParticalSys partical : list_partical) {
		partical.draw(windows);
	}
}

void LightRay::update() {
	this->applyForce(sf::Vector2f(0.f, 0.0001f));

	for (auto it = list_partical.begin(); it != list_partical.end();) {
		it->update();
		if (it->getTimeLife() <= 0) {
			it = list_partical.erase(it);
		}
		else ++it;
	}
	time_generator -= 1;
	if (time_generator < 0) {
		time_generator = TIME_GENERATOR;
		this->addPartical();
	}
	
}
