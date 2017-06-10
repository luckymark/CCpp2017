#ifndef _BULLET_LAYER_H_
#define _BULLET_LAYER_H_

#define PLANE_BULLET_TAG 107
#define ENEMY_BULLET_TAG 110
#define PLANE_BULLET_SPEED 30

#include "cocos2d.h"
#include "SelfPlaneLayer.h"
#include "EnemyPlaneLayer.h"
#include "Bullet.h"

class BulletLayer :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	static BulletLayer* create();

	void bulletMove();

	void bulletCreate();

	void enemyBulletCreate();

	void bulletRemove(Bullet* sprite);

	void bulletRemoveFromActin(Node * pNode);

	static BulletLayer* sharedBulletLayer;

	cocos2d::Vector<Bullet* > getBulletList();
private:
	
	cocos2d::Vector<Bullet* > bulletList;
};
#endif // !_BULLET_LAYER_H_
