#include "Character.h"
#include <cmath>

float length(sf::Vector2f a){
	return sqrt(a.x*a.x + a.y*a.y);
}

void Character::set_null(){
	buff.clear();
}

void Character::be_impacted_from(Item *other){
	animation[cur_animation].set_position(physics.get_position());
	animation[cur_animation].be_affected(other -> get_cur_animation());
	if(other -> get_kind() == type_Room){//Room
		if(!animation[cur_animation].is_affect()){
			int tp = animation[cur_animation].stand_at(other -> get_cur_animation());
			int tagx = tp%3, tagy = tp/3;
			if(tagy != 1){
				physics.turn_motivation_y();
				sf::Vector2f tmp_mo = physics.get_motivation();
				tmp_mo.y *= 0.6;
				physics.set_motivation(tmp_mo);
				if(tagy == 0){
					physics.add_position(sf::Vector2f(0,2));
				}else if(tagy == 2){
					physics.add_position(sf::Vector2f(0,-2));
				}
			}
			if(tagx != 1){
				physics.turn_motivation_x();
				sf::Vector2f tmp_mo = physics.get_motivation();
				tmp_mo.x *= 0.6;
				physics.set_motivation(tmp_mo);
				if(tagx == 0){
					physics.add_position(sf::Vector2f(2,0));
				}else if(tagx == 2){
					physics.add_position(sf::Vector2f(-2,0));
				}
			}
		}
	}else if( other -> get_kind() == type_Bullet){ //Bullet
		if(animation[cur_animation].is_affect() && item_kind == type_Enemy){
			physics.add_motivation(other -> physics.get_motivation());
			other -> dead();
		}
	}
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

