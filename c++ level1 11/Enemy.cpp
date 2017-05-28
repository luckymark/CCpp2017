#include "stdafx.h"
#include "Enemy.h"
#include "game.h"
#include "ctime"

extern sf::RenderWindow mainWindow;
Enemy::Enemy()
{
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
	EnemyPointX = -rand()%(width-30);
	EnemyPointY = 0 ;
}

int Enemy::right[enenumber] = { 0 };
int Enemy::left[enenumber] = { 0 };
