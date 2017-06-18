#include "stdafx.h"
#include "AgainMenu.h"
#include "StartMenu.h"
#include "StrUpdate.h"
extern sf::RenderWindow mainWindow;
AgainMenu::AgainMenu()
{
	if (image.loadFromFile("images/end.png") != true)
	{
		return;
	}
}

void AgainMenu::Draw()
{
	sf::Sprite sprite(image);
	sprite.setOrigin(0, 0);
	mainWindow.draw(sprite);
}
void AgainMenu::Choose()
{
	sf::Event event;
	while (1)
	{
		mainWindow.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed)
		{
			int x = event.mouseButton.x;
			int y = event.mouseButton.y;
			if (x > 334 && x < 900 && y>308 && y<442)
			{
				StartMenu::number = 0;
				StrUpdate::life = 40;
				StrUpdate::score = 0;
				return;
			}
			else if ((x > 530 && x <744 && y>500 && y<600))
			{
				StartMenu::number = 2;
				return;
			}
		}
	}
}