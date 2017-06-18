#include "stdafx.h"
#include "LevelControl.h"
#include "StrUpdate.h"

void LevelControl::Change()
{
	if (StrUpdate::level > record)
	{
		record++;
		//¹»ÓÃÊ®¹Ø
		if (enemyAppearTime > 0.5)
		{
			enemyAppearTime= enemyAppearTime-0.25;
		}
		if (enemyBulletAppearTime > 0.7)
		{
			enemyBulletAppearTime = enemyBulletAppearTime - 0.2;
		}
		if (bossAppearTime > 5)
		{
			bossAppearTime = bossAppearTime - 3;
		}
		if (bossBulletAppearTime > 0.5)
		{
			bossBulletAppearTime = bossBulletAppearTime - 0.35;
		}
	}
}

float LevelControl::enemyAppearTime = 3.0;
float LevelControl::enemyBulletAppearTime=2.7;
float LevelControl::enemyMoveSpeed = 85;
float LevelControl::bossAppearTime=35.0;
float LevelControl::bossBulletAppearTime=4.0;

int  LevelControl::record = 1;