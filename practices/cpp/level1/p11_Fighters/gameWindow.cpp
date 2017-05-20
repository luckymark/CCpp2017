#include "gameWindow.h"
#include "stdafx.h"
#include<iostream>
#include "plane.h"
#include "gameMusic.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define speed 0.5
void playerAction(plane & p) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		p.movePlane(-speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		p.movePlane(speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		p.movePlane(0, -speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		p.movePlane(0, speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		p.Fire();
		
	}
}
void gameProcess() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Sky Legend");
	plane playersPlane(350, 500, 'p');
	gameMusic gameBgm1(1);
	gameBgm1.playMusic();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		playerAction(playersPlane);
		window.clear(sf::Color::Black);
		playersPlane.moveBullet();
		playersPlane.showPlane(window);

		window.display();
	}
}
