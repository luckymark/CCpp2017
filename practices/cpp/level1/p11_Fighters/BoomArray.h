#pragma once
#include<SFML/Graphics.hpp>
#include "Picture.h"

class BoomArray
{
public:
	BoomArray(int bum);
	void produce(int i, int position_x, int position_y);
	sf::Sprite get(int No);
	bool exist(int No);
	void initialize(int No,int time);
private:
	Picture *b;
	int num;
};