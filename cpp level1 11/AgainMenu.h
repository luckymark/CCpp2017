#pragma once
#include "stdafx.h"
#include "Menu.h"
class AgainMenu :public Menu
{
public:
	sf::Texture image;
	AgainMenu();
	void Draw();
	void Choose();
};
