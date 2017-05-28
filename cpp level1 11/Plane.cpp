#include "stdafx.h"
#include "Plane.h"
extern sf::RenderWindow mainWindow;

	Plane::Plane(int width,int height)
	{
		if (image.loadFromFile("images/plane1.png") != true)
		{
			return ;
		}
		pointX = -width / 2;
		pointY = -height + 100;
		this->width = width;
		draw();
	}



	void Plane::MoveLeft()
	{
		if (pointX<0)
		{
			pointX = pointX +25;
			draw();
		
		}
		Sleep(50);
	}
	void Plane::MoveRight()
	{
		if (pointX>-width+80)
		{
			pointX = pointX - 25;
			draw();	
		}
		Sleep(50);
	}
	void Plane::draw()
	{
		sf::Sprite sprite(image);
		sprite.setOrigin(pointX, pointY);
		mainWindow.draw(sprite);
	}

	float Plane::pointX = 0;
	float Plane::pointY = 0;
	float Plane::width = 0;

