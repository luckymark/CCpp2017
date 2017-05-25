#pragma once
#include<iostream>
#include"plane.h"
#include<stdlib.h>
#include<time.h>

class Enemy
{
public:
	Enemy(int type,int num,int scanf);
	void produce();
	void move();
	sf::Sprite draw(int i);
	bool exist(int i);
	void destroy(); 
private:
	Plane *p;
	int num;
};
