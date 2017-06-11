#include "CG.h"
#include "Director.h"

CG::CG(int kind, string item_setting_name, sf::Vector2f pos, Director *world_)
	:Item(){ 
		item_kind = kind;
		physics.set_position(pos);
		world = world_;
		clock.restart();
		animation = NULL;
		get_setting(item_setting_name);
		animation[cur_animation].set_play_flag(1);
	}

void CG::dead(){
	world -> new_stuff(8,sf::Vector2f(0,0));
	world -> delete_stuff(this);
}

void CG::Action(sf::Time dt, sf::Vector2f pos){
	if(animation[cur_animation].is_playing() == 0 || sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if(clock.getElapsedTime().asSeconds() > 1){
			dead();
			return;
		}
	}
	next(dt);
}

void CG::get_setting(string item_setting_name){
	FILE *in = fopen(item_setting_name.c_str(), "r");

	fscanf(in," %d", &animation_num);
	if(animation != NULL){
		delete[] animation;
		animation = NULL;
	}
	animation = new MusicAnimation[animation_num];
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

void CG::next(sf::Time dt){
	physics.next(dt);
	animation[cur_animation].set_position(physics.get_position());
	animation[cur_animation].next_frame(dt);
}

void CG::display(){
	animation[cur_animation].begin_cur_display(&(world -> window));
}

CG::~CG(){
	if(animation != NULL)
		delete[] animation;
}
