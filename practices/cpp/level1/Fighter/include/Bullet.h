#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
    public:

        Bullet(float x,float y);
        virtual ~Bullet();
        sf::Sprite Get_bullet();
    private:
        sf::Texture bullet1;
        sf::Sprite bullet2;
};

#endif // BULLET_H
