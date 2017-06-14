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
void enemysAction(plane * p, bool & flag1,int max) {
	static int num=0;
	if (!flag1) {
		appendEnemy(p, num);
		num++;
		flag1 = 1;
	}
	for (int i = 0; i < max; i++) {
		if (!p[i].isExist())continue;
		p[i].Fire('e');
	}
	if (max == num) {
		num = 0;
	}
}

bool gameloop(sf::RenderWindow &window, int max_enemy ,int &time_count,int &time) {
	int fresh_count = 0, sound_count = 0, score = 0;
	bool bulletCD = 0, enemyCD = 0;
	int godfresh = 0;
	bool enemyBulletCD = 0;
	int flag_collision = 0;
	plane *enemysPlane=new plane[max_enemy];

	sf::Texture backgrand_texture;
	sf::Sprite backgrand_sprite;
	plane playersPlane(350, 500, 'p');

	gameMusic gameBgm1(2);
	gameMusic soundEffect;
	gameText scoreText('s', score);
	gameText lifeText('l', playersPlane.showLife());
	gameText timeText('t', time);

	backgrand_texture.loadFromFile("backgrand.psd");
	backgrand_sprite.setTexture(backgrand_texture);
	backgrand_sprite.setTextureRect(sf::IntRect(0, 2048, 800, 600));
	window.setFramerateLimit(60);
	gameBgm1.playMusic();
	window.draw(backgrand_sprite);
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
				return false;
			}
		}
		enemysAction(enemysPlane, enemyCD, max_enemy);
		playerAction(playersPlane);
		backgrand_sprite.setTextureRect(sf::IntRect(0, 2048 - fresh_count * 2, 800, 600));
		window.clear();
		window.draw(backgrand_sprite);
		playersPlane.moveBullet();
		moveEnemy(enemysPlane, playersPlane, max_enemy, flag_collision);
		playersPlane.showPlane(window);
		playersPlane.Count();
		playersPlane.freshBulletCD();
		if (flag_collision>0) {
			soundEffect.playMusic();
			if (1 == flag_collision) {
				score++;
			}
		}
		if (2 == flag_collision) {
			clearBullet(enemysPlane, max_enemy);
		}
		showEnemy(window, enemysPlane, max_enemy);
		scoreText.setScore(score);
		scoreText.showText(window);
		timeText.setGameText("Time:" + std::to_string(time));
		timeText.showText(window);
		lifeText.setGameText("Life:" + std::to_string(playersPlane.showLife() / 4));
		lifeText.showText(window);
		window.display();
		++fresh_count;
		++time_count;
		if (0 == fresh_count % 60) {
			enemyCD = 0;
		}
		if (1024 == fresh_count) {
			fresh_count = 0;
		}
		if (time_count == 60) {
			time++;
			time_count = 0;
			if (godfresh != 0) {
				godfresh++;
				if (godfresh == 3) {
					playersPlane.godmode = 0;
					godfresh = 0;
				}
			}
		}
		if (playersPlane.godmode&&godfresh == 0) {
			godfresh++;
		}
		flag_collision = 0;
		if (!playersPlane.isExist()) {
			break;
		}
		if (score >= max_enemy*2) {
			return true;
		}
	}
	return false;
}
void gameProcess() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Sky Legend");
	sf::Texture bg_texture;
	sf::Sprite bg_sprite;
	gameText help[5];
	setInformation(help[0], "SKY LEGEND", 250, 100, 50);
	setInformation(help[1], "Use 'w','a','s','d'(or up,left,down,right)to move,use 'j' or space to fire.", 100, 200, 20);
	setInformation(help[2], "press Space to start",275,300,20);
	setInformation(help[3], "Next Level", 275, 300, 35);
	setInformation(help[4], "YOU WIN!", 275, 300, 35);
	bg_texture.loadFromFile("bg.jpg");
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(sf::Vector2f(2.0f, 2.0f));
	int time_count = 0, time = 0;
	int enemy_amount=20;
	menu:while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
		}
		window.clear();
		window.draw(bg_sprite);
		for (int i = 0; i < 3; i++) {
			help[i].showText(window);
		}
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			while (gameloop(window, enemy_amount, time_count, time)) {
				enemy_amount = enemy_amount + 2;
				if (enemy_amount>30) {
					for (int i = 0; i < 30; i++) {
						window.clear();
						help[4].showText(window);
						window.display();
					}
					goto menu;
				}
				for (int i = 0; i < 30; i++) {
					window.clear();
					help[3].showText(window);
					window.display();
				}
			}
			setInformation(help[4], "YOU LOSE!", 275, 300, 35);
			for (int i = 0; i < 30; i++) {
				window.clear();
				help[4].showText(window);
				window.display();
			}
		}
	}
	

}