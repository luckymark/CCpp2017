#include "World.h"
#include "Game.h"
#include <iostream>
#define ENEMY_BULLET_SPEED 1.3f

World::World(sf::RenderWindow *window)
{
	//ctor
	this->window = window;
	this->setTexture(this->texture);
	this->setScale(1.0f*this->window->getSize().x / this->texture.getSize().x, 1.0f*this->window->getSize().y / this->texture.getSize().y);

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
	for (auto enemy = this->smallBoss.begin(); enemy != (this->smallBoss.end());)
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
			enemy = (this->smallBoss).erase(enemy);
			break;
		}

		if ((*enemy)->getPosition().y>1000)
		{
			delete *enemy;
			enemy = (this->smallBoss).erase(enemy);
			break;
		}
		for (auto sprite = this->heroBullets.begin(); sprite != (this->heroBullets.end());)
		{
			if ((*enemy)->getGlobalBounds().intersects((*sprite)->getGlobalBounds()))
			{
				this->heroBullets.erase(sprite);
				if ((((*enemy)->live -= 2) < 0)) {
					(*enemy)->state = 1;
					this->hero->AddScore(10);
					bonusState = 1;
					AddBonus((*enemy)->getPosition().x, (*enemy)->getPosition().y);



					break;

				}
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
				this->heroBullets.erase(sprite);
				if ((((*enemy)->live -= 2) < 0)) {
					(*enemy)->state = 1;
					this->hero->AddScore(5);
					bonusState = 0;
					AddBonus((*enemy)->getPosition().x, (*enemy)->getPosition().y);
				

					
					break;
					
				}
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

	for (auto &sprite : this->smallBossBullet)
	{
		this->window->draw(*sprite);
	}

	for (auto &sprite : this->enemyBullets)
	{
		
		this->window->draw(*sprite);
	}

	for (auto &sprite : this->bonuss)
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
	case 3:
		this->smallBossBullet.insert(bullet);
		
		break;
	}
}

void World::moveBullet()
{
	for (auto &bullet : this->heroBullets) {
		bullet->move();
	}

	for (auto &bullet : this->enemyBullets) {
		bullet->setBulletSpeed(ENEMY_BULLET_SPEED);
		bullet->move();
	}

	for (auto &bullet : this->smallBossBullet) {
		
		bullet->setBulletSpeed(ENEMY_BULLET_SPEED);
		
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
	uniform_int_distribution<time_t> E(0, 10);
	static int i = 0;
	if (i >= 90)
	{
		Enemy* enemy1 = new Enemy(this);
		if (0 <= E(Game::random) <= 6&&enemy1->get_bossState()==0) {
			//Enemy* enemy1 = new Enemy(this);
			////        Enemy* enemy2 = new Enemy(this);
			////        Enemy* enemy3 = new Enemy(this);
			//        this->enemyPlanes.insert(enemy3);
			this->enemyPlanes.insert(enemy1);
			enemy1->bulletState = 0;
			//bonusState = 0;
			//        this->enemyPlanes.insert(enemy2);
		}
		if (7 <= E(Game::random) <= 10&& enemy1->get_bossState()==1)
		{
			//Enemy *enemy4 = new Enemy(this);
			enemy1->bulletState = 1;
			//bonusState = 1;
			this->smallBoss.insert(enemy1);
		}
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

	for (auto enemy = this->smallBoss.begin(); enemy != this->smallBoss.end();)
	{
		
		(*enemy)->Fire();
		enemy++;
	}
}

bool World::killed()
{
	if ((--this->hero->unbeatable)>0)
	{
		static bool Mark = true;
		this->hero->set_bulletmuch(1);
		this->hero->set_bonusmuch(0);
		if (Mark)
		{
			this->hero->setTexture(RTexture::PLAYER1);
			Mark = false;
		}
		else
		{
			this->hero->setTexture(RTexture::PLAYER2);
			Mark = true;
		}
		return false;
	}

	if(loading)
	{
		return false;
	}

	for (auto &bullet : this->enemyBullets)
	{
		if ((bullet)->getGlobalBounds().intersects((this->hero)->getGlobalBounds()))
		{
			return true;
		}

	}

	for (auto &bullet : this->smallBossBullet)
	{
		if ((bullet)->getGlobalBounds().intersects((this->hero)->getGlobalBounds()))
		{
			return true;
		}

	}

	for (auto &enemy : this->smallBoss)
	{
		if ((enemy)->getGlobalBounds().intersects((this->hero)->getGlobalBounds()))
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

		for (auto &plane : this->smallBoss)
		{
			delete plane;
		}
		smallBoss.clear();
	}
	smallBossBullet.clear();
	enemyBullets.clear();
	heroBullets.clear();

}



void World::AddBonus(float x,float y)
{
	uniform_int_distribution<time_t> a(0, 50);

	if (a(Game::random) <3&&bonusState==0) 
	{

		Bonus *bonus = new Bonus(x, y);
		bonuss.insert(bonus);

	}

	if (4<=a(Game::random) <=35 &&bonusState == 1)
	{
		Bonus *bonus = new Bonus(x, y);
		bonuss.insert(bonus);
	}
}

void World::BonusFunction()
{
	for (auto &bonus : this->bonuss)
	{
		bonus->MoveRand();
		
		if (bonus->getGlobalBounds().intersects(this->hero->getGlobalBounds())&&bonus->get_bonusstate() == 0)
		{
			this->hero->AddLife();
			delete bonus;
			this->bonuss.erase(bonus);
			break;
		}
		if (bonus->getGlobalBounds().intersects(this->hero->getGlobalBounds()) && bonus->get_bonusstate() == 2)
		{
			if (this->hero->get_bonusmuch() == 0) {
				this->hero->set_bulletmuch(2);
				this->hero->setTexture(RTexture::PLAYER3);
				this->hero->set_bonusmuch(1);
			}
			else if (this->hero->get_bonusmuch() == 1)
			{
				this->hero->setTexture(RTexture::PLAYER);
				this->hero->set_bulletmuch(3);
				
			}
			delete bonus;
			this->bonuss.erase(bonus);
			break;
		}
		
		if (bonus->getGlobalBounds().intersects(this->hero->getGlobalBounds()) && bonus->get_bonusstate() == 1)
		{
			uniform_int_distribution<time_t> c(0, 1);
			switch (c(Game::random))
			{
			case 0:

				this->hero->set_bulletmuch(3);
				this->hero->setTexture(RTexture::PLAYER);
				this->hero->set_bonusmuch(2);
				break;
			case 1:
				this->hero->AddLife();
				break;
			default:
				break;
			}
			
			delete bonus;
			this->bonuss.erase(bonus);
			break;
		}
	}
}

void World::Skill()
{
	int x = 0;
	
	for (int i = 0; i<20; i++)
	{
		Bullet *bullet = new Bullet(RTexture::BULLET2, 1, sf::Vector2<float>(0.0, -1.0));
		bullet->setScale(1.0f, 1.0f);
		bullet->setPosition(x, 800);
		this->heroBullets.insert(bullet);
		x += 40;

	}



	
}



