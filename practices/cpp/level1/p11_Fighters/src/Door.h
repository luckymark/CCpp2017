#ifndef DOOR_H_
#define DOOR_H_

#include "Item.h"

class Background;
class Door:public Item{
	private:
		int change_flag;
		sf::Vector2f change_dir;
		int which;
		int next;
	public:
		Door(int kind, string item_setting_name, sf::Vector2f pos, Director *world_, int which_, sf::Vector2f change_dir_);
		void change_map();
		void add_next_map();
		void set_next_map_from_setting(string setting);
		virtual void Action(sf::Time dt, sf::Vector2f pos);
		virtual void be_impacted_from(Item *other);

};

#endif
