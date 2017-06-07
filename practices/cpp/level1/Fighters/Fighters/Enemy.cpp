#include "Enemy.h"
#include "World.h"
#include "Game.h"
#include <iostream>
#define ENEMY_SPEED 0.9
Enemy::Enemy(World *world) :Plane(world)
{
	//ctor

	uniform_int_distribution<unsigned> u(0, 200);
	uniform_int_distribution<unsigned> v(250, 500);
	uniform_int_distribution<unsigned> w(550, 700);
	this->setScale(0.8, 0.8);
	this->setTexture(RTexture::ENEMY);
	static int i = 1;
	switch (i)
	{
	case 1:
		this->setPosition(u(Game::random), 0);
		i++;
		break;
	case 2:
		this->setPosition(v(Game::random), 0);
		i++;
		break;
	case 3:
		this->setPosition(w(Game::random), 0);
		i = 1;
		break;
	}

	this->setSpeed(ENEMY_SPEED);

}

Enemy::~Enemy()
{
	//dtor
}

void Enemy::Fire()
{
	int speedd=100;
	uniform_int_distribution<unsigned> k(0, 300);
	speedd = k(Game::random);
	
	if (speedd>20 && speedd<35)
	{
		AddEnemyBullet();
		
	}
	else {};
}

void Enemy::enemyMove()
{

	direction = sf::Vector2f(0, 1);

	this->move(direction);

}

void Enemy::boomCheck(int state)
{
	if (state == 10) {

		this->BOOM.play();

	}
	sf::Sprite boom;
	boom.setTexture(BOOMP);
	boom.setScale(1, 1);
	boom.setPosition(this->getPosition().x, this->getPosition().y);
	this->world->window->draw(boom);
}

void Enemy::AddEnemyBullet()
{

	static int i = 0;
	if (i>10)
	{
		Bullet *bullet = new Bullet(RTexture::BULLET3);
		bullet->setPosition(this->getPosition().x + 30, this->getPosition().y);
		this->world->addBullet(bullet, 2);
		i = 0;
	}
	else { i++; }
}

