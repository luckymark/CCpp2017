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
