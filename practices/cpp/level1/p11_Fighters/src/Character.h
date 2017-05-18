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

static const int max_skill_num = 15;
static const int dirx[10]={0,0,-1,1,0,0,0,0};
static const int diry[10]={1,-1,0,0,0,0,0,0};

class Character: public Item{
	protected:
		Magic 		life;
		Magic 		magic;
		Skill 		skill[max_skill_num];
		vector<Buff*>	buff;			//用于储存当前的状态
		Bag		bag;			//用于储存当前的物品

		sf::Vector2f 	shot_direction;
		int 		bullte;
		sf::Clock	bullte_clock;
		void set_null();
	public:
		Character(int kind, string item_setting, string character_setting);
		Character(int kind, string item_setting, string character_setting, sf::Vector2f pos);
		Character(int kind, string item_setting, string character_setting, sf::Vector2f pos, int dir);

		void set_character_from_setting(string character_setting);

		void set_life(int key,int val);
		void set_magic(int key,int val);
		void set_shot_direction(sf::Vector2f pos);
		void set_skill(int key, Skill Sk);

		void add_buff(Buff bf);
		void clear_buff();
		void add_prop(int key, Prop prop);
		void use_prop(int key);

		void use_skill(int key);

		virtual ~Character();
};

#endif
