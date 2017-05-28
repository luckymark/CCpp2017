#include "stdafx.h"
#include "Bullet.h"
#include "game.h"
#include "math.h"

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
		Game::tail = right[Game::tail];	
		Game::empty = true;
	}
}

void Bullet::UseBullet()
{
	BulletPointX = Plane::pointX - 30;
	BulletPointY = Plane::pointY + 50;
}


int Bullet::right[bulnumber] = { 0 };
int Bullet::left[bulnumber] = { 0 };