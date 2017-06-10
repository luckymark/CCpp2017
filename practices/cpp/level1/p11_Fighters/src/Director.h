#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include "Item.h"
#include "BGM.h"

#include <vector>
#include <string>
using namespace std;

class Director{
	public:
		sf::RenderWindow 	window;
		sf::Clock		clock;
		sf::Event		event;

		vector<Item*>  		stuff;
		vector<string> 		sample;
		vector<int>		sample_type;
		sf::Vector2f		player_position;
		int 			player_key;
		BGM			bgm;

		Director();
		void set_world(string setting);
		void world_loop();
		void main_loop();
		void new_stuff(int x,sf::Vector2f place);
		void delete_stuff(Item* tmp);
		void clear_request();
		void update_player_position();
		int get_player_key();
		void draw();
		~Director();
};

#endif
