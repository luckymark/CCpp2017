#include "stdafx.h"
#include "StartMenu.h"
extern sf::RenderWindow mainWindow;
StartMenu::StartMenu()
{
	if (image.loadFromFile("images/start.png") != true)
	{
		return;
	}
}

void StartMenu::Draw()
{
	sf::Sprite sprite(image);
	sprite.setOrigin(0, 0);
	mainWindow.draw(sprite);
}

void StartMenu::Choose()
{
	sf::Event event;
	while (1)
	{
		mainWindow.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed)
		{
			int x = event.mouseButton.x;
			int y =event.mouseButton.y;
			if (x > 575 && x < 740)
			{
				if (y>470 && y < 550)
				{
					number = 0;
					break;
				}
				else if (y>580 && y < 670)
				{
					number = 1;
					break;
				}
				else if (y>670 && y < 800)
				{
					number = 2;
					break;
				}
			}
		}
	}
	
}

int StartMenu::number = -1;