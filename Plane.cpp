#include "stdafx.h"
#include "Plane.h"

	Plane::Plane(int width,int height,sf::RenderWindow &mainWindow)
	{
		if (image.loadFromFile("images/plane1.png") != true)
		{
			return ;
		}
		pointX = -width / 2;
		pointY = -height + 100;
		this->width = width;
		draw(mainWindow);
	}



	void Plane::MoveLeft(sf::RenderWindow &mainWindow)
	{
		if (pointX<0)
		{
			pointX = pointX + 30;
			draw(mainWindow);
		
		}
		Sleep(50);
	}
	void Plane::MoveRight(sf::RenderWindow &mainWindow)
	{
		if (pointX>-width+50)
		{
			pointX = pointX - 30;
			draw(mainWindow);	
		}
		Sleep(50);
	}
	void Plane::draw(sf::RenderWindow &mainWindow)
	{
		mainWindow.clear();
		sf::Sprite sprite(image);
		sprite.setOrigin(pointX, pointY);
		mainWindow.draw(sprite);
		mainWindow.display();
		
	}

	

