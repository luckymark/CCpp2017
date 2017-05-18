#include "Skill.h"

Skill::Skill(){
	cost = Buff();
	speed = 0;
	acceleration = 0;
	which_animation = 0;
}
Skill::Skill(Buff buff,Buff cost,int speed,int acceleration,int which)
	:buff(buff),cost(cost),speed(speed),acceleration(acceleration),which_animation(which){}
