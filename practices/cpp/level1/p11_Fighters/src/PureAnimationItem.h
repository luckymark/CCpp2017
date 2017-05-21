#ifndef PURE_ANIMATION_ITEM_H_
#define PURE_ANIMATION_ITEM_H_

#include "Item.h"

class PureAnimationItem: public Item{
	private:
		int cnt;
	public:
		PureAnimationItem(int kind, string setting, sf::Vector2f pos, Director *world, int times);
		virtual void Action(sf::Time dt, sf::Vector2f pos);
};

#endif
