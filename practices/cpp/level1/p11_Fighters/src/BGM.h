#ifndef BGM_H_
#define BGM_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

class BGM{
	private:
		vector<string> music_name;
		sf::Music music;
		int cur_music;
		int music_num;
		int setting_flag;
	public:
		BGM();
		BGM(string setting);
		void initial();
		void next();
		void load_music_from_file(int x);
		void open_from_setting(string setting);
};

#endif
