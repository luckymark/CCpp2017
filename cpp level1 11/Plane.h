#pragma once
#include "stdafx.h"

class Plane
{
public:
	 static float pointX;
	 static float pointY;
	 static float width;
	 static float height;
	 sf::Texture image;
	

	Plane(int width, int height);
	void MoveLeft(float timeDelta);
	void MoveRight(float timeDelta);
	void MoveUp(float timeDelta);
	void MoveDown(float timeDelta);
	void draw();
	friend class Bullet;
};

