#include "Door.h"
#include "Director.h"
#include "Background.h"

Door::Door(int kind, string item_setting_name, sf::Vector2f pos, Director *world_, int which_, sf::Vector2f change_dir_)
	:Item(kind, item_setting_name, pos, world_){
		change_flag = 0;
		change_dir = change_dir_;
		which = which_;
	}

void Door::change_map(){
	if(world -> enemy_exist_flag == 1) return;
	world -> map_change_flag = 1;
	world -> map_change_dir = change_dir;
	add_next_map();
}

void Door::add_next_map(){
	char tmp[1005];
	sprintf(tmp,"../data/door/%d/setting", which);
	set_next_map_from_setting(string(tmp));
}

void Door::set_next_map_from_setting(string setting){
	FILE *in = fopen(setting.c_str(), "r");
	if(in == NULL){
		cerr << "fail to open the file in Background.cpp" << endl;
		exit(0);
	}
	int k;
	int next;
	float x,y;
	while(fscanf(in,"%d%d%f%f",&k,&next,&x,&y) != EOF){
		Item *tmp = new Background(world -> sample_type[k],world -> sample[k], sf::Vector2f(x,y), world, next);
		if(tmp == NULL){
			cerr << "fail to get the memmory in Background.cpp" << endl;
			exit(0);
		}
		world -> stuff.push_back(tmp);
		world -> new_map = tmp;
	}
	fclose(in);
}

void Door::Action(sf::Time dt, sf::Vector2f pos){
	Item::next(dt);
	animation[cur_animation].set_play_flag(1);
}

void Door::be_impacted_from(Item *other){
	animation[cur_animation].set_position(physics.get_position());
	animation[cur_animation].be_affected(other -> get_cur_animation());
	if(other -> get_kind() == type_Player){
		if(animation[cur_animation].is_affect()){
			if(world -> enemy_exist_flag == 0){
				other -> physics.set_position(other -> physics.get_position() - change_dir*(float)2);
				other -> physics.set_motivation(sf::Vector2f(0,0));
				change_map();
			}
		}
	}
}
