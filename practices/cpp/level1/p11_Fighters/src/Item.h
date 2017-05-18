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
//Bullet 1 
//Room 	 2 
//Enemy  3 //means normal enemy
//Object 4
//Boss   5
enum {Player_type, Bullet_type, Room_type, Enemy_type, Object_type, Boss_type} item_type;

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
		int 		request;
		int 		request_flag;
		//int 		dead_request;
		sf::Vector2f	direction;
		sf::Vector2f	request_direction;
	public:
		Item(int kind, string item_setting_name);
		Item(int kind, string item_setting_name, sf::Vector2f pos);
		Item(int kind, string item_setting_name, sf::Vector2f pos, int dir);

		void 	set_toward(int dir);			//set the toward of the item
		void 	set_stop_ratio(float f);
		void 	set_position(sf::Vector2f pos);
		void 	set_speed(sf::Vector2f sp);
		void 	set_direction(sf::Vector2f sp);

		int 		get_toward();
		int 		get_kind();
		void 		get_setting(string item_setting_name);	//use to get the animation and other setting
		sf::Vector2f	get_speed();
		sf::Vector2f 	get_position();
		sf::Vector2f 	get_request_direction();
		virtual int 	get_request(){return request;}
		Animation* 	get_cur_animation();

		virtual void be_impacted_from(Item* other){}

		virtual void Action(sf::Time dt,sf::Vector2f pos){}
		virtual void use_skill(int which){}		//留给character使用的接口
		virtual void walk(){}

		virtual sf::Sprite* display();
		void next(sf::Time dt);
		void update_position();
		void update_speed();
		void stop();

		Animation* get_current_animation();
		virtual int is_dead(){return dead_flag;}
		virtual int has_request(){return request_flag;}
		virtual int dead(){return -1;}

		virtual ~Item();
};

#endif
