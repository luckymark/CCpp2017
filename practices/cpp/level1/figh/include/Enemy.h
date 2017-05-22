#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>

class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        static sf::Texture enemy1;
        static sf::Sprite enemy2;
    private:
};

#endif // ENEMY_H
