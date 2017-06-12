#include "Enemy.h"

Enemy::Enemy(int type, int num, int bullet_num, float scanf):enemy_bullet(bullet_num)
{
	
	this->num = num;
	p = new Plane[num];
	for (int i = 0;i < num;i++) {
		p[i].initialization(type, 0, 0, scanf, scanf);
	}
}

void Enemy::produce()
{
	int b = 1150, a = 20,randnum;
	for (int i = 0;i < num;i++) {
		if (p[i].gety() == 0) {
			randnum = (rand() % (b - a + 1)) + a;
			p[i].move(randnum, 0);
			break;
		}
	}
}

bool Enemy::bingo(sf::FloatRect b, int enemy_life)
{
	sf::FloatRect bullet_boundry;
	for (int i = 0; i < num; i++) {
		if (p[i].getx() != 0) {
			bullet_boundry = p[i].get().getGlobalBounds();
			if (bullet_boundry.intersects(b)) {
				if (p[i].is_bingo() == enemy_life) {
					p[i].bingo_initialization();
					p[i].move(0, 0);
				}
				return true;
			}
		}
	}
	return false;
}

void Enemy::destroy(int i)
{
	p[i].move(0, 0);
}

int Enemy::getx(int No)
{
	return p[No].getx();
}

int Enemy::gety(int No)
{
	return p[No].gety();
}

void Enemy::setspeed(int enemy_speed, int bullet_speed)
{
	this->enemy_speed = enemy_speed;
	enemy_bullet.setspeed(bullet_speed);
}


void Enemy::move(int &time)
{
	int b = num, a = 0, randnum;
	randnum = (rand() % (b - a + 1)) + a;
	for (int i = 0;i < num;i++) {
		if (p[i].getx() != 0) {
			p[i].move(p[i].getx(), p[i].gety() + enemy_speed);
			if (randnum ==time) {
				enemy_bullet.append(p[i].getx(), p[i].gety());
			}
		}
		if (p[i].gety() >= 1000) {
			p[i].move(0, 0);
		}  
	}
	enemy_bullet.move();
}

void Enemy::move(int &time, int boundry_positon)
{
	static int flag=0;
	for (int i = 0; i < num; i++) {
		if (p[i].getx() != 0) {
			if (p[i].gety() < 100) {
				p[i].move(p[i].getx(), p[i].gety() + enemy_speed);
			}
			else {
				if (boundry_positon > p[i].getx()) {
	 		   		p[i].move(p[i].getx() + enemy_speed, 100);
				}
				else if (boundry_positon < p[i].getx()) {
					p[i].move(p[i].getx() - enemy_speed, 100);
				}
				else {
					if (p[i].getx() == p[i + 1].getx()) {
						p[i].move(p[i].getx() - 200, 100 + i * 5);
						p[i+1].move(p[i+1].getx() + 200, 100 + (i+1) * 5);
					}
				}
			}
			if (time%100==0) {
				enemy_bullet.append(p[i].getx(), p[i].gety());
			}
		}
	}
	enemy_bullet.move();
}

sf::Sprite &Enemy::draw_enemy(int i)
{
		return p[i].get();
}

sf::Sprite & Enemy::draw_bullet(int i)
{
	if (enemy_bullet.exist(i)) {
		return enemy_bullet.draw(i);
	}
}

bool Enemy::exist(int i)
{
	if (p[i].getx() != 0) {
		return true;
	}
	return false;
}

bool Enemy::exist_bullet(int i)
{
	if (enemy_bullet.exist(i)) {
		return true;
	}
	return false;
}