#include "gameWindow.h"
#include "stdafx.h"
#include<iostream>
#include "plane.h"
#include "gameMusic.h"
#include "gameText.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void playerAction(plane & p) {
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
		sf::Keyboard::isKeyPressed(sf::Keyboard::J))) {
		p.Fire('p');
	}
	speedCtrl = 1;
}
void enemysAction(plane * p, bool & flag1) {
	static int num=0;
	if (!flag1) {
		appendEnemy(p, num);
		num++;
		flag1 = 1;
	}
	for (int i = 0; i < 30; i++) {
		p[i].Fire('e');
	}
	if (30 == num) {
		num = 0;
	}
}
void gameProcess() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Sky Legend");
	int fresh_count=0,sound_count=0,score=0;
	bool bulletCD=0,enemyCD=0;
	bool enemyBulletCD = 0;
	int flag_collision = 0;

	plane playersPlane(350, 500, 'p');
	plane enemysPlane[30];
	gameMusic gameBgm1(1);
	gameMusic soundEffect;
	gameText scoreText('s',score);
	gameText lifeText('l', playersPlane.showLife());

	window.setFramerateLimit(60);
	gameBgm1.playMusic();
	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed|| 
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))window.close();
		}
		enemysAction(enemysPlane, enemyCD);
		playerAction(playersPlane);
		window.clear();
		playersPlane.moveBullet();
		moveEnemy(enemysPlane,playersPlane,30,flag_collision);
		playersPlane.showPlane(window);
		playersPlane.Count();
		playersPlane.freshBulletCD();
		if (flag_collision>0) {
			soundEffect.playMusic(0);
			if (1 == flag_collision) {
				score++;
			}
		}
		flag_collision = 0;
		showEnemy(window,enemysPlane, 30);
		scoreText.setScore(score);
		scoreText.showText(window);
		lifeText.setGameText("Life:" + std::to_string(playersPlane.showLife()));
		lifeText.showText(window);
		window.display();
		++fresh_count;
		if (0 == fresh_count % 40) {
			enemyCD = 0;
		}
		if (100 == fresh_count) {
			fresh_count = 0;
		}
	}
}
