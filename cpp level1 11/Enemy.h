#pragma once
#include "stdafx.h"
#include "Plane.h"
#include "EnemyBullet.h"
class EnemyBullet;
class Enemy
{
public:
	EnemyBullet *enebullet;
	sf::Texture image;
	float EnemyPointX;
	float EnemyPointY;
	int life = 6;
	static int right[enenumber];
	static int left[enenumber];
	static int efflag ;
	Enemy();
	void draw();
	void move(float timeDelta);
	void UseEnemy();
	
	
};