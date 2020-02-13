#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>


using namespace sf;


struct UnitHeart
{
	sf::Vector2f loc;
	sf::Vector2f vec;
	sf::Vector2f acc;
	sf::CircleShape shape;
};

class MShape
{

public:
	virtual bool end() =0;
	virtual void init(Vector2f position) =0;
	virtual void update() = 0;
	virtual void draw(RenderWindow& window) = 0;

};

#endif // !SHAPE_H
