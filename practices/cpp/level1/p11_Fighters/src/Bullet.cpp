#include "Bullet.h"

Bullet::Bullet(int kind, string item_setting, string bullet_setting):Item(kind,item_setting){
	memset(max_speed,0,sizeof(max_speed));
	memset(acceleration,0,sizeof(acceleration));
	aim = sf::Vector2f(0,0);
	sound_flag = 0;

	set_bullet_from_setting(bullet_setting);
}
Bullet::Bullet(int kind, string item_setting, string bullet_setting, sf::Vector2f pos):Item(kind, item_setting, pos){
	memset(max_speed,0,sizeof(max_speed));
	memset(acceleration,0,sizeof(acceleration));
	aim = sf::Vector2f(0,0);
	sound_flag = 0;

	set_bullet_from_setting(bullet_setting);
}

void Bullet::set_bullet_from_setting(string bullet_setting){
	FILE *in = fopen(bullet_setting.c_str(), "r");
	for(int i = 0; i < 2; i++){
		fscanf(in," %f%f",&max_speed[i],&acceleration[i]);
	}
	fclose(in);
}

int Bullet::is_dead(){
	return dead_flag;
}

void Bullet::be_impacted_from(Item *other){
	animation[cur_animation].set_core_position(position);
	animation[cur_animation].be_affected(other -> get_cur_animation());
	if(other -> get_kind() == 2){//Room
		if(!animation[cur_animation].is_affect()){
			if(cur_animation == 0){
				cur_animation = 1;
				sound_flag = 0;
				animation[cur_animation].initlize();
				animation[cur_animation].set_play_flag(1);
				animation[cur_animation].set_max_speed(0);
				animation[cur_animation].set_acceleration(sf::Vector2f(0,0));
			}
		}
	}
	/*if(animation[cur_animation].is_affect()){
		cur_animation = 1;
		animation[cur_animation].set_core_position(position);
		animation[cur_animation].set_max_speed(0);
		animation[cur_animation].set_acceleration(sf::Vector2f(0,0));
		animation[cur_animation].set_play_flag(1);
	}*/
}

int Bullet::has_request(){
	return request_flag;
}

int Bullet::get_request(){
	return request;
}

void Bullet::Action(sf::Time dt, sf::Vector2f pos){
	animation[cur_animation].set_core_position(position);
	next(dt);
	if(cur_animation == 1){
		if(sound_flag){
			animation[cur_animation].set_sound_flag(0);
		}else {
			animation[cur_animation].set_play_flag(1);
		}
		if(animation[cur_animation].is_playing() == 0){
			dead_flag = 1;
			request = -1;
			request_flag = 0;
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
		animation[cur_animation].set_speed(speed);
		animation[cur_animation].set_max_speed(max_speed[0]);
		animation[cur_animation].set_acceleration(direction * acceleration[cur_animation]);
		animation[cur_animation].set_stop_ratio(1);
		sound_flag = 1;
	}
}


