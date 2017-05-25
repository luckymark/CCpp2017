#include "bullet.h"

void Bullets::move()
{
	for (int i = 0;i < 100;i++) {
		if (p[i].getx() != 0) {
			p[i].move(p[i].getx(), p[i].gety() - 1);
			if (p[i].gety() == 0) {
				p[i].move(0, 0);
			}
		}	
	}
}

Bullets::Bullets()
{
	for (int i = 0;i < 100;i++) {
		p[i] = Plane(4, 0, 0, 1, 1);
	}
}

void Bullets::append(int x, int y)
{
	for (int i = 0;i < 100;i++) {
		if (p[i].getx() == 0) {
			p[i].move(x, y);
			break;
		}
	}
}

sf::Sprite Bullets::draw(int i)
{
		if (p[i].getx() != 0) {
			return p[i].get();
	}
}

void Bullets::pop()
{
}

bool Bullets::exist(int i)
{
	if (p[i].getx() != 0) {
		return true;
	}
	return false;
}

