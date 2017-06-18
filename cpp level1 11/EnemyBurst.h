#pragma once
#include "stdafx.h"
#include "NormalBullet.h"
#include "Enemy.h"
#include "ObjectManager.h"
class EnemyBurst
{
public:
	int pointX;
	int pointY;
	int times = -1;
	sf::Texture image0, image1, image2;
	EnemyBurst();
	static void crash(NormalBullet *bullet, Enemy *enemy,EnemyBurst *burst, int &tail, int &head, int &efflag, bool &empty,int *right,int *left);
	static void crash(MultiBullet *bullet, Enemy *enemy, EnemyBurst *burst, int &tail, int &head, int &efflag, bool &empty, int *right, int *left);
	void explode();
};