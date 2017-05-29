#ifndef HERO_H
#define HERO_H
#include "Plane.h"
#include "Music.h"
#include "RTexture.h"
class Hero :public Plane
{
    public:
        Hero(World *world);
        virtual ~Hero();
        void init();
        void shoot();
        friend class World;
    protected:

    private:
        sf::Texture texture=RTexture::PLAYER;
};

#endif // HERO_H
