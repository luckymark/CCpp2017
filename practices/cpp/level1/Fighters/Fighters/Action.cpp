#include "Action.h"

Action::Action()
{
	//ctor
	direction.x = 0.0;
	direction.y = 1.0;
}

Action::~Action()
{
	//dtor
}

void Action::move(sf::Vector2f direction) {

	this->direction = direction;
	sf::Vector2f temp = this->direction;
	temp.x = this->direction.x*speed;
	temp.y = this->direction.y*speed;
	this->setPosition(this->getPosition() + temp);






}


void Action::move() {


	sf::Vector2f temp = this->direction;
	temp.x = this->direction.x*bullet_speed;
	temp.y = this->direction.y*bullet_speed;
	this->setPosition(this->getPosition() + temp);



}

void Action::bossBulletMove(int i)
{
	
	double dx = cos((2*i*Pi)/10);
	double dy = sin((2*i*Pi)/10);
	sf::Vector2f temp = this->direction;
	temp.x = dx*bullet_speed;
	temp.y = dy*bullet_speed;
	this->setPosition(this->getPosition() + temp);

}

void Action::setSpeed(float speed)
{
	this->speed = speed;
}

void Action::setBulletSpeed(float bullet_speed)
{
	this->bullet_speed = bullet_speed;
}