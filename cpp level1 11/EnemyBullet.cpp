#include "stdafx.h"
#include "EnemyBullet.h"
#include "game.h"
#include "math.h"
#include "LevelControl.h"
#define pi 3.14
extern sf::RenderWindow mainWindow;
EnemyBullet::EnemyBullet(Enemy *enemy)
{
	this->enemy = enemy;
	if (image.loadFromFile("images/bullet3.png") != true)
	{
		return;
	}
	
}

void EnemyBullet::draw()
{
	
	for (int i = 0; i < eneonce*enebulnumber; i++)
	{
		if (flag[i] != 0)
		{
			sf::Sprite sprite(image);
			sprite.setOrigin(BulletPointX[i], BulletPointY[i]);
			mainWindow.draw(sprite);
		}
	}
	
}

void EnemyBullet::move(float timeDelta)
{
	
	if (mark == 0)
	{
		float timeDelta3 = clock3.restart().asSeconds();
		mark = 1;
	}
	sf::Time time1 = clock3.getElapsedTime();
	if (time1.asSeconds() >LevelControl::enemyBulletAppearTime&&enemyExist==1&&total<eneonce*enebulnumber)
	{
		for (int i = total; i < total + 3; i++)
		{
			BulletPointX[i] =enemy->EnemyPointX-10;
			BulletPointY[i] = enemy->EnemyPointY-100;
		
		}
		flag[total] = flag[total + 1] = flag[total + 2] = 1;
		total = total + 3;
		mark = 0;
	}
	//printf(" %d ", total);
	for (int num = 0; num < total;)
	{
		//if(enemyExist)
			//printf(" num:%d %f ",num, BulletPointY[num]);
		if (BulletPointY[num] >-height)//没有必要flag[num]!=0,击中我方飞机，不打印就行了，这里无需判断
		{
			
				if (num % 3 == 0)
				{
					BulletPointY[num] = BulletPointY[num] - 155 * timeDelta;

				}
				else if (num % 3 == 1)
				{
					BulletPointY[num] = BulletPointY[num] - 155 * timeDelta*0.7;
					BulletPointX[num] = BulletPointX[num] + 130 * timeDelta*0.7;
				}
				else if (num % 3 == 2)
				{
					BulletPointY[num] = BulletPointY[num] - 155 * timeDelta*0.7;
					BulletPointX[num] = BulletPointX[num] - 130 * timeDelta*0.7;
				}
			num++;
			
		}
		else//(BulletPointY[num] <=-height)  //6.3 bug1:因为同一个不存在的子弹增加了多次begin;
		{
			if (flag[num] == 1)
			{
				begin++;
				flag[num] = 0;
			}		
			num++;
			
			//if(enemyExist==1)
			//printf("no");
			if (begin == total&&begin!=0)
			{
				total = 0;
				begin = 0;
			}
			
		}
	}
}


