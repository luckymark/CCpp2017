#ifndef _BOSS_LAYER_H_
#define _BOSS_LAYER_H_

#include "cocos2d.h"
#include "Boss.h"
#include "BulletLayer.h"

class BossLayer :public cocos2d::Layer
{
public:
	static BossLayer* create();

	static BossLayer* sharedBossLayer;

	virtual bool init();

	void bossCreate();

	void bossRunAction();

	void bossMove(int progress);

	void bossAttack(int progress);

	void bossMoveAndAttack(int progress);

private:
	Boss* boss;
};
#endif // !_BOSS_LAYER_H_

