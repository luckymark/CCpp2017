#include "gameWindow.h"
#include "stdafx.h"
#include<iostream>
#include "plane.h"
#include "gameMusic.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
void playerAction(plane & p,bool & flag) {
	static float speedCtrl=1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		speedCtrl = 0.5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		p.movePlane(-speedCtrl, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		p.movePlane(speedCtrl, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		p.movePlane(0, -speedCtrl);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		p.movePlane(0, speedCtrl);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::J))&&!flag) {
		p.Fire();
		flag = 1;
	}
	speedCtrl = 1;
}
void enemysAction(plane * p, bool & flag) {
	static int num=0;
	if (!flag) {
		appendEnemy(p, num);
		num++;
		flag = 1;
	}
	if (30 == num) {
		num = 0;
	}
}
void gameProcess() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Sky Legend");
	int fresh_count=0;
	bool bulletCD=0,enemyCD=0;
	plane playersPlane(350, 500, 'p');
	gameMusic gameBgm1(1);
	plane enemysPlane[30];
	srand(time(0));
	gameBgm1.playMusic();
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)window.close();
		}
		enemysAction(enemysPlane, enemyCD);
		playerAction(playersPlane,bulletCD);
		window.clear(sf::Color::Black);
		playersPlane.moveBullet();
		moveEnemy(enemysPlane, playersPlane, 30);
		playersPlane.showPlane(window);
		showEnemy(window,enemysPlane, 30);
		window.display();
		++fresh_count;
		if (0 == fresh_count % 100) {
			bulletCD = 0;
		}
		if (1000 == fresh_count) {
			fresh_count = 0;
			enemyCD = 0;
		}
	}
}
