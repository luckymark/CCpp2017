#include"bullet.h"

Bullet::Bullet(int x,int y,float bulletx,float bullety,int type)
{
    if(type!=3)this->setText("resources/image/bullet1.jpg",0,40,0,0);//("resources/image/shoot.png",69,78,9,21);
    else this->setText("resources/image/glass1.png",0,40,0,0);//("resources/image/shoot.png",1004,987,9,21);

	this->setTexture(*(getText()));
	this->setPosition(x,y);
    this->setSpeed(300);
    this->bulletx=bulletx;
    this->bullety=bullety;
}

void Bullet::moveNode(sf::Time deltaTime)
{
    /*
    sf::Vector2f movement(0.f,0.f);
    if(up)
    {
        if(this->getPosition().y>0)
        {
            movement.y -= getSpeed();
        }
    }
    else
    {
        if(this->getPosition().y<screenY)
        {
            movement.y += getSpeed();
        }
    }
    */
    sf::Vector2f movement(0.f,0.f);
    movement.x=bulletx*getSpeed();
    movement.y=bullety*getSpeed();
    this->move(movement*deltaTime.asSeconds());
}
//void Bullet::draw()
