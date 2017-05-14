/******************************************************************************
  在这个头文件中，我们对这个世界上的所有的物件都做了抽象，让他们成为了有血有肉的
  个体。

  当然，这里的item不会包括道具。

  经过一些具体的尝试之后，我意识到，这个世界还应该有和item不易样的东西
  Concept,不然的话，各种抽象的数据和状态会难以管理。
  item -----> Character-----------> Enemy----> Normal
        |                        |        |
        |                        |        |---> Boss
	|                        |---->Player
  	|---> Object
********************************************************************************/
/* author chenxiaoyu */

#ifndef ITEM_H_
#define ITEM_H_


#include <SFML/Graphics.hpp>
//#include <SFML/Vector2.hpp>
#include <SFML/Window.hpp>

#include "Concept.h"
#include "Animation.h"

#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;


//Player 0
//Normal 1 
//Boss   2
//Object 3
static const int dirx[10]={0,0,-1,1,0,0,0,0};
static const int diry[10]={1,-1,0,0,0,0,0,0};


class Item{
	protected:
		int 		toward; 		// 0 forward, 1 back, 2 left, 3 right.
		int 		item_kind;		//use to define the kind of item

		Animation	*animation;		//store the animations
		int 		animation_num;		//store the num of animations
		sf::Vector2f	position;		//store the position of item
		sf::Vector2f	speed;
		float 		stop_ratio;


		int 		cur_animation; 		//store the current animation
		int 		default_animation;	//store the default animation

		int 		is_on_ground;
		int 		dead_flag;
	public:
		Item(int kind, string item_setting_name);
		Item(int kind, string item_setting_name, sf::Vector2f pos);
		Item(int kind, string item_setting_name, sf::Vector2f pos, int dir);

		void set_toward(int dir);			//set the toward of the item
		void set_stop_ratio(float f);
		void stop();
		void set_position(sf::Vector2f pos);

		void get_setting(string item_setting_name);	//use to get the animation and other setting
		//virtual void get_hurt(Animation *from){}	//the ways that the item could
		//virtual void get_silence(Animation *from){}	//be affected by others
		//virtual void get_dizziness(Animation * from){}
		virtual void get_impact_from(Animation *from){}

		virtual void Action(sf::Time dt){}
		virtual void use_skill(int which){}		//留给character使用的接口
		virtual void walk(){}

								// 1) 所有的影响都是用Animation完成的。
								// 2) 所有的影响都必须交由Animation。

		sf::Sprite* display();
		void next(sf::Time dt);
		void update_position();
		void update_speed();
		int get_toward();
		int get_kind();
		sf::Vector2f get_speed();
		Animation* get_current_animation();
		int is_dead(){return 0;}
		int dead(){return 0;}

		virtual ~Item();
};


static const int max_skill_num = 15;
class Character: public Item{
	protected:
		Magic 	life;
		Magic 	magic;
		Skill 	skill[max_skill_num];
		Buff	*buff[max_skill_num];	//用于储存当前的状态
		Bag	bag;			//用于储存当前的物品

	public:
		Character(int kind, string item_setting, string character_setting);
		Character(int kind, string item_setting, string character_setting, sf::Vector2f pos);
		Character(int kind, string item_setting, string character_setting, sf::Vector2f pos, int dir);

		void set_character_from_setting(string character_setting);

		void set_life(int key,int val);
		void set_magic(int key,int val);
		void set_skill(int key, Skill Sk);
		void add_buff(Buff bf);
		void clear_buff();
		void use_prop(int key);
		void add_prop(int key, Prop prop);


		void use_skill(int key);

		void control(char key);

		virtual ~Character();
};

class Player: public Character{
	public:
		Player(int kind, string name, string character_setting);
		Player(int kind, string name, string character_setting, sf::Vector2f pos);
		Player(int kind, string name, string character_setting, sf::Vector2f pos, int dir);
		//void control(int key); 		//used to control the character
		virtual void Action(sf::Time dt);
};

class Object: public Item{

};

class Normal: public Character{
};

class Boss: public Character{
};


#endif
