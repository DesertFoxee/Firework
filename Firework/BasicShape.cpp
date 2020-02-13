#include "BasicShape.h"

BasicShape::BasicShape() {
	time_life = TIME_LIFE;
}

bool BasicShape::end() {
	return unit_basic.empty();
}

void BasicShape::init(Vector2f position) {
	for (auto i = 0; i < MAX_EXPLODE; i++) {
		Particle explode = { position, 200.f ,1.5f };
		explode.vec = { Random::floatUniform(-0.7f , 0.7f) , Random::floatUniform(-1.2f , 0.1f) };
		int a = Random::intUniform(1, 3);
		if (a == 1) {
			explode.shape.setFillColor(Color::Red);
		}
		else if (a == 2) {
			explode.shape.setFillColor(Color::Green);
		}
		else {
			explode.shape.setFillColor(Color::White);
		}
		unit_basic.push_back(explode);
	}
}

void BasicShape::update() {

	for (auto unit = unit_basic.begin(); unit != unit_basic.end();) {

		unit->applyForce(Gravitation);
		unit->update();

		Color color = unit->shape.getFillColor();
		color.a = int(Utility::map(time_life, { 0 ,200.f }, { 0 ,255 }));
		unit->shape.setFillColor(color);

		if (unit->loc.y > MAX_SCREEN_HEIGH + 100) {
			unit = unit_basic.erase(unit);
		}
		else unit++;

	}
	if (time_life > 0) time_life--;

}

void BasicShape::draw(RenderWindow& window) {
	for (auto & unit : unit_basic) {
		unit.draw(window);
	}
}
