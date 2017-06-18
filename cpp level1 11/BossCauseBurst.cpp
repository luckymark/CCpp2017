#include "stdafx.h"
#include "BossCauseBurst.h"
#include "BossBullet.h"
#include "Plane.h"
#include "math.h"
#include "StrUpdate.h"
extern MusicPlay musicPlay;
void BossCauseBurst::crash(Boss *boss)
{
	for (int i = Game::btail; ObjectManager::FullOrEmpty(i, Game::bhead, Game::bempty, Boss::efflag); i = Boss::right[i])
	{
		int &tail = boss[i].enebullet->tail;
		int &head = boss[i].enebullet->head;
		bool &empty= boss[i].enebullet->empty;
		for (int j = tail; ObjectManager::FullOrEmpty(j, head, empty, boss[i].enebullet->efflag); j = boss[i].enebullet->right[j])
		{
	
				if (fabs(boss[i].enebullet->BulletPointX[j] + 15 - Plane::pointX) < 30 && fabs(boss[i].enebullet->BulletPointY[j] - Plane::pointY + 15)<30)
				{
				
					if (j == tail)
					{
						tail = boss[i].enebullet->right[j];
					}
					boss[i].enebullet->right[boss[i].enebullet->left[j]] = boss[i].enebullet->right[j];
					boss[i].enebullet->left[boss[i].enebullet->right[j]] = boss[i].enebullet->left[j];
					boss[i].enebullet->right[boss[i].enebullet->left[tail]] = j;
					boss[i].enebullet->left[j] = boss[i].enebullet->left[tail];
					boss[i].enebullet->left[tail] = j;
					boss[i].enebullet->right[j] = tail;

					if (head == tail&&empty == false)
					{
						head = j;
					}
					StrUpdate::life--;

				}
			
		}
	}
}