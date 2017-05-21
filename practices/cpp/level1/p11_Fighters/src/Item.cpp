#include "Item.h"
#include "Director.h"

void Item::dead(){
	world -> delete_stuff(this);
}

Animation* Item::get_cur_animation(){
	return &animation[cur_animation];
}

void Item::set_speed(sf::Vector2f sp){
	physics.set_speed(sp);
}
sf::Vector2f Item::get_position(){
	return physics.get_position();
}
Item::Item(int kind, string item_setting_name, sf::Vector2f pos, Director *world_){
	item_kind = 0;
	animation = NULL;
	animation_num = 0;
	cur_animation = 0;
	world = NULL;

	item_kind = kind;
	physics.set_position(pos);
	world = world_;

	get_setting(item_setting_name);
}

int Item::get_kind(){
	return item_kind;
}

Animation* Item::get_current_animation(){
	return animation + cur_animation;
}

sf::Vector2f Item::get_speed(){
	return physics.get_speed();
}


void Item::set_position(sf::Vector2f pos){
	physics.set_position(pos);
	animation[cur_animation].set_position(pos);
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
		fscanf(in, "%s ", tmp);		//image_setting
		animation[i].set_sequence(string(tmp));
		fscanf(in, "%s ", tmp);		//audio_setting
		animation[i].set_sound(string(tmp));
		animation[i].update_last_time_from_sound(); //update the last time of each frame
	}

	for(int i = 0; i < 3; i++)
		if(fscanf(in, " %d",&life.w[i]) == EOF){
			cerr << "meet Eof" << endl;
			exit(0);
		}
	for(int i = 0; i < 3; i++)
		if(fscanf(in, " %d",&magic.w[i]) == EOF){
			cerr << "meet EOF" << endl;
			exit(0);
		}

	float mx;
	fscanf(in," %f",&mx);
	physics.set_max_power_ratio(mx);
	fscanf(in," %f",&mx);
	physics.set_mu(mx);
	fscanf(in," %f",&mx);
	physics.set_mass(mx);
	fscanf(in," %f",&mx);
	physics.set_max_force(mx);

	for(int i = 0; i < animation_num; i++){
		fscanf(in, " %f", &skill[i].power_ratio_percentage);
	}

	fclose(in);
}

void Item::add_force_from_skill(int key, sf::Vector2f dir,sf::Time dt){
	physics.add_power_ratio(dir * skill[key].power_ratio_percentage * physics.get_max_power_ratio(),dt);
}

void Item::display(){
	animation[cur_animation].begin_cur_display(&(world -> window));
}

void Item::next(sf::Time dt){
	physics.next(dt);
	animation[cur_animation].set_position(physics.get_position());
	animation[cur_animation].next_frame(dt);
}

Item::~Item(){
	if(animation != NULL)
		delete[] animation;
}
