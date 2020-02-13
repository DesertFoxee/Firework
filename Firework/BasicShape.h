
#ifndef BASICSHAPE_H
#define BASICSHAPE_H

#define MAX_EXPLODE 40

#include "Shape.h"
#include "Particle.h"
#include "config.h"
#include "Random.h"
#include "Utility.h"


using namespace sf;
using namespace std;

class BasicShape : public MShape
{
private:
	vector<Particle> unit_basic;
	float time_life;

public :
	BasicShape();
	bool end();
	void init(Vector2f position);
	void update();
	void draw(RenderWindow& window);
};



#endif // !BASICSHAPE_H



