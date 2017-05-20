#include "Character.h"
#include <cmath>

float length(sf::Vector2f a){
	return sqrt(a.x*a.x + a.y*a.y);
}

void Character::set_null(){
	buff.clear();
}


void Character::set_shot_direction(sf::Vector2f pos){
	shot_direction = pos - physics.get_position();
	if(length(shot_direction) != 0) shot_direction /= length(shot_direction);
}

Character::Character(int kind, string setting, sf::Vector2f pos, Director *world)
	:Item(kind,setting,pos,world){
		set_null();
	}

void Character::use_skill(int which){
	cur_animation = which;
	animation[cur_animation].set_play_flag(1);
}


Character::~Character(){
	for(int i = 0; i < buff.size(); i++){
		delete buff[i];
	}
}

