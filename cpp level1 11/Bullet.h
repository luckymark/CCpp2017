#pragma once
#include "stdafx.h"
#include "Plane.h"
#include "Enemy.h"
class Bullet
{
public:
	sf::Texture image;
	float BulletPointX;
	float BulletPointY;
	Bullet();
	void draw();
	void move(float timeDelta);
	void UseBullet();
	static int right[bulnumber];
	static int left[bulnumber];
};

 