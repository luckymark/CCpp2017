#include "background.h"


Background::Background(int type)
{
	this->type = type;
	background.produce(7, 0, 0);
}

void Background::move()
{
	background.produce(0, 3070-1080-No);
	No += 1;
	if (No >= 910)No = 0;
}

sf::Sprite Background::draw()
{
	return background.get();
}
