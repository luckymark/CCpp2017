#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#define GAME_UPDATE_SEC 1.0 / 60.0f

#include "cocos2d.h"
#include "SelfPlaneLayer.h"
#include "EnemyPlaneLayer.h"
#include "EnemyPlane.h"
#include "BulletLayer.h"
#include "TextLayer.h"
#include <map>

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);
private:

	cocos2d::LabelTTF* scoreLabel;

	void gameUpdate(float dt);

	void collisionJudge();

	void scoreUpdate();

	SelfPlaneLayer* planeLayer;

	EnemyPlaneLayer* enemyLayer;

	BulletLayer* bulletLayer;

	void planeBomb(cocos2d::Vec2 vec, int tag);

	void bombRemove(cocos2d::Node * sprite);

	int enemy_create_count = 0;

	int enemy_move_count = 0;

	int plane_bullet_create_count = 0;

	int enemy_bullet_create_count = 0;

	bool isFirstEnter = true;
};

#endif
