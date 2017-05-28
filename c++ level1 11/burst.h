#pragma once
#include "stdafx.h"
#include "Bullet.h"
#include "Enemy.h"
#include "ObjectManager.h"
class Burst
{
public:
	int pointX;
	int pointY;
	int times = -1;
	sf::Texture image0, image1, image2;
	Burst();
	static void crash(Bullet *bullet, Enemy *enemy,Burst *burst);
	void explode();
};