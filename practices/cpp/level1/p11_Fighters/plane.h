#pragma once
#include <SFML/Graphics.hpp>

class Plane
{
public:
	Plane();
	Plane(int i, int positionx, int positiony, float x, float y);
	void initialization(int i, int positionx,int positiony,float x, float y);
	void move(int positionx, int positiony);
	bool Isdestroy(sf::FloatRect boundry);
	int getx();
	int gety();
	sf::Sprite &get();
	sf::Texture &gettexture();
	void copy(Plane another);
	void destroy();
	void setspeed(int speed);
	void bingo_initialization();
	int is_bingo();
private:
	int positionx, positiony;
	sf::Texture picture;
	sf::Sprite plane;
	int speed;
	int bingo = 0;
};