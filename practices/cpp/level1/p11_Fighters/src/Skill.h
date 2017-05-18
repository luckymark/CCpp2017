#ifndef SKILL_H_
#define SKILL_H_
#include "Buff.h"

struct Skill{
	Buff buff;
	Buff cost;
	float speed;
	float acceleration;
	int which_animation;
	Skill();
       	Skill(Buff buff,Buff cost,int speed,int acceleration,int which);
};


#endif
