#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Plane.h"
#include <iostream>
#include <string>
#include <sstream>



Plane::Plane()
{
    //ctor
    for(int i=0;i<200;i++)
    {
        bullet[i].active=0;
    }
    HP=3;
    bullet_soundBuffer.loadFromFile("bullet.wav");
    soundBullet.setBuffer(bullet_soundBuffer);
}
Plane::~Plane()
{
    //dtor
}
std::string Plane::int_to_string(int n)
{
    std::stringstream ss;
    ss<<n;
    return ss.str();
}
void Plane::loadPlane()
{
    if(!texture.loadFromFile("plane.png"))//107x94
    {
        std::cout<<"error!";
    }
    sprite.setTexture(texture);
    sprite.setPosition(600,799);
}
void Plane::movePlane()
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&clock_1.getElapsedTime().asMilliseconds()>200)
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
        spriteShoot[temp++].setPosition(sprite.getPosition().x+15,sprite.getPosition().y+31);
        bullet[temp].active=1;
        spriteShoot[temp++].setPosition(sprite.getPosition().x+82,sprite.getPosition().y+31);
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
