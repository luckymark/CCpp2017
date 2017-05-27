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



}
