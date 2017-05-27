#ifndef HERO_H
#define HERO_H
#include "Plane.h"
#include "Music.h"

class Hero :public Plane
{
    public:
        Hero(World *world);
        virtual ~Hero();
        void init();
    protected:

    private:
        sf::Texture texture=RTexture::PLAYER;
};

#endif // HERO_H
