#ifndef PARITCLE_H

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Shape.h"

#define TIME_LIMIT_DEFAULT 200
#define RAIDUS_DEFAULT 10

class Particle :public Object
{
private:
	float time_life;
public:
	sf::CircleShape shape;

public :
	Particle(sf::Vector2f position = sf::Vector2f(100.f, 100.f ), float time_limit  = TIME_LIMIT_DEFAULT , float radius = RAIDUS_DEFAULT);
	void init(sf::Vector2f position , float time_limit , float radius);
	void update();
	void draw(sf::RenderWindow& windows);

	void applyForce(sf::Vector2f force);
};
#endif // !PARITCLE_H



