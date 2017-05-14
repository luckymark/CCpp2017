#ifndef PLAYER_H_
#define PLAYER_H_

#include "Character.h"

class Player: public Character{
	private:
		sf::Vector2f 	shot_direction;
		int 		bullte;
		sf::Clock	bullte_clock;
	public:
		Player(int kind, string name, string character_setting);
		Player(int kind, string name, string character_setting, sf::Vector2f pos);
		Player(int kind, string name, string character_setting, sf::Vector2f pos, int dir);
		//void control(int key); 		//used to control the character
		void set_shot_direction(sf::Vector2f pos);
		virtual void Action(sf::Time dt,sf::Vector2f pos);
		//virtual int has_request();
		//virtual int get_request();
		void fire(int x);

};



#endif
