#pragma once
#include "stdafx.h"
#include "Plane.h"
#include "BossBullet.h"
class BossBullet;
class Boss
{
public:
	
	BossBullet *enebullet;
	sf::Texture image;
	sf::Texture images[4];
	float EnemyPointX;
	float EnemyPointY;
	int bosslife = 12;
	static int efflag;
	Boss();
	void draw();
	void move(float timeDelta);
	void UseEnemy();
	static int right[bossnumber];
	static int left[bossnumber];
	
};