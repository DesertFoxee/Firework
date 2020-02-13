#ifndef UNITFIREWORK_H
#define UNITFIREWORK_H


#include "BasicShape.h"
#include "HeartShape.h"
#include <vector>
#include "Random.h"




using namespace std;
using namespace sf;

class UnitFireWork
{

public:
	Particle firework;
	shared_ptr<MShape> explodes;
public:
	bool is_firework;
	bool is_explode;
	bool is_end;
public:

	UnitFireWork(Vector2f loc, float radius_firework , int type);
	void initExplode();
	void draw(RenderWindow& window);
	void update();
};

#endif // !1 UNITFIREWORK_H



