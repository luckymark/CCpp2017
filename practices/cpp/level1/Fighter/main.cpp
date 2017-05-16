#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Music.h"
#include "Back.h"
#include "Hero.h"
int main()
{
	Music bgmusic;
	bgmusic.play_bgm();
	Back backs;
	backs.view_back();
	Hero heroes;
	heroes.init_hero();
	sf::Sprite sp=heroes.Get_hero();
    sf::Sprite spri=backs.Get_sprite();


	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Fighter");

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        heroes.hero_move(sp);

        window.clear();
        window.draw(spri);
        window.draw(sp);
        window.display();

    }



		return 0;
}
