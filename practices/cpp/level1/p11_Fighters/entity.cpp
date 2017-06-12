#include"entity.h"
Entity::Entity():mTexture()
{
	//mTexture.loadFromFile("resources/image/shoot.png",sf::IntRect(0, 100, 100, 135));
	//this->setTexture(mTexture);
	//this->setPosition(screenX - 300, screenY - 300);
	//isAlive=true;
	HP=1;
}

Entity::Entity(int sHP):mTexture()
{
	HP=sHP;
}

void Entity::setText(char* filePath,int x1,int y1,int x2,int y2)
{
    mTexture.loadFromFile(filePath,sf::IntRect(x1, y1, x2, y2));
}

void Entity::setSpeed(int a)
{
    Speed=a;
}

sf::Texture* Entity::getText()
{
    return &mTexture;
}

float Entity::getSpeed()
{
    return Speed;
}

void Entity::die()
{
    HP--;
}

int Entity::checkAlive()
{
    return HP;
}

void Entity::setHP(int a)
{
    HP=a;
}

