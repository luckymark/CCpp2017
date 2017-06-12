#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Fire.h"

Fire::Fire()
{
    enemy_active=0;
    level_enemyShoot=8;
    if(!texture_enemyFire.loadFromFile("bullet1.png"))//5*11
    {
        std::cout<<"error!";
    }
    sprite_enemyFire.setTexture(texture_enemyFire);
    //ctor
}

Fire::~Fire()
{
    //dtor
}
void Fire::on_off()
{
    enemy_active=1;
}
void Fire::load_enemyFire(int enemy_firePosition_x,int enemy_firePosition_y)
{
    sprite_enemyFire.setPosition(enemy_firePosition_x,enemy_firePosition_y);
}
void Fire::move_enemyShoot()
{
    sprite_enemyFire.move(0,level_enemyShoot);
    if(sprite_enemyFire.getPosition().y>900)
    {
        enemy_active=0;
    }
}
