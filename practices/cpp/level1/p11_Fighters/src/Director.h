#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include "Item.h"

#include <vector>
#include <string>
using namespace std;

class Director{
	private:
		vector<Item*>  		stuff;
		vector<int> 		dead_request;
		vector<sf::Vector2f>	dead_position;

		vector<string> 		sample;
		vector<int>		sample_type;

		sf::RenderWindow 	window;
		sf::Clock		clock;
		sf::Event		event;
	public:
		void set_world(string setting);
		void world_loop();
		void main_loop();
		void new_stuff(int x,sf::Vector2f place);
		void clean_stuff();
		void fill_request();
		~Director();
};

#endif
