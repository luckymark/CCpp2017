#include "Hero.h"

Hero::Hero()
{
    textur.loadFromFile("resource/image/hero.png");
    hero.setTexture(textur);
}

Hero::~Hero()
{
    //dtor
}

void Hero::init_hero()
{
//    hero.setTexture(textur);
    hero.setPosition(430, 840);
}

sf::Vector2f Hero::Get_hero_position()
{
    return hero_position;
}

sf::Sprite Hero::Get_hero()
{
    return hero;
}


void Hero::hero_move(sf::Sprite &sprit)
{
    hero_position=sprit.getPosition();
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(hero_position.x>130))
        {

           sprit.move(-1,0 );
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&(hero_position.x<725))
        {

           sprit.move(1, 0);
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&(hero_position.y>-30))
        {

           sprit.move(0, -1);
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&(hero_position.y<840))
        {

           sprit.move(0, 1);
        }

}
