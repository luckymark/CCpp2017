#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Music.h"
#include "Back.h"
#include "Hero.h"
#include "Bullet.h"

#include "World.h"

sf::RenderWindow World::window(sf::VideoMode(1000, 1050), "Fighter");


int main()
{
	Music bgmusic;
	bgmusic.play_bgm();
	Hero heroes;


//	srand( (unsigned)time( NULL ) );
//	Enemy enemy(130+rand()%680,5+rand()%100);

	sf::Sprite hero=heroes.Get_hero();

	while (World::window.isOpen())
    {
        sf::Event event;
        while (World::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                World::window.close();
        }
//        Enemy enemy;
//        enemy.Create_enemy();
        heroes.hero_move(hero);
        heroes.fire(hero);
//        enemy.Create_enemy();
        World::window.display();
    }
		return 0;
}
















































//
////        window.draw(backes);
////
//
////        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
////        {
////         Bullet   *p=new Bullet(posit.x+60,posit.y+40);
////         sf::Sprite bullet=p->Get_bullet();
//////         sf::Vector2f bullet_position=bullet.getPosition();
////         for(int i=0;i<=250;i++){
////              bullet.move(0,-3.5);
////              window.draw(bullet);
////              window.display();
////              window.clear();
////              window.draw(backes);
////              window.draw(hero);
////              window.draw(enemy.Get_enemy());
////              heroes.hero_move(hero);
//           }
//          delete p;
//        }
//        World::window.display();
//    }
//		return 0;
//}
//
//
