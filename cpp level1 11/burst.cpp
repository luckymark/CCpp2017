#include "stdafx.h"
#include "burst.h"
#include "game.h"
#include "StrUpdate.h"
extern sf::RenderWindow mainWindow;

void Burst::crash(Bullet *bullet, Enemy *enemy,Burst *burst)
{
	int flag = 0;
	for (int i = Game::tail; ObjectManager::FullOrEmpty(i); i = Bullet::right[i])
	{
		for (int j = Game::etail; ObjectManager::EnemyFullOrEmpty(j); j = Enemy::right[j])
		{
			if (fabs(bullet[i].BulletPointX + 15 - enemy[j].EnemyPointX) < 30 && fabs(bullet[i].BulletPointY - enemy[j].EnemyPointY) < 30)
			{
				StrUpdate::score++;
				burst[j].pointX = enemy[j].EnemyPointX;
				burst[j].pointY = enemy[j].EnemyPointY;
				burst[j].times = 0;
				enemy[j].enebullet->enemyExist = 0;
			/*	enemy[j].enebullet->total = 0;
				for (int i = 0; i < eneonce*enebulnumber; i++)
				{
					enemy[j].enebullet->flag[i] = 0;
				}*/
				if (i == Game::tail)
				{
					Game::tail = Bullet::right[i];
				}
				if (j == Game::etail)
				{
					Game::etail = Enemy::right[j];
				}
				//调整模拟双向链表，连接当前项前后两项，把当前项插入tail左侧的位置,当处理项不是tail时，tail和head都不变
				Bullet::right[Bullet::left[i]] = Bullet::right[i];
				Bullet::left[Bullet::right[i]] = Bullet::left[i];
				Enemy::right[Enemy::left[j]] = Enemy::right[j];
				Enemy::left[Enemy::right[j]] = Enemy::left[j];

				Bullet::right[Bullet::left[Game::tail]] = i;
				Bullet::left[i] = Bullet::left[Game::tail];
				Bullet::left[Game::tail] = i;
				Bullet::right[i] = Game::tail;

				Enemy::right[Enemy::left[Game::etail]] = j;
				Enemy::left[j] = Enemy::left[Game::etail];
				Enemy::left[Game::etail] = j;
				Enemy::right[j] = Game::etail;
				//bug 5:ehead==etail满了时，不管插到哪里都插到了ehead，etail之间，还会打印，故插到etail之前，改变ehead
				//ehead==etail为空时，不管插到哪里都没插到了ehead，etail之间，不调整ehead,etail
				if (Game::ehead == Game::etail&&Game::eempty == false)
				{
					Game::ehead = j;
				}

				if (Game::head == Game::tail&&Game::empty == false)
				{
					Game::head = i;
				}

				flag = 1;
			}
			if (flag == 1)
			{
				break;
			}
		}
		if (flag == 1)
		{
			flag = 0;
			continue;
		}
	}
}

void Burst::explode()
{
	static sf::Clock clock4;
	static int mark = 0;
	
	if (mark == 0)
	{
		float timeDelta4 = clock4.restart().asSeconds();
		mark = 1;
	}
	sf::Time time1 = clock4.getElapsedTime();
	
		if (times == 0)
		{
			
			sf::Sprite sprite(image0);
			sprite.setOrigin(pointX, pointY);
			mainWindow.draw(sprite);
			
		}
		else if (times ==1)
		{
			
			sf::Sprite sprite(image1);
			sprite.setOrigin(pointX, pointY);
			mainWindow.draw(sprite);
			
		}
		else if (times == 2)
		{
			
			sf::Sprite sprite(image2);
			sprite.setOrigin(pointX, pointY);
			mainWindow.draw(sprite);
			
		}
		else if (times == 3)
		{
			times = -1;
		}
		if (time1.asSeconds() > 0.5)
		{
			times++;
			mark = 0;
		}
	
}

Burst::Burst()
{
	if (image0.loadFromFile("images/enemyExplode00.png") != true)
	{
		return;
	}
	if (image1.loadFromFile("images/enemyExplode11.png") != true)
	{
		return;
	}
	if (image2.loadFromFile("images/enemyExplode22.png") != true)
	{
		return;
	}
}

