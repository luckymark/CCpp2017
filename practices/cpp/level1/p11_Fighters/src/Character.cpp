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
				sf::Vector2f tmp_mo = physics.get_motivation();
				if(tagy == 0){
					if(tmp_mo.y < 0) tmp_mo.y *= float(-1);
				}else if(tagy == 2){
					if(tmp_mo.y > 0) tmp_mo.y *= float(-1);
				}
				physics.set_motivation(tmp_mo);
			}
			if(tagx != 1){
				sf::Vector2f tmp_mo = physics.get_motivation();
				if(tagx == 0){
					if(tmp_mo.x < 0) tmp_mo.x *= float(-1);
				}else if(tagx == 2){
					if(tmp_mo.x > 0) tmp_mo.x *= float(-1);
				}
				physics.set_motivation(tmp_mo);
			}
		}
	}else if( other -> get_kind() == type_Bullet){ //Bullet
		if(animation[cur_animation].is_affect() && item_kind == type_Enemy){
			collision(physics, other -> physics);
			if(!(item_kind == type_Player && (cur_animation == 5 || cur_animation == 6))){//
				other -> dead();
			}
		}
	}else if(other -> get_kind() == type_Enemy_bullet){ //Enemy_bullet
		if(animation[cur_animation].is_affect() && item_kind == type_Player){
			collision(physics, other -> physics);
			if(!(item_kind == type_Player && (cur_animation == 5 || cur_animation == 6 || cur_animation == 7))){//
				other -> dead();
			}
		}
	}else if(other -> get_kind() == type_Enemy){
		if(animation[cur_animation].is_affect() && item_kind == type_Player){
			collision(physics, other -> physics);
		}
	}

	//skill 效果
	/*if(item_kind == type_Player){
		if(cur_animation == 5 || cur_animation == 6){
		}
	}*/
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
	//if(!skill[which].is_ready()) return;
	//skill[which].use();
	cur_animation = which;
	animation[cur_animation].initlize();
	animation[cur_animation].set_play_flag(1);
	animation[cur_animation].set_sound_flag(1);
}


Character::~Character(){
	for(int i = 0; i < buff.size(); i++){
		delete buff[i];
	}
}

