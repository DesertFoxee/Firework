#include "Firework.h"

Clock Firework::clock;

void Firework::init() {
	clock.restart();
}

void Firework::addFirework() {
	int type = Random::intUniform(0, 1);
	UnitFireWork firework = { Vector2f(float(Random::intUniform(0, MAX_SCREEN_WIDTH)), MAX_SCREEN_HEIGH), 2.5f , type};
	firework.firework.vec = Vector2f(0, -Random::normal(2.5f, 2.8f));
	fireworks.push_back(firework);
}

void Firework::update() {

	auto time_elapsed = clock.getElapsedTime().asMilliseconds();
	if (time_elapsed > TIME_GENERATE_FIREWORK) {
		clock.restart();
		this->addFirework();
	}

	for (auto firework = fireworks.begin(); firework != fireworks.end();) {
		firework->update();
		if (firework->firework.vec.y >= 0) {
			if (firework->is_firework == true) {
				firework->is_firework = false;
				firework->initExplode();
			}
			firework->is_explode = true;
			
		}
		if (firework->is_end == true) {
			firework = fireworks.erase(firework);
		}
		else firework++;
	}
}

void Firework::draw(sf::RenderWindow& window) {
	for (auto &firework : fireworks) {
		firework.draw(window);
	}
}
