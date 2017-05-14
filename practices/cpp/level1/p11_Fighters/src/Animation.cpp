#include "Animation.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

void Animation::set_stop_ratio(float f){
	stop_ratio = f;
}
Animation::Animation( string frame_setting_file_name, string sound_file_name){
	play_flag = 0;
	cur_frame = 0;

	set_sound(sound_file_name); 		
	set_sequence(frame_setting_file_name);
	update_last_time();
}

void Animation::set_sound(const string &sound_file_name){
	if(!sound_buffer.loadFromFile(sound_file_name)){
		cerr << "fail to load sound from: " << sound_file_name << endl;
		exit(0);
	}
	sound.setBuffer(sound_buffer);
}

void Animation::set_sequence(const string &frame_setting_file_name){
	FILE *in = fopen(frame_setting_file_name.c_str(), "r");
	sequence.clear();
	char image_file_name[1005];
	char image_info_file_name[1005];

	while(fscanf(in,"%s",image_file_name) != EOF){
		fscanf(in,"%s",image_info_file_name);
		sequence.push_back(Frame());
	}
	fclose(in);

	in = fopen(frame_setting_file_name.c_str(), "r");
	for(int i = 0; i < sequence.size(); i++){
		fscanf(in,"%s",image_file_name);
		fscanf(in,"%s",image_info_file_name);

		sequence[i].set_image(string(image_file_name));
		sequence[i].set_image_info(string(image_info_file_name));
	}
	fclose(in);
}

void Animation::update_last_time(){
	last_time = sound_buffer.getDuration() / (long long)sequence.size();
}

int Animation::is_playing(){
	return play_flag;
}

void Animation::initlize(){
	cur_frame = 0;
	sound.stop(); 	// reset the play position
}

float length2(sf::Vector2f vec){

	return vec.x*vec.x + vec.y*vec.y;
}

void Animation::set_max_speed(float sp){
	max_speed = sp;
}

void Animation::next_frame(sf::Time dt){
	core_position += speed * dt.asSeconds();
	speed += acceleration * dt.asSeconds();

	if(length2(speed) > max_speed){
		speed *= max_speed / length2(speed);
	}
	if(play_flag == 0){ 			//当没有按键的事件的时候，就慢慢停下来
		acceleration = sf::Vector2f(0,0);
		speed *= stop_ratio;
	}


	if(cur_time.getElapsedTime() < last_time) return;
	cur_frame++;
	if(cur_frame >= sequence.size()){
		//play_flag = 0;
		cur_frame = 0;
		initlize();
		return;
	}
	//sound.stop();
	//sound.setPlayingOffset(last_time * (long long)cur_frame);
	cur_time.restart();
}

sf::Vector2f Animation::get_speed(){
	return speed;
}

void Animation::set_acceleration(sf::Vector2f ac){
	acceleration = ac;
}

void Animation::set_speed(sf::Vector2f sp){
	speed = sp;
}

sf::Sprite* Animation::begin_cur_display(){
	if(sound.getStatus() == 0)sound.play();
	sequence[cur_frame].set_core_position(core_position);
	return sequence[cur_frame].display();
}

void Animation::end_cur_display(){
	//sound.pause();
	//sound.setPlayingOffset(last_time * (long long)cur_frame);
}

void Animation::set_core_position(sf::Vector2f pos){
	core_position = pos;
}

void Animation::set_play_flag(int f){
	play_flag = f;
}

sf::Vector2f Animation::get_core_position(){
	return core_position;
}

