#pragma once
#include "stdafx.h"
#include "Menu.h"
class StartMenu:public Menu
{
public:
	static int number;
	sf::Texture image;
	StartMenu();
	void Draw();
	void Choose();
};
