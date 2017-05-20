#ifndef SKILL_H_
#define SKILL_H_
#include "Buff.h"

struct Skill{
	Buff buff;
	Buff cost;
	float power_ratio_percentage;
	Skill();
       	Skill(Buff buff,Buff cost,float power_ratio_percentage);
};


#endif
