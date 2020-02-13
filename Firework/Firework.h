#ifndef FIREWORD_H
#define FIREWORD_H


#define MAX_FIREWORKS 20
#define TIME_GENERATE 0.01
#define TIME_GENERATE_FIREWORK 1000


#include <vector>
#include "config.h"
#include "Random.h"
#include "UnitFireWork.h"
#include <iostream>




using namespace std;
using namespace sf;


class Firework
{
private:
	vector <UnitFireWork> fireworks;
	static Clock clock;
public:
	void init();
	void addFirework();
	void update();
	void draw(sf::RenderWindow& window);
};


#endif // !FIREWORD_H



