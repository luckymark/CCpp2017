#pragma once
#include "stdafx.h"
#include "Plane.h"
#include "NormalBullet.h"
#include "MultiBullet.h"

#include "Enemy.h"
#include "EnemyBurst.h"
#include "EnemyBullet.h"
#include "EnemyCauseBurst.h"

#include "Boss.h"
#include "BossBurst.h"
#include "BossBullet.h"
#include "BossCauseBurst.h"
#include "LevelControl.h"
class EnemyBurst;
class BossBurst;
class ObjectManager
{
private:
	int flag = 1;
	int eflag = 0;

public:
	void BackgroundUpdate();
	void PlaneUpdate(Plane &plane);
	void BulletUpdate(NormalBullet *bullet);
	void MultiBulletUpdate(MultiBullet *bullet);



	void EnemyUpdate(Enemy *enemy);
	void EnemyBurstUpdate(EnemyBurst *burst, NormalBullet *bullet,MultiBullet *multiBullet,Enemy *enemy);


	void BossUpdate(Boss *boss);
	void BossBurstUpdate(BossBurst *burst, NormalBullet *bullet,MultiBullet *multiBullet, Boss *boss);
	bool static FullOrEmpty(int i, int head, bool empty, int &flag);
};

