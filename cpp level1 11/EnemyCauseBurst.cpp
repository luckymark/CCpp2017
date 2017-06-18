#include "stdafx.h"
#include "EnemyCauseBurst.h"
#include "EnemyBullet.h"
#include "Plane.h"
#include "math.h"
#include "StrUpdate.h"
extern MusicPlay musicPlay;
void EnemyCauseBurst::crash(Enemy *enemy)
{
	for (int i = 0; i < enenumber; i++)
	{
		for (int j = 0; j < eneonce*enebulnumber; j++)
		{
			if (enemy[i].enebullet->flag[j] != 0)
			{
				if (fabs(enemy[i].enebullet->BulletPointX[j] + 15 - Plane::pointX) < 30 && fabs(enemy[i].enebullet->BulletPointY[j] - Plane::pointY+15)<30)
				{
				
					enemy[i].enebullet->flag[j] = 0;
					enemy[i].enebullet->begin++;
					StrUpdate::life--;
					
				}
			}
		}
	}
}