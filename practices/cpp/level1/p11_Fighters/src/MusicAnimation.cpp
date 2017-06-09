#include "MusicAnimation.h"

MusicAnimation::MusicAnimation(){
	sequence.push_back(Frame());
	frame_cnt = frame_num = 0;
	image_file_name.clear();
}

void MusicAnimation::set_position(sf::Vector2f pos){
	position = pos;
	sequence[cur_frame].set_core_position(pos);
}

void MusicAnimation::update_last_time_from_sound(){
	if((long long)image_file_name.size() == 0) {
		cerr << " zero length sequence in Animation.cpp " << endl;
		//exit(0);
		return;
	}
	total_time = sound.getDuration();
	last_time = total_time / (long long)image_file_name.size();
	cerr << sound.getDuration().asSeconds() << endl;
	//last_time *= 0.5f;
}

void MusicAnimation::set_sound(const string &sound_file_name){
	if(!sound.openFromFile(sound_file_name)){
		cerr << "fail to load sound from: " << sound_file_name << endl;
		exit(0);
	}
}

void MusicAnimation::set_sequence(const string &frame_setting_file_name){
	FILE *in = fopen(frame_setting_file_name.c_str(), "r");
	if(in == NULL){
		cerr << "fail to open " << frame_setting_file_name << endl;
		exit(0);
	}
	char image_file_name_[1005];

	fscanf(in,"%d",&frame_num);
	if(frame_num == 0) return;

	for(int i = 0; i < frame_num; i++){
		fscanf(in,"%s",image_file_name_);

		image_file_name.push_back(string(image_file_name_));
	}
	fclose(in);
}

void MusicAnimation::next_frame(sf::Time dt){
	if(play_flag == 0){
		return;
	}
	if(frame_cnt % 10 == 0){
		frame_cnt = frame_num * sound.getPlayingOffset().asSeconds() / total_time.asSeconds();
	}
	if(cur_time.getElapsedTime() + del_time < last_time) return;
	//cerr << (cur_time.getElapsedTime() + del_time).asSeconds() << endl;
	del_time = cur_time.getElapsedTime() + del_time - last_time;
	frame_cnt++;
	if(frame_cnt >= frame_num){
		play_flag = 0;
		sound_flag = 0;
		frame_cnt = 0;
		initlize();
		return;
	}
	sequence[0].set_image(image_file_name[frame_cnt]);

	//cerr << cur_time.restart().asSeconds() << endl;
	//cur_time.restart();
	cur_time.restart();
}

void MusicAnimation::begin_cur_display(sf::RenderWindow  *win){
	if(sound.getStatus() == 0 && sound_flag)sound.play();
	sequence[cur_frame].set_core_position(position);
	if(play_flag){
		sequence[cur_frame].display(win);
	}
}
