#ifndef ENEMY_H_
#define ENEMY_H_


#include "Character.h"


class Enemy:public Character{
	public:
		Enemy(int kind, string item_setting,sf::Vector2f pos, Director *world);

		void fire(sf::Time dt, sf::Vector2f dir);
		virtual void Action(sf::Time dt, sf::Vector2f mouse_position);
		virtual void dead();
};


#endif
