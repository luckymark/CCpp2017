#include "stdafx.h"
#include "Boss.h"
#include "game.h"
#include "ctime"

extern sf::RenderWindow mainWindow;
Boss::Boss()
{
	enebullet = new BossBullet(this);

	if (image.loadFromFile("images/boss.png") != true)
	{
		return;
	}
	if (images[0].loadFromFile("images/bossExplode3.png") != true)
	{
		return;
	}
	if (images[1].loadFromFile("images/bossExplode2.png") != true)
	{
		return;
	}
	if (images[2].loadFromFile("images/bossExplode1.png") != true)
	{
		return;
	}
	if (images[3].loadFromFile("images/bossExplode0.png") != true)
	{
		return;
	}
}

void Boss::draw()
{
	if (bosslife/3>=3)
	{
		sf::Sprite sprite(image);
		sprite.setOrigin(EnemyPointX, EnemyPointY);
		mainWindow.draw(sprite);
		
	}
	else 
	{
		sf::Sprite sprite(images[bosslife/3]);
		sprite.setOrigin(EnemyPointX, EnemyPointY);
		mainWindow.draw(sprite);	
	}
	
	
}
	
	

void Boss::move(float timeDelta)
{

	if (EnemyPointY >-height)
	{
		EnemyPointY = EnemyPointY - 30 * timeDelta;
	}
	else
	{
		Game::btail = right[Game::btail];
		Game::bempty = true;
	}
}

void Boss::UseEnemy()
{
	static int mark = 0;
	if (mark == 0)
	{
		srand((unsigned)time(NULL));
		mark = 1;
	}
	EnemyPointX = -rand() % (width - 70);
	EnemyPointY = 300;
}

int Boss::right[bossnumber] = { 0 };
int Boss::left[bossnumber] = { 0 };
int Boss::efflag = 0;