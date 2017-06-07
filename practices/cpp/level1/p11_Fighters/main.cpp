#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(540, 720), "SFML works!");

    //load hero
    sf::Texture t_hero;
    t_hero.loadFromFile("assets/hero.png");
    sf::Sprite hero;
    hero.setTexture(t_hero);
    hero.setScale(0.5,0.5); //PLANE--------(128,128)*0.5=(64,64)
    hero.setPosition(540*0.5-32,720-64);

    //load bgm
    sf::Music bgm;
    bgm.openFromFile("assets/bgm1.ogg");
    bgm.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(hero);
        window.display();
    }

    return 0;
}
