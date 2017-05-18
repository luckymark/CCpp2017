#include "Character.h"
#include <cmath>

float length(sf::Vector2f a){
	return sqrt(a.x*a.x + a.y*a.y);
}

void Character::set_null(){
	buff.clear();
}

void Character::set_shot_direction(sf::Vector2f pos){
	shot_direction = pos - position;
	if(length(shot_direction) != 0) shot_direction /= length(shot_direction);
}

Character::Character(int kind, string name, string character_setting):Item(kind,name){
	set_null();
	set_character_from_setting(character_setting);
}
Character::Character(int kind, string name, string character_setting, sf::Vector2f pos):Item(kind,name,pos){
	set_null();
	set_character_from_setting(character_setting);
}
Character::Character(int kind, string name, string character_setting, sf::Vector2f pos, int dir)
	:Item(kind,name,pos,dir){
	set_null();
	set_character_from_setting(character_setting);
}

void Character::set_character_from_setting(string character_setting){
	FILE *in = fopen(character_setting.c_str(), "r");

	for(int i = 0; i < 3; i++)
		fscanf(in, " %d",&life.w[i]);
	for(int i = 0; i < 3; i++)
		fscanf(in, " %d",&magic.w[i]);

	for(int i = 0; i < animation_num; i++){
		fscanf(in, " %f%f",&skill[i].speed,&skill[i].acceleration);
		skill[i].which_animation = i;
	}

	float x; fscanf(in," %f", &x);
	set_stop_ratio(x);

	fclose(in);
}

void Character::set_life(int key,int val){
	life.w[key] = val;
}

void Character::set_magic(int key,int val){
	life.w[key] = val;
}

void Character::set_skill(int key, Skill sk){
	skill[key] = sk;
}


void Character::add_buff(Buff bf){
	Buff *tmp = NULL;
	tmp = new Buff;
	if(tmp != NULL){
		*tmp = bf;
		tmp -> clock.restart();
		buff.push_back(tmp);
	}
}

void Character::clear_buff(){
	for(vector<Buff*>::iterator it = buff.begin(); it != buff.end(); ){
		sf::Time dur_time = (*it) -> clock.getElapsedTime();
		if(dur_time.asSeconds() > ((*it) -> duration_time)){
			delete *it;
			it = buff.erase(it);
		}else {
			it++;
		}
	}
}

void Character::use_prop(int key){
	if(bag.w[key].num == 0){
		cerr << "prop run out" << endl;
		return;
	}
	bag.w[key].num--;
	add_buff(bag.w[key].buff);
}


void Character::add_prop(int key, Prop prop){
	if(bag.w[key].kind == prop.kind){
		bag.w[key].num += prop.num;
	}else if(bag.w[key].num == 0){
		bag.w[key] = prop;
	}else if(bag.w[key].kind != prop.kind){
		cerr << "already have something" << endl;
		return;
	}
}

void Character::use_skill(int which){
	animation[cur_animation].set_play_flag(1);
	if(cur_animation == skill[which].which_animation){
		animation[cur_animation].set_play_flag(1);
		animation[cur_animation].set_acceleration(direction * skill[which].acceleration);
		return;
	}
	cur_animation = skill[which].which_animation;
	animation[cur_animation].set_speed(speed);
	animation[cur_animation].set_core_position(position);
	animation[cur_animation].set_max_speed(skill[which].speed);
	animation[cur_animation].set_acceleration(direction * skill[which].acceleration);
	animation[cur_animation].set_stop_ratio(1);
}


Character::~Character(){
	for(int i = 0; i < buff.size(); i++){
		delete buff[i];
	}
}

