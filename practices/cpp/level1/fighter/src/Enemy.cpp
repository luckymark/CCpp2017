#include "Enemy.h"

Enemy::Enemy(World *world):Plane(world)
{
    //ctor
    this->setScale(0.8,0.8);
    static int i=1;
    this->setTexture(RTexture::ENEMY);
    switch(i)
    {
    case 1:
        this->setPosition(130+rand()%200,0);
        i++;
        break;
    case 2:
        this->setPosition(250+rand()%290,60);
        i++;
        break;
    case 3:
        this->setPosition(340+rand()%350,120);
        i=1;
        break;
    }
    this->setSpeed(0.3);

}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::enemyMove()
{

    direction=sf::Vector2f(0,1);
    this->move(direction);

}
