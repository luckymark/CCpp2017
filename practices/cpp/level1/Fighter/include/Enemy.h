#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Bullet.h"
class Enemy:public Bullet
{
    public:
        Enemy(int x,int y);
        virtual ~Enemy();
        sf::Sprite Get_enemy();
    private:
        sf::Texture enemy1;
        sf::Sprite enemy2;
};

#endif // ENEMY_H
