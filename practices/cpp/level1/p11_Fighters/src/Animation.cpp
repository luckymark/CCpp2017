#include "Animation.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

Animation::Animation(){
	sequence.clear();
	cur_time.restart();
	last_time = cur_time.getElapsedTime();
	play_flag = 0;
	cur_frame = 0;
	position = sf::Vector2f(0,0);
	affect_flag = 0;
	sound_flag = 1;
}

void Animation::set_sound_flag(int f){
	sound_flag = f;
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
	if(in == NULL){
		cerr << "fail to open " << frame_setting_file_name << endl;
		exit(0);
	}
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

void Animation::update_last_time_from_sound(){
	if((long long)sequence.size() == 0) {
		cerr << " zero length sequence in Animation.cpp " << endl;
		exit(0);
	}
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

	return vec.x*vec.x + vec.y*vec.y + 0.01;
}

void Animation::next_frame(sf::Time dt){

	if(cur_time.getElapsedTime() < last_time) return;
	cur_frame++;
	if(cur_frame >= sequence.size()){
		play_flag = 0;
		cur_frame = 0;
		initlize();
		return;
	}
	cur_time.restart();
}

void Animation::set_length(int key,sf::Vector2f len){
	sequence[key].set_length(len);
}

sf::Sprite* Animation::begin_cur_display(){
	if(sound.getStatus() == 0 && sound_flag)sound.play();
	sequence[cur_frame].set_core_position(position);
	return sequence[cur_frame].display();
}

void Animation::set_position(sf::Vector2f pos){
	position = pos;
	sequence[cur_frame].set_core_position(pos);
}

void Animation::set_play_flag(int f){
	play_flag = f;
}

void Animation::be_affected(Animation *other){
	int flag = sequence[cur_frame].is_in(&(other -> sequence[other -> cur_frame]));
	flag |= other -> sequence[other -> cur_frame].is_in(&(sequence[cur_frame]));
	affect_flag = flag;
}

int Animation::is_affect(){
	return affect_flag;
}
