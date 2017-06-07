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
		this->height = height;
		draw();
	}



	void Plane::MoveLeft(float timeDelta)
	{
		if (pointX<0)
		{
			pointX = pointX +400*timeDelta;
			draw();
		
		}
		
	}
	void Plane::MoveRight(float timeDelta)
	{
		if (pointX>-width+80)
		{
			pointX = pointX -400* timeDelta;
			draw();	
		}
		
	}

	void Plane::MoveUp(float timeDelta)
	{
		if (pointY<0)
		{
			pointY = pointY +400*timeDelta;
			draw();

		}
		
	}

	void Plane::MoveDown(float timeDelta)
	{
		if (pointY>-height + 80)
		{
			pointY = pointY -400*timeDelta;
			draw();

		}
		
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
	float Plane::height = 0;

