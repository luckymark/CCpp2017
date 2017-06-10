#ifndef BEGIN_H_
#define BEGIN_H_

#include "CG.h"

class Begin:public CG{
	public:
		Begin(int kind, string item_setting_name, sf::Vector2f pos, Director *world_);
		virtual void dead();
		virtual void Action(sf::Time dt);
};

#endif
