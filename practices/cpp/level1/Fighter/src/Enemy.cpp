#include "Enemy.h"

Enemy::Enemy(int x,int y):Bullet(x,y)
{
    enemy1.loadFromFile("resource/image/enemy1.png");
    enemy2.setTexture(enemy1);
    enemy2.setPosition(x,y);
}

Enemy::~Enemy()
{
    //dtor
}

sf::Sprite Enemy:: Get_enemy()
{
    return enemy2;
}
