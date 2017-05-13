#pragma once
#include "stdafx.h"
class Plane
{
public:
	 int pointX;
	 int pointY;
	 int width;
	sf::Texture image;
	sf::RenderWindow mainWindow;
	Plane(int width, int height, sf::RenderWindow &mainWindow);
	void MoveLeft(sf::RenderWindow &mainWindow);
	void MoveRight(sf::RenderWindow &mainWindow);
	void draw(sf::RenderWindow &mainWindow);
	
};