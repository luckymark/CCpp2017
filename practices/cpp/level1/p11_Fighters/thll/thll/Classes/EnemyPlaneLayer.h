#ifndef _ENEMU_PLANE_LAYER_H_
#define _ENEMU_PLANE_LAYER_H_

#define ENEMY_TYPE_1_TAG 104
#define ENEMY_TYPE_2_TAG 105

#include "cocos2d.h"
#include "EnemyPlane.h"

class EnemyPlaneLayer :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	CREATE_FUNC(EnemyPlaneLayer);

	virtual bool init();

	cocos2d::Vector<EnemyPlane* > getEnemyList();

private:
	cocos2d::Vector<EnemyPlane* > enemyList;

	void enemyCreate(float dt);

	void enemyMove(float dt);
};
#endif