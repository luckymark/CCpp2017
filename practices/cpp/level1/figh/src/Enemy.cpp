#include "Enemy.h"
sf::Texture Enemy::enemy1;
sf::Sprite Enemy::enemy2;
Enemy::Enemy()
{
    enemy1.loadFromFile("resource/image/enemy1.png");
    enemy2.setTexture(enemy1);
}

Enemy::~Enemy()
{
    //dtor
}
