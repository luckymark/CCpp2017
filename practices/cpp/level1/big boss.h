#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Bigen
{
    public:
        sf::Sprite convex;
        sf::Texture pic;
        int statement=0;
        int blood;
        sf::FloatRect Bigenbounding;

    Bigen()
    {

        pic.loadFromFile("big.png");
        convex.setTexture(pic);
    }
};
