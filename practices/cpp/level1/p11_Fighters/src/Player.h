#ifndef PLAYER_H_
#define PLAYER_H_

#include "Character.h"

class Player: public Character{
	public:
		Player(int kind, string name, string character_setting);
		Player(int kind, string name, string character_setting, sf::Vector2f pos);
		Player(int kind, string name, string character_setting, sf::Vector2f pos, int dir);
		virtual void Action(sf::Time dt,sf::Vector2f pos);
		void fire(int x);
};



#endif
