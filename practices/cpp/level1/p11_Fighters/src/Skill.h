#ifndef SKILL_H_
#define SKILL_H_
#include "Buff.h"

struct Skill{
	Buff buff;
	Buff cost;
	int during_flag;
	float cooling_time;
	float power_ratio_percentage;
	sf::Clock clock;
	Skill();
       	void set(Buff buff, Buff cost, float cooling_time);
	void use();
	int is_ready();
};


#endif
