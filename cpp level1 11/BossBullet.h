#pragma once
#include "stdafx.h"
#include "NormalBullet.h"

#define bossonce 4
#define bossbulnumber 20//每辆敌机发射子弹的批次
class Boss;
class BossBullet
{
public:
	sf::Texture image;
	float BulletPointX[bossonce*bossbulnumber];
	float BulletPointY[bossonce*bossbulnumber];
	int flag[bossonce*bossbulnumber] = { 0 };
	float rateX[bossonce*bossbulnumber] = { 0 };
	float rateY[bossonce*bossbulnumber] = { 0 };
	int right[bossonce*bossbulnumber] = { 0 };
	int left[bossonce*bossbulnumber] = { 0 };
	int enemyExist = 0;
	int begin = 0;
	int total = 0;
	int mark = 0;
	int head = 0;
	int tail = 0;
	bool empty = true;
	int efflag = 0;
	sf::Clock clock3;
	BossBullet(Boss *boss);
	Boss *boss;

	void draw();
	void move(float timeDelta);
};