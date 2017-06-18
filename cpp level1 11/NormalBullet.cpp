#include "stdafx.h"
#include "NormalBullet.h"
#include "game.h"
#include "math.h"

extern sf::RenderWindow mainWindow;
NormalBullet::NormalBullet()
{
	if (image.loadFromFile("images/bullet1.png") != true)
	{
		return;
	}
	
}

void NormalBullet::draw()
{
	sf::Sprite sprite(image);
	sprite.setOrigin(BulletPointX, BulletPointY);
	mainWindow.draw(sprite);
}

void NormalBullet::move(float timeDelta)
{
	
	if (BulletPointY < 0)
	{
		BulletPointY = BulletPointY + 150*timeDelta;
	}
	else
	{
		Game::tail = right[Game::tail];	
		Game::empty = true;
	}
}

void NormalBullet::UseBullet()
{
	BulletPointX = Plane::pointX - 30;
	BulletPointY = Plane::pointY + 50;
}


int NormalBullet::right[bulnumber] = { 0 };
int NormalBullet::left[bulnumber] = { 0 };
