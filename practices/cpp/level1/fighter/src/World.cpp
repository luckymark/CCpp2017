#include "World.h"
World::World(sf::RenderWindow *window)
{
    //ctor
    this->window=window;
    this->setTexture(this->texture);
     this->setScale(1.0*this->window->getSize().x/this->texture.getSize().x,1.0*this->window->getSize().y/this->texture.getSize().y);

}

World::~World()
{
    //dtor
}

void World::add(Hero *Hero){
   // this->planes.insert(Player);
    this->hero=Hero;

}


void World::Refresh(){



    this->window->clear();
    this->window->draw(*this);
    this->window->draw(*(this->hero));
    for(auto &sprite : this->heroBullets){

        this->window->draw(*sprite);
    }
}

void World::addBullet(Bullet *bullet,int mark)
{
    switch (mark)
    {
        case 1:
             this->heroBullets.insert(bullet);//添加子弹到玩家子弹
             break;
        case 2:

             this->enemyBullets.insert(bullet);//添加子弹到敌人子弹
             break;
    }
}

void World::moveBullet()
{
    for(auto &bullet : this->heroBullets){
        bullet->move();
    }
     for(auto &bullet : this->enemyBullets){

        bullet->move();
    }
}

void World::cleanBullet(){

    for(auto bullet = this->heroBullets.begin(); bullet!=(this->heroBullets.end());){

        if((*bullet)->getPosition().y<0){

            delete *bullet;

            bullet = (this->heroBullets).erase(bullet);

        }else{
            bullet++;
        }

    }

}
