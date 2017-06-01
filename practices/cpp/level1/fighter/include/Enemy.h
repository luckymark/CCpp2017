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
        void Fire();
        void boomCheck(int state);
        int state=0;
        int mark;

    protected:
        sf::Vector2f direction;

    private:
};

#endif // ENEMY_H
