#ifndef HERO_H
#define HERO_H
#include <SFML/Graphics.hpp>

class Hero
{
    public:
        Hero();
        virtual ~Hero();
        void init_hero();
        sf::Sprite Get_hero();
        sf::Vector2f Get_hero_position();
        void hero_move(sf::Sprite &sprite);
    private:
        sf::Texture textur;
        sf::Sprite hero;
        sf::Vector2f hero_position;
};

#endif // HERO_H
