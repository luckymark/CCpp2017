#include "Hero.h"

Hero::Hero()
{
    textur.loadFromFile("hero.jpg");
}

Hero::~Hero()
{
    //dtor
}

void Hero::init_hero()
{
    hero.setTexture(textur);

}

sf::Sprite Hero::Get_hero()
{
    return hero;
}



void Hero::hero_move(sf::Sprite &sprit)
{
    sf::Vector2f hero_position=sprit.getPosition();

     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(hero_position.x>0))
        {

           sprit.move(-1,0 );
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&(hero_position.x<1820))
        {

           sprit.move(1, 0);
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&(hero_position.y>0))
        {

           sprit.move(0, -1);
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&(hero_position.y<920))
        {

           sprit.move(0, 1);
        }
}
