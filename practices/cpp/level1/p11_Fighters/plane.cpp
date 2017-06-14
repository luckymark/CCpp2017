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
			plane_texture.loadFromFile("player.psd");
			plane_bullet=new bullet(25);
			speed =8;
			life = 12;
			half_sizeX = 37.5;
			half_sizeY = 15;
			this->x = x;
			this->y = y;
			plane_sprite.setTextureRect(sf::IntRect(0, 0, 200, 101));
			plane_sprite.setScale(sf::Vector2f(0.375f, 0.3f));
			fireRate = 5;
			godmode = 1;
			break;
		case 'e':
			plane_texture.loadFromFile("enemy.psd");
			plane_bullet = new bullet(20);
			speed = 1;
			life = 0;
			half_sizeX = 16;
			half_sizeY = 12;
			this->x = rand()%Xmax-half_sizeX;
			this->y = y;
			plane_sprite.setTextureRect(sf::IntRect(0, 0, 107, 80));
			plane_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
			fireRate = 50;
			godmode = 0;
			break;
	}
	bulletCD = 0;
	count = 0;
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
		this->y < -half_sizeY || this->y > Ymax ) {
		life = 0;
		return;
	}
	plane_sprite.setPosition(sf::Vector2f(this->x, this->y));
}
void plane::showPlane(sf::RenderWindow &thisWindow) {
	switch (this->life) {
		case 11:
		case 7:
		case 3:
			plane_sprite.setTextureRect(sf::IntRect(0, 101, 200, 101));
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			this->life = this->life - 1;
			break;
		case 10:
		case 6:
			plane_sprite.setTextureRect(sf::IntRect(0, 202, 200, 101));
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			this->life = this->life - 1;
			break;
		case 2:
			plane_sprite.setTextureRect(sf::IntRect(0, 202, 200, 101));
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			this->life = 0;
			break;
		case 9:
		case 5:
			plane_sprite.setTextureRect(sf::IntRect(0, 0, 200,101));
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			plane_sprite.setPosition(sf::Vector2f(350, 500));
			this->x = 350, this->y = 500;
			this->godmode = 1;
			this->life = this->life - 1;
			break;
		case 12:
		case 8:
		case 4:
		case 1:
			if (this->godmode) {
				plane_sprite.setTextureRect(sf::IntRect(0, 303, 200, 101));
			}
			else if('p'==this->type){
				plane_sprite.setTextureRect(sf::IntRect(0, 0, 200, 101));
			}
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			break;
		case -1:
		case -2:
		case -3:
			plane_sprite.setTextureRect(sf::IntRect(0, 80, 107, 80));
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			this->life = this->life - 1;
			break;
		case -4:
		case -5:
		case -6:
			plane_sprite.setTextureRect(sf::IntRect(0, 160, 107,100));
			thisWindow.draw(plane_sprite);
			plane_bullet->showBullet(thisWindow);
			this->life = this->life - 1;
			break;
		case -7:

			this->life = 0;
			break;
		case 0:
			plane_bullet->showBullet(thisWindow);
		default:
			break;

	}
	
}
void plane::Fire(char type) {
	if (this->life <= 0)return;
	if (this->life % 4 != 0 && this->life != 1)return;
	if (!bulletCD) {
		switch (this->type) {
		case 'p':
			plane_bullet->appendBullet(this->x + this->half_sizeX , this->y, type);
			break;
		case 'e':
			plane_bullet->appendBullet(this->x + this->half_sizeX, this->y + 2 * this->half_sizeY, type);
			break;
		default:
			;
		}
		
		bulletCD = 1;
	}
	
}
void plane::moveBullet() {
	plane_bullet->moveBullet();
}
void plane::lifeChange(int delta) {
	life += delta;
}
void plane::freshBulletCD() {
	if (bulletCD&&(0==count%fireRate)) {
		bulletCD =0;
	}
}
void plane::Count() {
	this->count=this->count+1;
	if (100 == count) {
		count = 0;
	}
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
	if ( this->life<=0)return false;
	for (int i = 0; i < 25; i++) {
		if (bp.bulletInfo[i].ifExist == 0)continue;
		if ((bp.bulletInfo[i].x > this->x  &&
			bp.bulletInfo[i].x < this->x + 2*this->half_sizeX) &&
			(bp.bulletInfo[i].y > this->y  &&
				bp.bulletInfo[i].y < this->y + 2*this->half_sizeY)) {
			bp.bulletInfo[i].ifExist = 0;
			switch (this->showType()) {
				case 'e':
					this->lifeChange(-2);
					break;
				case 'p':
					if (this->godmode)return false;
					this->lifeChange(-1);
					break;
				default:
					;
			}
			
			
			return true;
		}
	}
	return false;
}
bool plane::collision(plane & p) {
	if (0 >= this->life)return false;
	if (!p.isExist())return false;
	if (p.isCollision(this->x, this->y,this->half_sizeX,this->half_sizeY)) {
		this->lifeChange(-2);
		if (p.godmode)return true;
		p.lifeChange(-1);
		return true;
	}
	return false;
}
char plane::showType() {
	return this->type;
}
int plane::showLife(){
	return this->life;
}
void appendEnemy(plane * enemy,int index) {
	enemy[index] = *(new plane());
	enemy[index].lifeChange(1);
}

void moveEnemy(plane * enemy,plane & player,int max,int & ifCollision) {
	for (int i = 0; i < max; i++) {
		enemy[i].movePlane();
		enemy[i].moveBullet();
		if (enemy[i].collision(*player.plane_bullet)||
			enemy[i].collision(player) ){
			ifCollision = 1;
		}
		if (player.collision(*enemy[i].plane_bullet)) {
			ifCollision = 2;
		}
	}
}
void showEnemy(sf::RenderWindow &thisWindow,plane * enemy,int max) {
	for (int i = 0; i < max; i++) {
		enemy[i].showPlane(thisWindow);
		enemy[i].Count();
		enemy[i].freshBulletCD();
	}
}
void plane::deleteBullet() {
	int max;
	switch (this->type) {
		case 'p':
			max = 25;
			break;
		case 'e':
			max = 20;
			break;
		default:
			;
	}
	for (int i = 0; i < max; i++) {
		this->plane_bullet->bulletInfo[i].ifExist = 0;
	}
}
void clearBullet(plane * enemy,int max) {
	for (int i = 0; i < max; i++) {
		enemy[i].deleteBullet();
	}
}