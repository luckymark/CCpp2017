#include "stdafx.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include "bullet.h"

#define Xmax 800
#define Ymax 600
bullet::bullet(int max) {
	info * tem = new info[max];
	bulletInfo = tem;
	tail = 0;
	this->max = max;
	for (int i = 0; i <max; i++) {
		bulletInfo[i].ifExist = 0;
	}
}
void bullet::appendBullet(float x, float y, char type) {
	sf::Texture tex;
	sf::Sprite spr;
	float ispeed;
	switch (type) {
		case 'p':
			tex.loadFromFile("UFO.psd");
			bulletInfo[tail].bullet_sprite.setScale(sf::Vector2f(0.05f, 0.2f));
			ispeed = -10;
			break;
		case 'e':
			tex.loadFromFile("UFO.psd");
			bulletInfo[tail].bullet_sprite.setScale(sf::Vector2f(0.05f, 0.2f));
			ispeed = 5;
			break;
		default:
		;
	}
	bulletInfo[tail].bullet_texture = tex;
	bulletInfo[tail].x = x;
	bulletInfo[tail].y = y;
	bulletInfo[tail].ifExist = 1;
	bulletInfo[tail].speed = ispeed;
	bulletInfo[tail].bullet_sprite.setTexture(bulletInfo[tail]. bullet_texture);
	bulletInfo[tail].bullet_sprite.setPosition(sf::Vector2f(x, y));
	if ( max-1 == tail) {
		tail = 0;
	}
	else {
		++tail;
	}
}

void bullet::moveBullet() {
	for (int i = 0; i<max; i++) {
		if (0==bulletInfo[i].ifExist )continue;
		bulletInfo[i].y = bulletInfo[i].y + bulletInfo[i].speed;
		bulletInfo[i].bullet_sprite.setPosition(sf::Vector2f(bulletInfo[i].x, bulletInfo[i].y));
		isExist(i);
	}

}
void bullet::showBullet(sf::RenderWindow &thisWindow) {

	for (int i = 0; i<max; i++) {
		if (0==bulletInfo[i].ifExist )continue;
		thisWindow.draw(bulletInfo[i].bullet_sprite);
	}
}
bool bullet::isExist(int index) {
	float x = bulletInfo[index].x;
	float y = bulletInfo[index].y;
	if (x<0 || x>Xmax || y<0 || y>Ymax) {
		bulletInfo[index].ifExist = 0;
		return false;
	}
	return true;
}