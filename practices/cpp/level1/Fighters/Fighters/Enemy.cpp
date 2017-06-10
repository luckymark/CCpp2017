#include "Enemy.h"
#include "World.h"
#include "Game.h"
#include <iostream>
#include <cmath>
#define Pi 3.14
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
	static int j = 0;
	if (i > 50)
	{
		if (this->bossState == 0)
		{
			Bullet *bullet = new Bullet(RTexture::BULLET3, 1);
			bullet->setPosition(this->getPosition().x + 30, this->getPosition().y);
			this->world->addBullet(bullet, 2);
			

		}

		if (this->bossState == 1)
		{
			if (j > 0) {

				Bullet *bullet1 = new Bullet(RTexture::BOSSBULLET1, 1);
				Bullet *bullet2 = new Bullet(RTexture::BOSSBULLET1, 1);
				Bullet *bullet3 = new Bullet(RTexture::BOSSBULLET1, 1);
				Bullet *bullet4 = new Bullet(RTexture::BOSSBULLET1, 1);
				Bullet *bullet5 = new Bullet(RTexture::BOSSBULLET1, 1);
				Bullet *bullet6 = new Bullet(RTexture::BOSSBULLET1, 1);
				Bullet *bullet7 = new Bullet(RTexture::BOSSBULLET1, 1);
				Bullet *bullet8 = new Bullet(RTexture::BOSSBULLET1, 1);
				Bullet *bullet9 = new Bullet(RTexture::BOSSBULLET1, 1);
				Bullet *bullet10 = new Bullet(RTexture::BOSSBULLET1, 1);

				bullet1->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);
				bullet2->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);
				bullet3->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);
				bullet4->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);
				bullet5->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);
				bullet6->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);
				bullet7->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);
				bullet8->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);
				bullet9->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);
				bullet10->setPosition(this->getPosition().x + 50, this->getPosition().y + 50);

				bullet1->setSpeed(10);
				bullet2->setSpeed(10);
				bullet3->setSpeed(10);
				bullet4->setSpeed(10);
				bullet5->setSpeed(10);
				bullet6->setSpeed(10);
				bullet7->setSpeed(10);
				bullet8->setSpeed(10);
				bullet9->setSpeed(10);
				bullet10->setSpeed(10);

				bullet1->move(sf::Vector2<float>(cos((2 * 1 * Pi) / 10), sin((2 * 1 * Pi) / 10)));
				bullet2->move(sf::Vector2<float>(cos((2 * 2 * Pi) / 10), sin((2 * 2 * Pi) / 10)));
				bullet3->move(sf::Vector2<float>(cos((2 * 3 * Pi) / 10), sin((2 * 3 * Pi) / 10)));
				bullet4->move(sf::Vector2<float>(cos((2 * 4 * Pi) / 10), sin((2 * 4 * Pi) / 10)));
				bullet5->move(sf::Vector2<float>(cos((2 * 5 * Pi) / 10), sin((2 * 5 * Pi) / 10)));
				bullet6->move(sf::Vector2<float>(cos((2 * 6 * Pi) / 10), sin((2 * 6 * Pi) / 10)));
				bullet7->move(sf::Vector2<float>(cos((2 * 7 * Pi) / 10), sin((2 * 7 * Pi) / 10)));
				bullet8->move(sf::Vector2<float>(cos((2 * 8 * Pi) / 10), sin((2 * 8 * Pi) / 10)));
				bullet9->move(sf::Vector2<float>(cos((2 * 9 * Pi) / 10), sin((2 * 9 * Pi) / 10)));
				bullet10->move(sf::Vector2<float>(cos((2 * 10 * Pi) / 10), sin((2 * 10 * Pi) / 10)));

				this->world->addBullet(bullet1, 2);
				this->world->addBullet(bullet2, 2);
				this->world->addBullet(bullet4, 2);
				this->world->addBullet(bullet3, 2);
				this->world->addBullet(bullet5, 2);
				this->world->addBullet(bullet6, 2);
				this->world->addBullet(bullet7, 2);
				this->world->addBullet(bullet8, 2);
				this->world->addBullet(bullet9, 2);
				this->world->addBullet(bullet10, 2);

				j = 0;
			}
			else { j++; }

		}
		i = 0;
	}
	
	else { i++; }

}
