#ifndef CG_H_
#define CG_H_

#include "Item.h"
#include "MusicAnimation.h"

class CG:public Item{
	private:
		MusicAnimation *animation;
	public:
		CG(int kind, string item_setting_name, sf::Vector2f pos, Director *world_);
		virtual void dead();
		virtual void Action(sf::Time dt, sf::Vector2f pos);
		virtual void get_setting(string item_setting_name);
		virtual void next(sf::Time dt);
		virtual void display();
		~CG();
};

#endif
