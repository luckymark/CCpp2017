#ifndef MUSIC_ANIMATION_H_
#define MUSIC_ANIMATION_H_


#include "Animation.h"
#include <vector>
using namespace std;

class MusicAnimation:public Animation{
	private:
		sf::Music sound;
		//Frame sequence;
		vector<Frame> sequence;
		vector<string> image_file_name;
		vector<string> image_info_flie_name;
		int frame_num;
		int frame_cnt;
		sf::Time del_time;
		sf::Time total_time;
	public:
		MusicAnimation();
		virtual void set_position(sf::Vector2f pos);
		virtual void update_last_time_from_sound();
		virtual void set_sound(const string &sound_file_name);
		virtual void set_sequence(const string &frame_setting_file_name);
		virtual void next_frame(sf::Time dt);
		virtual void begin_cur_display(sf::RenderWindow *win);
};

#endif
