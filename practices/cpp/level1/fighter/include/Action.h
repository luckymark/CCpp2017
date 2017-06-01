#ifndef ACTION_H
#define ACTION_H
#include <SFML/Graphics.hpp>

class Action :public sf::Sprite
{
    public:
        Action();
        virtual ~Action();
        void move(sf::Vector2f direction);
        void move();
        void setSpeed(float speed);
    protected:
        sf::Vector2f direction;

    private:
        float speed=1;
};

#endif // ACTION_H
