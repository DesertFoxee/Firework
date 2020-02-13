#ifndef LIGHTRAY_H
#define LIGHTRAY_H


#include <vector>
#include "ParticalSys.h"
#include <SFML/Graphics.hpp>
#include "Random.h"
#include "config.h"
#include <iostream>
#include "Convert.h"
#include "Vector2F.h"

#define TIME_GENERATOR 50

class LightRay
{
private:
	sf::Vector2f loc;
	std::vector<ParticalSys> list_partical;
	int time_generator = TIME_GENERATOR;
	float angle;
protected:
	void setLocation(sf::Vector2f loc) { this->loc = loc; };
	void addPartical();
	void applyForce(sf::Vector2f force);
public:
	LightRay();
	LightRay(sf::Vector2f loc);
	void init(sf::Vector2f loc);
	void draw(sf::RenderWindow* windows);
	void update();
};


#endif // !LIGHTRAY_H


