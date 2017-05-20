#ifndef BULLET_H_
#define BULLET_H_

#include "Item.h"

class Bullet: public Item{
	private:
		int sound_flag;
	public:
		Bullet(int kind, string item_setting, sf::Vector2f pos, Director *world);

		virtual int is_dead();
		virtual void be_impacted_from(Item *other);
		virtual void Action(sf::Time dt, sf::Vector2f pos);
};


#endif
