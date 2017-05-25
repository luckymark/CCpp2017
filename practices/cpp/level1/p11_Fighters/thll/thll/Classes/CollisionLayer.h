#ifndef _COLLISION_LAYER_H_
#define _COLLISION_LAYER_H_

#include "cocos2d.h"

class CollisionLayer:public cocos2d::Layer
{
public:
	CREATE_FUNC(CollisionLayer);

	virtual bool init();

	//virtual void onEnter();

	virtual void collisionJudge(float dt);

private:
	/*bool onContactBegin(cocos2d::PhysicsContact &contact);

	void planBomb(cocos2d::Vec2 vec, int tag);

	void bombRemove(cocos2d::Node * sprite);*/
};
#endif
