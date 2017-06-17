#include "stdafx.h"
#include "Quicker_killer.h"

extern int window_width;
extern int window_heigth;
Quicker_killer::Quicker_killer(int order)
{
	filename = "image/rocket.psd";
	if (!image.loadFromFile(filename))
	{
		cout << "quicker plane read failed!";
	}
	sprite.setTexture(image);
	width = image.getSize().x;
	height = image.getSize().y;
	//srand((unsigned)time(NULL));
	speed = rand()%20+10;//最小速度是30
	__x=-order*(width/2);
	__y = -window_heigth;

};


int Quicker_killer::get_width()
{
	return width;
}

int Quicker_killer::get_x()
{
	return __x;
}
int Quicker_killer::get_y()
{
	return __y;
}

int Quicker_killer::get_speed()
{
	return speed;
}


Quicker_killer::~Quicker_killer()
{
}
