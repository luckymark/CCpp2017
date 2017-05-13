// 飞机.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <SFML/Graphics.hpp>                                                 。  
#include "windows.h"
#include "Plane.h"
#define width 1024
#define height 770
static sf::RenderWindow mainWindow;
int main()
{
	
	mainWindow.create(sf::VideoMode(width,height , 32), "PlaneGame!");
	Plane plane(width,height,mainWindow);

	
	Sleep(1000);
	
	while (1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			plane.MoveLeft(mainWindow);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			plane.MoveRight(mainWindow);
		}
	}

	//sf::Music music;
	//if (!music.openFromFile("sound/game_music.ogg"))
	//	return EXIT_FAILURE;
	//// Play the music
	//music.play();

	system("pause");
	return 0;
}