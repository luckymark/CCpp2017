#include "stdafx.h"
#include "ObjectManager.h"
#include "Plane.h"
#include "game.h"
#include "windows.h"


extern sf::RenderWindow mainWindow;
extern Enemy enemy[enenumber];
void ObjectManager::PlaneUpdate(Plane &plane)
{
	sf::Event event;
	mainWindow.pollEvent(event);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		plane.MoveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		plane.MoveRight();
	}
	else
	{
		plane.draw();
	}
}

void ObjectManager::BulletUpdate(Bullet *bullet)
{
	static int mark = 0;
	if (mark == 0)
	{
		for (int i = 0; i < bulnumber-1; i++)
		{
			Bullet::right[i] = i + 1;
		}
		Bullet::right[bulnumber - 1] = 0;
		for (int i = 1; i < bulnumber ; i++)
		{
			Bullet::left[i] = i- 1;
		}
		Bullet::left[0] = bulnumber - 1;
		mark = 1;
	}
	static sf::Clock clock1;
	float timeDelta = clock1.restart().asSeconds();
	for (int i = Game::tail; FullOrEmpty(i); i = Bullet::right[i])
	{
		bullet[i].move(timeDelta);
		bullet[i].draw();		
	}

	

	

	sf::Event event;
	mainWindow.pollEvent(event);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && flag == 1)
	{
		//head point to the new launched one add 1 while tail point to the oldest one.
		if (Game::head != Game::tail || (Game::head == Game::tail&&Game::empty == true))
		{
			bullet[Game::head].UseBullet();
			Game::head = Bullet::right[Game::head];
			if (Game::head ==Game::tail)
			{
				Game::empty = false;
			}
			flag = 0;//bug 3:如果发不出子弹，就不必改变flag
		}
		
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))//bug 4:release没有用，改成现在的做法
	{		
		flag = 1;
	}

}

void ObjectManager::EnemyUpdate(Enemy *enemy)
{
	static int emark = 0;
	if (emark == 0)
	{
		for (int i = 0; i < enenumber - 1; i++)
		{
			Enemy::right[i] = i + 1;
		}
		Enemy::right[enenumber - 1] = 0;
		for (int i = 1; i < enenumber; i++)
		{
			Enemy::left[i] = i - 1;
		}
		Enemy::left[0] = enenumber - 1;
		emark = 1;
	}
	static sf::Clock clock2;
	float timeDelta = clock2.restart().asSeconds();
	for (int i = Game::etail; EnemyFullOrEmpty(i); i = Enemy::right[i])
	{
		enemy[i].move(timeDelta);	
		enemy[i].draw();
		
	}
	//打印敌机子弹
	for (int i = 0; i < enenumber; i++)
	{
		enemy[i].enebullet->move(timeDelta);
		enemy[i].enebullet->draw();
	}
	static sf::Clock clock3;
	static int mark = 0;
	if (mark == 0)
	{
		float timeDelta3 = clock3.restart().asSeconds();
		mark = 1;
	}
	sf::Time time1 = clock3.getElapsedTime();
	if (time1.asSeconds() > 2.0)
	{
		if (Game::ehead != Game::etail || (Game::ehead == Game::etail&&Game::eempty == true))
		{
			
			enemy[Game::ehead].UseEnemy();
			enemy[Game::ehead].enebullet->enemyExist = 1;
			Game::ehead = Enemy::right[Game::ehead];
			if (Game::ehead == Game::etail)
			{
				Game::eempty = false;			
			}
			
		}
		mark = 0;//bug 5:两个mark不能合并，必须分开
	}
}

bool  ObjectManager::FullOrEmpty(int i)
{
	static int flag = 0;
	if (Game::empty == true && i != Game::head)
	{
		return true;
	}
	else if (Game::empty == false && flag == 0)//when empty == false,i==tail==head
	{
		flag = 1;
		return true;
	}
	//deal with empty==true && i==head and empty==false
	else if (flag == 1)
	{
		if (i == Game::head)//i should meet head twice
		{
			flag = 0;
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool ObjectManager::EnemyFullOrEmpty(int i)
{
	static int flag = 0;
	if (Game::eempty == true && i != Game::ehead)
	{
		return true;
	}
	else if (Game::eempty == false && flag == 0)//when empty == false,i==tail==head
	{
		flag = 1;
		return true;
	}
	//deal with empty==true && i==head and empty==false
	else if (flag == 1)
	{
		if (i == Game::ehead)//i should meet head twice
		{
			flag = 0;
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

void ObjectManager::BurstUpdate(Burst *burst,Bullet *bullet)
{
	Burst::crash(bullet, enemy,burst);
	for (int i = 0; i < enenumber; i++)
	{
		if (burst[i].times != -1)
		{
			burst[i].explode();
		}
	}
}

