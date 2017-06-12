#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Plane.h"
#include <iostream>
#include <string>
#include <sstream>



Plane::Plane()
{
    //ctor
    explosion_status=0;
    count_explosion=0;
    myPlane_status=0;
    texture_myPlaneExplosion1.loadFromFile("hero_blowup_n1.png");
    texture_myPlaneExplosion2.loadFromFile("hero_blowup_n2.png");
    texture_myPlaneExplosion3.loadFromFile("hero_blowup_n3.png");
    texture_myPlaneExplosion4.loadFromFile("hero_blowup_n4.png");
    sprite_myPlaneExplosion1.setTexture(texture_myPlaneExplosion1);
    sprite_myPlaneExplosion2.setTexture(texture_myPlaneExplosion2);
    sprite_myPlaneExplosion3.setTexture(texture_myPlaneExplosion3);
    sprite_myPlaneExplosion4.setTexture(texture_myPlaneExplosion4);
    sprite_myPlaneExplosion1.scale(0.75f,0.75f);
    sprite_myPlaneExplosion2.scale(0.75f,0.75f);
    sprite_myPlaneExplosion3.scale(0.75f,0.75f);
    sprite_myPlaneExplosion4.scale(0.75f,0.75f);
    for(int i=0;i<200;i++)
    {
        bullet[i].active=0;
    }
    HP=9;
    bullet_soundBuffer.loadFromFile("bullet.wav");

    soundBullet.setBuffer(bullet_soundBuffer);
}
Plane::~Plane()
{
    //dtor
}
void Plane::explosion(int position_explosion_x,int position_explosion_y)
{
    switch (explosion_status)
    {
       case 1 :sprite_myPlaneExplosion1.setPosition(position_explosion_x,position_explosion_y);
       count_explosion++;
       break;
       case 2 :sprite_myPlaneExplosion2.setPosition(position_explosion_x,position_explosion_y);
       count_explosion++;
       break;
       case 3 :sprite_myPlaneExplosion3.setPosition(position_explosion_x,position_explosion_y);
       count_explosion++;
       break;
       case 4 :sprite_myPlaneExplosion4.setPosition(position_explosion_x,position_explosion_y);
       break;
    }

}
void Plane::controlExplosion()
{
    if(count_explosion==5)
    {
        explosion_status++;
        count_explosion=0;
    }
}
std::string Plane::int_to_string(int n)
{
    std::stringstream ss;
    ss<<n;
    return ss.str();
}
void Plane::loadPlane()
{
    if(!texture.loadFromFile("plane.png"))//(107x94)*0.75
    {
        std::cout<<"error!";
    }
    sprite.setTexture(texture);
    sprite.setPosition(600,799);
    //sprite.setScale(1.0f.1.0f);
    sprite.scale(0.75f,0.75f);

}
void Plane::movePlane()
{
    if(explosion_status==0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&sprite.getPosition().x>0)
        {
            sprite.move(-10,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&sprite.getPosition().x<1093)
        {
            sprite.move(10,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&sprite.getPosition().y>0)
        {
            sprite.move(0,-10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&sprite.getPosition().y<780)
        {
            sprite.move(0,10);
        }
    }

}
void Plane::loadShoot()
{
    for(int i=0;i<200;i++)
    {
        textureShoot.loadFromFile("bullet2.png");//5x11
        spriteShoot[i].setTexture(textureShoot);
    }
}
void Plane::moveShoot( sf::RenderWindow* window )
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&clock_1.getElapsedTime().asMilliseconds()>200&&(HP>0||HP==0))
    {
        for(int i=0;i<200;i++)
        {
            if(bullet[i].active==0)
            {
                temp=i;
                break;
            }
        }
        soundBullet.play();
        bullet[temp].active=1;
        spriteShoot[temp++].setPosition(sprite.getPosition().x+11,sprite.getPosition().y+31);
        bullet[temp].active=1;
        spriteShoot[temp++].setPosition(sprite.getPosition().x+61,sprite.getPosition().y+31);
        clock_1.restart();
    }
    for(int i=0;i<200;i++)
    {
        if(bullet[i].active==1)
        {
            window->draw(spriteShoot[i]);
            spriteShoot[i].move(0,-5);
            if(spriteShoot[i].getPosition().y<0)
            {
                bullet[i].active=0;
            }
        }
    }
}
