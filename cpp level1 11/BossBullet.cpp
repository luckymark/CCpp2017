#include "stdafx.h"
#include "BossBullet.h"
#include "game.h"
#include "math.h"
#include "Boss.h"
#include "LevelControl.h"
#define pi 3.14
extern sf::RenderWindow mainWindow;
BossBullet::BossBullet(Boss *boss)
{
	this->boss = boss;
	if (image.loadFromFile("images/bullet3.png") != true)
	{
		return;
	}

	for (int i = 0; i < bossonce*bossbulnumber - 1; i++)
	{
		right[i] = i + 1;
	}
	right[bossonce*bossbulnumber - 1] = 0;
	for (int i = 1; i < bossonce*bossbulnumber; i++)
	{
		left[i] = i - 1;
	}
	left[0] = bossonce*bossbulnumber - 1;
}

void BossBullet::draw()
{
	for (int i =tail; ObjectManager::FullOrEmpty(i, head, empty, efflag); i = right[i])
	{
			sf::Sprite sprite(image);
			sprite.setOrigin(BulletPointX[i], BulletPointY[i]);
			mainWindow.draw(sprite);	
	}

}

void BossBullet::move(float timeDelta)
{

	if (mark == 0)
	{
		float timeDelta3 = clock3.restart().asSeconds();
		mark = 1;
	}
	sf::Time time1 = clock3.getElapsedTime();
	if (time1.asSeconds() > LevelControl::bossBulletAppearTime&&enemyExist == 1 && total<bossonce*bossbulnumber)
	{
		
		for (int i = head,j=0; j < bossonce; j++,i=right[i])
		{
			BulletPointX[i] = boss->EnemyPointX +10- 30*j;
			BulletPointY[i] = boss->EnemyPointY - 150;
			head =right[head];
			if (head ==tail)
			{
				empty = false;
			}

			float deltaX = BulletPointX[i] - Plane::pointX;
			float deltaY = BulletPointY[i] - Plane::pointY;
			float delta = sqrt(deltaX*deltaX + deltaY*deltaY);
			float rateX = deltaX / delta;
			float rateY = deltaY / delta;
			this->rateX[i] = rateX;
			this->rateY[i] = rateY;
		}
		
		mark = 0;
		if (boss->EnemyPointX > Plane::pointX)
		{
			boss->EnemyPointX = boss->EnemyPointX - 15;
		}
		else if (boss->EnemyPointX < Plane::pointX)
		{
			boss->EnemyPointX = boss->EnemyPointX + 15;
		}
	}

	for (int num = tail; ObjectManager::FullOrEmpty(num, head, empty, efflag); num = right[num])
	{
	
		if (BulletPointY[num] >-height&& BulletPointY[num]<=150&&BulletPointX[num]<0&&BulletPointX[num]>-width)//没有必要flag[num]!=0,击中我方飞机，不打印就行了，这里无需判断
		{	
			BulletPointY[num] = BulletPointY[num] - 130 * timeDelta*rateY[num];
			BulletPointX[num] = BulletPointX[num] - 130 * timeDelta*rateX[num];
		}
		else
		{
			if (num == tail)
			{
				tail = right[tail];
			}
		
			right[left[num]] = right[num];
			left[right[num]] = left[num];
			right[left[tail]] = num;
			left[num] = left[tail];
			left[tail] = num;
			right[num] =tail;
			empty = true;
		}
		
		
	}
}

