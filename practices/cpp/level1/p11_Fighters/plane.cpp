#include "stdafx.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include "plane.h"
#include "bullet.h"

plane::plane(float x,float y,char type) {
	switch (type) {
		case 'p':
			plane_texture.loadFromFile("UFO.png");
			break;
		default:
			;
	}
	this->x = x;
	this->y = y;
	plane_sprite.setTexture(plane_texture);
	plane_sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	plane_sprite.setPosition(sf::Vector2f(x, y));
}
void plane::setPlane(float x, float y) {
	this->x = x;
	this->y = y;
	plane_sprite.setPosition(sf::Vector2f(x, y));
}
void plane::movePlane(float x, float y) {
	float x0, y0;
	x0 = this->x+x;
	y0 = this->y+y;
	if (x0 >= -25 && x0 <= 750 && y0 >= -25 && y0 <= 550) {
		this->x = x0;
		this->y = y0;
	}//±ß½çÅÐ¶Ï
	plane_sprite.setPosition(sf::Vector2f(this->x, this->y));
}
void plane::showPlane(sf::RenderWindow &thisWindow) {
	thisWindow.draw(plane_sprite);
	plane_bullet.showBullet(thisWindow);
}
void plane::Fire() {
	plane_bullet.appendBullet(this->x, this->y,'p');
}
void plane::moveBullet() {
	plane_bullet.moveBullet();
}