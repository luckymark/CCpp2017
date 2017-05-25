#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "plane.h"


class Bullets
{
public:
	void move();
	Bullets();
	void append(int x,int y);
	sf::Sprite draw(int i);
	void pop();
	bool exist(int i);
private:
	Plane p[100];
};