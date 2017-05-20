#include "Bullet.h"

Bullet::Bullet(int kind, string setting,sf::Vector2f pos,Director *world):Item(kind, setting, pos,world){
	sound_flag = 0;

}

int Bullet::is_dead(){
	return dead_flag;
}

void Bullet::be_impacted_from(Item *other){
	animation[cur_animation].set_position(physics.get_position());
	animation[cur_animation].be_affected(other -> get_cur_animation());
	if(other -> get_kind() == 2){//Room
		if(!animation[cur_animation].is_affect()){
			if(cur_animation == 0){
				cur_animation = 1;
				sound_flag = 0;
				animation[cur_animation].initlize();
				animation[cur_animation].set_play_flag(1);
			}
		}
	}else if(other -> get_kind() == 3){ // enemy
		if(animation[cur_animation].is_affect()){
			if(cur_animation == 0){
				cur_animation = 1;
				sound_flag = 0;
				animation[cur_animation].initlize();
				animation[cur_animation].set_play_flag(1);
			}
		}
	}
}

void Bullet::Action(sf::Time dt, sf::Vector2f pos){
	animation[cur_animation].set_position(physics.get_position());
	next(dt);
	if(cur_animation == 1){
		if(sound_flag){
			animation[cur_animation].set_sound_flag(0);
		}else {
			animation[cur_animation].set_play_flag(1);
		}
		if(animation[cur_animation].is_playing() == 0){
			dead_flag = 1;
		}
		sound_flag = 1;
	}
	if(cur_animation == 0){
		if(sound_flag){
			animation[cur_animation].set_sound_flag(0);
		}else {
			animation[cur_animation].set_play_flag(1);
		}
		animation[cur_animation].set_play_flag(1);
		sound_flag = 1;
	}
}


