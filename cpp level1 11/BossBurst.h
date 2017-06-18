#pragma once
#include "stdafx.h"
#include "NormalBullet.h"
#include "Boss.h"
#include "ObjectManager.h"
class BossBurst
{
public:
	int pointX;
	int pointY;
	int times = -1;
	sf::Texture image0, image1, image2;
	BossBurst();
	static void crash(NormalBullet *bullet, Boss *boss, BossBurst *burst,int &tail, int &head, int &efflag, bool &empty, int *right, int *left);
	static void crash(MultiBullet *bullet, Boss *boss, BossBurst *burst, int &tail, int &head, int &efflag, bool &empty, int *right, int *left);
	void explode();
};