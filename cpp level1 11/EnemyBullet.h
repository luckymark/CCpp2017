#pragma once
#include "stdafx.h"
#include "NormalBullet.h"

#define eneonce 3
#define enebulnumber 10//ÿ���л������ӵ�������
class Enemy;
class EnemyBullet
{
public:
	sf::Texture image;
	float BulletPointX[eneonce*enebulnumber];
	float BulletPointY[eneonce*enebulnumber];
	int flag[eneonce*enebulnumber] = { 0 };
	int total = 0;//�ڵ�����
	int mark = 0;
	int enemyExist = 0;//�ж϶�Ӧ�ĵл��Ƿ���ڣ�������������������ӵ�
	int begin = 0;
	sf::Clock clock3;
	EnemyBullet(Enemy *enemy);
	Enemy *enemy;
	void draw();
	void move(float timeDelta);
};
