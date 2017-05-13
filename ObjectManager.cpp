#include "stdafx.h"
#include "ObjectManager.h"
#include "Plane.h"
#include "game.h"
extern sf::RenderWindow mainWindow;

void ObjectManager::PlaneUpdate(Plane &plane)
{
	sf::Event event;
	mainWindow.pollEvent(event);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		plane.MoveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		plane.MoveRight();
	}
	else
	{
		plane.draw();
	}
}

void ObjectManager::BulletUpdate(Bullet *bullet)
{
	static sf::Clock clock1;
	float timeDelta = clock1.restart().asSeconds();
	for (int i = Game::tail; FullOrEmpty(i); i = (i + 1) % bulnumber)
	{
		bullet[i].move(timeDelta);
		bullet[i].draw();
	}

	sf::Event event;
	mainWindow.pollEvent(event);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && flag == 1)
	{
		//head point to the new launched one add 1 while tail point to the oldest one.
		if (Game::head != Game::tail || (Game::head == Game::tail&&Game::empty == true))
		{
			bullet[Game::head].UseBullet();
			Game::head = (Game::head + 1) % bulnumber;
			if (Game::head ==Game::tail)
			{
				Game::empty = false;
			}
		}
		flag = 0;
	}
	else if (event.type == sf::Event::EventType::KeyReleased)
	{
		flag = 1;
	}

}

bool ObjectManager::FullOrEmpty(int i)
{
	static int flag = 0;
	if (Game::empty == true && i != Game::head)
	{
		return true;
	}
	else if (Game::empty == false && flag == 0)//when empty == false,i==tail==head
	{
		flag = 1;
		return true;
	}
	//deal with empty==true && i==head and empty==false
	else if (flag == 1)
	{
		if (i == Game::head)//i should meet head twice
		{
			flag = 0;
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}