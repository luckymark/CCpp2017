#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Music.h"
#include "Back.h"
#include "Hero.h"
#include "Bullet.h"
#include "Enemy.h"

int main()
{
	Music bgmusic;
	bgmusic.play_bgm();

	Back backs;
	backs.view_back();
	Hero heroes;
	heroes.init_hero();
	srand((unsigned)time(0));
	Enemy enemy(130+rand()%680,5+rand()%100);
	sf::Sprite hero=heroes.Get_hero();
    sf::Sprite backes=backs.Get_sprite();


	sf::RenderWindow window(sf::VideoMode(1000, 1050), "Fighter");

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f posit=heroes.Get_hero_position();

        heroes.hero_move(hero);
        window.draw(backes);
        window.draw(hero);
        window.draw(enemy.Get_enemy());
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
         Bullet   *p=new Bullet(posit.x+60,posit.y+40);
         sf::Sprite bullet=p->Get_bullet();
//         sf::Vector2f bullet_position=bullet.getPosition();
         for(int i=0;i<=250;i++){
              bullet.move(0,-3.5);
              window.draw(bullet);
              window.display();
              window.clear();
              window.draw(backes);
              window.draw(hero);
              heroes.hero_move(hero);
           }
          delete p;
        }
        window.display();
    }
		return 0;
}


