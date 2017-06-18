#include "stdafx.h"
#include "EnemyBurst.h"
#include "game.h"
#include "StrUpdate.h"

extern sf::RenderWindow mainWindow;
extern MusicPlay musicPlay;
void EnemyBurst::crash(NormalBullet *bullet, Enemy *enemy,EnemyBurst *burst,int &tail,int &head,int &efflag,bool &empty,int *right,int *left)
{
	
	int flag = 0;
	for (int i = tail; ObjectManager::FullOrEmpty(i,head,empty,efflag); i = right[i])//tail,head,empty,efflag,right
	{
	
		for (int j = Game::etail; ObjectManager::FullOrEmpty(j,Game::ehead,Game::eempty,Enemy::efflag); j = Enemy::right[j])
		{
			
			if (fabs(bullet[i].BulletPointX + 15 - enemy[j].EnemyPointX) < 30 && fabs(bullet[i].BulletPointY - enemy[j].EnemyPointY) < 30)
			{
				flag = 1;
				musicPlay.BurstMusic();
				StrUpdate::score=StrUpdate::score+6;
				burst[j].pointX = enemy[j].EnemyPointX;
				burst[j].pointY = enemy[j].EnemyPointY;
				burst[j].times = 0;//这一句暂时搁置
				enemy[j].enebullet->enemyExist = 0;
				if (i == tail)
				{
					tail = right[i];
				}
			
				//调整模拟双向链表，连接当前项前后两项，把当前项插入tail左侧的位置,当处理项不是tail时，tail和head都不变
				right[left[i]] = right[i];
				left[right[i]] = left[i];
				right[left[tail]] = i;
				left[i] = left[tail];
				left[tail] = i;
				right[i] = tail;

				if (head == tail&&empty == false)
				{
					head = i;
				}

				
				if (j == Game::etail)
				{
					Game::etail = Enemy::right[j];
				}
				Enemy::right[Enemy::left[j]] = Enemy::right[j];
				Enemy::left[Enemy::right[j]] = Enemy::left[j];
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

void EnemyBurst::crash(MultiBullet *bullet, Enemy *enemy, EnemyBurst *burst, int &tail, int &head, int &efflag, bool &empty, int *right, int *left)
{

	int flag = 0;
	for (int i = tail; ObjectManager::FullOrEmpty(i, head, empty, efflag); i = right[i])//tail,head,empty,efflag,right
	{

		for (int j = Game::etail; ObjectManager::FullOrEmpty(j, Game::ehead, Game::eempty, Enemy::efflag); j = Enemy::right[j])
		{

			if ((bullet[i].BulletPointX -enemy[j].EnemyPointX-8.5)*(bullet[i].BulletPointX - enemy[j].EnemyPointX - 8.5)
				+ (bullet[i].BulletPointY - enemy[j].EnemyPointY - 20.5)*(bullet[i].BulletPointY - enemy[j].EnemyPointY - 20.5)<10000)
			{
				flag = 1;
				StrUpdate::score++;
			
				enemy[j].life--;
				if (i == tail)
				{
					tail = right[i];
				}
				
				
		
				right[left[i]] = right[i];
				left[right[i]] = left[i];
				right[left[tail]] = i;
				left[i] = left[tail];
				left[tail] = i;
				right[i] = tail;
				if (head == tail&&empty == false)
				{
					head = i;
				}

				if (enemy[j].life> 0)
				{
					break;
				}
				musicPlay.BurstMusic();
				burst[j].pointX = enemy[j].EnemyPointX;
				burst[j].pointY = enemy[j].EnemyPointY;
				burst[j].times = 0;//这一句暂时搁置
				enemy[j].enebullet->enemyExist = 0;
				if (j == Game::etail)
				{
					Game::etail = Enemy::right[j];
				}
				Enemy::right[Enemy::left[j]] = Enemy::right[j];
				Enemy::left[Enemy::right[j]] = Enemy::left[j];
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
void EnemyBurst::explode()
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

EnemyBurst::EnemyBurst()
{
	if (image0.loadFromFile("images/enemyExplode0.png") != true)
	{
		return;
	}
	if (image1.loadFromFile("images/enemyExplode1.png") != true)
	{
		return;
	}
	if (image2.loadFromFile("images/enemyExplode2.png") != true)
	{
		return;
	}
}

