#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include "Item.h"

#include <vector>
#include <string>
using namespace std;

class Director{
	private:
		vector<Item*>  		stuff;

		vector<string> 		sample;
		vector<int>		sample_type;

		sf::RenderWindow 	window;
		sf::Clock		clock;
		sf::Event		event;

		sf::Vector2f		player_position;
		int 			player_key;

	public:
		Director();
		void set_world(string setting);
		void world_loop();
		void main_loop();
		void new_stuff(int x,sf::Vector2f place, sf::Vector2f dir);
		void clean_stuff();
		void clear_request();
		void update_player_position();
		int get_player_key();
		~Director();
};

#endif
