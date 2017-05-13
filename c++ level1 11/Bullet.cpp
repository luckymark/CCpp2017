#include "stdafx.h"
#include "Bullet.h"
#include "game.h"
//extern int head;
//extern int tail;
//extern bool empty;
extern sf::RenderWindow mainWindow;
Bullet::Bullet()
{
	if (image.loadFromFile("images/bullet1.png") != true)
	{
		return;
	}
	
}

void Bullet::draw()
{
	sf::Sprite sprite(image);
	sprite.setOrigin(BulletPointX, BulletPointY);
	mainWindow.draw(sprite);
}

void Bullet::move(float timeDelta)
{
	
	if (BulletPointY < 0)
	{
		BulletPointY = BulletPointY + 100*timeDelta;
	}
	else
	{
		Game::tail = (Game::tail + 1) % bulnumber;	
		Game::empty = true;
	}
}

void Bullet::UseBullet()
{
	BulletPointX = Plane::pointX - 30;
	BulletPointY = Plane::pointY + 50;
}