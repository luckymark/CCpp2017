#ifndef BACK_H
#define BACK_H
#include <SFML/Graphics.hpp>

class Back
{
    public:
        Back();
        virtual ~Back();
        sf::Sprite Get_sprite();
        void view_back();

    protected:

    private:
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // BACK_H
