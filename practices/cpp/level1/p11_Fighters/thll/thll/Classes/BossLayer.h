#ifndef _BOSS_LAYER_H_
#define _BOSS_LAYER_H_

#include "cocos2d.h"
#include "Boss.h"

class BossLayer :public cocos2d::Layer
{
public:
	static BossLayer* create();

	static BossLayer* sharedBossLayer;

	virtual bool init();

	void bossCreate();

	void bossRunAction();

private:
	Boss* boss;
};
#endif // !_BOSS_LAYER_H_

