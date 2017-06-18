#include "stdafx.h"
#include "BossBurst.h"
#include "game.h"
#include "StrUpdate.h"

extern sf::RenderWindow mainWindow;
extern MusicPlay musicPlay;
void BossBurst::crash(NormalBullet *bullet, Boss *boss, BossBurst *burst,int &tail, int &head, int &efflag, bool &empty, int *right, int *left)
{
	int flag = 0;
	for (int i = tail; ObjectManager::FullOrEmpty(i,head,empty,efflag); i = right[i])
	{
		for (int j = Game::btail; ObjectManager::FullOrEmpty(j,Game::bhead,Game::bempty,Boss::efflag); j = Boss::right[j])
		{
			if (fabs(bullet[i].BulletPointX + 50 - boss[j].EnemyPointX) <50 && fabs(bullet[i].BulletPointY - boss[j].EnemyPointY) < 50)
			{
				
				
				StrUpdate::score=StrUpdate::score+3;
				boss[j].bosslife=boss[j].bosslife-3;
				//printf(" %d ", boss[j].bosslife);
				if (i == tail)
				{
					tail =right[i];
				}
				right[left[i]] =right[i];
				left[right[i]] = left[i];
				right[left[tail]] = i;
				left[i] = left[tail];
				left[tail] = i;
				right[i] = tail;
			
				if (head == tail&&empty == false)
				{
					head = i;
				}

				if (boss[j].bosslife > 0)
				{
					break;
				}
				musicPlay.BurstMusic();
				burst[j].pointX = boss[j].EnemyPointX;
				burst[j].pointY = boss[j].EnemyPointY;
				burst[j].times = 0;
				boss[j].enebullet->enemyExist = 0;
				
				if (j == Game::btail)
				{
					Game::btail = Boss::right[j];
				}
				//调整模拟双向链表，连接当前项前后两项，把当前项插入tail左侧的位置,当处理项不是tail时，tail和head都不变
				
				Boss::right[Boss::left[j]] = Boss::right[j];
				Boss::left[Boss::right[j]] = Boss::left[j];
				Boss::right[Boss::left[Game::btail]] = j;
				Boss::left[j] = Boss::left[Game::btail];
				Boss::left[Game::btail] = j;
				Boss::right[j] = Game::btail;

				
				if (Game::bhead == Game::btail&&Game::bempty == false)
				{
					Game::bhead = j;
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

void BossBurst::crash(MultiBullet *bullet, Boss *boss, BossBurst *burst, int &tail, int &head, int &efflag, bool &empty, int *right, int *left)
{
	int flag = 0;
	for (int i = tail; ObjectManager::FullOrEmpty(i, head, empty, efflag); i = right[i])
	{
		for (int j = Game::btail; ObjectManager::FullOrEmpty(j, Game::bhead, Game::bempty, Boss::efflag); j = Boss::right[j])
		{
			if (fabs(bullet[i].BulletPointX + 50 - boss[j].EnemyPointX) <50 && fabs(bullet[i].BulletPointY - boss[j].EnemyPointY) < 50)
			{
				
				
				StrUpdate::score++;
				boss[j].bosslife--;
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

				if (boss[j].bosslife > 0)
				{
					flag = 1;
					break;
				}
				musicPlay.BurstMusic();
				burst[j].pointX = boss[j].EnemyPointX;
				burst[j].pointY = boss[j].EnemyPointY;
				burst[j].times = 0;
				boss[j].enebullet->enemyExist = 0;

				if (j == Game::btail)
				{
					Game::btail = Boss::right[j];
				}
				//调整模拟双向链表，连接当前项前后两项，把当前项插入tail左侧的位置,当处理项不是tail时，tail和head都不变

				Boss::right[Boss::left[j]] = Boss::right[j];
				Boss::left[Boss::right[j]] = Boss::left[j];



				Boss::right[Boss::left[Game::btail]] = j;
				Boss::left[j] = Boss::left[Game::btail];
				Boss::left[Game::btail] = j;
				Boss::right[j] = Game::btail;

				if (Game::bhead == Game::btail&&Game::bempty == false)
				{
					Game::bhead = j;
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

void BossBurst::explode()
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
	else if (times == 1)
	{

		sf::Sprite sprite(image1);
		sprite.setOrigin(pointX, pointY);
		mainWindow.draw(sprite);

	}
	else if (times == 2)
	{
		times = -1;
		
	}
	
	if (time1.asSeconds() > 0.5)
	{
		times++;
		mark = 0;
	}

}

BossBurst::BossBurst()
{
	if (image0.loadFromFile("images/bossExplode3.png") != true)
	{
		return;
	}
	if (image1.loadFromFile("images/bossExplode4.png") != true)
	{
		return;
	}

}