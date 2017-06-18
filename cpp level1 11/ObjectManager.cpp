#include "stdafx.h"
#include "ObjectManager.h"
#include "Plane.h"
#include "game.h"
#include "windows.h"


extern sf::RenderWindow mainWindow;
void ObjectManager::PlaneUpdate(Plane &plane)
{
	static sf::Clock clock0;
	float timeDelta = clock0.restart().asSeconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		plane.MoveLeft(timeDelta);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		plane.MoveRight(timeDelta);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		plane.MoveUp(timeDelta);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		plane.MoveDown(timeDelta);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		plane.WeaponChange();
	}
		plane.draw();
}

void ObjectManager::BulletUpdate(NormalBullet *bullet)
{

	static int mark = 0;
	if (mark == 0)
	{
		for (int i = 0; i < bulnumber-1; i++)
		{
			NormalBullet::right[i] = i + 1;
		}
		NormalBullet::right[bulnumber - 1] = 0;
		for (int i = 1; i < bulnumber ; i++)
		{
			NormalBullet::left[i] = i- 1;
		}
		NormalBullet::left[0] = bulnumber - 1;
		mark = 1;
	}
	
	static sf::Clock clock1;
	float timeDelta = clock1.restart().asSeconds();
	for (int i = Game::tail; FullOrEmpty(i,Game::head,Game::empty,Plane::efflag); i = NormalBullet::right[i])
	{
	
		bullet[i].move(timeDelta);
		bullet[i].draw();		
	}

	sf::Event event;
	mainWindow.pollEvent(event);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && flag == 1)
	{
		if (Plane::weaponStatus == 0)
		{
			if (Game::head != Game::tail || (Game::head == Game::tail&&Game::empty == true))
			{
				bullet[Game::head].UseBullet();
				Game::head = NormalBullet::right[Game::head];
				if (Game::head == Game::tail)
				{
					Game::empty = false;
				}
				flag = 0;//bug 3:如果发不出子弹，就不必改变flag
			}
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
	for (int i = Game::etail; FullOrEmpty(i,Game::ehead,Game::eempty,Enemy::efflag); i = Enemy::right[i])
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
	if (time1.asSeconds() >LevelControl::enemyAppearTime)
	{
		if (Game::ehead != Game::etail || (Game::ehead == Game::etail&&Game::eempty == true))
		{
			enemy[Game::ehead].life = 6;
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

bool  ObjectManager::FullOrEmpty(int i,int head,bool empty,int &flag)
{
	if (empty == true && i != head)
	{
		return true;
	}
	else if (empty == false && flag == 0)//when empty == false,i==tail==head
	{
		flag = 1;
		return true;
	}
	//deal with empty==true && i==head and empty==false
	else if (flag == 1)
	{
		if (i == head)//i should meet head twice
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


void ObjectManager::EnemyBurstUpdate(EnemyBurst *burst,NormalBullet *bullet,MultiBullet *multiBullet,Enemy *enemy)
{
	
	//6.17 bug1:把派生类指针赋给基类指针，而两者加1的效果不同
	//不能用基类指针处理派生类数组
	EnemyBurst::crash(bullet, enemy,burst,Game::tail,Game::head,Plane::efflag,Game::empty,NormalBullet::right,NormalBullet::left);
	EnemyBurst::crash(multiBullet, enemy, burst, Game::mtail, Game::mhead, Plane::mefflag, Game::mempty, MultiBullet::right, MultiBullet::left);
	static sf::Clock clock3;
	static int mark = 0;
	
	if (mark == 0)
	{
		float timeDelta3 = clock3.restart().asSeconds();
		mark = 1;
	}
	
	
		EnemyCauseBurst::crash(enemy);
		mark = 0;
	
	for (int i = 0; i < enenumber; i++)
	{
		if (burst[i].times != -1)
		{
			burst[i].explode();
		}
	}
}

void ObjectManager::BackgroundUpdate()
{
	sf::Texture image;
	if (image.loadFromFile("images/Background.jpg") != true)
	{
		return;
	}
	sf::Sprite sprite(image);
	sprite.setOrigin(0,0);
	mainWindow.draw(sprite);
}



void ObjectManager::BossBurstUpdate(BossBurst *burst, NormalBullet *bullet, MultiBullet *multiBullet,Boss *boss)
{
	BossBurst::crash(bullet, boss, burst, Game::tail, Game::head, Plane::efflag, Game::empty, NormalBullet::right, NormalBullet::left);
	BossBurst::crash(multiBullet, boss, burst, Game::mtail, Game::mhead, Plane::mefflag, Game::mempty, MultiBullet::right, MultiBullet::left);
	static sf::Clock clock3;
	static int mark = 0;

	if (mark == 0)
	{
		float timeDelta3 = clock3.restart().asSeconds();
		mark = 1;
	}


	BossCauseBurst::crash(boss);
	mark = 0;

	for (int i = 0; i < bossnumber; i++)
	{
		if (burst[i].times != -1)
		{
			burst[i].explode();
		}
	}
}

void ObjectManager::BossUpdate(Boss *boss)
{
	static int bmark = 0;
	if (bmark == 0)
	{
		for (int i = 0; i < bossnumber - 1; i++)
		{
			Boss::right[i] = i + 1;
		}
		Boss::right[bossnumber - 1] = 0;
		for (int i = 1; i < bossnumber; i++)
		{
			Boss::left[i] = i - 1;
		}
		Boss::left[0] = bossnumber - 1;
		bmark = 1;
	}
	static sf::Clock clock2;
	float timeDelta = clock2.restart().asSeconds();
	for (int i = Game::btail; FullOrEmpty(i,Game::bhead,Game::bempty,Boss::efflag); i = Boss::right[i])
	{
		boss[i].move(timeDelta);
		boss[i].draw();

	}
	//打印敌机子弹
	for (int i = 0; i < bossnumber; i++)
	{
		boss[i].enebullet->move(timeDelta);
		boss[i].enebullet->draw();
	}
	static sf::Clock clock3;
	static int mark = 0;
	if (mark == 0)
	{
		float timeDelta3 = clock3.restart().asSeconds();
		mark = 1;
	}
	sf::Time time1 = clock3.getElapsedTime();
	if (time1.asSeconds() > LevelControl::bossAppearTime)
	{
		if (Game::bhead != Game::btail || (Game::bhead == Game::btail&&Game::bempty == true))
		{
			boss[Game::bhead].UseEnemy();
			
			boss[Game::bhead].enebullet->enemyExist = 1;
			boss[Game::bhead].bosslife = 12;
			Game::bhead = Boss::right[Game::bhead];
			if (Game::bhead == Game::btail)
			{
				Game::bempty = false;
			}

		}
		mark = 0;//bug 5:两个mark不能合并，必须分开
	}
}

void  ObjectManager::MultiBulletUpdate(MultiBullet *bullet)
{
	static int mark = 0;
	if (mark == 0)
	{
		for (int i = 0; i < multinumber*multionce - 1; i++)
		{
			MultiBullet::right[i] = i + 1;
		}
		MultiBullet::right[multinumber*multionce - 1] = 0;
		for (int i = 1; i < multinumber*multionce; i++)
		{
			MultiBullet::left[i] = i - 1;
		}
		MultiBullet::left[0] = multinumber*multionce - 1;
		mark = 1;
		for (int i = 0; i < multi; i++)
		{
			MultiBullet::direction[i] = i%multionce;
		}
	}
	
	static sf::Clock clock1;
	float timeDelta = clock1.restart().asSeconds();
	for (int i = Game::mtail; FullOrEmpty(i, Game::mhead, Game::mempty, Plane::mefflag); i = MultiBullet::right[i])
	{

		bullet[i].move(timeDelta,i);
		bullet[i].draw();
	}

	sf::Event event;
	mainWindow.pollEvent(event);
	static int timemark = 1;
	static sf::Clock clock4;

	if (timemark == 1)
	{
		float timeDelta3 = clock4.restart().asSeconds();
		timemark = 2;
	}
	sf::Time time2 = clock4.getElapsedTime();

	static bool empty = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && time2.asSeconds() > 0.7 && Plane::weaponStatus == 1&&MultiBullet::Judge())
	{
		//head的调整，大于五个发射下一轮的调整
			for (int i = Game::mhead, j = 0; j<5; i = MultiBullet::right[i], j++)
			{
				bullet[i].BulletPointX = Plane::pointX - 30;
				bullet[i].BulletPointY = Plane::pointY;
				MultiBullet::direction[i] = j;
				Game::mhead = MultiBullet::right[Game::mhead];
				if (Game::mhead == Game::mtail)
				{
					Game::mempty = false;
				}
			}		
			timemark = 1;
	}
	
	
}
