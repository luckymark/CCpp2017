#ifndef RTEXTURE_H
#define RTEXTURE_H
#include <SFML/Graphics.hpp>

class RTexture
{
    public:
        RTexture();
        virtual ~RTexture();
        static sf::Texture PLAYER;
        static sf::Texture ENEMY;
        static sf::Texture BULLET1;
        static sf::Texture BULLET2;
        static sf::Texture BACK_GROUND;
        static sf::Texture BOOM1;
        static sf::Texture BULLET3;
        static void load();

    protected:

    private:
};

#endif // RTEXTURE_H
