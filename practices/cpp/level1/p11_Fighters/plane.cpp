#include "plane.h"
#include <fstream>
#include <cstdlib>
#include<iostream>



Plane::Plane()
{
	positionx = 0;
	positiony = 0;
}

Plane::Plane(int i, int positionx, int positiony, float x, float y)
{
	std::string p;
	switch (i) {
		case 1: {
			p = "plane.jpg";
			break;
		}
		case 2: {
			p = "plane2.jpg";
			break;
		}
		case 3: {
			p = "Xiaoyueyue.jpg";
			break;
		}
		case 4: {
			p = "Fire1.png";
			break;
		}
	}
	/*sf::ContextSettings glsettings;
	glsettings.antialiasingLevel = 1;//上述两行代码保证窗口无法被更改

	sf::RenderWindow window{ sf::VideoMode(1920,1080), "loadFromMemory Example", sf::Style::Titlebar | sf::Style::Close, glsettings };
	*/

	std::ifstream texture{ p, std::ifstream::binary };
	std::vector<char> buffer;
	texture.seekg(0, texture.end);
	const auto length = texture.tellg();
	
	buffer.resize(length); // reserve space
	texture.seekg(0, texture.beg);

	auto start = &*buffer.begin();
	texture.read(start, length);
	texture.close();

	picture.loadFromMemory(&buffer[0], buffer.size());

	plane.setTexture(picture);
	this->positionx = positionx;
	this->positiony = positiony;
	plane.setPosition(positionx, positiony);
	plane.scale(x, y);
}

void Plane::move(int positionx, int positiony)
{
	this->positionx = positionx;
	this->positiony = positiony;
	plane.setPosition(positionx, positiony);
}

void Plane::destroy()
{

}

int Plane::getx()
{
	return positionx;
}

int Plane::gety()
{
	return positiony;
}

sf::Sprite Plane::get()
{
	return plane;
}

