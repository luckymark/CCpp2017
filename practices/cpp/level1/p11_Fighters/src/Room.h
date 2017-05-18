/****************************************************************************************************
  Room类承担了地图和背景的功能。但是其实他自身也是一个Item，因为只有Item才能和其他的东西互动，
  这里Room要和其他的东西互动来
****************************************************************************************************/

#ifndef ROOM_H_
#define ROOM_H_
#include "Item.h"


class Room: public Item{
	public:
		Room(int 		kind,
	             string 		item_setting_name, 
		     sf::Vector2f 	pos);

		Room(int 		kind, 
		     string 		item_setting_name, 
		     string 		room_name, 
		     sf::Vector2f 	pos);

		Room(int 		kind,
	  	     string 		item_setting_name, 
		     string 		room_name, 
		     sf::Vector2f 	pos,
		     sf::Vector2f	size);
		
		void set_edge(sf::Vector2f len);
};

#endif
