#ifndef GUN_H
#define GUN_H
#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Bullet.h"

class Hero;
class Bullet;
class Gun
{
    public:
        Gun();
        virtual ~Gun();
        void shoot();
    private:
        Hero *her;
        Bullet *bul;
};

#endif // GUN_H
