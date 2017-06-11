#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "Item.h"
#include "Door.h"

#include <vector>

class Background: public Item{
	private:
		int which;
	public:
		void add_door();
		void add_enemy();
		Background(int kind, string item_setting_name, sf::Vector2f pos,Director *world_, int which);
		virtual void Action(sf::Time dt, sf::Vector2f pos);
		void set_door_from_setting(string setting);
		void set_enemy_from_setting(string setting);
};

#endif
