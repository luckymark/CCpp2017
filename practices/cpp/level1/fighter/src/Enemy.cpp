#include "Enemy.h"

Enemy::Enemy(World *world):Plane(world)
{
    //ctor
    this->setScale(0.8,0.8);
    int *r=new int;
    this->setTexture(RTexture::ENEMY);
    this->setPosition((*r)%560,10);
    delete r;
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::enemyMove()
{
     if((*_num)<0){(*_num)=-(*_num);}
            this->move(sf::Vector2<float>(0,1));
            num++;
        }else{
            num++;
            this->move(sf::Vector2<float>(0,1));

            if(num>=((*_num)%100)){
                _num =new int;
                num=1;

            }

        }
}
