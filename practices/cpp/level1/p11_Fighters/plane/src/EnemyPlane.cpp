#include <string>
#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>
#include "Fire.h"
#include "EnemyPlane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>



EnemyPlane::EnemyPlane()
{
    //explosion_soundBuffer_1.loadFromFile("enemy1_down.wav");
    //explosion_soundBuffer_2.loadFromFile("enemy2_down.wav");
    enemyPlane.active=0;
    explosion_status=0;
    count_explosion=0;
    level_enemyPlane=1.5;
    sprite_enemyPlane.setPosition(rand()%1100,0);
    texture_enemyPlane.loadFromFile("enemy1.png");//57*43
    textureExplosion1.loadFromFile("enemy1_down1.png");
    textureExplosion2.loadFromFile("enemy1_down2.png");
    textureExplosion3.loadFromFile("enemy1_down3.png");
    textureExplosion4.loadFromFile("enemy1_down4.png");
    spriteExplosion1.setTexture(textureExplosion1);
    spriteExplosion2.setTexture(textureExplosion2);
    spriteExplosion3.setTexture(textureExplosion3);
    spriteExplosion4.setTexture(textureExplosion4);
    sprite_enemyPlane.setTexture(texture_enemyPlane);
    //ctor1
}

EnemyPlane::~EnemyPlane()
{
    //dtor
}
void EnemyPlane::explosion(int positionExplosion_x,int positionExplosion_y)
{
    switch (explosion_status)
    {
       case 1 :spriteExplosion1.setPosition(positionExplosion_x,positionExplosion_y);
       count_explosion++;
       break;
       case 2 :spriteExplosion2.setPosition(positionExplosion_x,positionExplosion_y);
       count_explosion++;
       break;
       case 3 :spriteExplosion3.setPosition(positionExplosion_x,positionExplosion_y);
       count_explosion++;
       break;
       case 4 :spriteExplosion4.setPosition(positionExplosion_x,positionExplosion_y);
       count_explosion++;
       break;
    }

}
void EnemyPlane::controlExplosion()
{
    if(count_explosion==5)
    {
        explosion_status++;
        count_explosion=0;
    }
}
void EnemyPlane::load_enemyPlane()
{
    if(!texture_enemyPlane.loadFromFile("enemy1.png"))//57*43
    {
        std::cout<<"error!";
    }
    sprite_enemyPlane.setTexture(texture_enemyPlane);
}
void EnemyPlane::on_off()
{
    enemyPlane.active=1;
}
void EnemyPlane::move_enemyPlane()
{
    sprite_enemyPlane.move(0,level_enemyPlane);
    if(sprite_enemyPlane.getPosition().y>900)
    {
        EnemyPlane::reset();
    }
}
void EnemyPlane::reset()
{
    enemyPlane.active=0;
    sprite_enemyPlane.setPosition(rand()%1100,-45);
}
