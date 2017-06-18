#pragma once
#include "stdafx.h"
class LevelControl
{
public:
	static float enemyAppearTime;
	static float enemyBulletAppearTime;
	static float bossAppearTime;
	static float bossBulletAppearTime;
	static float enemyMoveSpeed;
	static int record;
	static void Change();
};