#ifndef _BULLET_LAYER_H_
#define _BULLET_LAYER_H_

#include "cocos2d.h"
#include "SelfPlaneLayer.h"

class BulletLayer :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	static BulletLayer* create();

	void bulletMove();

	void bulletCreate();

	void bulletRemove(cocos2d::Sprite* sprite);

	static BulletLayer* sharedBullet;

	cocos2d::Vector<cocos2d::Sprite* > getBulletList();
private:
	
	cocos2d::Vector<cocos2d::Sprite* > bulletList;
};
#endif // !_BULLET_LAYER_H_
