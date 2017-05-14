#include "Item.h"

Animation* Item::get_cur_animation(){
	//return animation + cur_animation;
	return &animation[cur_animation];
}

void Item::set_direction(sf::Vector2f dir){
	direction = dir;
}

sf::Vector2f Item::get_request_direction(){
	return request_direction;
}

void Item::set_speed(sf::Vector2f sp){
	speed = sp;
}
sf::Vector2f Item::get_position(){
	return position;
}
Item::Item(int kind, string item_setting_name){
	toward = 0;
	item_kind = 0;
	animation = NULL;
	animation_num = 0;
	position = sf::Vector2f(0,0);
	speed = sf::Vector2f(0,0);
	stop_ratio = 1;
	cur_animation = 0;
	default_animation = 0;
	is_on_ground = 0;
	dead_flag = 0;
	request = -1;
	request_flag = 0;
	direction = sf::Vector2f(0,0);
	request_direction = sf::Vector2f(0,0);

	item_kind = kind;
	get_setting(item_setting_name);
}
Item::Item(int kind, string item_setting_name, sf::Vector2f pos){
	toward = 0;
	item_kind = 0;
	animation = NULL;
	animation_num = 0;
	position = sf::Vector2f(0,0);
	speed = sf::Vector2f(0,0);
	stop_ratio = 1;
	cur_animation = 0;
	default_animation = 0;
	is_on_ground = 0;
	dead_flag = 0;
	request = -1;
	request_flag = 0;
	direction = sf::Vector2f(0,0);
	request_direction = sf::Vector2f(0,0);

	item_kind = kind;
	request_flag = dead_flag = 0;
	position = pos;
	get_setting(item_setting_name);
}
Item::Item(int kind, string item_setting_name, sf::Vector2f pos, int dir){
	toward = 0;
	item_kind = 0;
	animation = NULL;
	animation_num = 0;
	position = sf::Vector2f(0,0);
	speed = sf::Vector2f(0,0);
	stop_ratio = 1;
	cur_animation = 0;
	default_animation = 0;
	is_on_ground = 0;
	dead_flag = 0;
	request = -1;
	request_flag = 0;
	direction = sf::Vector2f(0,0);
	request_direction = sf::Vector2f(0,0);

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
		animation = NULL;
	}
	animation = new Animation[animation_num];
	if(animation == NULL){
		cerr << "fail to get mem" << endl;
		exit(0);
	}

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
	if(animation != NULL)
		delete[] animation;
}
