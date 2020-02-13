#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>


using namespace sf;


#define MAX_HEART 150




static  VertexArray heart(Points ,MAX_HEART);

inline void loadHeart() {
	for (auto i = 0; i < MAX_HEART; i++) {
		
		auto x = float (25 * pow(sin(i), 3));
		auto y = float(17 * cos(i) - 5 * cos(2 * i) - 2 * cos(3 * i) - cos(4 * i));

		heart[i].position = { x+100 , -y+100 };
		heart[i].color = Color(100, 100, 100);
	}
}

inline void drawHeart(RenderWindow & window) {
	window.draw(heart);
}



#endif // !SHAPE_H
