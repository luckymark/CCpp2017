#ifndef ACTION_H
#define ACTION_H
#include <SFML/Graphics.hpp>

class Action :public sf::Sprite
{
    public:
        Action();
        virtual ~Action();
        void move(sf::Vector2<float> direction);
        void move();
    protected:
        sf::Vector2<float> direction;

    private:
};

#endif // ACTION_H
