#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
#include "SelfPlaneLayer.h"
#include "EnemyPlaneLayer.h"
#include <map>

class GameScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* create();

	SelfPlaneLayer* getSelfPlaneLayer();

private:
	static cocos2d::Scene* gameScene;

	static SelfPlaneLayer* planeLayer;

	static EnemyPlaneLayer* enemyLayer;
};

#endif
