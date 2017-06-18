#include "stdafx.h"
#include "MultiBullet.h"
#include "game.h"
#include "math.h"

extern sf::RenderWindow mainWindow;
MultiBullet::MultiBullet()
{
	
	if (image.loadFromFile("images/bullet2.png") != true)
	{
		return;
	}
}

void MultiBullet::draw()
{
	
			sf::Sprite sprite(image);
			sprite.setOrigin(BulletPointX, BulletPointY);
			mainWindow.draw(sprite);

}

void MultiBullet::move(float timeDelta,int num)
{
	
		if (BulletPointY <0&&BulletPointX<0&&BulletPointX>-width)
		{

			if(MultiBullet::direction[num]==0)
			{
				BulletPointY = BulletPointY + 200 * timeDelta;

			}
			else if (MultiBullet::direction[num] == 1)
			{
				BulletPointY = BulletPointY + 200 * timeDelta*0.86;
				BulletPointX = BulletPointX + 200 * timeDelta*0.5;
			}
			else if (MultiBullet::direction[num] == 2)
			{
				BulletPointY = BulletPointY + 200 * timeDelta*0.86;
				BulletPointX = BulletPointX - 200 * timeDelta*0.5;
			}
			else if (MultiBullet::direction[num] == 3)
			{
				BulletPointY = BulletPointY + 200 * timeDelta*0.5;
				BulletPointX = BulletPointX + 200 * timeDelta*0.86;
			}
			else if (MultiBullet::direction[num] == 4)
			{
				BulletPointY = BulletPointY + 200 * timeDelta*0.5;
				BulletPointX = BulletPointX - 200 * timeDelta*0.86;
			}
			

		}
		else
		{
			if (num == Game::mtail)
			{
				Game::mtail = right[Game::mtail];
			}
			//逻辑严密性有待检验
			right[left[num]] = right[num];
			left[right[num]] = left[num];
			right[left[Game::mtail]] = num;
			left[num] = left[Game::mtail];
			left[Game::mtail] = num;
			right[num] = Game::mtail;
			
			Game::mempty = true;
		}
	
}

bool MultiBullet::Judge()
{
	int sub = Game::mtail - Game::mhead;
	if (sub == 0&&Game::mempty==true)
	{
		return true;
	}
	else if ((Game::mtail + multi - Game::mhead) % (multinumber*multionce) >= 5)
	{
		return true;
	}

	else
	{
		return false;
	}
	
}
int MultiBullet::right[multinumber*multionce] = { 0 };
int MultiBullet::left[multinumber*multionce] = { 0 };
int MultiBullet::direction[multi] = { 0 };
int flag[multionce*multinumber] = { 0 };