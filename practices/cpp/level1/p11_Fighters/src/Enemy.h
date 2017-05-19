#ifndef ENEMY_H_
#define ENEMY_H_


#include "Character.h"


class Enemy:public Character{
	public:
		Enemy(int		kind, 
		      string		item_setting,
		      string		enemy_setting);

		Enemy(int		kind,
		      string		item_setting, 
		      string		enemy_setting,
		      sf::Vector2f 	pos);

		Enemy(int 		kind,
		      string 		item_setting,
		      string 		enemy_setting, 
		      sf::Vector2f 	pos, 
		      int 		dir);

		void fire(int x);
		virtual void Action(sf::Time dt, sf::Vector2f mouse_position);
};


#endif
