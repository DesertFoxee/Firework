#include "HeartShape.h"

void HeartShape::init() {
	float posx = 100.f;
	float posy = 100.f;
	float width = 20;
	float height = 16;

	Vector2f p_center = { posx, posy };

	for (auto i = 0; i < MAX_HEART; i++) {
		UnitHeart unit;
		auto x = float(width * pow(sin(i), 3));
		auto y = float(height * cos(i) - 6 * cos(2 * i) - 2 * cos(3 * i) - cos(4 * i));
		unit.loc = { x + posx ,-y + posy };
		unit.vec = { 0 ,0 };
		unit.acc = { 0 ,0 };
		unit.shape.setRadius(1.2f);
		unit.shape.setFillColor(Color(200, 100, 100));
		unit.vec = Utility::normalize(unit.loc - p_center)/4.f;

		unit_heart.push_back(unit);
	}
}

void HeartShape::draw(RenderWindow& window) {
	for (auto const& unit : unit_heart) {
		window.draw(unit.shape);
	}
}

void HeartShape::update() {

	for (auto& unit : unit_heart) {
		unit.acc += Vector2f{ 0.f , 0.001f };

		unit.vec += unit.acc;
		unit.loc += unit.vec;

		unit.shape.setPosition(unit.loc);

		unit.acc *= 0.f;

	}

}
