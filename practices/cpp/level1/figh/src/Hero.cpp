#include "Hero.h"

sf::Texture Hero::textur;
sf::Sprite Hero::hero;

Hero::Hero()
{
    textur.loadFromFile("resource/image/hero.png");
    hero.setTexture(textur);
    hero.setPosition(430, 840);
}

Hero::~Hero()
{
    //dtor
}

sf::Vector2f Hero::Get_hero_position()
{
    return hero_position;
}

sf::Sprite Hero::Get_hero()
{
    return hero;
}


void Hero::hero_move(sf::Sprite &sprit)
{


//    Enemy::enemy2.setPosition(130+rand()%680,5+rand()%100);
    hero_position=sprit.getPosition();
    sf::Sprite backes=B.Get_sprite();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(hero_position.x>130))
        {
//           World::window.clear();
           sprit.move(-0.5,0 );        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&(hero_position.x<725))
        {
//           World::window.clear();
           sprit.move(0.5 , 0);
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&(hero_position.y>-30))
        {
//           World::window.clear();
           sprit.move(0, -1);
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&(hero_position.y<840))
        {
//           World::window.clear();
           sprit.move(0, 1);
        }
    World::window.draw(backes);
    World::window.draw(sprit);

}

void Hero::fire(sf::Sprite &sprit)
{
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {

         Bullet   *p=new Bullet(hero_position.x+60,hero_position.y-20);
         sf::Sprite bullet=p->Get_bullet();
         for(int i=0;i<=300;i++){
              bullet.move(0,-3);
              Enemy::enemy2.move(0,0.5);
              World::window.draw(bullet);
              World::window.draw(Enemy::enemy2);
              World::window.display();
              World::window.clear();
              World::window.draw(sprit);
              Hero::hero_move(sprit);
           }
          delete p;
        }
}

