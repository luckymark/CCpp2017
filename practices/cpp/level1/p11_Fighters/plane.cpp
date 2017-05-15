#include "stdafx.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include "plane.h"

plane::plane(int x,int y,char type) {
	
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
void plane::setPlane(int x, int y) {
	this->x = x;
	this->y = y;
	plane_sprite.setPosition(sf::Vector2f(x, y));
}
void plane::showPlane(sf::RenderWindow &thisWindow) {
	thisWindow.draw(plane_sprite);
}