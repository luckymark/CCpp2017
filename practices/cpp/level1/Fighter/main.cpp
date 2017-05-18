#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Music.h"
#include "Back.h"
#include "Hero.h"
#include "Bullet.h"
//
//void func()
//{
//    // this function is started when thread.launch() is called
//
//    for (int i = 0; i < 10; ++i)
//        std::cout << "I'm thread number one" << std::endl;
//}
class Bullet
{
    public:

        Bullet(float x,float y)
        {
            bullet1.loadFromFile("resource/image/bullet.png");
            bullet2.setTexture(bullet1);
            bullet2.setPosition(x,y);
        }
sf::Sprite Get_b()
{
    return bullet2;
}

    private:
        sf::Texture bullet1;
        sf::Sprite bullet2;

};



int main()
{
	Music bgmusic;
	bgmusic.play_bgm();
	Back backs;
	backs.view_back();
	Hero heroes;
	heroes.init_hero();
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

        heroes.hero_move(hero);
        sf::Vector2f posit=heroes.Get_hero_position();

        window.draw(backes);
        window.draw(hero);
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
         Bullet   *p=new Bullet(posit.x+60,posit.y+40);

         sf::Sprite r=p->Get_b();
         sf::Vector2f pp=r.getPosition();
         while(pp.y>0){

           r.move(0, -3  );
//          window.draw(r);

                    window.draw(r);
                    window.display();
                  //  window.clear();
                  window.clear();
        window.draw(backes);
        window.draw(hero);
                    pp=r.getPosition();

         }
          delete p;
//          window.draw(p->Get_b());
        }



        window.display();

    }



		return 0;
}
