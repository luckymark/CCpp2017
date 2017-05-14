#include "Item.h"
Item::Item(int kind, string item_setting_name){
	toward = 0;
	cur_animation = 0;
	item_kind = kind;
	position.x = position.y = 0.0;
	get_setting(item_setting_name);
}
Item::Item(int kind, string item_setting_name, sf::Vector2f pos){
	toward = 0;
	cur_animation = 0;
	item_kind = kind;
	position = pos;
	get_setting(item_setting_name);
}
Item::Item(int kind, string item_setting_name, sf::Vector2f pos, int dir){
	toward = 0;
	cur_animation = 0;
	item_kind = kind;
	position = pos;
	get_setting(item_setting_name);
	set_toward(dir);
}

int Item::get_toward(){
	return toward;
}

void Item::stop(){
	animation[cur_animation].set_stop_ratio(stop_ratio);
	animation[cur_animation].set_play_flag(0);
}

int Item::get_kind(){
	return item_kind;
}

Animation* Item::get_current_animation(){
	return animation + cur_animation;
}

sf::Vector2f Item::get_speed(){
	return speed;
}

void Item::update_speed(){
	speed = animation[cur_animation].get_speed();
}

void Item::set_position(sf::Vector2f pos){
	position = pos;
	animation[cur_animation].set_core_position(pos);
}

void Item::get_setting(string item_setting_name){
	FILE *in = fopen(item_setting_name.c_str(), "r");

	fscanf(in," %d", &animation_num);
	if(animation != NULL){
		delete[] animation;
	}
	animation = new Animation[animation_num];

	char tmp[1005];
	for(int i = 0; i < animation_num; i++){
		fscanf(in, "%s", tmp);		//image_setting
		animation[i].set_sequence(string(tmp));
		fscanf(in, "%s", tmp);		//audio_setting
		animation[i].set_sound(string(tmp));
		animation[i].update_last_time(); //update the last time of each frame
	}

	fclose(in);
}

void Item::set_toward(int dir){
	toward = dir;
}

void Item::set_stop_ratio(float f){
	stop_ratio = f;
}

sf::Sprite* Item::display(){
	return animation[cur_animation].begin_cur_display();
}

void Item::next(sf::Time dt){
	animation[cur_animation].next_frame(dt);
	update_position();
	update_speed();
}

void Item::update_position(){
	position = animation[cur_animation].get_core_position();
}

Item::~Item(){
	delete[] animation;
}
