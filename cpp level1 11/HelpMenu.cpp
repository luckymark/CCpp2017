#include "stdafx.h"
#include "HelpMenu.h"
#include "StartMenu.h"
extern sf::RenderWindow mainWindow;
HelpMenu::HelpMenu()
{
	if (image.loadFromFile("images/help.png") != true)
	{
		return;
	}
}

void HelpMenu::Draw()
{
	sf::Sprite sprite(image);
	sprite.setOrigin(0, 0);
	mainWindow.draw(sprite);
}
void HelpMenu::Choose()
{
	sf::Event event;
	while (1)
	{
		mainWindow.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed)
		{
			int x = event.mouseButton.x;
			int y = event.mouseButton.y;
			if (x > 475 && x < 777&&y>548&&y<623)
			{
				StartMenu::number = 0;
				return;
			}
		}
	}
}