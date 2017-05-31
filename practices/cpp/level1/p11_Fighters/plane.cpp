#include "stdafx.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include "plane.h"
#include "bullet.h"
#include "gameMusic.h"
#define Xmax 800
#define Ymax 600
plane::plane(float x,float y,char type) {
	this->type = type;
	switch (type) {
		case 'p':
			plane_texture.loadFromFile("UFO.psd");
			plane_bullet=new bullet(25);
			speed =8;
			life = 3;
			half_sizeX = 30;
			half_sizeY = 10;
			this->x = x;
			this->y = y;
			plane_sprite.setScale(sf::Vector2f(0.5f, 0.5f));
			break;
		case 'e':
			plane_texture.loadFromFile("UFO.psd");
			plane_bullet = new bullet(20);
			speed = 1;
			life = 0;
			half_sizeX = 18;
			half_sizeY = 6;
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
	if (life<=0)return;
	this->y = this->y + speed;
	if (this->x < -half_sizeX || this->x > Xmax - half_sizeX ||
		this->y < -half_sizeY || this->y > Ymax - 2 * half_sizeY) {
		life = 0;
		return;
	}
	plane_sprite.setPosition(sf::Vector2f(this->x, this->y));
}
void plane::showPlane(sf::RenderWindow &thisWindow) {
	switch (this->life) {
		case 1:
		case 2:
		case 3:
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			break;
		case -1:
		case -2:
		case -3:
			this->plane_texture.loadFromFile("UFOc1.psd");
			plane_sprite.setTexture(plane_texture);
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			this->life = this->life - 1;
			break;
		case -4:
		case -5:
		case -6:
			this->plane_texture.loadFromFile("UFOc2.psd");
			plane_sprite.setTexture(plane_texture);
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			this->life = this->life - 1;
			break;
		case -7:
			this->life = 0;
			break;
		case 0:
		default:
			break;

	}
	
}
void plane::Fire() {
	plane_bullet->appendBullet(this->x+30, this->y,'p');
}
void plane::moveBullet() {
	plane_bullet->moveBullet();
}
void plane::lifeChange(int delta) {
	life += delta;
}
bool plane::isExist() {
	if (life != 0)return true;
	return false;
}
bool plane::isCollision(float x, float y,float Xsize,float Ysize) {
	if ((this->x + 2 * this->half_sizeX > x&&this->x < x + 2 * Xsize) &&
		(this->y + 2*this->half_sizeY > y&&this->y< y+2*Ysize ))return true;
	return false;
}
bool plane::collision(bullet & bp) {
	if ( this->life==0)return false;
	for (int i = 0; i < 25; i++) {
		if (bp.bulletInfo[i].ifExist == 0)continue;
		if ((bp.bulletInfo[i].x > this->x  &&
			bp.bulletInfo[i].x < this->x + 2*this->half_sizeX) &&
			(bp.bulletInfo[i].y > this->y  &&
				bp.bulletInfo[i].y < this->y + 2*this->half_sizeY)) {
			this->lifeChange(-2);
			bp.bulletInfo[i].ifExist = 0;
			return true;
		}
	}
	return false;
}
bool plane::collision(plane & p) {
	if (0 == this->life)return false;
	if (!p.isExist())return false;
	if (p.isCollision(this->x, this->y,this->half_sizeX,this->half_sizeY)) {
		this->lifeChange(-2);
		//p.lifeChange(-1);
		return true;
	}
	return false;
}
void appendEnemy(plane * enemy,int index) {
	enemy[index] = *(new plane());
	enemy[index].lifeChange(1);
}

void moveEnemy(plane * enemy,plane & player,int max,bool & ifCollision) {
	for (int i = 0; i < max; i++) {
		enemy[i].movePlane();
		if (enemy[i].collision(*player.plane_bullet)) {
			ifCollision = 1;
		}
		if (enemy[i].collision(player)) {
			ifCollision = 1;
		}
	}
}
void showEnemy(sf::RenderWindow &thisWindow,plane * enemy,int max) {
	for (int i = 0; i < max; i++) {
		if (!enemy[i].isExist())continue;
		enemy[i].showPlane(thisWindow);
	}
}