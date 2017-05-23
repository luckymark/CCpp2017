#include "stdafx.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include "plane.h"
#include "bullet.h"
#define Xmax 800
#define Ymax 600
plane::plane(float x,float y,char type) {
	switch (type) {
		case 'p':
			plane_texture.loadFromFile("UFO.png");
			plane_bullet=new bullet(25);
			speed = 0.5;
			life = 3;
			half_sizeX = 30;
			half_sizeY = 30;
			this->x = x;
			this->y = y;
			plane_sprite.setScale(sf::Vector2f(0.5f, 0.5f));
			break;
		case 'e':
			plane_texture.loadFromFile("UFO.png");
			plane_bullet = new bullet(20);
			speed = 0.05;
			life = 0;
			half_sizeX = 18;
			half_sizeY = 18;
			this->x = rand()%Xmax-half_sizeX;
			this->y = y;
			plane_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
			break;
	}

	plane_sprite.setTexture(plane_texture);
	
	plane_sprite.setPosition(sf::Vector2f(this->x, this->y));
}
void plane::setPlane(float x, float y) {
	this->x = x;
	this->y = y;
	plane_sprite.setPosition(sf::Vector2f(this->x,this-> y));
}
void plane::movePlane(float x, float y) {
	float x0, y0;
	x0 = this->x+x*speed;
	y0 = this->y+y*speed;
	if (x0 >= -half_sizeX && x0 <= Xmax- half_sizeX && y0 >= -half_sizeY && y0 <= Ymax-2*half_sizeY) {
		this->x = x0;
		this->y = y0;
	}//±ß½çÅÐ¶Ï
	plane_sprite.setPosition(sf::Vector2f(this->x, this->y));
}
void plane::movePlane() {
	if (0 == life)return;
	this->y = this->y + speed;
	if (this->x < -half_sizeX || this->x > Xmax - half_sizeX ||
		this->y < -half_sizeY || this->y > Ymax - 2 * half_sizeY) {
		life = 0;
		return;
	}
	plane_sprite.setPosition(sf::Vector2f(this->x, this->y));
}
void plane::showPlane(sf::RenderWindow &thisWindow) {
	thisWindow.draw(plane_sprite);
	plane_bullet->showBullet(thisWindow);
}
void plane::Fire() {
	plane_bullet->appendBullet(this->x+30, this->y,'p');
}
void plane::moveBullet() {
	plane_bullet->moveBullet();
}
void plane::lifeUp() {
	life += 1;
}
bool plane::isExist() {
	if (life != 0)return true;
	return false;
}
void plane::collision(bullet & bp) {
	if (0 == this->life)return;
	for (int i = 0; i < 25; i++) {
		if (bp.bulletInfo[i].ifExist == 0)continue;
		if ((bp.bulletInfo[i].x > this->x  &&
			bp.bulletInfo[i].x < this->x + 2*this->half_sizeX) &&
			(bp.bulletInfo[i].y > this->y  &&
				bp.bulletInfo[i].y < this->y + 2*this->half_sizeY)) {
			this->life = this->life - 1;
			bp.bulletInfo[i].ifExist = 0;
			return;
		}
	}
}
void appendEnemy(plane * enemy,int index) {
	enemy[index] = *(new plane());
	enemy[index].lifeUp();
}

void moveEnemy(plane * enemy,plane & player,int max) {
	for (int i = 0; i < max; i++) {
		enemy[i].movePlane();
		enemy[i].collision(*player.plane_bullet);
	}
}
void showEnemy(sf::RenderWindow &thisWindow,plane * enemy,int max) {
	for (int i = 0; i < max; i++) {
		if (!enemy[i].isExist())continue;
		enemy[i].showPlane(thisWindow);
	}
}