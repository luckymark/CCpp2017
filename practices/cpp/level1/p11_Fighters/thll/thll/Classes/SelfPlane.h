#ifndef _SELF_PLANE_H_
#define _SELF_PLANE_H_

#include "cocos2d.h"

class SelfPlane :public cocos2d::Sprite
{
public:
	static SelfPlane* create(const char* fileName);

private:
	int life;
};
#endif