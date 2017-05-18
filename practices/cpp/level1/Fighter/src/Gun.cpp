#include "Gun.h"

Gun::Gun()

{
    //ctor
}

Gun::~Gun()
{
    //dtor
}

void Gun::shoot()
{
    sf::Vector2f posi=her->Get_hero_position();
    bul->bullet(posi.x,posi.y);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
           sf::Sprite bullet3=bul->Get_bullet2();
           bullet3.move(0,-500);
        }
}
