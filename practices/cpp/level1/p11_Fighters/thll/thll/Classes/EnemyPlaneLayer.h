#ifndef _ENEMU_PLANE_LAYER_H_
#define _ENEMU_PLANE_LAYER_H_

#define ENEMY_TYPE_1_TAG 104
#define ENEMY_TYPE_2_TAG 105

#include "cocos2d.h"
#include "EnemyPlane.h"
#include "BulletLayer.h"
#include "EnemyPlaneMedium.h"

class EnemyPlaneLayer :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	static EnemyPlaneLayer* create();

	virtual bool init();

	cocos2d::Vector<EnemyPlane* > getEnemyList();

	void enemyCreate(int progress);

	//void enemyMove();

	void enemyRemove(Node* pNode);

	void enemyShoting();

	static EnemyPlaneLayer* sharedEnemy;

	void eraseEnemy(EnemyPlane* enemy);

	void emptyAllEnemy();

	void aniRemove(cocos2d::Node * sprite);

private:
	cocos2d::Vector<EnemyPlane* > enemyList;
};
#endif