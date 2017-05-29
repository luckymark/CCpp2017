#include "Hero.h"
#include "World.h"

Hero::Hero(World *world):Plane(world)
{
    //ctor
    this->setTexture(this->texture);
    this->setPosition(400,400);
}

Hero::~Hero()
{
    //dtor
}

void Hero::init()
{
    this->setPosition(400,400);

}

void Hero::shoot()
{
    static int i=0;
    if(i>50){
//        FIRE.play();
        Bullet *bulletM=new Bullet(RTexture::BULLET1,sf::Vector2<float>(0.0,-1.0));
        Bullet *bulletR=new Bullet(RTexture::BULLET2,sf::Vector2<float>(0.0,-1.0));
        Bullet *bulletL=new Bullet(RTexture::BULLET2,sf::Vector2<float>(0.0,-1.0));
        bulletM->setScale(1,1);
        bulletR->setScale(1,1);
        bulletL->setScale(1,1);
        bulletM->setPosition(this->getPosition().x+63,this->getPosition().y);
        bulletR->setPosition(this->getPosition().x+88,this->getPosition().y);
        bulletL->setPosition(this->getPosition().x+10,this->getPosition().y);
        this->world->addBullet(bulletM,1);
        this->world->addBullet(bulletR,1);
        this->world->addBullet(bulletL,1);

        i=0;
    }else{
        i++;
    }
}
