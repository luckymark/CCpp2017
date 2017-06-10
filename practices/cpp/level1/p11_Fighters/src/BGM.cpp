#include "BGM.h"

BGM::BGM(){
	music_name.clear();
	cur_music = 0;
	setting_flag = 0;
}

void BGM::open_from_setting(string setting){
	setting_flag = 1;
	FILE *in = fopen(setting.c_str(), "r");
	if(in == NULL){
		cerr << "fail to open setting in BGM.cpp" << endl;
		exit(0);
	}
	char tmp[1005];
	while(fscanf(in,"%s",tmp) != EOF){
		music_name.push_back(string(tmp));
	}
	music_num = music_name.size();
	initial();
}

BGM::BGM(string setting){
	music_name.clear();
	setting_flag = cur_music = 0;
	open_from_setting(setting);
}

void BGM::initial(){
	load_music_from_file(0);
}


void BGM::next(){
	if(setting_flag == 0) return;
	if(music.getStatus() == 0){
		cur_music = (cur_music + 1) % music_num;
		load_music_from_file(cur_music);
	}
}

void BGM::load_music_from_file(int x){
	if(!music.openFromFile(music_name[x])){
		cerr << "fail to open music in BGM.cpp" << endl;
		exit(0);
	}
	music.play();
}
