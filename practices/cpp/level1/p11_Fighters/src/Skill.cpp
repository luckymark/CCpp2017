#include "Skill.h"

Skill::Skill(){
	buff = cost = Buff();
	power_ratio_percentage = 0;
}
Skill::Skill(Buff buff,Buff cost, float power_ratio_percentage)
	:buff(buff),cost(cost),power_ratio_percentage(power_ratio_percentage){}
