/************************************************************************
 这个类专门用来存储这个世界中不是实物的东西，我们称之为概念。
 Concept
 	Buff
	Prop //道具
	Bag
	Skill
	Life
	Magic

************************************************************************/
#ifndef CONCEPT_H_
#define CONCEPT_H_

#include <iostream>
#include <SFML/Window.hpp>
using namespace std;

struct Buff{
	//0 speed_up;
	//1 speed_up_ratio;
	//2 life_up & attack
	//3 life_grow_speed_up;
	//4 magic_power_up;
	//5 magic_power_grow_speed_up;
	//6 silence_time;
	//7 dizziness_time;

	int w[10];
	sf::Clock clock;
	float duration_time;
};

struct Prop{
	Buff buff;
	int kind;
	int num;
	Prop(){}
	Prop(Buff buff,int num):buff(buff),num(num){}
};

const int max_bag_size = 15;
struct Bag{
	Prop w[max_bag_size];
};

struct Magic{
	int w[3];
	Magic(int x=0,int y=0,int z=0){
		w[0] = x;
		w[1] = y;
		w[2] = z;
	}
	// 0 power
	// 1 power_lim
	// 2 power_grow_speed
};

struct Skill{
	Buff buff;
	int cost;
	float speed;
	float acceleration;
	int which_animation;
	Skill(){}
	Skill(Buff buff,int cost,int speed,int acceleration,int which)
		:buff(buff),cost(cost),speed(speed),acceleration(acceleration),which_animation(which){}
};

#endif
