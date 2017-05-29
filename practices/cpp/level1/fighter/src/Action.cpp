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

void Action::move(sf::Vector2<float> direction){

    this->direction=direction;
    sf::Vector2<float> temp = this->direction;
    temp.x=this->direction.x;
    temp.y=this->direction.y;
    this->setPosition(this->getPosition()+temp);




}


void Action::move(){


    sf::Vector2<float> temp = this->direction;
    temp.x=this->direction.x;
    temp.y=this->direction.y;
    this->setPosition(this->getPosition()+temp);



}
