#include "Bullet.h"
#include "Director.h"
#include "PureAnimationItem.h"

Bullet::Bullet(int kind, string setting,sf::Vector2f pos,Director *world):Item(kind, setting, pos,world){
	sound_flag = 0;
}

void Bullet::be_impacted_from(Item *other){
	animation[cur_animation].set_position(physics.get_position());
	animation[cur_animation].be_affected(other -> get_cur_animation());
	if(other -> get_kind() == 2){//Room
		if(!animation[cur_animation].is_affect()){
			dead();
		}
	}else if(other -> get_kind() == 3){ // enemy
		if(animation[cur_animation].is_affect()){
			dead();
		}
	}
}

void Bullet::Action(sf::Time dt, sf::Vector2f pos){
	animation[cur_animation].set_position(physics.get_position());
	next(dt);
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

void Bullet::dead(){
	Item *tmp = NULL;
	tmp = new PureAnimationItem( world -> sample_type[4], world -> sample[4], physics.get_position(), world, 1);
	if(tmp == NULL){
		cerr << "fail to get mem" << endl;
		exit(0);
	}
	world -> stuff.push_back(tmp);
	world -> delete_stuff(this);
}
