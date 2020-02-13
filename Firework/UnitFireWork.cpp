#include "UnitFireWork.h"

UnitFireWork::UnitFireWork(Vector2f loc, float radius_firework) :firework(loc, 200, radius_firework) {
	is_firework = true;
	is_explode = false;
	is_end = false;
	time_life_explodes = 200.f;
}


void UnitFireWork::initExplode() {
	for (auto i = 0; i < MAX_EXPLODE; i++) {
		Particle explode = { firework.loc, 200.f ,2.5f };
		explode.vec = { Random::floatUniform(-0.7f , 0.7f) , Random::floatUniform(-1.2f , 0.1f) };
		explodes.push_back(explode);
	}
}

void UnitFireWork::draw(sf::RenderWindow& window) {
	if (is_firework) {
		firework.draw(window);
	}
	else if (is_explode) {
		for (auto particle : explodes) {
			particle.draw(window);
		}
	}
}

void UnitFireWork::update() {
	if (is_firework) {
		firework.applyForce(Gravitation);
		firework.update();
	}
	else if (is_explode) {
		for (auto explode = explodes.begin(); explode != explodes.end();) {
			explode->applyForce(Gravitation);
			explode->update();

			Color color = explode->shape.getFillColor();
			color.a = int (Utility::map(time_life_explodes, { 0 ,200.f }, { 0 ,255 }));
			explode->shape.setFillColor(color);

			if (explode->loc.y > MAX_SCREEN_HEIGH + 100) {
				explode = explodes.erase(explode);
			}
			else explode++;

		}
		if (explodes.empty() == true) {
			is_end = true;
		}
		if ( time_life_explodes > 0) time_life_explodes--;
	}
}
