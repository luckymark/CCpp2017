#ifndef ANIMATION_H_
#define ANIMATION_H_


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Frame.h"
#include "Concept.h"

#include <string>
#include <utility>
using namespace std;

class Animation{
	private:
		vector<Frame> 		sequence;	
							
							

		sf::SoundBuffer 	sound_buffer;	
		sf::Sound		sound;		

		sf::Time		last_time;	
		sf::Clock		cur_time;	

		int 			play_flag;	
		int 			cur_frame;	

		sf::Vector2f		position;	

		int 			affect_flag;
		int 			sound_flag;
	public:
		Animation();

		int is_playing();				
		void initlize();				
		void next_frame(sf::Time dt);			
								

		sf::Sprite* begin_cur_display();		
								


		void be_affected(Animation *other);		


		void set_sound(const string &sound_file_name);	
		void set_sequence(const string &frame_setting_file_name); 
								
		void update_last_time_from_sound();			
		void set_position(sf::Vector2f pos);	
		void set_play_flag(int f);			
		void set_sound_flag(int f);			
		void set_length(int key, sf::Vector2f len);

		int is_affect();


		~Animation(){}

};



#endif
