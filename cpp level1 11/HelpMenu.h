#pragma once
#include "stdafx.h"
#include "Menu.h"
class HelpMenu:public Menu
{
public:
	sf::Texture image;
	HelpMenu();
	void Draw();
	void Choose();
};
