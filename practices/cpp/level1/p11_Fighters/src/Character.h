#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Item.h"
#include "Concept.h"
#include "Animation.h"

#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;


class Character: public Item{
	protected:
		sf::Vector2f 	shot_direction;
		int 		bullte;
		sf::Clock	bullte_clock;
		void set_null();
	public:
		Character(int kind, string setting, sf::Vector2f pos, Director *world);
		void animation_init();
		void set_shot_direction(sf::Vector2f pos);
		void use_skill(int key);
		virtual ~Character();
};

#endif
