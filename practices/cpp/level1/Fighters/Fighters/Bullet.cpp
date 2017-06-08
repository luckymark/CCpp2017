#include "Bullet.h"

Bullet::Bullet(sf::Texture texture, int A, sf::Vector2f direction)
{
	//ctor
	this->Attack = A;
	this->texture = texture;
	this->setTexture(this->texture);
	this->direction = direction;
}

Bullet::~Bullet()
{
	//dtor
}
