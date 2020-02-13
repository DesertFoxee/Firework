
#include "Game.h"

void Game::init() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window.create(sf::VideoMode(width, height), title ,sf::Style::Default , settings);
	if (limit_frame != 0) window.setFramerateLimit(limit_frame);

	fireworks.init();
}

Game::Game(std::string title, unsigned int width, unsigned int height, unsigned int limit_frame) {
	this->title = title;
	this->width = width;
	this->height = height;
	this->limit_frame = limit_frame;
	this->init();
}

void Game::draw() {
	window.clear();

	fireworks.draw(window);
	window.display();
}

void Game::run() {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				window.close();
			}
		}
		this->process();
		this->update();
		this->draw();
	}
}

void Game::update() {
	fireworks.update();
}

void Game::process() {
}
