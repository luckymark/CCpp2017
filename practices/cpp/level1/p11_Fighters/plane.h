#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>

class Plane
{
public:
	Plane();
	Plane(int i, int positionx,int positiony,float x, float y);
	void move(int positionx, int positiony);
	void destroy();
	int getx();
	int gety();
	sf::Sprite get();
private:
	int positionx, positiony;
	sf::Texture picture;
	sf::Sprite plane;
};