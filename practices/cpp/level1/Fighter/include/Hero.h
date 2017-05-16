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
        void hero_move(sf::Sprite &sprite);


    protected:

    private:
        sf::Texture textur;
        sf::Sprite hero;


};

#endif // HERO_H
