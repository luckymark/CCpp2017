#pragma once
#include "stdafx.h"
#include "Plane.h"
class Enemy
{
public:
	sf::Texture image;
	float EnemyPointX;
	float EnemyPointY;
	Enemy::Enemy();
	void draw();
	void move(float timeDelta);
	void UseEnemy();
	static int right[enenumber];
	static int left[enenumber];
	
	
};