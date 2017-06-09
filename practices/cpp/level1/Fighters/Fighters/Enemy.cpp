#include "Enemy.h"
#include "World.h"
#include "Game.h"
#include <iostream>
#define ENEMY_SPEED 0.9f
Enemy::Enemy(World *world) :Plane(world)
{
	//ctor

	uniform_int_distribution<time_t> u(0, 200);
	uniform_int_distribution<time_t> v(250, 500);
	uniform_int_distribution<time_t> w(550, 700);
	if (u(Game::random) <= 150) {
		this->live = 1;
		this->setScale(0.8f, 0.8f);
		this->setTexture(RTexture::ENEMY);
	}
	else { this->setTexture(RTexture::BOSS1);
	this->setScale(1.3f, 1.3f);
	this->set_bossState(1);
	this->live = 8;
	}
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
	
	if (speedd>0 && speedd<35)
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

void Enemy::set_bossState(int i)
{
	this->bossState = i;
}

int Enemy::get_bossState()
{
	return bossState;
}

void Enemy::AddEnemyBullet()
{

	static int i = 0;
	if (i>10)
	{
		if (this->bossState== 0) 
		{
			Bullet *bullet = new Bullet(RTexture::BULLET3, 1);
			bullet->setPosition(this->getPosition().x + 30, this->getPosition().y);
			this->world->addBullet(bullet, 2);
			
		}

		if (this->bossState== 1)
		{
			
			for (int i = 0; i <= 2; i++) {

				Bullet *bullet1 = new Bullet(RTexture::BOSSBULLET, 1);
				bullet1->setPosition(this->getPosition().x + 30, this->getPosition().y);
				this->world->addBullet(bullet1, 3);
	

			}
		}
		i = 0;
	}
	else { i++; }
}

