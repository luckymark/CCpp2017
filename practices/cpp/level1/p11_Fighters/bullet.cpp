#include "stdafx.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include "bullet.h"
bullet::bullet(int max) {
	head = 0;
	tail = 0;
	this->max = max - 1;
	flag_full = 0;
	flag_null = 1;
}
void bullet::appendBullet(float x, float y, char type) {
	if (flag_full)return;
	sf::Texture tex;
	sf::Sprite spr;
	float ispeed;
	switch (type) {
	case 'p':
		tex.loadFromFile("UFO.png");
		ispeed = -1;
		break;
	default:
		;
	}
	bulletInfo[tail].bullet_texture = tex;
	bulletInfo[tail].x = x;
	bulletInfo[tail].y = y;
	bulletInfo[tail].speed = ispeed;
	bulletInfo[tail].bullet_sprite.setTexture(bulletInfo[tail]. bullet_texture);
	bulletInfo[tail].bullet_sprite.setScale(sf::Vector2f(0.01f, 0.2f));
	bulletInfo[tail].bullet_sprite.setPosition(sf::Vector2f(x, y));
	if (max-1 == tail) {
		tail = 0;
	}
	else {
		++tail;
	}
	if (tail == head) {
		flag_full = 1;
	}
	else {
		flag_full = 0;
	}
	flag_null = 0;
}

void bullet::moveBullet() {
	if (head<tail) {
		for (int i = head; i<tail; i++) {
			bulletInfo[i].y = bulletInfo[i].y + bulletInfo[i].speed;
			bulletInfo[i].bullet_sprite.setPosition(sf::Vector2f(bulletInfo[i].x, bulletInfo[i].y));
		}
	}
	else {
		for (int i = head; i<max; i++) {
			bulletInfo[i].y = bulletInfo[i].y + bulletInfo[i].speed;
			bulletInfo[i].bullet_sprite.setPosition(sf::Vector2f(bulletInfo[i].x, bulletInfo[i].y));
		}
		for (int i = 0; i<tail; i++) {
			bulletInfo[i].y = bulletInfo[i].y + bulletInfo[i].speed;
			bulletInfo[i].bullet_sprite.setPosition(sf::Vector2f(bulletInfo[i].x, bulletInfo[i].y));
		}

	}
}
void bullet::showBullet(sf::RenderWindow &thisWindow) {
	if (flag_null)return;
	if (head<tail) {
		for (int i = head; i<tail; i++) {
			thisWindow.draw(bulletInfo[i].bullet_sprite);
		}
	}
	else {
		for (int i = head; i<max; i++) {
			thisWindow.draw(bulletInfo[i].bullet_sprite);
		}
		for (int i = 0; i<tail; i++) {
			thisWindow.draw(bulletInfo[i].bullet_sprite);
		}
	}

}