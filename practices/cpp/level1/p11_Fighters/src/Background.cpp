#include "Background.h"
#include "Director.h"
#include "Enemy.h"

Background::Background(int kind, string item_setting_name, sf::Vector2f pos,Director *world_, int which_)
	:Item(kind, item_setting_name, pos, world_){
		which = which_;
		physics.set_position(pos);
		add_door();
		add_enemy();
       	}

void Background::add_door(){
	char tmp[1005];
	sprintf(tmp,"../data/Background/door/%d/setting", which);
	set_door_from_setting(string(tmp));
}

void Background::set_door_from_setting(string setting){
	FILE *in = fopen(setting.c_str(), "r");
	if(in == NULL){
		cerr << "fail to open the file in Background.cpp" << endl;
		exit(0);
	}
	int whi;
	int k;
	float x,y;
	float x1,y1;
	while(fscanf(in,"%d%d%f%f%f%f",&whi,&k,&x,&y,&x1,&y1) != EOF){
		Item *tmp = new Door(world -> sample_type[type_Door], world -> sample[type_Door], sf::Vector2f(x,y) + physics.get_position(), world, whi, sf::Vector2f(x1,y1));
		tmp -> set_animation(k);
		if(tmp == NULL){
			cerr << "fail to get the memmory in Background.cpp" << endl;
			exit(0);
		}
		world -> stuff.push_back(tmp);
	}
	fclose(in);
}

void Background::Action(sf::Time dt, sf::Vector2f pos){
	next(dt);
	animation[cur_animation].set_play_flag(1);
}

void Background::add_enemy(){
	char tmp[1005];
	sprintf(tmp,"../data/Background/enemy/%d/setting", which);
	set_enemy_from_setting(string(tmp));
}

void Background::set_enemy_from_setting(string setting){
	FILE *in = fopen(setting.c_str(), "r");
	if(in == NULL){
		cerr << "fail to open the file in Background.cpp" << endl;
		exit(0);
	}
	int k;
	float x,y;
	while(fscanf(in,"%d%f%f",&k,&x,&y) != EOF){
		Item *tmp = new Enemy(world -> sample_type[k],world -> sample[k], sf::Vector2f(x,y) + physics.get_position(), world);
		tmp -> physics.set_motivation(sf::Vector2f(0,0));
		if(tmp == NULL){
			cerr << "fail to get the memmory in Background.cpp" << endl;
			exit(0);
		}
		world -> stuff.push_back(tmp);
	}
	fclose(in);
}
