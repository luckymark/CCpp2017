#include "World.h"
#include <iostream>
#define ENEMY_BULLET_SPEED 1.3
World::World(sf::RenderWindow *window)
{
	//ctor
	this->window = window;
	this->setTexture(this->texture);
	this->setScale(1.0*this->window->getSize().x / this->texture.getSize().x, 1.0*this->window->getSize().y / this->texture.getSize().y);

}

World::~World()
{
	//dtor
}

void World::add(Hero *Hero) {
	this->hero = Hero;

}


void World::Refresh() {



	this->window->clear();
	this->window->draw(*this);
	this->window->draw(*(this->hero));

	for (auto enemy = this->enemyPlanes.begin(); enemy != (this->enemyPlanes.end());)
	{
		auto temp = enemy;
		(*enemy)->enemyMove();
		if ((*enemy)->state >= 1 && (*enemy)->state <= 10)
		{
			(*enemy)->boomCheck(((*enemy)->state)++);
			break;
		}
		else if ((*enemy)->state == 11)
		{
			delete *enemy;
			enemy = (this->enemyPlanes).erase(enemy);
			break;
		}
		
		for (auto sprite = this->heroBullets.begin(); sprite != (this->heroBullets.end());)
		{
			if ((*enemy)->getGlobalBounds().intersects((*sprite)->getGlobalBounds()))
			{
				(*enemy)->state = 1;
				this->hero->AddScore(5);
				this->heroBullets.erase(sprite);
				break;
			}
			sprite++;
		}

		if ((*enemy)->getPosition().y>1000)
		{
			delete *enemy;
			enemy = (this->enemyPlanes).erase(enemy);
			break;
		}
		this->window->draw(**enemy);
		if (temp == enemy) { ++enemy; }

	}


	for (auto &sprite : this->heroBullets)
	{
		this->window->draw(*sprite);
	}

	for (auto &sprite : this->enemyBullets)
	{
		
		this->window->draw(*sprite);
	}
}

void World::addBullet(Bullet *bullet, int mark)
{
	switch (mark)
	{
	case 1:
		this->heroBullets.insert(bullet);
		break;
	case 2:

		this->enemyBullets.insert(bullet);
		break;
	}
}

void World::moveBullet()
{
	for (auto &bullet : this->heroBullets) {
		bullet->move();
	}
	for (auto &bullet : this->enemyBullets) {
		bullet->setSpeed(ENEMY_BULLET_SPEED);
		bullet->move();
	}
}

void World::cleanBullet() {

	for (auto bullet = this->heroBullets.begin(); bullet != (this->heroBullets.end());)
	{
		if ((*bullet)->getPosition().y<0) {

			delete *bullet;

			bullet = (this->heroBullets).erase(bullet);

		}
		else {
			bullet++;
		}
	}

	for (auto bullet = this->enemyBullets.begin(); bullet != (this->enemyBullets.end());)
	{
		if ((*bullet)->getPosition().y>1000) {

			delete *bullet;

			bullet = (this->enemyBullets).erase(bullet);

		}
		else {
			bullet++;
		}
	}



}

void World::addEnemy()
{
	static int i = 0;
	if (i >= 90)
	{
		Enemy* enemy1 = new Enemy(this);
		////        Enemy* enemy2 = new Enemy(this);
		////        Enemy* enemy3 = new Enemy(this);
		//        this->enemyPlanes.insert(enemy3);
		this->enemyPlanes.insert(enemy1);
		//        this->enemyPlanes.insert(enemy2);
		i = 0;
	}
	else { i++; }

}

void World::EnemyShoot()
{
	for (auto enemy = this->enemyPlanes.begin(); enemy != this->enemyPlanes.end();)
	{
		(*enemy)->Fire();
		enemy++;
	}
}

bool World::killed()
{
	if (--(this->hero->unbeatable)>0)
	{
		static bool Mark = true;

		if (Mark)
		{
			this->hero->setTexture(RTexture::PLAYER1);
			Mark = false;
		}
		else
		{
			this->hero->setTexture(RTexture::PLAYER);
			Mark = true;
		}
		return false;
	}

	for (auto &bullet : this->enemyBullets)
	{
		if ((bullet)->getGlobalBounds().intersects((this->hero)->getGlobalBounds()))
		{
			return true;
		}

	}

	for (auto &enemy : this->enemyPlanes)
	{
		if ((enemy)->getGlobalBounds().intersects((this->hero)->getGlobalBounds()))
		{
			return true;
		}
	}

	return false;
}

void World::ClearAll(bool mark)
{
	for (auto &bullet : this->enemyBullets)
	{
		delete bullet;
	}

	if (mark)
	{
		for (auto &plane : this->enemyPlanes)
		{
			delete plane;
		}
		enemyPlanes.clear();
	}

	enemyBullets.clear();
	heroBullets.clear();

}




