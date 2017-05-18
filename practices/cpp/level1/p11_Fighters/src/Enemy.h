#ifndef CHARACTER_H_
#define CHARACTER_H_


#include "Character.h"


class Enemy:public Character{
	public:
		Enemy::Enemy(int		kind, 
			     string		item_setting,
			     string		enemy_setting);

		Enemy::Enemy(int		kind,
			     string		item_setting, 
			     string		enemy_setting,
			     sf::Vector2f 	pos);

		Enemy::Enemy(int 		kind,
			     string 		item_setting,
			     string 		enemy_setting, 
			     sf::Vector2f 	pos, 
			     int 		dir);

		void fire(int x);
		virtual Action(sf::Time dt, sf::Vector2f mouse_position);
};


#endif
