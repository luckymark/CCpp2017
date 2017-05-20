#ifndef _ENEMU_PLANE_LAYER_H_
#define _ENEMU_PLANE_LAYER_H_

#define ENEMY_TYPE_1_TAG 104
#define ENEMY_TYPE_2_TAG 105

#include "cocos2d.h"

class EnemyPlaneLayer :public cocos2d::Layer
{
public:
	CREATE_FUNC(EnemyPlaneLayer);

	virtual bool init();

private:
	cocos2d::Vector<cocos2d::Sprite* > enemyList;

	void enemyCreate(float dt);

	void enemyMove(float dt);
};
#endif