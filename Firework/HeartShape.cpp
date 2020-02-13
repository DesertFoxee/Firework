#include "HeartShape.h"

HeartShape::HeartShape() {
	time_life = TIME_LIFE;
}

bool HeartShape::end() {
	return unit_heart.empty();
}

void HeartShape::init(Vector2f position) {
	float width = 20;
	float height = 16;

	for (auto i = 0; i < MAX_HEART; i++) {
		UnitHeart unit;
		auto x = float(width * pow(sin(i), 3));
		auto y = float(height * cos(i) - 7 * cos(2 * i) - 3 * cos(3 * i) - cos(4 * i));
		unit.loc = { x + position.x ,-y + position.y };
		unit.vec = { 0 ,0 };
		unit.acc = { 0 ,0 };
		unit.shape.setRadius(2.f);
		int a = Random::intUniform(1, 3);
		if (a == 1) {
			unit.shape.setFillColor(Color::Red);
		}
		else if (a == 2) {
			unit.shape.setFillColor(Color::Green);
		}
		else {
			unit.shape.setFillColor(Color::White);
		}

		unit.vec = Utility::normalize(unit.loc - position);


		unit_heart.push_back(unit);
	}
}

void HeartShape::draw(RenderWindow& window) {
	for (auto& unit : unit_heart) {
		window.draw(unit.shape);
	}
}

void HeartShape::update() {


	for (auto unit = unit_heart.begin(); unit != unit_heart.end();) {

		unit->acc += Gravitation / 3.f;


		unit->vec += unit->acc;
		unit->loc += unit->vec;

		unit->shape.setPosition(unit->loc);

		Color color = unit->shape.getFillColor();
		color.a = int(Utility::map(time_life, { 0 ,200.f }, { 0 ,255 }));
		unit->shape.setFillColor(color);

		unit->acc *= 0.f;

		if (unit->loc.y > MAX_SCREEN_HEIGH + 100) {
			unit = unit_heart.erase(unit);
		}
		else unit++;

	}
	if (time_life > 0) time_life--;
}
