#include "Bonus.h"
#include "Game.h"



Bonus::Bonus(float x,float y)
{
	uniform_int_distribution<time_t> b(0,3);
	switch (b(Game::random))
	{
	case 0:
		texture = &RTexture::LIFE;
		set_bonusstate(0);
		break;
	case 1:
		texture = &RTexture::RANDBONUS;
		set_bonusstate(1);
		this->scale(0.5, 0.5);
		break;
	case 2:
		texture = &RTexture::BULLETBONUS;
		set_bonusstate(2);
		break;
	case 3:
		texture = &RTexture::ENERGY;
		set_bonusstate(3);
		break;
	}
	this->setPosition(x, y);
	this->setTexture(*texture);
}


Bonus::~Bonus()
{
}

void Bonus::MoveRand()
{
	uniform_int_distribution<unsigned> t(0, 4);
	int T = t(Game::random);
	switch (T)
	{
	case 0:
		direction = sf::Vector2<float>(1.0, 0);
		break;
	case 1:
		direction = sf::Vector2<float>(-1.0, 0);
		break;
	case 2:
		direction = sf::Vector2<float>(0, 1);
		break;
	case 3:
		direction = sf::Vector2<float>(0, 1);
		break;
	case 4:
		direction = sf::Vector2<float>(0, 1);
		break;
	default:
		break;
	}
	this->move(direction);
}

void Bonus::set_bonusstate(int bonusstate)
{
	this->bonusstate = bonusstate;
}

int Bonus::get_bonusstate()
{
	return bonusstate;
}
