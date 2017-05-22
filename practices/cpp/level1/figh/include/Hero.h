#ifndef HERO_H
#define HERO_H
#include <SFML/Graphics.hpp>
#include "World.h"
#include "Back.h"
#include "Bullet.h"
#include "Enemy.h"
class Hero
{
    public:
        Hero();
        virtual ~Hero();
        static sf::Texture textur;
        static sf::Sprite hero;
        sf::Sprite Get_hero();
        sf::Vector2f Get_hero_position();
        void hero_move(sf::Sprite &sprite);
        void fire(sf::Sprite &sprite);

    private:
//        sf::Texture textur;
//        sf::Sprite hero;
        sf::Vector2f hero_position;
        Back B;
        Enemy E;

};

#endif // HERO_H
