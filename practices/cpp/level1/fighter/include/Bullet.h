#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include "RTexture.h"
#include "Action.h"

class Bullet:public Action
{
    public:
        Bullet(sf::Texture texture,sf::Vector2f direction=sf::Vector2f(0.0,1.0));
        virtual ~Bullet();

    protected:

    private:
        sf::Texture texture;
};

#endif // BULLET_H
