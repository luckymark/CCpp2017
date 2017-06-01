#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Audio.hpp>
#include "Music.h"
#include "Plane.h"

class Enemy:public Plane
{
    public:
        Enemy(World *world);
        virtual ~Enemy();
        virtual void enemyMove();

        int mark;

    protected:
        sf::Vector2f direction;

    private:
};

#endif // ENEMY_H
