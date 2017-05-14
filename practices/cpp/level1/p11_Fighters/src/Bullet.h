#ifndef BULLET_H_
#define BULLET_H_

#include "Item.h"

class Bullet: public Item{
	private:
		float 		max_speed[2];
		float 		acceleration[2];
		sf::Vector2f 	aim;
		int 		sound_flag;
	public:
		Bullet(int kind, string item_setting, string bullet_setting);
		Bullet(int kind, string item_setting, string bullet_setting, sf::Vector2f pos);
		void set_bullet_from_setting(string bullet_setting);
		virtual int is_dead();
		virtual int has_request();
		virtual int get_request();
		virtual void be_impacted_from(Item *other);
		virtual void Action(sf::Time dt, sf::Vector2f pos);
};


#endif
