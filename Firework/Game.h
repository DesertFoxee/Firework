#ifndef GAME_H
#define GAME_H


#include "Firework.h"

#define LIMIT_FRAME 70

class Game
{
private:
	sf::RenderWindow window;
	std::string title;
	unsigned int width;
	unsigned int height;
	unsigned int limit_frame;

	Firework fireworks;

private:
	void init();

public:
	Game(std::string title, unsigned int width, unsigned int height, unsigned int limit_frame = 0);
	void run();
	void draw();
	void update();
	void process();
};



#endif // !GAME_H
