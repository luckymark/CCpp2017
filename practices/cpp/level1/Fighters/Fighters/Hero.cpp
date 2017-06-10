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
	this->blood = 100;
	this->setPosition(340,750);

}

void Hero::shoot(int j)
{
	int k;
	if (j == 1) {k = 50 * j;}
	if (j == 2) { k = 20 * j; }
	if (j == 3) { k = 8 * j; }

	static int i = 0;

	if (i>k) {
		if (j == 3) {
			Music::Fire.play();
			Bullet *bulletM = new Bullet(RTexture::BULLET1,1, sf::Vector2f(0.0, -1.0));
			Bullet *bulletR = new Bullet(RTexture::BULLET2,1, sf::Vector2f(0.0, -1.0));
			Bullet *bulletL = new Bullet(RTexture::BULLET2,1, sf::Vector2f(0.0, -1.0));
			bulletM->setScale(1, 1);
			bulletR->setScale(1, 1);
			bulletL->setScale(1, 1);
			bulletM->setBulletSpeed(SHOOT_SPEED);
			bulletR->setBulletSpeed(SHOOT_SPEED);
			bulletL->setBulletSpeed(SHOOT_SPEED);
			bulletM->setPosition(this->getPosition().x + 63, this->getPosition().y);
			bulletR->setPosition(this->getPosition().x + 88, this->getPosition().y);
			bulletL->setPosition(this->getPosition().x + 10, this->getPosition().y);
			this->world->addBullet(bulletM, 1);
			this->world->addBullet(bulletR, 1);
			this->world->addBullet(bulletL, 1);

		}
		if (j == 2)
		{
			Music::Fire.play();
			Bullet *bulletR = new Bullet(RTexture::BULLET2,1, sf::Vector2f(0.0, -1.0));
			Bullet *bulletL = new Bullet(RTexture::BULLET2,1, sf::Vector2f(0.0, -1.0));
			bulletR->setScale(1, 1);
			bulletL->setScale(1, 1);
			bulletR->setBulletSpeed(SHOOT_SPEED);
			bulletL->setBulletSpeed(SHOOT_SPEED);
			bulletR->setPosition(this->getPosition().x + 88, this->getPosition().y);
			bulletL->setPosition(this->getPosition().x + 10, this->getPosition().y);
			this->world->addBullet(bulletR, 1);
			this->world->addBullet(bulletL, 1);
		}
		if(j==1) {
			Music::Fire.play();
			Bullet *bulletM = new Bullet(RTexture::BULLET1,1, sf::Vector2f(0.0, -1.0));
			bulletM->setScale(1, 1);
			bulletM->setBulletSpeed(SHOOT_SPEED);
			bulletM->setPosition(this->getPosition().x + 63, this->getPosition().y);
			this->world->addBullet(bulletM, 1);
		}
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
	if (blood >= 100) {
		life++;
	}
	else if (blood < 100) { blood+=20; }
}
int Hero::GetBlood()
{
	return blood;
}
void Hero::add_mp()
{
	if (MP < 100) { this->MP = MP + 10; }
}
int Hero::get_mp()
{
	return this->MP;
}
int Hero::GetLife()
{
	return this->life;
}

int Hero::GetScore()
{
	return score;
}

void Hero::set_bulletmuch(int BulletMuch)
{
	this->BulletMuch = BulletMuch;
}

int Hero::get_bulletmuch()
{
	return BulletMuch;
}

bool Hero::dead()
{
	
	if (blood < 0) {
		this->BOOM.play();
		life--;
		sf::Sprite boom;
		boom.setTexture(BOOMP);
		boom.scale(1.5, 1.5);
		boom.setPosition(this->getPosition().x, this->getPosition().y);
		world->window->draw(boom);
		world->window->display();
		sf::Time s = sf::seconds(0.3f);
		sf::sleep(s);
	}
	return life == 0;
}


void Hero::set_bonusmuch(int bonusmuch)
{
	this->bonusmuch = bonusmuch;
}

int Hero::get_bonusmuch()
{
	return bonusmuch;
}
