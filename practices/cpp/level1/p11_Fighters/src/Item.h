#ifndef ITEM_H_
#define ITEM_H_


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Concept.h"
#include "Animation.h"
#include "Physics.h"

#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;


//Player 0
//Bullet 1 
//Room 	 2 
//Enemy  3 //means normal enemy
//Object 4
//Boss   5
enum {Player_type, Bullet_type, Room_type, Enemy_type, Object_type, Boss_type} item_type;
static const int max_skill_num = 15;
class Director;
class Item{
	protected:
		int 		item_kind;		//use to define the kind of item
		Animation	*animation;		//store the animations
		int 		animation_num;		//store the num of animations
		int 		cur_animation; 		//store the current animation
		Director	*world;

		Magic 		life;
		Magic 		magic;
		Skill 		skill[max_skill_num];
		vector<Buff*>	buff;			//用于储存当前的状态
		Bag		bag;			//用于储存当前的物品

	public:
		Physics		physics;

		Item(int kind, string item_setting_name, sf::Vector2f pos,Director *world_);

		void 	set_position(sf::Vector2f pos);
		void 	set_speed(sf::Vector2f sp);
		void 	set_direction(sf::Vector2f sp);
		void 	add_force_from_skill(int key, sf::Vector2f dir, sf::Time dt);

		int 		get_kind();
		void 		get_setting(string item_setting_name);	//use to get the animation and other setting
		sf::Vector2f	get_speed();
		sf::Vector2f 	get_position();
		Animation* 	get_cur_animation();

		virtual void be_impacted_from(Item* other){}

		virtual void Action(sf::Time dt,sf::Vector2f pos){}
		virtual void use_skill(int which){}		//留给character使用的接口

		virtual void display();
		void next(sf::Time dt);
		virtual void dead();

		Animation* get_current_animation();

		virtual ~Item();
};

#endif
