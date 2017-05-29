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
        void enemyMove();

    protected:

    private:
};

#endif // ENEMY_H
