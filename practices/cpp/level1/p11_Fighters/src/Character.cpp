#include "Item.h"
//#include "Animation.h"

Character::Character(int kind, string name, string character_setting):Item(kind,name){
	set_character_from_setting(character_setting);
}
Character::Character(int kind, string name, string character_setting, sf::Vector2f pos):Item(kind,name,pos){
	set_character_from_setting(character_setting);
}
Character::Character(int kind, string name, string character_setting, sf::Vector2f pos, int dir)
	:Item(kind,name,pos,dir){
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
	for(int i = 0; i < max_skill_num; i++){
		if(buff[i] == NULL){
			buff[i] = new Buff;
			(*buff[i]) = bf;
			buff[i] -> clock.restart();
			return;
		}
	}
	cerr << "buff pos run out" << endl;
}

void Character::clear_buff(){
	for(int i = 0; i < max_skill_num; i++){
		if(buff[i] != NULL){
			sf::Time dur_time = buff[i] -> clock.getElapsedTime();
			if(dur_time.asSeconds() > (buff[i] -> duration_time)){
				delete buff[i];
				buff[i] = NULL;
			}

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
		animation[cur_animation].set_acceleration(
			sf::Vector2f(skill[which].acceleration * dirx[toward],skill[which].acceleration * diry[toward]));
		return;
	}
	cur_animation = skill[which].which_animation;
	animation[cur_animation].set_speed(speed);
	//animation[cur_animation].initlize();
	animation[cur_animation].set_core_position(position);
	animation[cur_animation].set_max_speed(skill[which].speed);
	animation[cur_animation].set_acceleration(
			sf::Vector2f(skill[which].acceleration * dirx[toward],skill[which].acceleration * diry[toward]));
	animation[cur_animation].set_stop_ratio(1);
}

void Character::control(char key){
	switch(key){
		case 's': use_skill(0); break;
	 	case 'w': use_skill(1); break;		 
		case 'a': use_skill(2); break;
		case 'd': use_skill(3); break;
	}
}

Character::~Character(){
	for(int i = 0; i < max_skill_num; i++){
		if(buff[i] != NULL){
			delete buff[i];
		}
	}
}
