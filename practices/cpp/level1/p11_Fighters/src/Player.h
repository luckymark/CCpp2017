#ifndef PLAYER_H_
#define PLAYER_H_

#include "Character.h"

class Player: public Character{
	public:
		Player(int kind, string name, sf::Vector2f pos, Director *world);
		virtual void Action(sf::Time dt,sf::Vector2f pos);
		void fire(sf::Time dt, sf::Vector2f dir);
};



#endif
