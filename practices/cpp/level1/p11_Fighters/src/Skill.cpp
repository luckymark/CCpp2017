#include "Skill.h"

Skill::Skill(){
	buff = cost = Buff();
	cooling_time = 0;
	during_flag = 0;
	clock.restart();
}
void Skill::set(Buff buff_,Buff cost_, float cooling_time_){
	buff = buff_;
	cost = cost_;
	cooling_time = cooling_time_;
	clock.restart();
}
int Skill::is_ready(){
	return clock.getElapsedTime().asSeconds() > cooling_time;
}
void Skill::use(){
	if(is_ready()){
		clock.restart();
	}
}
