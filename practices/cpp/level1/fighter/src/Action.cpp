#include "Action.h"

Action::Action()
{
    //ctor
    direction.x=0.0;
    direction.y=1.0;
}

Action::~Action()
{
    //dtor
}

void Action::move(sf::Vector2f direction){

    this->direction=direction;
    sf::Vector2f temp = this->direction;
    temp.x=this->direction.x*speed;
    temp.y=this->direction.y*speed;
    this->setPosition(this->getPosition()+temp);




}


void Action::move(){


    sf::Vector2f temp = this->direction;
    temp.x=this->direction.x*speed;
    temp.y=this->direction.y*speed;
    this->setPosition(this->getPosition()+temp);



}

void Action::setSpeed(float speed)
{
    this->speed=speed;
}
