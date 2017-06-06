#ifndef _BULLET_LAYER_H_
#define _BULLET_LAYER_H_

#define PLANE_BULLET_TAG 107
#define ENEMY_BULLET_TAG 110

#include "cocos2d.h"
#include "SelfPlaneLayer.h"
#include "EnemyPlaneLayer.h"

class BulletLayer :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	static BulletLayer* create();

	void bulletMove();

	void bulletCreate();

	void enemyBulletCreate();

	void bulletRemove(cocos2d::Sprite* sprite);

	static BulletLayer* sharedBullet;

	cocos2d::Vector<cocos2d::Sprite* > getBulletList();
private:
	
	cocos2d::Vector<cocos2d::Sprite* > bulletList;
};
#endif // !_BULLET_LAYER_H_
