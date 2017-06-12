#include "bullet.h"

void Bullets::move()
{
	for (int i = 0;i < num;i++) {
		if (p[i].getx() != 0) {
			p[i].move(p[i].getx(), p[i].gety() - speed);
			if ((p[i].gety() <= 0)||(p[i].gety()>=1000)) {
				p[i].move(0, 0);
			}
		}	
	}
}


void Bullets::setpoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Bullets::append2(int x, int y)
{
	int flag = 0;
	for (int i = 0; i < num; i++) {
		if (p[i].getx() == 0) {
			flag += 1;
			p[i].move(x + 10, y + 10);
			if (flag == 10)break;
		}
	}
}

Bullets::Bullets(int num)
{
	this->num = num;
	p = new Plane[num];
	for (int i = 0;i < num;i++) {
		p[i].initialization(4, 0, 0, 1, 1);
	}
	speed = 1;
}

void Bullets::append(int x, int y)
{
	for (int i = 0;i < num;i++) {
		if (p[i].getx() == 0) {
			p[i].move(x+10, y+10);
			break;
		}
	}
}

sf::Sprite &Bullets::draw(int i)
{
	return p[i].get();
}

void Bullets::destroy(int No)
{
	p[No].move(0, 0);
}

bool Bullets::exist(int i)
{
	if (p[i].getx() != 0) {
		return true;
	}
	return false;
}

int Bullets::getx(int No)
{
	return p[No].getx();
}

int Bullets::gety(int No)
{
	return p[No].gety();
}

void Bullets::setspeed(int speed)
{
	this->speed = speed;
}