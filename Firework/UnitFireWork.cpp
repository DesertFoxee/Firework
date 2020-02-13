#include "UnitFireWork.h"


UnitFireWork::UnitFireWork(Vector2f loc, float radius_firework , int type) :firework(loc, 200, radius_firework) {
	is_firework = true;
	is_explode = false;
	is_end = false;
	if (type == 0) {
		explodes = std::make_shared<BasicShape>();
	}
	else {
		explodes = std::make_shared<HeartShape>();
	}
}


void UnitFireWork::initExplode() {
	explodes->init(firework.loc);
}

void UnitFireWork::draw(sf::RenderWindow& window) {
	if (is_firework) {
		firework.draw(window);
	}
	else if (is_explode) {
		explodes->draw(window);
	}
}

void UnitFireWork::update() {
	if (is_firework) {
		firework.applyForce(Gravitation);
		firework.update();
	}
	else if (is_explode) {
		explodes->update();
		if (explodes->end() == true) {
			is_end = true;
		}
	}
}
