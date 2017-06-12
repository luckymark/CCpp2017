#pragma once
#include <SFML/Graphics.hpp>
#include"plane.h"

class Bullets
{
public:
	void move();
	void setpoint(int x,int y);
	void append2(int x, int y);
	Bullets(int num);
	void append(int x,int y);
	sf::Sprite &draw(int i);
	void destroy(int No);
	bool exist(int i);
	int getx(int No);
	int gety(int No);
	void setspeed(int speed);
private:
	Plane *p;
	int speed;
	int num;
	int r = 0, a = 0, x, y;
};