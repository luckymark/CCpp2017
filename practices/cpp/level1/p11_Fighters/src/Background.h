#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "Item.h"

class Background: public Item{
	public:
		Background(int kind, string item_setting_name, sf::Vector2f pos,Director *world_);
		virtual void Action(sf::Time dt, sf::Vector2f pos);
};

#endif
