#pragma once
#include "stdafx.h"
#include "Plane.h"
#include "Enemy.h"
#include "MyBullet.h"
class NormalBullet :public MyBullet
{
public:
	
	sf::Texture image;
	NormalBullet();
	void draw();
	void move(float timeDelta);
	void UseBullet();
	static int right[bulnumber];
	static int left[bulnumber];
};

 