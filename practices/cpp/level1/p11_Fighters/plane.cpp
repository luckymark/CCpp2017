#include "plane.h"

Plane::Plane()
{
	positionx = 0;
	positiony = 0;
}

void Plane::initialization(int i, int positionx, int positiony, float x, float y)
{
	switch (i) {
		case 1: {
			picture.loadFromFile("plane.jpg");
			break;
		}
		case 2: {
			picture.loadFromFile("enemy1.png");
			break;
		}
		case 3: {
			picture.loadFromFile("myplane1.png");
			break;
		}
		case 4: {
			picture.loadFromFile("Fire1.png");
			break;
		}
		case 5: {
			picture.loadFromFile("enemy4.png");
			break;
		}
	}


	plane.setTexture(picture);
	this->positionx = positionx;
	this->positiony = positiony;
	plane.setPosition(positionx, positiony);
	plane.scale(x, y);
}

Plane::Plane(int i, int positionx, int positiony, float x, float y)
{
	switch (i) {
		case 1: {
			picture.loadFromFile("plane.jpg");
			break;
		}
		case 2: {
			picture.loadFromFile("enemy1.png");
			break;
		}
		case 3: {
			picture.loadFromFile("myplane1.png");
			break;
		}
		case 4: {
			picture.loadFromFile("Fire1.png");
			break;
		}
		case 5: {
			picture.loadFromFile("enemy4.jpg");
			break;
		}
	}
	

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

bool Plane::Isdestroy(sf::FloatRect boundry)
{
	sf::FloatRect boundingBox = plane.getGlobalBounds();
	if (boundingBox.intersects(boundry))
	{
		return true;
	}
	return false;
}

int Plane::getx()
{
	return positionx;
}

int Plane::gety()
{
	return positiony;
}

sf::Sprite &Plane::get()
{
	return plane;
}

sf::Texture &Plane::gettexture()
{
	return picture;
}

void Plane::copy(Plane another)
{
	this->picture = another.gettexture();
	plane.setTexture(picture);
	this->positionx = another.getx();
	this->positiony = another.gety();
}

void Plane::destroy()
{
	plane.move(0, 0);
}

void Plane::setspeed(int speed)
{
	this->speed = speed;
}

void Plane::bingo_initialization()
{
	bingo = 0;
}

int Plane::is_bingo()
{
	bingo += 1;
	return bingo;
}
