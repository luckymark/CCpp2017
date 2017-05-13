#pragma once
#include "stdafx.h"
#include "Plane.h"
class Bullet
{
public:
	sf::Texture image;
	float BulletPointX;
	float BulletPointY;
	Bullet::Bullet();
	void draw();
	void move(float timeDelta);
	void UseBullet();
};

 