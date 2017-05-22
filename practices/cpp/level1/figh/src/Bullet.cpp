#include "Bullet.h"

Bullet::Bullet(float x,float y)
{
    bullet1.loadFromFile("resource/image/bullet.png");
    bullet2.setTexture(bullet1);
    bullet2.setPosition(x,y);
}

Bullet::~Bullet()
{
    //dtor
}


sf::Sprite Bullet::Get_bullet()
{
    return bullet2;
}


