#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include "Item.h"
#include "BGM.h"

#include <vector>
#include <string>
using namespace std;

class Director{
	public:
		int 			map_change_flag;
		sf::Vector2f		map_change_dir;
		Item*			new_map;
		int			enemy_exist_flag;

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
		void deal_with_window_event();
		int get_player_key();
		void basic_work();
		void draw();
		int map_change_checker();
		void map_change_process();
		void update_enemy_exist_flag();
		~Director();
};

#endif
