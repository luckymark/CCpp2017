#include "Hero.h"
#include "World.h"
#define HERO_SPEED 8
#define SHOOT_SPEED 12
Hero::Hero(World *world) :Plane(world)
{
	//ctor
	this->setTexture(this->texture);
	this->setPosition(340, 750);
	this->setSpeed(HERO_SPEED);
}

Hero::~Hero()
{
	//dtor
}

void Hero::init()
{
	this->life = 3;
	this->score = 0;
	this->setPosition(400, 400);

}

void Hero::shoot()
{
	static int i = 0;
	if (i>50) {
		Bullet *bulletM = new Bullet(RTexture::BULLET1, sf::Vector2f(0.0, -1.0));
		/*Bullet *bulletR = new Bullet(RTexture::BULLET2, sf::Vector2f(0.0, -1.0));
		Bullet *bulletL = new Bullet(RTexture::BULLET2, sf::Vector2f(0.0, -1.0));*/
		bulletM->setScale(1, 1);
		/*bulletR->setScale(1, 1);
		bulletL->setScale(1, 1);*/
		bulletM->setSpeed(SHOOT_SPEED);
		/*bulletR->setSpeed(SHOOT_SPEED);
		bulletL->setSpeed(SHOOT_SPEED);*/
		bulletM->setPosition(this->getPosition().x + 63, this->getPosition().y);
		/*bulletR->setPosition(this->getPosition().x + 88, this->getPosition().y);
		bulletL->setPosition(this->getPosition().x + 10, this->getPosition().y);*/
		this->world->addBullet(bulletM, 1);
		/*this->world->addBullet(bulletR, 1);
		this->world->addBullet(bulletL, 1);*/

		i = 0;
	}
	else {
		i++;
	}
}

void Hero::AddScore(int score)
{
	this->score += score;
}

void Hero::AddLife()
{
	life++;
}

int Hero::GetLife()
{
	return this->life;
}

int Hero::GetScore()
{
	return score;
}

bool Hero::dead()
{
	this->BOOM.play();
	life--;
	sf::Sprite boom;
	boom.setTexture(BOOMP);
	boom.scale(1.5, 1.5);
	boom.setPosition(this->getPosition().x, this->getPosition().y);
	world->window->draw(boom);
	world->window->display();
	sf::Time s = sf::seconds(0.3);
	sf::sleep(s);
	return life == 0;
}
