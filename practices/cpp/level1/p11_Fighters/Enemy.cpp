#include "Enemy.h"
#include<stdlib.h>
#include<time.h>

Enemy::Enemy(int type, int num, int scanf)
{
	this->num = num;
	p = new Plane[num];
	for (int i = 0;i < num;i++) {
		p[i] = Plane(type, 0, 0, scanf, scanf);
	}
}

void Enemy::produce()
{
	int b = 1800, a = 10,randnum;
	for (int i = 0;i < num;i++) {
		if (p[i].gety() == 0) {
			randnum = (rand() % (b - a + 1)) + a;
			p[i].move(randnum, 0);
			break;
		}
	}
}

void Enemy::destroy()
{
}


void Enemy::move()
{
	for (int i = 0;i < num;i++) {
		if (p[i].getx() != 0) {
			p[i].move(p[i].getx(), p[i].gety() + 1);
		}
		if (p[i].gety() == 1000) {
			p[i].move(0, 0);
		}
	}
}

sf::Sprite Enemy::draw(int i)
{
	if (p[i].getx() != 0) {
		return p[i].get();
	}
}

bool Enemy::exist(int i)
{
	if (p[i].getx() != 0) {
		return true;
	}
	return false;
}

