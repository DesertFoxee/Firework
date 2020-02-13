#ifndef HEARTSHAPE_H
#define HEARTSHAPE_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "Random.h"
#include "Object.h"
#include "Utility.h"
#include "Shape.h"
#include "config.h"


using namespace sf;
using namespace std;

#define MAX_HEART 50


class HeartShape :public MShape
{
private:
	vector<UnitHeart> unit_heart;
	float time_life;
public:
	HeartShape();
	bool end();
	void init(Vector2f position);
	void draw(RenderWindow& window);
	void update();

};


#endif // !HEARTSHAPE_H



