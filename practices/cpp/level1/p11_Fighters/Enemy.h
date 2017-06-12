#pragma once
#include"plane.h"
#include"bullet.h"
#include<time.h>

class Enemy
{
public:
	Enemy(int type, int num, int bullet_num, float scanf);
	void produce();
	bool bingo(sf::FloatRect b, int enemy_life);
	void move(int &time);
	void move(int &time, int boundry_positon);
	void move2(int &time, int boundry_positon);
	sf::Sprite &draw_enemy(int i);
	sf::Sprite &draw_bullet(int i);
	bool exist(int i);
	bool exist_bullet(int i);
	void destroy(int i);
	int getx(int No);
	int gety(int No);
	void setspeed(int enemy_speed, int bullet_speed);
private:
	Plane *p;
	int num;
	Bullets enemy_bullet;
	int enemy_speed;
};