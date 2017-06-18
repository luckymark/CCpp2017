#pragma once
#include "stdafx.h"
#include "NormalBullet.h"

#define eneonce 3
#define enebulnumber 10//每辆敌机发射子弹的批次
class Enemy;
class EnemyBullet
{
public:
	sf::Texture image;
	float BulletPointX[eneonce*enebulnumber];
	float BulletPointY[eneonce*enebulnumber];
	int flag[eneonce*enebulnumber] = { 0 };
	int total = 0;//炮弹总数
	int mark = 0;
	int enemyExist = 0;//判断对应的敌机是否存在，如果不存在则不生成新子弹
	int begin = 0;
	sf::Clock clock3;
	EnemyBullet(Enemy *enemy);
	Enemy *enemy;
	void draw();
	void move(float timeDelta);
};
