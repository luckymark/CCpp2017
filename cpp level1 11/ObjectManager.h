#pragma once
#include "stdafx.h"
#include "Plane.h"
#include "Enemy.h"
#include "burst.h"
#include "EnemyBullet.h"
#include "Bullet.h"
class Burst;
class ObjectManager
{
private:
	int flag = 1;
	int eflag = 0;

public:
	void PlaneUpdate(Plane &plane);
	void BulletUpdate(Bullet *bullet);
	void EnemyUpdate(Enemy *enemy);
	void BackgroundUpdate();
	void ObjectManager::BurstUpdate(Burst *burst, Bullet *bullet);
	bool static FullOrEmpty(int i);
	bool static EnemyFullOrEmpty(int i);
};

