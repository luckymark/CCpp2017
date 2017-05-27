#ifndef MAINLOOP_H
#define MAINLOOP_H
#include <SFML/Graphics.hpp>
#include "Hero.h"
class Hero;

class World:public sf::Sprite
{
    public:
        World(sf::RenderWindow *window);
        virtual ~World();
        void add(Hero *Hero);
        void Refresh();
        sf::RenderWindow *window;//Ìì¿ÕµÄ´°¿Ú
        Hero *hero;
        bool loading=true;


    protected:

    private:
        sf::Texture texture=RTexture::BACK_GROUND;
};

#endif // MAINLOOP_H
