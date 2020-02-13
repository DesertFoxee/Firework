#ifndef HEARTSHAPE_H
#define HEARTSHAPE_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

#include "Object.h"
#include "Utility.h"

using namespace sf;
using namespace std;


#define MAX_HEART 50


struct UnitHeart
{
	sf::Vector2f loc; 
	sf::Vector2f vec;
	sf::Vector2f acc;
	sf::CircleShape shape;
};



class HeartShape
{
public:
	void init();
	void draw(RenderWindow& window);
	void update();
private:
	int count = 0;
	vector<UnitHeart> unit_heart;
};


#endif // !HEARTSHAPE_H



