#include "Enemy.h"
#include "World.h"
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
    this->setSpeed(0.2 );

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

void Enemy::boomCheck(int state)
{
    if(state==50){

//        this->BOOM.play();

    }
    sf::Sprite boom;
    boom.setTexture(BOOMP);
    boom.setScale(1,1);
    boom.setPosition(this->getPosition().x,this->getPosition().y);
    this->world->window->draw(boom);
}

void Enemy::Fire()
{
    static int i=2000;
    if(i>2000)
    {
        Bullet *bullet=new Bullet(RTexture::BULLET3);
        bullet->setPosition(this->getPosition().x+30,this->getPosition().y);
        this->world->addBullet(bullet,2);
        i=100+rand()%1500;
    }
    else{i++;}
}
