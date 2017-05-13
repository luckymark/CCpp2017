#pragma once
#include "stdafx.h"

class Plane
{
public:
	 static float pointX;
	 static float pointY;
	 static float width;
	 sf::Texture image;
	

	Plane(int width, int height);
	void MoveLeft();
	void MoveRight();
	 void draw();
	friend class Bullet;
};

