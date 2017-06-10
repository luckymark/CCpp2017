#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"

class Bullet :public cocos2d::Sprite
{
public:
	static Bullet* create(const std::string& filename);

	static Bullet* createWithSpriteFrameName(const std::string& spriteFrameName);

	virtual bool init();

	int getType();

	void setType(int type);

	int getDirection();

	void setDirection(int dir);

private:
	int type;

	int direction;
};
#endif