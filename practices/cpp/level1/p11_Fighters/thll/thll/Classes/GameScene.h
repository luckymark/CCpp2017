#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#define GAME_UPDATE_SEC 1.0 / 60.0f
#define BG_1_TAG 101
#define BG_2_TAG 102
#define JUD_T(x) TimeManager::getInstance()->JudgeTime(x)
#define JUD_T_A(x) TimeManager::getInstance()->JudgeTimeArray(std::vector<long double>{x})

#include "cocos2d.h"
#include "SelfPlaneLayer.h"
#include "EnemyPlaneLayer.h"
#include "EnemyPlane.h"
#include "BulletLayer.h"
#include "TextLayer.h"
#include "TimeManager.h"
#include "BossLayer.h"
#include "ProgressView.h"
#include "DropItemLayer.h"
#include "GamePauseLayer.h"
#include "GameOver.h"
#include "Audio.h"
#include <map>
#include <vector>

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);

private:

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

	cocos2d::LabelBMFont *scoreLabel;

	cocos2d::LabelBMFont *lifeLabel;

	cocos2d::LabelBMFont *bombLabel;

	ProgressView *bloodbar;

	cocos2d::Sprite* bombPic;

	void gameUpdate(float dt);

	void collisionJudge();

	void scoreUpdate();

	void lifeUpdate();

	void bombUpdate();

	SelfPlaneLayer* planeLayer;

	EnemyPlaneLayer* enemyLayer;

	BulletLayer* bulletLayer;

	BossLayer* bossLayer;

	DropItemLayer* dropLayer;

	GamePauseLayer* pauseLayer;

	SelfPlane* plane;

	void planeBomb(cocos2d::Vec2 vec, int tag);

	void bombRemove(cocos2d::Node * sprite);

	void buttonPauseCallBack();

	long getCurrentTime();

	bool isEnemyShoot();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

	void buttonBombCallBack();

	int enemy_create_count = 0;

	int enemy_move_count = 0;

	int plane_auto_bullet_create_count = 0;

	int auto_bullet_create = 0;

	bool is_first_enter = true;

	bool is_boss_create = false;
};

#endif
