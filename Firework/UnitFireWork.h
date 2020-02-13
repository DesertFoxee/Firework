#ifndef UNITFIREWORK_H
#define UNITFIREWORK_H


#include "Particle.h"
#include <vector>
#include "config.h"
#include "Random.h"
#include <iostream>
#include "Utility.h"

#define MAX_EXPLODE 40


using namespace std;
using namespace sf;

class UnitFireWork
{

public:
	Particle firework;
	vector <Particle> explodes;
	float time_life_explodes;
public:
	bool is_firework;
	bool is_explode;
	bool is_end;
public:
	UnitFireWork(Vector2f loc, float radius_firework);
	void initExplode();
	void draw(RenderWindow& window);
	void update();

};

#endif // !1 UNITFIREWORK_H



