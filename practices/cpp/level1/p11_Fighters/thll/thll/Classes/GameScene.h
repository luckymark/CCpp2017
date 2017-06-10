#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#define GAME_UPDATE_SEC 1.0 / 60.0f
#define BG_1_TAG 101
#define BG_2_TAG 102

#include "cocos2d.h"
#include "SelfPlaneLayer.h"
#include "EnemyPlaneLayer.h"
#include "EnemyPlane.h"
#include "BulletLayer.h"
#include "TextLayer.h"
#include "TimeManager.h"
#include <map>
#include <vector>

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

	long getCurrentTime();

	int enemy_create_count = 0;

	int enemy_move_count = 0;

	int plane_auto_bullet_create_count = 0;

	int enemy_bullet_create_count = 0;

	bool is_first_enter = false;
};

#endif
