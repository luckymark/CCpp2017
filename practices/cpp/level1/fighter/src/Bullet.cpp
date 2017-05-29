#include "Bullet.h"

Bullet::Bullet(sf::Texture texture,sf::Vector2<float> direction)
{
    //ctor
    this->texture=texture;
    this->setTexture(this->texture);
    this->direction=direction;
}

Bullet::~Bullet()
{
    //dtor
}
