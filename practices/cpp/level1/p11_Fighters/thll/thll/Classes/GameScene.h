#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
#include "SelfPlaneLayer.h"
#include "EnemyPlaneLayer.h"
#include "EnemyPlane.h"
#include <map>

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void onEnterTransitionDidFinish();

	CREATE_FUNC(GameScene);


private:

	void collisionJudge(float dt);

	SelfPlaneLayer* planeLayer;

	EnemyPlaneLayer* enemyLayer;

	void planeBomb(cocos2d::Vec2 vec, int tag);

	void bombRemove(cocos2d::Node * sprite);
};

#endif
