#pragma once
#include"Text.h"

class StartText
{
public:
	StartText();
	sf::Text draw(int i);
	void change(int i,int j);
private:
	Text a[3];
};