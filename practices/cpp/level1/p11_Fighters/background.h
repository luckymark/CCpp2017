#pragma once
#include"Picture.h"

class Background
{
public:
	Background(int type);
	void move();
	sf::Sprite draw();
private:
	Picture background;
	int type;
	int No = 0;
};