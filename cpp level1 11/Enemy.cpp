#include "stdafx.h"
#include "Enemy.h"
#include "game.h"
#include "ctime"

extern sf::RenderWindow mainWindow;
Enemy::Enemy()
{
	enebullet=new EnemyBullet(this);
	if (image.loadFromFile("images/plane2.png") != true)
	{
		return;
	}

}

void Enemy::draw()
{
	sf::Sprite sprite(image);
	sprite.setOrigin(EnemyPointX, EnemyPointY);
	mainWindow.draw(sprite);
}

void Enemy::move(float timeDelta)
{

	if (EnemyPointY >-height)
	{
		EnemyPointY = EnemyPointY - 40 * timeDelta;
	}
	else
	{
		Game::etail = right[Game::etail];
		Game::eempty = true;
	}
}

void Enemy::UseEnemy()
{
	static int mark = 0;
	if (mark == 0)
	{
		srand((unsigned)time(NULL));
		mark = 1;
	}
	EnemyPointX = -rand()%(width-70);
	EnemyPointY = 0 ;
}

int Enemy::right[enenumber] = { 0 };
int Enemy::left[enenumber] = { 0 };
