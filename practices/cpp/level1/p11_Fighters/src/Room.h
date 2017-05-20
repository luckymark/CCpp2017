#ifndef ROOM_H_
#define ROOM_H_
#include "Item.h"


class Room: public Item{
	public:
		Room(int kind, string setting, sf::Vector2f pos, Director *world);
		void set_edge(sf::Vector2f len);
};

#endif
