#ifndef LIFE_BAR_H_
#define LIFE_BAR_H_

#include "Frame.h"

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Director;
class Item;
class LifeBar{
	private:
		Frame frame[2]; //0 bg, 1 fg
	public:
		LifeBar(){}
		void set_from_setting(string setting, sf::Vector2f pos);
		void set_life(float life, float max_life);
		void display(sf::RenderWindow *win);
};

#endif
